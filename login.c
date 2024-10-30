#include <stdio.h>
#include <string.h>
#include "login.h"
#include "display.h"
#include "aksi.h"

// Daftar pengguna
User users[MAX_USERS] = {
    {"admin123", "adminpass", "admin"}, // Data admin
    {"user123", "userpass", "user"},    // Data user
};

int userCount = 2; // Jumlah pengguna yang ada

// Variabel global untuk menyimpan pengguna yang login
LoggedInUser currentUser;

void checkLogin() {
    char username[50], password[50];

    printSubBorder("Log In Perpustakaan");
    printf("|| Username : ");
    fgets(username, sizeof(username), stdin);
    printf("|| Password : ");
    fgets(password, sizeof(password), stdin);
    username[strcspn(username, "\n")] = 0;
    password[strcspn(password, "\n")] = 0;

    // Memeriksa kredensial
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            // Simpan informasi pengguna yang berhasil login
            strcpy(currentUser.username, users[i].username);
            strcpy(currentUser.role, users[i].role);

            char curUserName[100];
            sprintf(curUserName, "Selamat Datang %s", currentUser.username);

            // Tampilkan pesan berdasarkan peran
            if (strcmp(currentUser.role, "admin") == 0) {
                printCenteredBorder(curUserName);
                showAdminMenu();
                
            } else if (strcmp(currentUser.role, "user") == 0) {
                printCenteredBorder(curUserName);
                
            }
            return; // Keluar 
        }
    }

    // Jika login gagal
    printf("\nLog In Gagal, coba lagi? ");
    if (konfirmasi()) {
        checkLogin(); // Panggil kembali untuk mencoba login lagi
    }
}
