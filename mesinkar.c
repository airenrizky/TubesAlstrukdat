#include <stdio.h>
#include <string.h>
#include "mesinkar.h"

char CC;

static FILE *pita;
static int retval;


boolean IsFileExist(char namafile[50])
/* Mengecek apakah file dengan nama namafile ada atau tidak */
{
    pita = fopen(namafile,"r");
    return (pita != Nil);
}

void CLOSE()
/* Menutup file yang sudah ada
   I.S. : File sedang dibuka
   F.S. : File ditutup */
{
    fclose(pita);
}

void START(char namafile[50])
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya pada jendela.
   I.S. : semabrang
   F.S. : CC adalah karakter pertama pada pita
          Jika CC != MARK amaka EOP akan padam (false)
          Jika CC = MARK maka EOP akan menyala (true) */
{
    pita = fopen(namafile,"r");
    retval = fscanf(pita,"%c",&CC);
}

void ADV()
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = CC, CC != MARK
   F.S. : CC adalah karakter berikutnya dari CC yang lama
          CC mungkin = MARK
          Jika CC = MARK maka EOP akan menyala (true) */
{
    retval = fscanf(pita,"%c",&CC);
    if (CC == MARK)
    {
        fclose(pita);
    }
}

boolean EOP()
/* true jika CC == MARK */
{
    return(CC == MARK);
}

void STARTSAVE(char namafile[50])
/* Membuka file untuk siap menyimpan nama-nama pemain yang diregister.
   I.S. : Sembarang
   F.S. : File siap untuk menyimpan */
{
    pita = fopen(namafile,"w");
}

void SAVESTATE(char X[50])
/* Menyimpan satu nama dari program ke file.
   I.S. : File sudah terlebih dahulu dibuka, nama yang ingin disimpan
          siap ditulis ke dalam file
   F.S. : Nama sudah tersimpan di dalam file */
{
    fprintf(pita,"%s ",X);
}

void ENDSAVESTATE(char X[50])
/* Mengakhiri penyimpanan nama ke dalam file dengan menyimpan nama terakhir
   yang diakhiri dengan MARK.
   I.S. : Nama-nama yang ingin disimpan sudah tersimpan pada file
   F.S. : Nama terakhir tersimpan diakhiri dengan MARK lalu file ditutup */
{
    fprintf(pita,"%s.",X);
    fclose(pita);
}

void ENDSAVENULL()
/* Mengakhiri penyimpanan apabila tidak ada nama yang bisa disimpan ke dalam file
   I.S. : Tidak ada nama yang bisa disimpan ke dalam file
   F.S. : Mengakhiri penyimoanan dengan menulis MARK pada file lalu file ditutup */
{
    fprintf(pita,".");
    fclose(pita);
}
