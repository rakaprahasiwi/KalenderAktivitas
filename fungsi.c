#include "header.h"

///cek tanggal valid
int isTanggal(int tgl, int bln, int thn)
{
    int oke=0;
    if((bln>0 && bln<=12) && thn>0){
        if(bln == 2){
            if(thn%4 == 0){
                if(tgl>0 && tgl<=29){
                    oke=1;
                }
            }
            else{
                if(tgl>0 && tgl<=28){
                    oke=1;
                }
            }
        }
        else if(bln == 4 || bln == 6 || bln == 9 || bln == 11){
            if(tgl>0 && tgl<=30){
            oke=1;
            }
        }
        else{
            if(tgl>0 && tgl<=31){
                oke=1;
            }
        }
    }
    return oke;
}
///cek waktu valid
int isWaktu(int jam, int menit)
{
    int oke=0;

    if(jam >= 0 && jam < 24){
        if(menit>=0 && menit<60){
            oke=1;
        }
    }

    return oke;
}
///menambah kegiatan
void tambahKegiatan(dataKegiatan saya[],int *indeks)
{
    int i;///untuk iterasi

    ///melakukan looping jika tdk valid
    while(isTanggal(saya[*indeks].kegiatan.tgl, saya[*indeks].kegiatan.bln, saya[*indeks].kegiatan.thn) == 0){
        printf("\n\t\tInput Tanggal, Bulan, Tahun (D/M/YYYY): "); scanf("%d %d %d", &saya[*indeks].kegiatan.tgl, &saya[*indeks].kegiatan.bln, &saya[*indeks].kegiatan.thn);
    }

    ///melakukan looping jika tdk valid
    do{
        printf("\t\tInput Jam, Menit (HH:MM)              : "); scanf("%d %d", &saya[*indeks].kgtan.jam, &saya[*indeks].kgtan.menit);
    }while(isWaktu(saya[*indeks].kgtan.jam, saya[*indeks].kgtan.menit) == 0);

    fflush(stdin);
    printf("\t\tInput Nama Kegiatan                   : "); gets(saya[*indeks].namaKegiatan);

    strlwr(saya[*indeks].namaKegiatan);

    printf("\t\tInput Tempat Kegiatan                 : "); gets(saya[*indeks].tempatKegiatan);

    printf("\t\tBanyak orang yang berpartisipasi      : "); scanf("%d", &saya[*indeks].banyakOrang);
    fflush(stdin);
    for(i=0;i<saya[*indeks].banyakOrang;i++){
        printf("\n\t\t\tInput Nama Member (%d) : ",i+1); gets(saya[*indeks].orang[i].namaAnggota);
    }

    *indeks+=1;///menambah 1 array pada batas
}
///menampilkan kegiatan
void tampilKegiatan(dataKegiatan saya[], int indeks)
{
    int i, j;

    for(i=0;i<indeks;i++){
        printf("\n\t\t%d. Tanggal Kegiatan : %d/%d/%d\n",i+1, saya[i].kegiatan.tgl, saya[i].kegiatan.bln, saya[i].kegiatan.thn);
        printf("\t\t    Waktu Kegiatan    : %d:%d WIB\n", saya[i].kgtan.jam, saya[i].kgtan.menit);
        printf("\t\t    Nama Kegiatan     : %s\n", saya[i].namaKegiatan);
        printf("\t\t    Tempat Kegiatan   : %s\n", saya[i].tempatKegiatan);
        printf("\t\t    Banyak Member     : \n");

        if(saya[i].banyakOrang == 0){
            printf("\n\t\t\tTidak Ada Member\n");
        }
        else{
            for(j=0;j<saya[i].banyakOrang;j++){
                printf("\t\t\t\tMember (%d) : %s\n", j+1, saya[i].orang[j].namaAnggota);
            }
        }
        printf("\n");
    }
}
///mencari kegiatan
int cariKegiatan(dataKegiatan saya[],char nama[],int Btsindeks)
{
    int i;
    strlwr(nama);///untuk mengubah menjadi huruf tidak kapital
    for(i=0;i<Btsindeks;i++)
    {
        if(strcmp(saya[i].namaKegiatan,nama)==0)///membandingkan nama yang dicari dengan data yang ada
            break;
    }
    if(i<Btsindeks)
        return i;
    else
        return -1;
}
///menampilkan kegiatan setelah dicari
void tampilCariKgtan(dataKegiatan saya[], int indeks)
{
    int j;
    printf("\n\t\tNama kegiatan     : %s\n",saya[indeks].namaKegiatan);
    printf("\t\tTanggal kegiatan  : %d/%d/%d\n",saya[indeks].kegiatan.tgl,saya[indeks].kegiatan.bln,saya[indeks].kegiatan.thn);
    printf("\t\tTempat kegiatan   : %s\n",saya[indeks].tempatKegiatan);
    printf("\t\tWaktu Kegiatan    : %d:%d WIB\n",saya[indeks].kgtan.jam,saya[indeks].kgtan.menit);
    printf("\t\tBanyak Member     :\n");
    if(saya[indeks].banyakOrang == 0)
    {
        printf("\n\t\t\tTidak Ada Member\n");
    }
    else
    {
        for(j=0;j<saya[indeks].banyakOrang;j++)
        {
            printf("\t\t\tMember (%d) : %s\n",j+1,saya[indeks].orang[j].namaAnggota);
        }
    }
}
///untuk swap
void swapData(dataKegiatan *A, dataKegiatan *B)
{
    dataKegiatan C;

    C=*A;
    *A=*B;
    *B=C;
}
///untuk menghapus data kegiatan
void hapusData(dataKegiatan saya[], int *indeks, int iHapus)
{
    int i;
    *indeks-=1;
    for(i=iHapus;i<*indeks;i++){
        saya[i]=saya[i+1];
    }
}
///untuk mengurutkan data kegiatan
void sorting(dataKegiatan saya[], int indeks)
{
    int i, j;

    for(i=0;i<indeks-1;i++){
        for(j=0;j<indeks-1;j++){
            if(strcmp(saya[j+1].namaKegiatan,saya[j].namaKegiatan)<0){
                swapData(&saya[j+1],&saya[j]);
            }
        }
    }
}
