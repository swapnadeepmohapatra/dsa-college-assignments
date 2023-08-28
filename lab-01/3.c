// Write a program to create a structure to store the information of n number of Employees. Employee’s information includes data members: Emp-id, Name, Designation, basic_salary, hra%, da%. Display the information of employees with gross salary. Use array of structure.

#include <stdio.h>
#include <string.h>

struct Employee
{
    char empId[20];
    char name[100];
    char designation[100];
    float basicSalary;
    float hraPercentage;
    float daPercentage;
};

void displayEmployeeInfo(struct Employee emp)
{
    float hra = emp.basicSalary * (emp.hraPercentage / 100);
    float da = emp.basicSalary * (emp.daPercentage / 100);
    float grossSalary = emp.basicSalary + hra + da;
    printf("Name: %s\n", emp.name);
    printf("Designation: %s\n", emp.designation);
    printf("Basic Salary: %.2f\n", emp.basicSalary);
    printf("HRA %%: %.2f%%\n", emp.hraPercentage);
    printf("DA %%: %.2f%%\n", emp.daPercentage);
    printf("Gross Salary: %.2f\n\n", grossSalary);
}

int main()
{
    int n;
    printf("Enter no. of employees: ");
    scanf("%d", &n);
    struct Employee employees[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter employee %d information:\n", i + 1);
        scanf("%s %s %f %f %f",
              employees[i].name,
              employees[i].designation,
              &employees[i].basicSalary,
              &employees[i].hraPercentage,
              &employees[i].daPercentage);
    }
    printf("Employee Information:\n");
    for (int i = 0; i < n; i++)
    {
        displayEmployeeInfo(employees[i]);
    }
    return 0;
}
