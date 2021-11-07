#ifndef foo_h
#define foo_h

#define MAX_SIZE_STRING 25

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct StorageDevice storage_device;

struct StorageDevice {
    int number;
    char type[10];
    int capacity;
    int rewrite;
    storage_device* Next;
};

void print_out(int Cap, storage_device *lib);

storage_device* from_file(char* st);

storage_device* to_lib(FILE* base);

void free_lib(storage_device *lib);

#endif /* foo_h */
