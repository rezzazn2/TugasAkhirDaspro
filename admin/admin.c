#include <stdio.h>
#include "../display.h"
#include "../login.h"
#include "../aksi.h"
#include "../buku/buku.h"
#include "admin.h"

   

    void showAdminMenu(){
        printSubBorder("Menu Admin");
        printf("||================================================================||\n");
        printf("|| 1. Kelola Buku                                                 ||\n");
        printf("|| 2. Kelola User                                                 ||\n");
        printf("|| 3. Logout                                                      ||\n");
        printf("||================================================================||\n");

        int pilihMenu;
        printf("\n|| pilih menu : ");
        scanf("%d", &pilihMenu);
        getchar();

        switch (pilihMenu)
        {
        case 1 :
            showAdminBuku();
            break;
        case 3 :
            printf("Anda yakin ingin Log Out?");
            if(konfirmasi()){
                checkLogin();
            }else{
                showAdminMenu();
            }
            break;
        default:
            printf(" Pilihan tidak valid, tolong isi input dengan ketentuan yang ada");
            showAdminMenu();
            break;
        }
    }

     void showAdminBuku(){
        printSubBorder("Menu Admin->buku");
        printf("||================================================================||\n");
        printf("|| 1. Lihat Buku                                                  ||\n");
        printf("|| 2. Tambah Buku                                                 ||\n");
        printf("|| 3. Hapus Buku                                                  ||\n");
        printf("|| 4. Edit Buku                                                   ||\n");
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
        case 2 : 
            printSubBorder("Menu Admin->Buku->Tambah Buku");
            printCenteredBorder("Tambah Buku");
            tambahBuku();
            break;
        case 3 :
            printSubBorder("Menu Admin->Buku->Hapus Buku");
            printCenteredBorder("Hapus Buku");
            hapusBuku();
            break;
        case 4 : 
            printSubBorder("Menu Admin->Buku->Edit Buku");
            printCenteredBorder("Edit Buku");
            showBuku2();
            editBuku();

            break;
        case 5 : 
            showAdminMenu();
            break;
        default:
            printf(" Pilihan tidak valid, tolong isi input dengan ketentuan yang ada");
            showAdminBuku();
            break;
        }
    }


    
