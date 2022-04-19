#include <stdio.h>
#include <string.h>

int pil1, pil2; 
typedef struct {
	char nama[50];
	char nim[50];
	char prodi[50];
	char tgl_lahir[3];
	char bln_lahir[3];
	char thn_lahir[5];
	char angkatan[5];
}IDUSER;

typedef struct {
	char judul[50];
	char kode_buku[20];
	char tgl_pinjam[20];
}PERPUS;

IDUSER A;
PERPUS buku;

void buat_ID (IDUSER *A) {
	FILE*buat; // Deklarasi file dengan pointer buat
	FILE*idfix; // Deklarasi file dengan pointer idfix
	buat = fopen("Data Diri.txt", "w"); // Untuk membuka file baru dan menuliskannya ke "Data Diri.txt"
	idfix = fopen("ID.txt", "w"); // Untuk membuka file baru dan menuliskannya ke "ID.txt"
	
	printf("Nama \t\t\t: "); fflush(stdin); gets(A->nama);
	printf("NIM \t\t\t: "); gets(A->nim); fflush(stdin);
	printf("Prodi \t\t\t: "); gets(A->prodi); fflush(stdin);
	printf("Tanggal Lahir (dd)\t: "); gets(A->tgl_lahir); fflush(stdin);
	printf("Bulan Lahir (mm)\t: "); gets(A->bln_lahir); fflush(stdin);
	printf("Tahun Lahir (yyyy)\t: "); gets(A->thn_lahir); fflush(stdin);
	printf("Angkatan \t\t: "); gets(A->angkatan); fflush(stdin);
	
	printf("\nANDA SUDAH MEMBUAT ID");
	printf("\n%s%s%s\n\n", A->tgl_lahir, A->bln_lahir, A->thn_lahir);
	fprintf(idfix, "%s%s%s", A->tgl_lahir, A->bln_lahir, A->thn_lahir); 
	
	fprintf(buat, "Nama: %s\n", A->nama);
	fprintf(buat, "NIM: %s\n", A->nim);
	fprintf(buat, "Prodi: %s\n", A->prodi);
	fprintf(buat, "Tanggal Lahir: %s\n", A->tgl_lahir);
	fprintf(buat, "Bulan Lahir: %s\n", A->bln_lahir);
	fprintf(buat, "Tahun Lahir: %s\n", A->thn_lahir);
	fprintf(buat, "Angkatan: %s\n", A->angkatan);
	
	fclose(idfix); // untuk menutup file idfix
	fclose(buat); // untuk menutup file buat
}

void meminjam_buku () {
	printf("\n+-----------------------+\n|                       |\n|    PEMINJAMAN BUKU \t|\n|                       |\n+-----------------------+\n\n"); // Untuk mencetak kata di dalam tanda kutip
	printf("1. Peminjaman Buku\n");
	printf("2. Data Buku yang Dipinjam\n");
	printf("3. MENU UTAMA\n\n");
}

void pinjam_buku (PERPUS buku) {
	FILE*daftar;
	int i, b;
	daftar = fopen("Daftar Buku.txt", "w");
	printf("\n+-----------------------------------+\n|\t\t\t\t    |\n|      BUKU YANG INGIN DIPINJAM     |\n|                       \t    |\n+-----------------------------------+\n");
	printf("\nJumlah Buku yang Ingin Dipinjam: "); scanf("%d", &b);
	
	for (i=0; i<b; i++) {
		printf("\nJudul Buku: "); fflush(stdin); gets(buku.judul);
		printf("Kode Buku: "); gets(buku.kode_buku);
		printf("Tanggal Peminjaman (ddmmyyyy): "); gets(buku.tgl_pinjam);
		
		fprintf(daftar, "\nJudul Buku: %s\n", buku.judul);
		fprintf(daftar, "Kode Buku: %s\n", buku.kode_buku);
		fprintf(daftar, "Tanggal Peminjaman: %s\n", buku.tgl_pinjam);
	}
	
	fclose(daftar);
}

void data_buku () { 
	char read[50];
	FILE*daftar;
	daftar = fopen("Daftar Buku.txt", "r");
	while (fgets(read, 50, daftar)) {
		printf("%s", read);
	}
	
	fclose(daftar);
}

int main () {
	char id[15], id2[10];
	FILE*idfix;
	
	do {
		printf("\n\t\t\t\t+--------------------------------------------------+\n");
		printf("\t\t\t\t| \t\t\t\t\t\t   |\n \t\t\t\t| \t\tPROGRAM PERPUSTAKAAN\t\t   |\n \t\t\t\t| \t\t      SEDERHANA \t\t   |\n \t\t\t\t| \t\t\t\t\t\t   |\n");
		printf("\t\t\t\t+--------------------------------------------------+\n");
		printf("\n1. Buat ID Perpustakaan\n");
		printf("2. Sudah memiliki ID\n");
		printf("3. KELUAR\n");
		printf("\nPilihan Anda: ");
		scanf("%d", &pil1); 
		system("cls");
		
		switch (pil1) {
			case 1: 
				printf("+-----------------------+\n|                       |\n|      PEMBUATAN ID \t|\n|                       |\n+-----------------------+\n\n");
				buat_ID (&A);		
				printf("Mohon Konfirmasi ID Anda: "); scanf("%s", id);
				system("pause");
				system("cls");
				break;
			case 2: 
				idfix = fopen("ID.txt", "r");
				while (!feof(idfix)){
					fgets(id, sizeof(id), idfix);
				}
				fclose(idfix);
				
				printf("Masukkan ID Anda: "); scanf("%s", id2);
				system("cls");
				
				if (!(strcmp(id,id2))) {
					do {
						meminjam_buku ();
						printf("Pilihan Anda: ");
						scanf("%d", &pil2);
						
						switch (pil2) {
							case 1:
								pinjam_buku (buku);
								printf("\nAnda Berhasil Meminjam Buku\n");			
								system("pause");
								system("cls");
								break;
							case 2:
								data_buku ();
								system("pause");		
								break;
							case 3:
								system("pause");
							default:
								printf("");
						}						
					}while (pil2 != 3);
				} else {
					printf("ID YANG ANDA MASUKKAN SALAH !!!");
				}
			break;	
			case 3: 
				system("pause");
			break;
			default:
				printf("\nPILIHAN YANG ANDA MASUKKAN SALAH !!!");
		}
	}while (pil1 != 3);
		
	return 0;
}
