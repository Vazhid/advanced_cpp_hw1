#include "foo.h"

int main()
{
    int Cap_p;

    StorageDevice *lib = NULL;

    FILE *base;
    base = fopen("base.txt", "r");
    if(base == NULL){
        printf("Файл 'base.txt' не найден\n");
    }

    lib = to_lib(base);

    printf("Введите объем данных, который вам требуется: ");
    scanf("%d", &Cap_p);
    printf("\n\nВам подойдут следующие накопители:\n\n");
    print_out(Cap_p, lib);

    free_lib(lib);
    return 0;
}

