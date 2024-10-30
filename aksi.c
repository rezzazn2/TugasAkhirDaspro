#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "aksi.h"

bool konfirmasi() {
    char konfir;
    printf("(y/t) : ");
    scanf("%c", &konfir);
    getchar();
    switch (konfir) {
        case 'y':
            return true;
        case 't':
            return false;
        default:
            printf("Pilihan tidak valid. Silakan masukkan y atau t.\n");
            return konfirmasi();
    }
}