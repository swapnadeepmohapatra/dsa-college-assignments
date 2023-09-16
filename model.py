import torch
import torch.nn as nn
import torch.optim as optim
import numpy as np
import matplotlib.pyplot as plt

# Variable initialization functions
def weight_variable(shape):
    initial = torch.randn(shape) * 0.1
    return nn.Parameter(initial)

def bias_variable(shape):
    initial = torch.ones(shape) * 0.1
    return nn.Parameter(initial)

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

# Usage example:
# device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
# model = Model(in_dim=784, out_dim=10).to(device)
# dataloader = torch.utils.data.DataLoader(dataset, batch_size=batch_size, shuffle=True)
# fisher_information = compute_fisher(model, dataloader, num_samples=200, plot_diffs=True, disp_freq=10)
