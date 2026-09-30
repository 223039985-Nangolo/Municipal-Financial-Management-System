#ifndef ASSETS_H
#define ASSETS_H

#define MAX_ASSETS 100
#define MAX_INFO 50

typedef struct {
    int id;
    char name[MAX_INFO];
    char type[MAX_INFO];
    float purchaseValue;
    char department[MAX_INFO];
    char condition[MAX_INFO];
} Asset;

extern Asset assets[MAX_ASSETS];
extern int assetCount;

void handleAssetMenu();
void addAsset();
void displayAllAssets();
void searchAsset();

#endif