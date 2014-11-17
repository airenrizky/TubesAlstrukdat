#include "list_linear.h"
#include "boolean.h"
#include "mesinkar.h"
#include "mesinkata.h"
#include "queue_dadu.h"

char namafile[50], tempNama[50], pil, opsi, logout;
List L;
address P, Ps;
infotype nama;
int i;

int main()
{
    /*printf("Masukkan nama file : ");
    scanf("%s", &namafile);*/
    strcpy(namafile,"daftarpemain.txt");
    if (IsFileExist(namafile)) {
        CLOSE();
    } else {
        STARTSAVE(namafile);
        ENDSAVENULL();
    }
    do {
        printf("\nMENU UTAMA \n");
        printf("1. Register \n");
        printf("2. Login \n");
        printf("3. Keluar \n");
        printf("Pilihan Anda : ");
        scanf("%s", &pil);
        switch (pil) {
        case '1' :  {
                        printf("\n--Register-- \n");
                        do {
                            CreateList(&L);
                            STARTKATA(namafile);
                            while (!EndKata) {
                                for (i = 0; i < CKata.Length; i++) {
                                    nama.c[i] = CKata.TabKata[i];
                                }
                                P = Alokasi(nama);
                                InsertLast(&L,P);
                                memset(nama.c,0,sizeof nama.c);
                                ADVKATA();
                            }
                            printf("Nama : ");
                            scanf("%s", &tempNama);
                            while (strlen(tempNama) < 3) {
                                printf("Nama terlalu pendek, ulangi! \n");
                                printf("Nama : ");
                                scanf("%s", &tempNama);
                            }
                            Ps = Search(L,tempNama);
                            if (Ps == Nil) {
                                strcpy(nama.c,tempNama);
                                P = Alokasi(nama);
                                InsertLast(&L,P);
                                STARTSAVE(namafile);
                                if (IsListEmpty(L)) {
                                    ENDSAVENULL();
                                    printf("Pendaftaran gagal! \n");
                                } else {
                                    P = First(L);
                                    while (Next(P) != Nil) {
                                        SAVESTATE(InfoNama(P));
                                        P = Next(P);
                                    }
                                    ENDSAVESTATE(InfoNama(P));
                                    printf("Pendaftaran Berhasil. %s terdaftar. \n", tempNama);
                                }
                            } else {
                                printf("Nama sudah terdaftar! \n");
                            }
                            printf("Mendaftar lagi? (Y/T) : ");
                            scanf("%s", &opsi);
                            while ((opsi != 'Y') && (opsi != 'T')) {
                                printf("Input salah, ulangi! \n");
                                printf("Mendaftar lagi? (Y/T) : ");
                                scanf("%s", &opsi);
                            }
                        } while ((opsi == 'Y') && (opsi != 'T'));
                        break;
                    }
        case '2' :  {
                        printf("\n--Login-- \n");
                        CreateList(&L);
                        STARTKATA(namafile);
                        while (!EndKata) {
                            for (i = 0; i < CKata.Length; i++) {
                                nama.c[i] = CKata.TabKata[i];
                            }
                            P = Alokasi(nama);
                            InsertLast(&L,P);
                            memset(nama.c,0,sizeof nama.c);
                            ADVKATA();
                        }
                        if (IsListEmpty(L)) {
                            printf("File kosong! Register terlebih dahulu! \n");
                        } else if (!IsPemainCukup(L)) {
                            printf("Pemain kurang! Minimal sudah ada dua pemain yang ter-register untuk bermain! \n");
                        } else {
                            printf("Nama : ");
                            scanf("%s", &tempNama);
                            Ps = Search(L,tempNama);
                            if (Ps == Nil) {
                                printf("Login Gagal. Nama tidak terdaftar. Silakan daftarkan terlebih dahulu! \n");
                            } else {
                                printf("Login berhasil. \n");
                                printf("Selamat datang %s! \n", tempNama);
                                printf("\nTeman bermain Anda : \n");
                                P = First(L);
                                while (P != Nil) {
                                    if (P == Ps) {
                                        P = Next(P);
                                    } else {
                                        printf("%s \n", InfoNama(P));
                                        P = Next(P);
                                    }
                                }
                                printf("\nSilakan Log Out dengan masukan karakter 'Y' : ");
                                scanf("%s", &logout);
                                while (logout != 'Y') {
                                    printf("Input salah! \n");
                                    printf("Silakan Log Out dengan masukan karakter 'Y' : ");
                                    scanf("%s", &logout);
                                }
                            }
                        }
                        break;
                    }
        case '3' :  {
                        printf("Selamat Tinggal! \n");
                        break;
                    }
        default  :  {
                        printf("Masukkan Anda salah. Silakan periksa kembali ! \n");
                        break;
                    }
        }
    } while (pil != '3');
    return 0;
}
