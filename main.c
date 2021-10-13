#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "foo.h"


int main()
{
    int Cap_p;

    // Создание массива струкутур с выделением для него памяти
    StorageDevice *lib = NULL;
//    lib = (StorageDevice*)malloc(sizeof(StorageDevice));


    // Работа с файлом
    FILE *base;
    base = fopen("base.txt", "r");
    if(base == NULL){
        printf("Файл 'base.txt' не найден\n");
        exit(9);
    }



    lib = WrTolib(base);

//    _printall(lib);

    printf("Введите объем данных, который вам требуется: ");
    scanf("%d", &Cap_p);
    printf("\n\nВам подойдут следующие накопители:\n\n");
    PrintC(Cap_p, lib);


    freelib(lib);
    return 0;
}

