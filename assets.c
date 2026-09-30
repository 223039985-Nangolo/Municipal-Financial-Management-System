#include <stdio.h>
#include <string.h>
#include "assets.h"

Asset assets[MAX_ASSETS];
int assetCount = 0;

void handleAssetMenu() {
    int opt;
    while (1) {
        printf("\n--- ASSET MANAGEMENT ---\n");
        printf("1. Register Asset\n");
        printf("2. Display All Assets\n");
        printf("3. Search Asset\n");
        printf("4. Back to Main Menu\n");
        printf("Choice: ");

        if (scanf("%d", &opt) != 1) {
            printf("Enter a number!\n");
            while(getchar() != '\n');
            continue;
        }

        switch(opt) {
            case 1: addAsset(); break;
            case 2: displayAllAssets(); break;
            case 3: searchAsset(); break;
            case 4: return;
            default: printf("Invalid option!\n");
        }
    }
}

void addAsset() {
    if (assetCount >= MAX_ASSETS) {
        printf("Asset register full!\n");
        return;
    }

    Asset a;
    printf("Asset ID: ");
    scanf("%d", &a.id);

    for (int i = 0; i < assetCount; i++) {
        if (assets[i].id == a.id) {
            printf("Asset ID already exists!\n");
            return;
        }
    }

    printf("Asset Name: ");
    while(getchar() != '\n');
    fgets(a.name, MAX_INFO, stdin);
    a.name[strcspn(a.name, "\n")] = 0;
    if (strlen(a.name) == 0) {
        printf("Name cannot be empty!\n");
        return;
    }

    printf("Asset Type (Vehicle/Computer/Building/etc): ");
    fgets(a.type, MAX_INFO, stdin);
    a.type[strcspn(a.type, "\n")] = 0;

    printf("Purchase Value: N$");
    scanf("%f", &a.purchaseValue);
    if (a.purchaseValue < 0) {
        printf("Value cannot be negative!\n");
        return;
    }

    printf("Assigned Department: ");
    while(getchar() != '\n');
    fgets(a.department, MAX_INFO, stdin);
    a.department[strcspn(a.department, "\n")] = 0;

    printf("Condition (New/Good/Fair/Poor): ");
    fgets(a.condition, MAX_INFO, stdin);
    a.condition[strcspn(a.condition, "\n")] = 0;

    assets[assetCount++] = a;
    printf("Asset registered!\n");
}

void displayAllAssets() {
    if (assetCount == 0) {
        printf("No assets registered.\n");
        return;
    }
    printf("\n%5s | %-18s | %-12s | %12s | %-15s | %-10s\n",
           "ID", "Name", "Type", "Value", "Department", "Condition");
    printf("------------------------------------------------------------------------\n");
    for (int i = 0; i < assetCount; i++) {
        printf("%5d | %-18s | %-12s | N$%10.2f | %-15s | %-10s\n",
               assets[i].id, assets[i].name, assets[i].type,
               assets[i].purchaseValue, assets[i].department, assets[i].condition);
    }
}

void searchAsset() {
    int searchId, found = 0;
    printf("Enter Asset ID to search: ");
    scanf("%d", &searchId);

    for (int i = 0; i < assetCount; i++) {
        if (assets[i].id == searchId) {
            printf("\n Asset Found:\n");
            printf("Name: %s\nType: %s\nValue: N$%.2f\nDepartment: %s\nCondition: %s\n",
                   assets[i].name, assets[i].type, assets[i].purchaseValue,
                   assets[i].department, assets[i].condition);
            found = 1;
            break;
        }
    }
    if (!found) printf("No asset with ID %d\n", searchId);
}