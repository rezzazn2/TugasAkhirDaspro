#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "buku.h"
#include "../aksi.h"
#include "../display.h"
#include "../login.h"
#include "../admin/admin.h"
#include "../user/user.h"

// Daftar pengguna
Buku buku[MAX_BUKU] = {
    {"Berani Tidak Disukai", "Ichiro Kishimi", 251, "Self Improvement", "Seorang Pemuda mencari keadilan dunia"},
    {"Atomic Habits", "James Clear", 320, "Self Improvement", "Cara mengembangkan kebiasaan kecil untuk hasil besar"}
};

int bukuCount = 2;



void showBuku(){
    printSubBorder("Menu List Buku");
    // Tampilkan header tabel
    printf("===============================================================================\n");
    printf("| %-3s | %-30s | %-20s | %-5s | %-15s |\n", 
           "No", "Judul", "Penulis", "Hal.", "Genre");
    printf("===============================================================================\n");

    // Tampilkan setiap buku
    for(int i = 0; i < bukuCount; i++){
        printf("| %-3d | %-30s | %-20s | %-5d | %-15s |\n",
               i + 1, buku[i].nama, buku[i].pengarang, buku[i].jmlHalaman, buku[i].genre);
    }

    printf("===============================================================================\n");

    printf("1. lihat Sinopsis \n2. Kembali\n");
    printf("pilih menu :");
    switch (selectMenu())
    {
    case 1:
        printf("sinopsis dari buku nomor berapa yang ingin anda lihat? ");
        int num = selectMenu();
        printf("Sinopsis Buku : %s\n%s\n\n",buku[num - 1].nama, buku[num - 1].sinopsis);

        printf("Apa anda ingin melihat sinopsis buku lain juga? :");
        if(konfirmasi()){
            
        }else{
            break;
        }
        
       
    case 2:
        if(strcmp(currentUser.role, "admin") == 0){
            showAdminMenu();
            break;
        }else if (strcmp(currentUser.role, "user") == 0)
        {
            showUserMenu();
            break;
        }
       
    default:
        printf(" Pilihan tidak valid, tolong isi input dengan ketentuan yang ada");
        showBuku();
        break;
    }
    
}