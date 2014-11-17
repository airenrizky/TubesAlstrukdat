/* NIM/Nama  : 18213031/Yusuf Luthfi Ramdhani
   Nama File : P08-18213031-031114-01.c
   Tanggal   : 3 November 2014
   Deskripsi : body prototype type queue dadu */

#include "queue_dadu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void CreateEmpty(Queue *Q, int Max)
/* I.S. Sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max */
/* atau : jika alokasi gagal, Q kosong dgn MaxEl = 0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
{
    (*Q).T = (infotype_dadu *) malloc ((Max+1) * sizeof(infotype_dadu));
    if ((*Q).T != NULL)
    {
        MaxEl(*Q) = Max;
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    }
    else
    {
        MaxEl(*Q) = Nil;
    }
}

void DealokasiDadu(Queue *Q)
/* Proses : mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
{
    MaxEl(*Q) = Nil;
    free((*Q).T);
}

boolean IsEmpty(Queue Q)
/* Mengirim true jika Queue kosong */
{
    return ((Head(Q) == Nil) && (Tail(Q) == Nil));
}

boolean IsFull(Queue Q)
/* Mengirim true jika tabel penampung nilai elemen queue penuh */
{
    return ((Head(Q) == 1) && (Tail(Q) == MaxEl(Q)));
}

int NBElmt(Queue Q)
/* Mengirimkan banyaknya elemen queue, mengirimkan 0 jika Q kosong */
{
    return (Tail(Q)-Head(Q)+1);
}

void Add(Queue *Q, infotype_dadu X)
/* Menambahkan X sebagai elemen Queue Q */
/* I.S. Q mungkin kosong, tabel penampung elemen Q tidak penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" */
{
    if (IsEmpty(*Q))
    {
        Head(*Q) = 1;
    }
    Tail(*Q)++;
    InfoTail(*Q) = X;
}

void Del(Queue *Q, infotype_dadu *X)
/* Menghapus elemen pertama pada Q */
/* I.S. Q tidak kosong */
/* F.S. X = nilai elemen HEAD pada I.S., */
/*      JIka Queue masih isim HEAD diset tetap = 1, elemen-elemen setelah HEAD YANG */
/*      lama digeser ke "kiri", TAIL = TAIL - 1 */
/*      Jika Queue menjadi kosog, HEAD = TAIL = Nil */
{
    int i;
    *X = InfoHead(*Q);
    if (Head(*Q) == Tail(*Q))
    {
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    }
    else
    {
        for (i = 1; i < Tail(*Q); i++)
        {
            *((*Q).T+i) = *((*Q).T+i+1);
        }
        Tail(*Q) = Tail(*Q) - 1;
    }
}

boolean IsGame(Queue Q)
/* mengembalikan true apabila kondisi permainan berakhir terpenuhi, yaitu */
/* salah satu pemain mendapatkan skor sebesar 3 atau */
/* hanya tinggal satu pemain yang bermain */
{
	if ((NBElmt(Q) == 1) || (InfoTailSkor(Q) == 3))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void CreateQueuePemain(Queue *Q, int Maks)
/* I.S : Queue kosong dengan alokasi Min 2 dan Maks 4 */
/* F.S : Menghasilkan Q yang berisi informasi seluruh pemain berupa nama dengan skor awal = 0 */
{
	int i;
	Pemain P;
	CreateEmpty(&(*Q),Maks);
	for (i = 1; i <= MaxEl(*Q); i++)
	{
		printf("Nama Pemain %d :  ", i);
		scanf("%s", &P.Nama);
		P.Skor = 0;
		Add(&(*Q),P);
	}
}

void ChangeTurn(Queue *Q)
/* I.S : Queue berisi minimal 2 elemen */
/* F.S : Head(Q) diganti menjadi pemain yang berada di antrian selanjutnya */
/*       Sedangkan untuk Head(Q) di awal dipindah ke antrian paling belakang / Tail(Q) */
{
	Pemain P;
	Del(&(*Q),&P);
	Add(&(*Q),P);
}

void PrintSkor(Queue *Q)
/* I.S : Queue tidak kosong */
/* F.S : Menampilkan seluruh skor pemain sesuai dengan format yang telah ditentukan */
{
	int i;
	for (i = Head(*Q); i <= Tail(*Q); i++)
	{
		printf("%s : %d", InfoHeadNama(*Q), InfoHeadSkor(*Q));
		printf("  ");
		ChangeTurn(&(*Q));
	}
	printf("\n");
}
