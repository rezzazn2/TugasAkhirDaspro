#ifndef LOGIN_H
#define LOGIN_H

#include <stdbool.h>

#define MAX_USERS 100

// Struktur untuk menyimpan data pengguna
typedef struct {
    char username[50];
    char password[50];
    char role[10];
} User;

// Struktur untuk menyimpan data pengguna yang login
typedef struct {
    char username[50];
    char role[10];
} LoggedInUser;

// Deklarasi array pengguna
extern User users[MAX_USERS];
extern int userCount;

// Variabel global untuk menyimpan informasi pengguna yang sedang login
extern LoggedInUser currentUser;

// Deklarasi fungsi
bool konfirmasi();
void checkLogin();

#endif 
