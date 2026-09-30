#include <stdio.h>
#include "reports.h"
#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"

void generateEmployeeReport() {
    printf("\n\n===== EMPLOYEE REPORT =====\n");
    printf("Total Employees: %d\n", employeeCount);
    if (employeeCount == 0) return;
    printf("Average Salary: N$%.2f\n", getAverageSalary());
    Employee high = getHighestSalary();
    Employee low = getLowestSalary();
    printf("Highest Salary: N$%.2f (%s)\n", high.totalSalary, high.name);
    printf("Lowest Salary: N$%.2f (%s)\n", low.totalSalary, low.name);
}

void generateBudgetReport() {
    printf("\n\n===== BUDGET REPORT =====\n");
    printf("Total Allocated Budget: N$%.2f\n", getTotalAllocated());
    printf("Total Expenditure:      N$%.2f\n", getTotalSpent());
    printf("Remaining Budget:      N$%.2f\n", getTotalAllocated() - getTotalSpent());
    displayBudgetStatus();
}

void generateSupplierReport() {
    printf("\n\n===== SUPPLIER REPORT =====\n");
    printf("Total Suppliers: %d\n", supplierCount);
    displayAllSuppliers();
}

void generateAssetReport() {
    printf("\n\n===== ASSET REPORT =====\n");
    printf("Total Assets: %d\n", assetCount);
    displayAllAssets();
}

void generateAllReports() {
    int opt;
    while (1) {
        printf("\n--- REPORTS ---\n");
        printf("1. Employee Report\n");
        printf("2. Budget Report\n");
        printf("3. Supplier Report\n");
        printf("4. Asset Report\n");
        printf("5. All Reports\n");
        printf("6. Back to Main Menu\n");
        printf("Choice: ");

        if (scanf("%d", &opt) != 1) {
            printf("Enter a number!\n");
            while(getchar() != '\n');
            continue;
        }

        switch(opt) {
            case 1: generateEmployeeReport(); break;
            case 2: generateBudgetReport(); break;
            case 3: generateSupplierReport(); break;
            case 4: generateAssetReport(); break;
            case 5:
                generateEmployeeReport();
                generateBudgetReport();
                generateSupplierReport();
                generateAssetReport();
                break;
            case 6: return;
            default: printf("Invalid option!\n");
        }
    }
}