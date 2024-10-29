#include <stdio.h>
#include <string.h>
#include <stdbool.h>


// Fungsi konfirmasi
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


// Fungsi untuk menampilkan border
void printBorder() {
    printf("||================================================================||\n");
    printf("||                      Selamat Datang :)                         ||\n");
    printf("||                 di Perpustakaan Digital Mini                   ||\n");
    printf("||================================================================||\n");
}

// Fungsi untuk menampilkan sub-border
void printSubBorder(const char* teks){
    printf("\n\n=> %s\n", teks);
}

// Fungsi untuk menampilkan menu utama
void showMenu(){
    printSubBorder("Menu Utama Perpustakaan");
    printf("||================================================================||\n");
    printf("|| 1. List Buku                                                   ||\n");
    printf("|| 2. Tambah Buku                                                 ||\n");
    printf("|| 3. Edit Buku                                                   ||\n");
    printf("|| 4. Pinjam Buku                                                 ||\n");
    printf("|| 5. Kembalikan Buku                                             ||\n");
    printf("|| 6. Keluar                                                      ||\n");
    printf("||================================================================||\n");

    int pilihMenu;
    printf("\n|| pilih menu : ");
    scanf("%d", pilihMenu);

}

// Fungsi untuk mengecek login
void checkLogin(){
    // Deklarasi Variable
    char username[50], password[50];

     // input user 
    printSubBorder("Log In Perpustakaan");
    printf("|| Username : ");   
    fgets(username, sizeof(username), stdin);
    printf("|| Password : ");
    fgets(password, sizeof(password), stdin);
    username[strcspn(username, "\n")] = 0;
    password[strcspn(password, "\n")] = 0;

    // Membandingkan username dan password
    if(strcmp(username, "admin123") == 0 && strcmp(password, "admin123") == 0){
        printf("Selamat Datang, Log In anda berhasil \n");
        showMenu();
    }else{
        printf("\nLog In Gagal, coba lagi? ");
        if (konfirmasi())
        {
            checkLogin();
        }
        
    }
}



    int main(){


        printBorder();
        checkLogin();

        return 0;
    }
