/* 
Program : ADT
Version : 0.1
Deskripsi Program : Merangkai suatu data dengan alokasi statis dan suatu data lain dengan alokasi dinamis
Author : M.Agim, Revandi maudiamar
Tanggal : 20/02/2023
*/

#include <stdio.h>
#include <malloc.h>
#define first(L) (L).first 
#define  nextB(L, I) (L).data[I].next
#define kota(L, I) (L).data[I].kota
#define nextK(L) (L).next
#define kotaMhs(L, I) (L).data[I].mhs
#define nama(L) (L).nama

typedef char* String;
typedef struct elmt *alamtelemt;
typedef struct elmt {
	String nama;
	alamtelemt next;
} Mhs;

typedef struct {
	String kota;
	int next;
	Mhs *mhs;
} Kota;

typedef struct {
	int first;
	Kota data[10];
} list;

//Kondisi awal
void createList(list *L);

//Menhitung element
int countElementKota(list L);
int countElementMhs(char *kota, list *L);

//Mengecek element
int emptyElement(list L);

//Menambahkan Kota
void addFirstKota(char *kota, list *L);
void addAfterKota(int prev, char *kota, list *L);
void addLastKota(char *kota, list *L);

//Menghapus Kota
void delFirstKota(list *L);
void delAfterKota(int prev, list *L);
void delLastKota(list *L);
void delAllKota(list *L);

//Menampilkan Kota
void printKota(list L);

//Mencari Index Kota
int cariIndexKota(char *k,list L);

//Menambahkan Mahasiswa
void addFirstMhs(char *mhs, char *kota, list *L);
void addAfterMhs(Mhs *prev, char *nama, char *kota, list *L);
void addLastMhs(char *nama, char *kota, list *L);

//Menghapus Mahasiswa
void delFirstMhs(char *kota, list *L);
void delAfterMhs(Mhs *prev, char *kota, list *L);
void delLastMhs(char *kota, list *L);
void delAllMhs(char *kota, list *L);

//Menampilkan Mahasiswa
void printMhs(char *kota, list L);

//Menampilkan kota dan mahasiswanya
void printAllKotaMhs(list L);
