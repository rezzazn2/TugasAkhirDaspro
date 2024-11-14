#ifndef BUKU_H
#define BUKU_H

#define MAX_BUKU 200

        typedef struct {
            char judul[50];
            char pengarang[50];
            int jmlHalaman;
            char genre[50];
            char sinopsis[1000];
            int jmlBuku;
        } Buku;

// Deklarasi Array buku
    extern Buku buku[MAX_BUKU];
    extern int bukuCount;

    void showBuku();
    void showBuku2();
    void tambahBuku();
    void hapusBuku();
    void editBuku();

#endif