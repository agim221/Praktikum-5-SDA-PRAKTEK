/* 
Program : ADT
Version : 0.1
Deskripsi Program : Merangkai suatu data dengan alokasi statis dan suatu data lain dengan alokasi dinamis
Author : M.Agim, Revandi maudiamar
Tanggal : 20/02/2023
*/

#include "list.c"

int main() {
	list L;
	
	createList(&L);
	addFirstKota("Jakarta", &L);
//	addAfterKota(0,"Yogyakarta", &L);
	addFirstKota("Bali", &L);
	addLastKota("Garut", &L);
	addFirstKota("Bandung", &L);
	addFirstKota("Cimahi",&L);
//	addLastKota("Banten", &L);
	addLastMhs("Farhan", "Garut", &L);
	addLastMhs("Namab", "Jakarta", &L);
	addLastMhs("Rafif", "Cimahi", &L);
	delFirstMhs("Jakarta",&L);
	addFirstMhs("Agim", "Bandung", &L);
	addFirstMhs("saya", "Bandung", &L);
//	addAfterMhs(kotaMhs(L, cariIndexKota("Bandung", L)), "Najib", "Bandung", &L);
	addLastMhs("Liti", "Bandung", &L);
//	delFirstKota(&L);
//	printKota(L);
//	delFirstMhs("Bandung", &L);
//	delAfterMhs(kotaMhs(L, cariIndexKota("Bandung", L)), "Bandung", &L);
//	delLastMhs("Bandung", &L);
//	delAllMhs("Bandung", &L);
//	delFirstKota(&L);
//	delFirstKota(&L);
	delAfterKota(cariIndexKota("Jakarta", L), &L);
//	delLastKota(&L);
//	delLastKota(&L);
//	delAllKota(&L);
//	printAllKotaMhs(L);
	printMhs("Bandung", L);
//	printKota(L);
	return 0;
}
