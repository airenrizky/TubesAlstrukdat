/* NIM/Nama  : 18213031/Yusuf Luthfi Ramdhani
   Nama File : P06-18213031-131014-01.h
   Tanggal   : 13 Oktober 2014
   Deskripsi : deklarasi prototype mesin kata */

#ifndef mesinkata_H
#define mesinkata_H
#include "mesinkar.h"
#include <stdlib.h>
#include <string.h>

#define BLANK ' '
#define NMax 50

typedef struct {
	char TabKata[NMax+1];
	int Length;
	} Kata;

/* State Mesin Kata */
extern boolean EndKata;
extern Kata CKata;

void Ignore_Blank();
/* Mengabaikan satu atau beberapa BLANK */
/* I.S. : CC sembarang */
/* F.S. : CC != BLANK atau CC = MARK */

void STARTKATA();
/* I.S. : CC sembarang */
/* F.S. : EndKata = true, dan CC = Mark; */
/*        atau EndKata = false, CKata adalah kata yang sudah diakuisisi, */
/*        CC karakter pertama sesudah karakter terakhir kata */

void ADVKATA();
/* I.S. : EndKata = false; CC adalah karakter sesudah karakter terakhir */
/*        dari kata yg sudah diakuisisi */
/* F.S. : Jika CC = MARK, maka EndKata = true */
/*        atau EndKata = false, CKata adalah kata terakhir yang sudah diakuisisi; */
/*        CC karakter pertama sesudah karakter terakhir kata */

void SalinKata();
/* Mengakuisisi kata, menyimpan dalam CKata */
/* I.S. : CC adalah karakter pertama dari kata */
/* F.S. : CKata berisi kata yang sudah diakuisisi, jika karakternya melebihi */
/*        NMax, sisa "kata" dibuang; CC = BLANK atau CC = MARK; CC adalah */
/*        karakter sesudah karakter terakhir yang diakuisisi */\

#endif
