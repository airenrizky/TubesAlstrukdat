#include "list_linear.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* PROTOTYPE */
/* ***************** TEST LIST KOSONG ***************** */
boolean IsListEmpty (List L)
/* Mengirim true jika list kosong */
{
    /* Kamus Lokal */

    /* Algoritma */
    return (First(L)==Nil);
}

/* ***************** TEST JUMLAH PEMAIN ***************** */
boolean IsPemainCukup (List L)
/* Mengirim true jika pemain cukup */
{
    /* Kamus Lokal */
    int count;
    address P;
    /* Algoritma */
    count = 0;
    P = First(L);
    while (P != Nil) {
        count++;
        P = Next(P);
    }
    return(count > 1);
}

/* ***************** PEMBUATAN LIST KOSONG ***************** */
void CreateList (List *L)
/* I.S. sembarang */
/* F.S. Terbentuk list kosong */
{
    /* Kamus Lokal */

    /* Algoritma */
    (First(*L)= Nil);

}

/* ***************** Manajemen Memori ***************** */
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak Nil, dan misalnya menghasilkan P, maka
Info(P) = X, Next(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    /* Kamus Lokal */
    address P;
    /* Algoritma */
    P = (address) malloc (sizeof(ElmtList));
    if (P == Nil) {
        return Nil;
    } else {
        Info(P) = X;
        Next(P) = Nil;
        return P;
    }
}
void Dealokasi (address *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
    /* Kamus Lokal */

    /* Algoritma */
    free(*P);
}

/* ***************** PENCARIAN SEBUAH ELEMEN LIST ***************** */
address Search (List L, char X[50])
/* Mencari apakah ada elemen list dengan Info(P) = X */
/* Jika ada, mengirimkan address elemen tersebut */
/* Jika tidak ada, mengirimkan Nil */
{
    /* Kamus Lokal */
    address P;
    /* Algoritma */
    if (IsListEmpty(L))
    {
        return Nil;
    }
    else
    {
        P = First(L);
        while ((P != Nil) && (strcmp(InfoNama(P),X))) {
               P = Next(P);
        }
        return P;
    }
}

/* ***************** PRIMITIF BERDASARKAN ALAMAT ***************** */
/* *** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT *** */
void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi */
{
    /* Kamus Lokal */

    /* Algoritma */
    Next(P) = First(*L);
    First(*L) = P;

}
void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/* P sudah dialokasi */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    /* Kamus Lokal */

    /* Algoritma */
    Next(P) = Next(Prec);
    Next(Prec) = P;

}
void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
    /* Kamus Lokal */
    address Last;
    /* Algoritma */
    if (IsListEmpty(*L)) // insert sebagai elemen pertama
    {
        InsertFirst(&(*L), P);
    }
    else
    /* Traversal list sampai address terakhir */
    /* Bagaimana menghindari traversal list untuk mencapai Last?*/
    {
        Last = First(*L);
        while (Next(Last)!= Nil)
        {
            Last = Next(Last);
        }
        /* Next(Last) = Nil, Last adalah elemen terakhir */
        /* Insert P after Last */
        InsertAfter(&(*L),P,Last);
    }

}

/* ***************** PROSES SEMUA ELEMEN LIST ***************** */
void PrintInfo (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, */
/* Semua info yg disimpan pada elemen list diprint */
/* Jika list kosong, hanya menuliskan "list kosong" */
{
    /* Kamus Lokal */
    address P;
    P = First(L);
    /* Algoritma */
    if (IsListEmpty(L))
    {
        printf ("\n List Kosong");
    }
    else
    {
        while (P!= Nil)
        {
            printf("%s \n", InfoNama(P));
            P = Next (P);
        }
    }
}
