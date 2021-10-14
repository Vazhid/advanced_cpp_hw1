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

void print_out(int Cap, StorageDevice *lib);

StorageDevice* from_file(char* st);

StorageDevice* to_lib(FILE* base);

void free_lib(StorageDevice *lib);

#endif //UNTITLED1_FOO_H
