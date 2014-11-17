#include "boolean.h"
#include <stdlib.h>
#include <string.h>

/* ***************** MODUL LIST BERKAIT ***************** */
/* List direpresentasi dengan pointer, First dinyatakan secara eksplisit. */
/* Konstanta */
#define Nil NULL /* address tidak terdefinisi */

typedef struct {
    char c[50];
} str;

typedef str infotype;
typedef  struct tElmtList *address;
typedef struct tElmtList
{
    infotype Info;
    address Next;
} ElmtList;

typedef struct
{
   address First;
} List;

/* Jika L : List dan P : address (address untuk traversal), maka penulisan : }
{ First(L) menjadi L.First
Next(P) menjadi P.Next
Info(P) menjadi P.Info */

#define First(L)     (L).First
#define Next(P)      (P)->Next
#define Info(P)      (P)->Info
#define InfoNama(P) (P)->Info.c

/* Definisikan selektor yang tepat. */

/* PROTOTYPE */
/* ***************** TEST LIST KOSONG ***************** */
boolean IsListEmpty (List L);
/* Mengirim true jika list kosong */

/* ***************** TEST JUMLAH PEMAIN ***************** */
boolean IsPemainCukup (List L);
/* Mengirim true jika pemain cukup */

/* ***************** PEMBUATAN LIST KOSONG ***************** */
void CreateList (List *L);
/* I.S. sembarang */
/* F.S. Terbentuk list kosong */

/* ***************** Manajemen Memori ***************** */
address Alokasi (infotype X);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak Nil, dan misalnya menghasilkan P, maka
Info(P) = X, Next(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void Dealokasi (address *P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/* ***************** PENCARIAN SEBUAH ELEMEN LIST ***************** */
address Search (List L, char X[50]);
/* Mencari apakah ada elemen list dengan Info(P) = X */
/* Jika ada, mengirimkan address elemen tersebut */
/* Jika tidak ada, mengirimkan Nil */
/* ***************** PRIMITIF BERDASARKAN ALAMAT ***************** */

/* *** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT *** */
void InsertFirst (List *L, address P);
/* I.S. Sembarang, P sudah dialokasi */
void InsertAfter (List *L, address P, address Prec);
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/* P sudah dialokasi */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLast (List *L, address P);
/* I.S. Sembarang, P sudah dialokasi */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/* ***************** PROSES SEMUA ELEMEN LIST ***************** */
void PrintInfo (List L);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, */
/* Semua info yg disimpan pada elemen list diprint */
/* Jika list kosong, hanya menuliskan "list kosong" */
