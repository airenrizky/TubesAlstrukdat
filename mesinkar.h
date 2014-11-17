#ifndef mesinkar_H
#define mesinkar_H
#include "boolean.h"

#define MARK '.'
#define Nil NULL

/* State Mesin */
extern char CC;

boolean IsFileExist(char namafile[50]);
/* Mengecek apakah file dengan nama namafile ada atau tidak */

void CLOSE();
/* Menutup file yang sudah ada
   I.S. : File sedang dibuka
   F.S. : File ditutup */

void START(char namafile[50]);
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya pada jendela.
   I.S. : semabrang
   F.S. : CC adalah karakter pertama pada pita
          Jika CC != MARK amaka EOP akan padam (false)
          Jika CC = MARK maka EOP akan menyala (true) */

void ADV();
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = CC, CC != MARK
   F.S. : CC adalah karakter berikutnya dari CC yang lama
          CC mungkin = MARK
          Jika CC = MARK maka EOP akan menyala (true) */

boolean EOP();
/* true jika CC == MARK */

void STARTSAVE(char namafile[50]);
/* Membuka file untuk siap menyimpan nama-nama pemain yang diregister.
   I.S. : Sembarang
   F.S. : File siap untuk menyimpan */

void SAVESTATE(char X[50]);
/* Menyimpan satu nama dari program ke file.
   I.S. : File sudah terlebih dahulu dibuka, nama yang ingin disimpan
          siap ditulis ke dalam file
   F.S. : Nama sudah tersimpan di dalam file */

void ENDSAVESTATE(char X[50]);
/* Mengakhiri penyimpanan nama ke dalam file dengan menyimpan nama terakhir
   yang diakhiri dengan MARK.
   I.S. : Nama-nama yang ingin disimpan sudah tersimpan pada file
   F.S. : Nama terakhir tersimpan diakhiri dengan MARK lalu file ditutup */

void ENDSAVENULL();
/* Mengakhiri penyimpanan apabila tidak ada nama yang bisa disimpan ke dalam file
   I.S. : Tidak ada nama yang bisa disimpan ke dalam file
   F.S. : Mengakhiri penyimoanan dengan menulis MARK pada file lalu file ditutup */

#endif

