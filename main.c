#include "header.h"

int main()
{
    int pilih;
    dataKegiatan ku[100];
    int indeks;
    char cari[100];
    int Kgtcari;
    char tambah;
    char hapus;

    menu:system("cls");
    system("color 30");//warna aqua tulis hitam
    puts("\t\t------------------------------------");
    printf("\t\t\tKALENDER AKTIVITAS\n");
    puts("\t\t------------------------------------");
    printf("\n1. Tambah Kegiatan\n");
    printf("2. Tampilkan Kegiatan\n");
    printf("3. Cari Kegiatan\n");
    printf("4. Hapus Kegiatan\n");
    printf("5. Urutkan Kegiatan\n");
    printf("6. Exit\n");

    lagi:printf("\n\tPilih Menu (1-6) : "); scanf("%d", &pilih);
    if(pilih<1 || pilih>6){
        system ("color 4F");//warna merah
        goto lagi;
    }

    switch(pilih)
    {
        case 1 :
            system ("color 1F");//warna biru
            tmbh:tambahKegiatan(ku,&indeks);
            slh:printf("\n\tTambah Kegiatan Lagi? [y/n] : "); scanf("%c", &tambah);
            if(tambah == 'Y' || tambah == 'y'){
                goto tmbh;
            }
            else if(tambah == 'N' || tambah == 'n'){
                goto menu;
            }
            else{
                fflush(stdin);
                system ("color 4F");//warna merah
                goto slh;
            }

            break;
        case 2 :
            system ("color 1F");//warna biru
            tampilKegiatan(ku,indeks);
            printf("\n\t");system("pause");
            goto menu;
            break;
        case 3 :
            system ("color 1F");//warna biru
            fflush(stdin);
            printf("\n\t\tMasukan Nama Kegiatan yang dicari : "); gets(cari);
            Kgtcari = cariKegiatan(ku,cari,indeks);
            if(Kgtcari != -1){
                tampilCariKgtan(ku,Kgtcari);
            }
            else{
                system ("color 4F");//warna merah
                printf("\n\t\t\tData Tidak Ada\n");
            }
            printf("\n\t");system("pause");
            goto menu;
            break;
        case 4 :
            system ("color 1F");//warna biru
            fflush(stdin);
            tampilKegiatan(ku,indeks);
            ketik:printf("\n\tKetik Kegiatan yang Akan dihapus : "); gets(cari);
            Kgtcari = cariKegiatan(ku,cari,indeks);
            if(Kgtcari != -1){
                tampilCariKgtan(ku,Kgtcari);
                hps:fflush(stdin);
                printf("\n\t\t\t Hapus? [y/n] "); scanf("%c",&hapus);
                if(hapus == 'y' || hapus == 'Y'){
                    hapusData(ku,&indeks,Kgtcari);
                    printf("\n\t\tData Telah Terhapus\n\n");
                }
                else if(hapus == 'n' || hapus == 'N'){
                    goto menu;
                }
                else{
                    system ("color 4F");//warna merah
                    goto hps;
                }
            }
            else{
                system ("color 4F");//warna merah
                printf("\n\t\t\tData Tidak Ada\n");
                goto ketik;
            }
            system("pause");
            goto menu;
            break;
        case 5 :
            system ("color 1F");//warna biru
            sorting(ku,indeks);
            tampilKegiatan(ku,indeks);
            printf("\n");system("pause");
            goto menu;
            break;
        case 6 :
            system("color 80");//warna aqua tulis hitam
            system("cls");
            printf("\n\n\n\tTHANKS FOR USING THIS APPLICATION\n\n\n");
            printf("\t\t\t\3\3\3\n\n\n");
            system("exit");
            break;
    }
    return 0;
}
