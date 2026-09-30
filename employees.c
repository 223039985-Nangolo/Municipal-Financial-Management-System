#include <stdio.h>
#include <string.h>
#include "employees.h"

Employee employees[MAX_EMPLOYEES];
int employeeCount = 0;

void handleEmployeeMenu() {
    int opt;
    while (1) {
        printf("\n--- EMPLOYEE MANAGEMENT ---\n");
        printf("1. Add Employee\n");
        printf("2. Display All\n");
        printf("3. Search Employee\n");
        printf("4. Salary Summary\n");
        printf("5. Back to Main Menu\n");
        printf("Choice: ");
        
        if (scanf("%d", &opt) != 1) {
            printf("Enter a number!\n");
            while(getchar() != '\n');
            continue;
        }
        switch(opt) {
            case 1: addEmployee(); break;
            case 2: displayAllEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: calculateSalaries(); break;
            case 5: return;
            default: printf("Invalid option!\n");
        }
    }
}

void addEmployee() {
    if (employeeCount >= MAX_EMPLOYEES) {
        printf("Employee list full!\n");
        return;
    }
    Employee e;
    printf("Enter Employee ID: ");
    scanf("%d", &e.id);
    for (int i=0; i<employeeCount; i++) {
        if (employees[i].id == e.id) {
            printf(" ID already exists!\n");
            return;
        }
    }
    printf("Enter Full Name: ");
    while(getchar() != '\n');
    fgets(e.name, MAX_NAME_LEN, stdin);
    e.name[strcspn(e.name, "\n")] = 0;
    if (strlen(e.name) == 0) {
        printf("Name cannot be empty!\n");
        return;
    }
    printf("Enter Department: ");
    fgets(e.department, MAX_DEPT_LEN, stdin);
    e.department[strcspn(e.department, "\n")] = 0;
    printf("Basic Salary: N$");
    scanf("%f", &e.basicSalary);
    if (e.basicSalary < 0) {
        printf("Salary cannot be negative!\n");
        return;
    }
    printf("Housing Allowance: N$");
    scanf("%f", &e.housingAllowance);
    printf("Transport Allowance: N$");
    scanf("%f", &e.transportAllowance);
    e.totalSalary = e.basicSalary + e.housingAllowance + e.transportAllowance;
    employees[employeeCount++] = e;
    printf("Added! Total Salary: N$%.2f\n", e.totalSalary);
}

void displayAllEmployees() {
    if (employeeCount == 0) { printf("📋 No employees.\n"); return; }
    printf("\n%5s | %-25s | %-15s | %12s\n", "ID", "Name", "Department", "Total Salary");
    printf("-----------------------------------------------------------\n");
    for (int i=0; i<employeeCount; i++) {
        printf("%5d | %-25s | %-15s | N$%10.2f\n",
            employees[i].id, employees[i].name,
            employees[i].department, employees[i].totalSalary);
    }
}

void searchEmployee() {
    int id, found=0;
    printf("Enter ID to search: ");
    scanf("%d", &id);
    for (int i=0; i<employeeCount; i++) {
        if (employees[i].id == id) {
            printf("\n Found:\nName: %s\nDept: %s\nTotal: N$%.2f\n",
                employees[i].name, employees[i].department, employees[i].totalSalary);
            found = 1; break;
        }
    }
    if (!found) printf("No employee with ID %d\n", id);
}

void calculateSalaries() {
    displayAllEmployees();
    printf("\n--- Salary Summary ---\n");
    printf("Total Employees: %d\n", employeeCount);
    if (employeeCount == 0) return;
    printf("Average Salary: N$%.2f\n", getAverageSalary());
    Employee h = getHighestSalary();
    Employee l = getLowestSalary();
    printf("Highest: N$%.2f (%s)\n", h.totalSalary, h.name);
    printf("Lowest: N$%.2f (%s)\n", l.totalSalary, l.name);
}

float getAverageSalary() {
    if (employeeCount == 0) return 0;
    float sum = 0;
    for (int i=0; i<employeeCount; i++) sum += employees[i].totalSalary;
    return sum / employeeCount;
}

Employee getHighestSalary() {
    int idx = 0;
    for (int i=1; i<employeeCount; i++)
        if (employees[i].totalSalary > employees[idx].totalSalary) idx = i;
    return employees[idx];
}

Employee getLowestSalary() {
    int idx = 0;
    for (int i=1; i<employeeCount; i++)
        if (employees[i].totalSalary < employees[idx].totalSalary) idx = i;
    return employees[idx];
}