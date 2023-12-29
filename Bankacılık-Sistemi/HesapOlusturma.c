//Bayram Enes Atay 23181616059
//Hesap olusturma fonksiyonunu kaba taslak hazirladim.
#include<stdio.h>
#include<string.h>
void hesapkurma();

int main()
{
    hesapkurma();
    return 0;
}
void hesapkurma()
{
    FILE *aptr;


    struct hesap{
        char ad[20];
        char soyad[20];
        int sifre;
        int sifre2;

    };


    struct hesap hesap1;

    printf("Adinizi giriniz:");
    fgets(hesap1.ad,20,stdin);
    printf("Soyadinizi giriniz:");
    scanf("%s",&hesap1.soyad);
    printf("Sifre(4haneli) giriniz:");
    scanf("%d",&hesap1.sifre);

    do{
        printf("Sifrenizi tekrar giriniz(onaylamak icin):");
        scanf("%d",&hesap1.sifre2);
    }
    while(hesap1.sifre2!=hesap1.sifre);

    aptr=fopen("HesapBilgileri.txt","w+");
    fprintf(aptr,"Hesap Bilgisi\n------------\nIsim:%s\nSoyisim:%s\nSifre:%d",hesap1.ad,hesap1.soyad,hesap1.sifre);
    printf("Hesabiniz olusturuldu.");

}
