#include <stdio.h>
#include <string.h>
#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"
#include "reports.h"

// Function to show main menu
void displayMainMenu() {
    printf("\n\n");
    printf("========================================\n");
    printf("   MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("========================================\n");
    printf("1. Employee Management\n");
    printf("2. Budget Management\n");
    printf("3. Supplier Management\n");
    printf("4. Asset Management\n");
    printf("5. Reports\n");
    printf("6. Exit\n");
    printf("========================================\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;

    while (1) {  // Loop until user chooses Exit
        displayMainMenu();
        
        // Input validation
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while(getchar() != '\n'); // Clear bad input
            continue;
        }

        switch (choice) {
            case 1:
                handleEmployeeMenu();
                break;
            case 2:
                handleBudgetMenu();
                break;
            case 3:
                handleSupplierMenu();
                break;
            case 4:
                handleAssetMenu();
                break;
            case 5:
                generateAllReports();
                break;
            case 6:
                printf("Exiting system... Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please select 1–6.\n");
        }
    }
    return 0;
}