#include <stdio.h>
#include "../display.h"
#include "../login.h"
#include "../aksi.h"
#include "../buku/buku.h"

void showUserMenu(){
    printSubBorder("Menu User");
    printf("||================================================================||\n");
    printf("|| 1. List Buku                                                   ||\n");
    printf("|| 2. Pinjam Buku                                                 ||\n");
    printf("|| 3. Kembalikan Buku                                             ||\n");
    printf("|| 4. History Peminjaman                                          ||\n");
    printf("|| 5. Keluar                                                      ||\n");
    printf("||================================================================||\n");

    int pilihMenu;
    printf("\n|| pilih menu : ");
    scanf("%d", &pilihMenu);
    getchar();
    switch (pilihMenu)
    {
    case 1 :
        showBuku();
        break;
    case 5 :
        printf("Anda yakin ingin Log Out?");
        if(konfirmasi()){
            checkLogin();
        }else{
            showUserMenu();
        }
        break;
    
    default:
        printf(" Pilihan tidak valid, tolong isi input dengan ketentuan yang ada");
        showUserMenu();
        break;
    }
}