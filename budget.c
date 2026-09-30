#include <stdio.h>
#include <string.h>
#include "budget.h"

Budget budgets[MAX_DEPT];
int deptCount = 0;

void handleBudgetMenu() {
    int opt;
    while (1) {
        printf("\n--- BUDGET MANAGEMENT ---\n");
        printf("1. Set Department Budget\n");
        printf("2. Record Expenditure\n");
        printf("3. Show All Budgets\n");
        printf("4. Check Over-Budget Depts\n");
        printf("5. Back to Main Menu\n");
        printf("Choice: ");
        if (scanf("%d", &opt) != 1) {
            printf("Enter a number!\n");
            while(getchar() != '\n'); continue;
        }
        switch(opt) {
            case 1: addDepartmentBudget(); break;
            case 2: recordExpenditure(); break;
            case 3: displayBudgetStatus(); break;
            case 4: checkOverBudget(); break;
            case 5: return;
            default: printf("Invalid option!\n");
        }
    }
}

void addDepartmentBudget() {
    if (deptCount >= MAX_DEPT) { printf(" Max departments reached!\n"); return; }
    char name[MAX_NAME];
    float alloc;
    printf("Department Name: ");
    while(getchar() != '\n');
    fgets(name, MAX_NAME, stdin);
    name[strcspn(name, "\n")] = 0;
    if (strlen(name) == 0) { printf("Name empty!\n"); return; }
    for (int i=0; i<deptCount; i++) {
        if (strcmp(budgets[i].name, name) == 0) {
            printf("Department exists!\n"); return;
        }
    }
    printf("Allocated Budget: N$");
    scanf("%f", &alloc);
    if (alloc < 0) { printf("Cannot be negative!\n"); return; }
    strcpy(budgets[deptCount].name, name);
    budgets[deptCount].allocated = alloc;
    budgets[deptCount].spent = 0;
    deptCount++;
    printf(" Budget set for %s\n", name);
}

void recordExpenditure() {
    char name[MAX_NAME];
    float amount;
    printf("Department Name: ");
    while(getchar() != '\n');
    fgets(name, MAX_NAME, stdin);
    name[strcspn(name, "\n")] = 0;
    printf("Amount Spent: N$");
    scanf("%f", &amount);
    if (amount < 0) { printf("Negative!\n"); return; }
    int found = 0;
    for (int i=0; i<deptCount; i++) {
        if (strcmp(budgets[i].name, name) == 0) {
            budgets[i].spent += amount;
            found = 1;
            printf("Recorded. Total Spent: N$%.2f\n", budgets[i].spent);
            break;
        }
    }
    if (!found) printf("Department not found!\n");
}

void displayBudgetStatus() {
    if (deptCount == 0) { printf("No budgets set.\n"); return; }
    printf("\n%-20s | %12s | %12s | %12s | %s\n",
        "Department", "Allocated", "Spent", "Remaining", "Status");
    printf("---------------------------------------------------------------\n");
    for (int i=0; i<deptCount; i++) {
        float rem = budgets[i].allocated - budgets[i].spent;
        printf("%-20s | N$%10.2f | N$%10.2f | N$%10.2f | %s\n",
            budgets[i].name, budgets[i].allocated, budgets[i].spent, rem,
            (rem >= 0) ? "WITHIN BUDGET" : "OVER BUDGET");
    }
}

void checkOverBudget() {
    int over = 0;
    printf("\n--- DEPARTMENTS OVER BUDGET ---\n");
    for (int i=0; i<deptCount; i++) {
        if (budgets[i].spent > budgets[i].allocated) {
            printf(" %s — Over by N$%.2f\n",
                budgets[i].name, budgets[i].spent - budgets[i].allocated);
            over = 1;
        }
    }
    if (!over) printf(" All departments within budget.\n");
}

float getTotalAllocated() {
    float sum = 0;
    for (int i=0; i<deptCount; i++) sum += budgets[i].allocated;
    return sum;
}

float getTotalSpent() {
    float sum = 0;
    for (int i=0; i<deptCount; i++) sum += budgets[i].spent;
    return sum;
}