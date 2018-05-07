#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///struct untuk tanggal
typedef struct
{
    int tgl;
    int bln;
    int thn;
}tanggal;

///struct untuk waktu
typedef struct
{
    int jam;
    int menit;
}waktu;

///struct untuk member
typedef struct
{
    char namaAnggota[20];
}member;

///struct untuk data kegiatan
typedef struct
{
    tanggal kegiatan;
    waktu kgtan;
    char namaKegiatan[30];
    char tempatKegiatan[50];
    member orang[100];
    int banyakOrang;
}dataKegiatan;


int isTanggal(int tgl, int bln, int thn);
int isWaktu(int jam, int menit);
void tambahKegiatan(dataKegiatan saya[],int *indeks);
void tampilKegiatan(dataKegiatan saya[], int indeks);
int cariKegiatan(dataKegiatan saya[],char nama[],int Btsindeks);
void tampilCariKgtan(dataKegiatan saya[], int indeks);
void hapusData(dataKegiatan saya[], int *indeks, int iHapus);
void swapData(dataKegiatan *A, dataKegiatan *B);
void sorting(dataKegiatan saya[], int indeks);

#endif // HEADER_H_INCLUDED
