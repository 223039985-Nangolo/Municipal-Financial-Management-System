#ifndef BUDGET_H
#define BUDGET_H

#define MAX_DEPT 20
#define MAX_NAME 40

typedef struct {
    char name[MAX_NAME];
    float allocated;
    float spent;
} Budget;

extern Budget budgets[MAX_DEPT];
extern int deptCount;

void handleBudgetMenu();
void addDepartmentBudget();
void recordExpenditure();
void displayBudgetStatus();
void checkOverBudget();
float getTotalAllocated();
float getTotalSpent();

#endif