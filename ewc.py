# generate a pytorch code for continual learning using a progressive neural network avoiding catastrophic forgetting on ResNet 18 neural architecture. Also provide suitable metrics for visualisation.

# Importing the libraries
import torch
import torchvision
import torch.nn as nn
import torch.nn.functional as F
import torchvision.transforms as transforms
import torch.optim as optim
import matplotlib.pyplot as plt
import numpy as np
from torch.autograd import Variable
from torchvision import datasets, transforms
from torch.utils.data import DataLoader
from torch.utils.data.sampler import SubsetRandomSampler
import numpy as np
import os
import copy
import random
import time
import math
import sys
import argparse
import pickle
import pdb
import matplotlib.pyplot as plt
import matplotlib.ticker as ticker
from PIL import Image
from torch.utils.data import Dataset
from torch.utils.data import DataLoader
from torch.utils.data import Subset
from torch.utils.data import random_split
from torchvision.datasets import MNIST
from torchvision

# Importing the dataset
dataset = torchvision.datasets.MNIST(root='./data', train=True, download=True, transform=transforms.ToTensor())

# Splitting the dataset into the Training set and Test set
train_set, test_set = torch.utils.data.random_split(dataset, [50000, 10000])
train_loader = torch.utils.data.DataLoader(train_set, batch_size=64, shuffle=True)
test_loader = torch.utils.data.DataLoader(test_set, batch_size=64, shuffle=True)

# Defining the model
class Model(nn.Module):
    def __init__(self, in_dim, out_dim):
        super(Model, self).__init__()
        self.W1 = weight_variable([in_dim, 50])
        self.b1 = bias_variable(50)
        self.W2 = weight_variable([50, out_dim])
        self.b2 = bias_variable(out_dim)

    def forward(self, x):
        h1 = torch.relu(torch.mm(x, self.W1) + self.b1)
        y = torch.mm(h1, self.W2) + self.b2
        return y

def compute_fisher(model, dataloader, num_samples=200, plot_diffs=False, disp_freq=10):
    # Compute Fisher information for each parameter

    # Initialize Fisher information for most recent task
    F_accum = [torch.zeros_like(param) for param in model.parameters()]

    if plot_diffs:
        # Track differences in mean Fisher info
        F_prev = deepcopy(F_accum)
        mean_diffs = []

    for i, (inputs, labels) in enumerate(dataloader):
        inputs, labels = inputs.to(device), labels.to(device)
        model.zero_grad()
        outputs = model(inputs)
        log_probs = torch.log_softmax(outputs, dim=1)
        class_ind = torch.multinomial(log_probs, 1)
        loss = -log_probs[0, class_ind[0]]

        grads = torch.autograd.grad(loss, model.parameters(), create_graph=True)

        for j, param in enumerate(model.parameters()):
            F_accum[j] += grads[j].pow(2)

        if plot_diffs:
            if i % disp_freq == 0 and i > 0:
                # Recording mean diffs of F
                F_diff = sum(torch.sum(torch.abs(F_accum[v] / (i + 1) - F_prev[v])) for v in range(len(F_accum)))
                mean_diff = F_diff.item() / len(F_accum)
                mean_diffs.append(mean_diff)

                for v in range(len(F_accum)):
                    F_prev[v] = F_accum[v] / (i + 1)

                plt.plot(range(disp_freq + 1, i + 2, disp_freq), mean_diffs)
                plt.xlabel("Number of samples")
                plt.ylabel("Mean absolute Fisher difference")
                plt.show()

    # Divide totals by number of samples
    for j, param in enumerate(model.parameters()):
        F_accum[j] /= num_samples

    return F_accum

# Training the model
def train(model, train_loader, optimizer, epoch, log_interval=100):
    model.train()
    for batch_idx, (data, target) in enumerate(train_loader):
        data, target = Variable(data), Variable(target)
        optimizer.zero_grad()
        output = model(data)
        loss = F.nll_loss(output, target)
        loss.backward()
        optimizer.step()
        if batch_idx % log_interval == 0:
            print('Train Epoch: {} [{}/{} ({:.1f}%)]\tLoss: {:.6f}'.format(
                epoch, batch_idx * len(data), len(train_loader.dataset),
                100. * batch_idx / len(train_loader), loss.item()))

# Testing the model
def test(model, test_loader):
    model.eval()
    test_loss = 0
    correct = 0
    for data, target in test_loader:
        data, target = Variable(data), Variable(target)
        output = model(data)
        # sum up batch loss
        test_loss += F.nll_loss(output, target, reduction='sum').item()
        # get the index of the max log-probability
        pred = output.data.max(1)[1]
        correct += pred.eq(target.data).cpu().sum().item()

    test_loss /= len(test_loader.dataset)
    print('\nTest set: Average loss: {:.4f}, Accuracy: {}/{} ({:.1f}%)\n'.format(
        test_loss, correct, len(test_loader.dataset),
        100. * correct / len(test_loader.dataset)))

# Training the model
for epoch in range(1, 10 + 1):
    train(model, train_loader, optimizer, epoch)
    test(model, test_loader)

# Saving the model
torch.save(model.state_dict(), 'model.ckpt')

# Loading the model
model.load_state_dict(torch.load('model.ckpt'))

# Storing fisher information
F_accum = compute_fisher(model, dataloader, num_samples=200, plot_diffs=False, disp_freq=10)

# Training the model with EWC
def train_ewc(model, train_loader, optimizer, epoch, lamda=15, log_interval=100):
    model.train()
    for batch_idx, (data, target) in enumerate(train_loader):
        data, target = Variable(data), Variable(target)
        optimizer.zero_grad()
        output = model(data)
        loss = F.nll_loss(output, target)
        for (name, param), F in zip(model.named_parameters(), F_accum):
            if 'weight' in name:
                loss += (lamda/2) * torch.sum(F * (param - prior_weights[name]) ** 2)
        loss.backward()
        optimizer.step()
        if batch_idx % log_interval == 0:
            print('Train Epoch: {} [{}/{} ({:.1f}%)]\tLoss: {:.6f}'.format(
                epoch, batch_idx * len(data), len(train_loader.dataset),
                100. * batch_idx / len(train_loader), loss.item()))

# Training the model with EWC
for epoch in range(1, 10 + 1):
    train_ewc(model, train_loader, optimizer, epoch)
    test(model, test_loader)