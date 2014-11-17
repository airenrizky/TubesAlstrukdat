#ifndef queuedadu_H
#define queuedadu_H
#include "boolean.h"

#define Nil NULL

typedef struct {
    char Nama[50];
    int Skor;
    } Pemain;

typedef Pemain infotype_dadu;
typedef int address_dadu;

typedef struct {
    infotype_dadu *T;
    address_dadu HEAD;
    address_dadu TAIL;
    int MaxEl;
    } Queue;

#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define InfoHead(Q) (Q).T[(Q).HEAD]
#define InfoHeadNama(Q) (Q).T[(Q).HEAD].Nama
#define InfoHeadSkor(Q) (Q).T[(Q).HEAD].Skor
#define InfoTail(Q) (Q).T[(Q).TAIL]
#define InfoTailNama(Q) (Q).T[(Q).TAIL].Nama
#define InfoTailSkor(Q) (Q).T[(Q).TAIL].Skor
#define MaxEl(Q) (Q).MaxEl

void CreateEmpty(Queue *Q, int Max);
/* I.S. Sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max */
/* atau : jika alokasi gagal, Q kosong dgn MaxEl = 0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

void DealokasiDadu(Queue *Q);
/* Proses : mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

boolean IsEmpty(Queue Q);
/* Mengirim true jika Queue kosong */

boolean IsFull(Queue Q);
/* Mengirim true jika tabel penampung nilai elemen queue penuh */

int NBElmt(Queue Q);
/* Mengirimkan banyaknya elemen queue, mengirimkan 0 jika Q kosong */

void Add(Queue *Q, infotype_dadu X);
/* Menambahkan X sebagai elemen Queue Q */
/* I.S. Q mungkin kosong, tabel penampung elemen Q tidak penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" */

void Del(Queue *Q, infotype_dadu *X);
/* Menghapus elemen pertama pada Q */
/* I.S. Q tidak kosong */
/* F.S. X = nilai elemen HEAD pada I.S., */
/*      JIka Queue masih isim HEAD diset tetap = 1, elemen-elemen setelah HEAD YANG */
/*      lama digeser ke "kiri", TAIL = TAIL - 1 */
/*      Jika Queue menjadi kosog, HEAD = TAIL = Nil */

boolean IsGame(Queue Q);
/* mengembalikan true apabila kondisi permainan berakhir terpenuhi, yaitu */
/* salah satu pemain mendapatkan skor sebesar 3 atau */
/* hanya tinggal satu pemain yang bermain */

void CreateQueuePemain(Queue *Q, int Maks);
/* I.S : Queue kosong dengan alokasi Min 2 dan Maks 4 */
/* F.S : Menghasilkan Q yang berisi informasi seluruh pemain berupa nama dengan skor awal = 0 */

void ChangeTurn(Queue *Q);
/* I.S : Queue berisi minimal 2 elemen */
/* F.S : Head(Q) diganti menjadi pemain yang berada di antrian selanjutnya */
/*       Sedangkan untuk Head(Q) di awal dipindah ke antrian paling belakang / Tail(Q) */

void PrintSkor(Queue *Q);
/* I.S : Queue tidak kosong */
/* F.S : Menampilkan seluruh skor pemain sesuai dengan format yang telah ditentukan */

#endif
