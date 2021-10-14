#include "foo.h"

void print_out(int Cap, StorageDevice *lib)
{
    if(lib != NULL)
    {
        print_out(Cap, lib->Next);
        if (Cap <= lib->Cap){
            printf("Инвентарный номер накопителя: %d\n", lib->Id);
            printf("Максимальный объём..........: %d Гб\n", lib->Cap);
            printf("Тип накопителя..............: %s\n", lib->type);
            printf("Функция перезаписи..........: ");
            if (lib->Rewr == 1){
                printf("Есть\n");
            } else {
                printf("Нет\n");
            }
            printf("-----------------------------\n");

        }
    }
}

StorageDevice* to_lib(FILE* base)
{
    StorageDevice* lib = NULL;

    char st[25] = {0};
    fgets(st, 25, base);

    while(!feof(base))
    {
        StorageDevice* elem = from_file(st);
        if(lib != NULL && elem != NULL){
            elem->Next = lib;
            lib = elem;
        } else if (elem != NULL){
            lib = elem;
        }
        fgets(st, 25, base);
    }
    return lib;
}

StorageDevice* from_file(char* st)
{
    if(st[0] == '\n'){
        return NULL;
    }

    char stId[10] = {0}, stType[10] = {0}, stCap[5] = {0}, stR[2] = {0};
    StorageDevice* File = malloc(sizeof(struct StorageDevice));
    if(File == NULL){
        printf("Malloc error > return NULL\n");
        return NULL;
    }


    strncpy(stId, &st[0], 7);
    strncpy(stType, &st[8], 5);
    strncpy(stCap, &st[14], 4);
    strncpy(stR, &st[19], 1);


    File->Id = atoi(stId);
    File->Cap = atoi(stCap);
    File->Rewr = atoi(stR);
    strncpy(File->type, &stType[0], 10);
    File->Next = NULL;

    return File;
}

void free_lib(StorageDevice* lib)
{
    if(lib != NULL)
    {
        free_lib(lib->Next);
        free(lib);
    }
}
