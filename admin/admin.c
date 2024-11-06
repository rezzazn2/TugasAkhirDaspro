#include <stdio.h>
#include "../display.h"
#include "../login.h"
#include "../aksi.h"


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

    
