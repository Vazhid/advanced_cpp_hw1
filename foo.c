#include "foo.h"

void print_out(int cap, storage_device *lib)
{
    if(lib != NULL)
    {
        print_out(cap, lib->Next);
        if (cap <= lib->capacity){
            printf("Инвентарный номер накопителя: %d\n", lib->number);
            printf("Максимальный объём..........: %d Гб\n", lib->capacity);
            printf("Тип накопителя..............: %s\n", lib->type);
            printf("Функция перезаписи..........: ");
            if (lib->rewrite == 1)
            {
                printf("Есть\n");
            }
            else printf("Нет\n");

            printf("-----------------------------\n");

        }
    }
}

storage_device* to_lib(FILE* base)
{
    storage_device* lib = NULL;

    char st[MAX_SIZE_STRING] = {0};
    fgets(st, MAX_SIZE_STRING, base);

    while(!feof(base))
    {
        storage_device* elem = from_file(st);
        if(lib != NULL && elem != NULL){
            elem->Next = lib;
            lib = elem;
        } else if (elem != NULL){
            lib = elem;
        }
        fgets(st, MAX_SIZE_STRING, base);
    }
    return lib;
}

storage_device* from_file(char* st)
{
    if(st[0] == '\n'){
        return NULL;
    }

    char st_number[10] = {0}, st_type[10] = {0}, st_cap[5] = {0}, st_rewrite[2] = {0};
    storage_device* File = malloc(sizeof(struct StorageDevice));
    if(File == NULL){
        printf("Malloc error > return NULL\n");
        return NULL;
    }


    strncpy(st_number, &st[0], 7);
    strncpy(st_type, &st[8], 5);
    strncpy(st_cap, &st[14], 4);
    strncpy(st_rewrite, &st[19], 1);


    File->number = atoi(st_number);
    File->capacity = atoi(st_cap);
    File->rewrite = atoi(st_rewrite);
    strncpy(File->type, &st_type[0], 10);
    File->Next = NULL;

    return File;
}

void free_lib(storage_device* lib)
{
    if(lib != NULL)
    {
        free_lib(lib->Next);
        free(lib);
    }
}
