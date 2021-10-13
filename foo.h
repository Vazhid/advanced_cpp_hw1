//
// Created by Vazhid on 13.10.2021.
//

#ifndef UNTITLED1_FOO_H
#define UNTITLED1_FOO_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct StorageDevice StorageDevice;

struct StorageDevice {
    int Id;
    char type[10];
    int Cap;
    int Rewr;
    StorageDevice* Next;
};

void _printall(StorageDevice *lib);

void PrintC(int Cap, StorageDevice *lib);

StorageDevice* FromFile(char* st);

StorageDevice* WrTolib(FILE* base);

void freelib(StorageDevice *lib);

#endif //UNTITLED1_FOO_H
