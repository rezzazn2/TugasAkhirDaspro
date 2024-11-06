#include <stdio.h>
#include <string.h>
#include "display.h"

void printBorder() {
    printf("||================================================================||\n");
    printf("||                      Selamat Datang :)                         ||\n");
    printf("||                 di Perpustakaan Nirmala Delima                 ||\n");
    printf("||================================================================||\n");
}

void printSubBorder(const char* teks) {
    printf("\n\n=> %s\n", teks);
}

void printCenteredBorder(const char *text) {
    // Ukuran border
    const int borderLength = 70; // Total panjang border
    const int padding = 2; // Ruang di kiri dan kanan
    int textLength = strlen(text); // Panjang teks
    int totalPadding = (borderLength - textLength) / padding; // Total ruang yang tersedia
    int leftPadding = totalPadding ; // Padding di sebelah kiri
    int rightPadding = totalPadding  ; // Padding di sebelah kanan

    // Mencetak border atas
    printf("\n||");
    for (int i = 0; i < borderLength; i++) {
        printf("=");
    }
    printf("||\n");

    // Mencetak teks dengan padding di kiri dan kanan
    printf("||");
    for (int i = 0; i < leftPadding; i++) {
        printf(" ");
    }
    printf("%s", text);
    for (int i = 0; i < rightPadding; i++) {
        printf(" ");
    }
    printf("||\n");

    // Mencetak border bawah
    printf("||");
    for (int i = 0; i < borderLength; i++) {
        printf("=");
    }
    printf("||\n");
}









