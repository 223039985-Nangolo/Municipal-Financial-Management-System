#ifndef SUPPLIERS_H
#define SUPPLIERS_H

#define MAX_SUPPLIERS 100
#define MAX_STR 50

typedef struct {
    int id;
    char name[MAX_STR];
    char email[MAX_STR];
    char phone[20];
    char location[MAX_STR];
} Supplier;

extern Supplier suppliers[MAX_SUPPLIERS];
extern int supplierCount;

void handleSupplierMenu();
void addSupplier();
void displayAllSuppliers();
void searchSupplier();

#endif