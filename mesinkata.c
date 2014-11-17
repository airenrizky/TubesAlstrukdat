/* NIM/Nama  : 18213031/Yusuf Luthfi Ramdhani
   Nama File : P06-18213031-131014-01.c
   Tanggal   : 13 Oktober 2014
   Deskripsi : body prototype mesin kata */

#include <stdio.h>
#include "mesinkata.h"
#include "mesinkar.h"

boolean EndKata;
Kata CKata;

void Ignore_Blank()
/* Mengabaikan satu atau beberapa BLANK */
/* I.S. : CC sembarang */
/* F.S. : CC != BLANK atau CC = MARK */
{
	while ((CC == BLANK) && (CC != MARK))
	{
		ADV();
	}
}

void STARTKATA(char namafile[50])
/* I.S. : CC sembarang */
/* F.S. : EndKata = true, dan CC = Mark; */
/*        atau EndKata = false, CKata adalah kata yang sudah diakuisisi, */
/*        CC karakter pertama sesudah karakter terakhir kata */
{
	START(namafile);
	Ignore_Blank();
	if (CC == MARK)
	{
		EndKata = true;
	}
	else
	{
		EndKata = false;
		SalinKata();
	}
}

void ADVKATA()
/* I.S. : EndKata = false; CC adalah karakter sesudah karakter terakhir */
/*        dari kata yg sudah diakuisisi */
/* F.S. : Jika CC = MARK, maka EndKata = true */
/*        atau EndKata = false, CKata adalah kata terakhir yang sudah diakuisisi; */
/*        CC karakter pertama sesudah karakter terakhir kata */
{
	Ignore_Blank();
	if (CC == MARK)
	{
		EndKata = true;
	}
	else
	{
		SalinKata();
	}
}

void SalinKata()
/* Mengakuisisi kata, menyimpan dalam CKata */
/* I.S. : CC adalah karakter pertama dari kata */
/* F.S. : CKata berisi kata yang sudah diakuisisi, jika karakternya melebihi */
/*        NMax, sisa "kata" dibuang; CC = BLANK atau CC = MARK; CC adalah */
/*        karakter sesudah karakter terakhir yang diakuisisi */
{
	int i;
	i = 0;
	for (;;)
	{
		CKata.TabKata[i] = CC;
		ADV();
		if ((CC == MARK) || (CC == BLANK))
		{
			break;
		}
		else
		{
			i++;
		}
	}
	CKata.Length = i+1;
}
