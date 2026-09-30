#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#define MAX_EMPLOYEES 100
#define MAX_NAME_LEN 50
#define MAX_DEPT_LEN 30

typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    char department[MAX_DEPT_LEN];
    float basicSalary;
    float housingAllowance;
    float transportAllowance;
    float totalSalary;
} Employee;

extern Employee employees[MAX_EMPLOYEES];
extern int employeeCount;

void handleEmployeeMenu();
void addEmployee();
void displayAllEmployees();
void searchEmployee();
void calculateSalaries();
float getAverageSalary();
Employee getHighestSalary();
Employee getLowestSalary();

#endif