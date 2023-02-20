/* 
Program : ADT
Version : 0.1
Deskripsi Program : Merangkai suatu data dengan alokasi statis dan suatu data lain dengan alokasi dinamis
Author : M.Agim, Revandi maudiamar
Tanggal : 20/02/2023
*/

#include "list.h"

void createList(list *L) {
	int i;
	
	first(*L) = -1;
	for(i = 0; i < 10;i++) {
		nextB(*L, i) = -2;
	}
}

int countElementKota(list L) {
	int hasil = 0;
	if(first(L) != 1) {
		int bantu = first(L);
		
		while(bantu != -1) {
			hasil++;
			bantu = nextB(L, bantu);
		}
	}
	
	return hasil;
}

int countElementMhs(char *kota, list *L) {
	int index = cariIndexKota(kota, *L);
	int hasil = 0;
	Mhs *bantu;
	bantu = kotaMhs(*L, index);
	
	while(bantu != NULL) {
		bantu = nextK(*bantu);
		hasil++;
	}
	
	return hasil;
}

int emptyElement(list L) {
	int hasil = -1;
	
	if(countElementKota(L) < 10) {
		int ketemu = 0;
		int i = 0;
		while((ketemu == 0) && (i <= 10)) {
			if(nextB(L, i) == -2) {
			hasil = i;
			ketemu = 1;
			} else {
				i = i + 1;
			}
		}
	return hasil;
	}
}

void addFirstKota(char *kota ,list *L) {
	int baru = emptyElement(*L);
	
	kota(*L, baru) = kota;
	
	if(countElementKota(*L) < 10) {
		if(first(*L) == -1) {
			nextB(*L, baru) = -1;
		} else {
			nextB(*L, baru) = first(*L);
		}
		first(*L) = baru;
		kotaMhs(*L, baru) = NULL;
	} else {
		printf("\nData Kota Sudah Penuh");
	}
}

void addAfterKota(int prev, char *kota, list *L) {
	if(countElementKota(*L) < 10) {
		int baru = emptyElement(*L);
		kota(*L, baru) = kota;
		
		if(nextB(*L, prev) == -1) {
			nextB(*L, baru) = -1;
		} else {
			nextB(*L, baru) = nextB(*L, prev);
		}
		nextB(*L, prev) = baru;
	} else {
		printf("Data Sudah Penuh");
	}
}

void addLastKota(char *kota, list *L) {
	if(countElementKota(*L) < 10) {
		if(first(*L) == -1) {
			addFirstKota(kota, L);
		} else {
			int last = first(*L);
			while(nextB(*L, last)!= -1) {
				last = nextB(*L, last);
			}
		addAfterKota(last, kota, L);
		}
	} else {
	printf("Data Sudah Penuh");
	}
}

void delFirstKota(list *L) {
	if(countElementKota(*L) != 0) {
		int hapus = first(*L);
		if(countElementKota(*L) == 1) {
			first(*L) = -1;
		} else {
			first(*L) = nextB(*L, hapus);
		}
		delAllMhs(kota(*L, hapus), L);
		nextB(*L, hapus) = -2;
	} else {
		printf("Data Kosong\n");
	}
}

void delAfterKota(int prev, list *L) {
	if(nextB(*L, prev) != -1) {
		int hapus = nextB(*L, prev);
		
		if(countElementKota(*L) == 1) {
			nextB(*L, prev) = -1; 
		} else {
			nextB(*L, prev) = nextB(*L, hapus);
		}
		delAllMhs(kota(*L, hapus), L);
		nextB(*L, hapus) = -2;
	}
}

void delLastKota(list *L) {
	if(first(*L) != -1) {
		int last, beforeLast;
		last = first(*L);
		
		if(countElementKota(*L) == 1) {
			delFirstKota(L);
		} else {
			while(nextB(*L, last) != -1) {
				beforeLast = last;
				last = nextB(*L, last);
			}
			delAfterKota(beforeLast, L);
		}
	} else {
		
	}
}

void delAllKota(list *L) {
	if(first(*L) != -1) {
		int i, batas;
		batas = countElementKota(*L);
		for(i = 0; i < batas;i++) {
			delLastKota(L);
		}
	} else {
		
	}
}

void addFirstMhs(char *mhs, char *kota, list *L) {
	int index = cariIndexKota(kota, *L);
	Mhs *baru;
	baru = (Mhs *) malloc(sizeof(Mhs));
	nama(*baru) = mhs;
	if(baru != NULL) {
		if(kotaMhs(*L, index)== NULL) {
			baru->next = NULL;
		} else {
			baru->next = kotaMhs(*L, index);
		}
		kotaMhs(*L, index) = baru;
		baru = NULL;
	} else {
		printf("\nMemori Sudah Penuh");
	}	
}

void addAfterMhs(Mhs *prev, char *nama, char *kota, list *L) {
	int index = cariIndexKota(kota, *L);
	Mhs *baru;
	baru = (Mhs *) malloc(sizeof(Mhs));
	nama(*baru) = nama;
	if(nextK(*prev) == NULL) {
		nextK(*baru) = NULL;
	} else {
		nextK(*baru) = nextK(*prev);
	}
	nextK(*prev) = baru;
}

void addLastMhs(char *nama, char *kota, list *L) {
	int index = cariIndexKota(kota, *L);
	if(kotaMhs(*L, index) == NULL) {
		addFirstMhs(nama, kota, L);
	} else {
		Mhs *last;
		last = kotaMhs(*L, index);
		while(nextK(*last) != NULL) {
			last = nextK(*last);
		}
		addAfterMhs(last, nama, kota, L);
	}
}

void delFirstMhs(char *kota, list *L) {
	int index = cariIndexKota(kota, *L);
	if(kotaMhs(*L, index) != NULL) {
		Mhs *hapus;
		hapus = kotaMhs(*L, index);
		if(nextK(*hapus) == NULL) {
			kotaMhs(*L, index) = NULL;
		} else {
			kotaMhs(*L, index) = nextK(*hapus);
		}
		nextK(*hapus) = NULL;
		free(hapus);
	} else {
		printf("Data Kosong\n");
	}
}

void delAfterMhs(Mhs *prev, char *kota, list *L) {
	int index = cariIndexKota(kota, *L);
	if(kotaMhs(*L, index) != NULL) {
		Mhs *bantu;
		bantu = nextK(*prev);
		if(nextK(*bantu) == NULL) {
			nextK(*prev) = NULL;
		} else {
			nextK(*prev) = nextK(*bantu);
		}
		nextK(*bantu) = NULL;
		free(bantu);
	} 
}

void delLastMhs(char *kota, list *L) {
	int index = cariIndexKota(kota, *L);
	if(kotaMhs(*L, index) != NULL) {
		Mhs *last, *beforeLast;
		last = kotaMhs(*L, index);
		beforeLast = NULL;
		
		if(nextK(*last) == NULL) {
			delFirstMhs(kota, L);
		} else {
			while(nextK(*last) != NULL) {
				beforeLast = last;
				last = nextK(*last);
			}
			delAfterMhs(beforeLast, kota, L);
		}
	} else {
		printf("");
	}
}

void delAllMhs(char *kota, list *L) {
	if(countElementMhs(kota, L)) {
		int i = 0;
		int batas = countElementMhs(kota, L);
		while(i < batas) {
			delLastMhs(kota, L);
			i++;
		}
	} else {
//		printf("Data Kosong\n");
	}
}

void printMhs(char *kota, list L) {
	int index = cariIndexKota(kota, L);
	Mhs *bantu;
	bantu = kotaMhs(L, index);
	while(bantu != NULL) {
		printf("%s ", nama(*bantu));
		bantu = nextK(*bantu);
	}
}

int cariIndexKota(char *k, list L) {
	int index = 0;
	while(index < 10) {
		if(!(strcmp(kota(L, index), k))) {
			return index;
		} else {
			index++;
		}
	}	
}

void printKota(list L) {
	if(countElementKota(L) != 0) {
		int bantu = first(L);
		
		while(bantu != -1) {
			printf(" %s", kota(L, bantu));
			bantu = nextB(L, bantu);
		}
	} else {
//		printf("\nData Kosong");
	}
}

void printAllKotaMhs(list L) {
	if(first(L) != -1) {
		int indexKota = first(L);
		Mhs *bantu;
		int i = 0;
		
		while(indexKota != -1) {
			printf("\n%s : ", kota(L, indexKota));
			bantu = kotaMhs(L, indexKota);
			while(i < 3) {
				printf("%s ", nama(*bantu));
				bantu = nextK(*bantu);
			}
			indexKota = nextB(L, indexKota);
		}
		
	} else {
		
	}
}
