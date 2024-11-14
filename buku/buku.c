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
    {"Berani Tidak Disukai", "Ichiro Kishimi", 251, "Self Improvement", "Seorang Pemuda mencari keadilan dunia", 20},
    {"Atomic Habits", "James Clear", 320, "Self Improvement", "Cara mengembangkan kebiasaan kecil untuk hasil besar", 37}
};

int bukuCount = 2;

void tambahBuku(){
    
    if (bukuCount >= MAX_BUKU) {
        printf("Koleksi buku penuh!\n");
        return;
    }

    Buku bukuBaru;
    
    printf("Masukkan judul buku: ");
    fgets(bukuBaru.judul, sizeof(bukuBaru.judul), stdin);
    strtok(bukuBaru.judul, "\n"); // Menghilangkan newline di akhir string

    printf("Masukkan pengarang buku: ");
    fgets(bukuBaru.pengarang, sizeof(bukuBaru.pengarang), stdin);
    strtok(bukuBaru.pengarang, "\n");

    printf("Masukkan jumlah halaman buku: ");
    scanf("%d", &bukuBaru.jmlHalaman);
    getchar(); // Membersihkan newline

    printf("Masukkan genre buku: ");
    fgets(bukuBaru.genre, sizeof(bukuBaru.genre), stdin);
    strtok(bukuBaru.genre, "\n");

    printf("Masukkan sinopsis buku: ");
    fgets(bukuBaru.sinopsis, sizeof(bukuBaru.sinopsis), stdin);
    strtok(bukuBaru.sinopsis, "\n");

    printf("Masukkan jumlah buku: ");
    scanf("%d", &bukuBaru.jmlBuku);
    getchar();

    // Menyimpan buku baru ke dalam array buku
    buku[bukuCount++] = bukuBaru;
    
    printf("Buku berhasil ditambahkan ke koleksi!\n");
    printf("Apakah anda ingin menambah buku lagi?\n");
    if(konfirmasi()){
        tambahBuku();
    }else{
        showAdminBuku();
    }

    
            
}

void hapusBuku(){
    

    printf("masukan no Buku yang ingin Anda hapus : ");
    int index = selectMenu();

    if (index < 0 || index >= bukuCount) {
        printf("Indeks buku tidak valid!\n");
        hapusBuku();
    }
    index = index -1 ;
    for (int i = index; i < bukuCount - 1; i++) {
        buku[i] = buku[i + 1];
    }
    bukuCount--;  // Mengurangi jumlah buku setelah penghapusan
    printf("Buku pada indeks %d berhasil dihapus.\n", index + 1);
    printf("Apakah Anda ingin menghapus buku lagi? ");
    if (konfirmasi())
    {
        hapusBuku();
    }else{
        showAdminBuku();
    }
}

void editBuku(){
    printf("\nPilih no buku yang ingin Anda edit : ");
    int no = selectMenu();

    if(no < 0 || no > bukuCount){
        printf("nomor buku yang anda masukan tidak ada, mau mengulang?");
        if(konfirmasi()){
            editBuku();
        }else{
             showAdminBuku();
        }
    }
    no = no - 1;

    printf("Masukkan judul buku: ");
            fgets(buku[no].judul, sizeof(buku[no].judul), stdin);
            strtok(buku[no].judul, "\n"); // Menghilangkan newline di akhir string

            printf("Masukkan pengarang buku: ");
            fgets(buku[no].pengarang, sizeof(buku[no].pengarang), stdin);
            strtok(buku[no].pengarang, "\n");

            printf("Masukkan jumlah halaman buku: ");
            scanf("%d", &buku[no].jmlHalaman);
            getchar(); // Membersihkan newline

            printf("Masukkan genre buku: ");
            fgets(buku[no].genre, sizeof(buku[no].genre), stdin);
            strtok(buku[no].genre, "\n");

            printf("Masukkan sinopsis buku: ");
            fgets(buku[no].sinopsis, sizeof(buku[no].sinopsis), stdin);
            strtok(buku[no].sinopsis, "\n");

            printf("Masukkan jumlah buku: ");
            scanf("%d", &buku[no].jmlBuku);
            getchar();
    printf("Buku berhasil diedit!\n");
    printf("Apakah anda ingin mengedit buku lagi? \n");
    if(konfirmasi()){
        editBuku();
    }else{
        showAdminBuku();
    }
}

void sinopsisBuku(){
    printf("sinopsis dari buku nomor berapa yang ingin anda lihat? ");
        int num = selectMenu();
        printf("Sinopsis Buku : %s\n%s\n\n",buku[num - 1].judul, buku[num - 1].sinopsis);

        printf("Apa anda ingin melihat sinopsis buku lain juga? :");
        if(konfirmasi()){
            sinopsisBuku();
        }else{
            if(strcmp(currentUser.role, "admin") == 0){
            showAdminMenu();
           
            }else if (strcmp(currentUser.role, "user") == 0)
            {
            showUserMenu();
           
            }
        }
}

void showBuku(){
    printSubBorder("Menu List Buku");
    // Tampilkan header tabel
    printf("=========================================================================================================\n");
    printf("| %-3s | %-30s | %-20s | %-5s | %-17s | %-10s |\n", 
           "No", "Judul", "Penulis", "Hal.", "Genre", "Jumlah Buku");
    printf("=========================================================================================================\n");


    // Tampilkan setiap buku
    for(int i = 0; i < bukuCount; i++){
        printf("| %-3d | %-30s | %-20s | %-5d | %-17s | %-10d |\n",
               i + 1, buku[i].judul, buku[i].pengarang, buku[i].jmlHalaman, buku[i].genre,buku[i].jmlBuku);
    }

    printf("=========================================================================================================\n");


    printf("1. lihat Sinopsis \n2. Kembali\n");
    printf("pilih menu :");
    switch (selectMenu())
    {
    case 1:       
        sinopsisBuku();
       break;
    case 2:
        if(strcmp(currentUser.role, "admin") == 0){
            showAdminBuku();
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

void showBuku2(){
    printSubBorder("Menu List Buku");
    // Tampilkan header tabel
    printf("=========================================================================================================\n");
    printf("| %-3s | %-30s | %-20s | %-5s | %-17s | %-10s |\n", 
           "No", "Judul", "Penulis", "Hal.", "Genre", "Jumlah Buku");
    printf("=========================================================================================================\n");


    // Tampilkan setiap buku
    for(int i = 0; i < bukuCount; i++){
        printf("| %-3d | %-30s | %-20s | %-5d | %-17s | %-10d |\n",
               i + 1, buku[i].judul, buku[i].pengarang, buku[i].jmlHalaman, buku[i].genre,buku[i].jmlBuku);
    }

    printf("=========================================================================================================");

}