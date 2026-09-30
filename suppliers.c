#include <stdio.h>
#include <string.h>
#include "suppliers.h"

Supplier suppliers[MAX_SUPPLIERS];
int supplierCount = 0;

void handleSupplierMenu() {
    int opt;
    while (1) {
        printf("\n--- SUPPLIER MANAGEMENT ---\n");
        printf("1. Add Supplier\n");
        printf("2. Display All Suppliers\n");
        printf("3. Search Supplier\n");
        printf("4. Back to Main Menu\n");
        printf("Choice: ");

        if (scanf("%d", &opt) != 1) {
            printf("Enter a number!\n");
            while(getchar() != '\n');
            continue;
        }

        switch(opt) {
            case 1: addSupplier(); break;
            case 2: displayAllSuppliers(); break;
            case 3: searchSupplier(); break;
            case 4: return;
            default: printf("Invalid option!\n");
        }
    }
}

void addSupplier() {
    if (supplierCount >= MAX_SUPPLIERS) {
        printf("Supplier list full!\n");
        return;
    }

    Supplier s;
    printf("Enter Supplier ID: ");
    scanf("%d", &s.id);

    for (int i = 0; i < supplierCount; i++) {
        if (suppliers[i].id == s.id) {
            printf("ID already exists!\n");
            return;
        }
    }

    printf("Supplier Name: ");
    while(getchar() != '\n');
    fgets(s.name, MAX_STR, stdin);
    s.name[strcspn(s.name, "\n")] = 0;
    if (strlen(s.name) == 0) {
        printf("Name cannot be empty!\n");
        return;
    }

    printf("Email: ");
    fgets(s.email, MAX_STR, stdin);
    s.email[strcspn(s.email, "\n")] = 0;

    printf("Phone Number: ");
    fgets(s.phone, 20, stdin);
    s.phone[strcspn(s.phone, "\n")] = 0;

    printf("Town/Location: ");
    fgets(s.location, MAX_STR, stdin);
    s.location[strcspn(s.location, "\n")] = 0;

    suppliers[supplierCount++] = s;
    printf("Supplier added successfully!\n");
}

void displayAllSuppliers() {
    if (supplierCount == 0) {
        printf("No suppliers registered.\n");
        return;
    }
    printf("\n%5s | %-20s | %-25s | %-15s | %-15s\n",
           "ID", "Name", "Email", "Phone", "Location");
    printf("---------------------------------------------------------------\n");
    for (int i = 0; i < supplierCount; i++) {
        printf("%5d | %-20s | %-25s | %-15s | %-15s\n",
               suppliers[i].id, suppliers[i].name,
               suppliers[i].email, suppliers[i].phone, suppliers[i].location);
    }
}

void searchSupplier() {
    int searchId, found = 0;
    printf("Enter Supplier ID to search: ");
    scanf("%d", &searchId);

    for (int i = 0; i < supplierCount; i++) {
        if (suppliers[i].id == searchId) {
            printf("\n Supplier Found:\n");
            printf("Name: %s\nEmail: %s\nPhone: %s\nLocation: %s\n",
                   suppliers[i].name, suppliers[i].email,
                   suppliers[i].phone, suppliers[i].location);
            found = 1;
            break;
        }
    }
    if (!found) printf("No supplier with ID %d\n", searchId);
}