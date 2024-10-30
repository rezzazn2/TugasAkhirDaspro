# Nama output
TARGET = Perpustakaan

# Daftar file sumber
SRC = main.c display.c login.c aksi.c

# Compiler dan opsi kompilasi
CC = gcc
CFLAGS = -o $(TARGET)

# Aturan kompilasi
all: $(SRC)
	$(CC) $(SRC) $(CFLAGS)

# Aturan untuk membersihkan file output
clean:
	rm -f $(TARGET)
