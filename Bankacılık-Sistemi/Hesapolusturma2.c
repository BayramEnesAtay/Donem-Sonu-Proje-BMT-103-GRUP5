// Bayram Enes Atay 23181616059
// Hesap olusuturma fonksıyonu 2
#include<stdio.h>

void Hesapolusturma();

int main()
{

    Hesapolusturma();

}


void Hesapolusturma()
{
    int sifre2;

    struct hesap{
        char isim[20];
        char soyad[20];
        int sifre;
        int bakiye;

    };

    FILE *aptr;

    struct hesap hesap1;

    aptr=fopen("HesapBilgisi","a+");
    printf("Olusturmak istediginiz hesabin ismini giriniz:");
    fgets(hesap1.isim,20,stdin);
    printf("Soyismini giriniz:");
    fgets(hesap1.soyad,20,stdin);
    printf("Hesaba giris sifrenizi belirleyiniz(4 haneli):");
    scanf("%d",&hesap1.sifre);
    while(hesap1.sifre<999 || hesap1.sifre>9999)
    {
        printf("Sifrenizin 4 haneli olmasi gerekir,lutfen 4 haneli sifre giriniz:");
        scanf("%d",&hesap1.sifre);
    }
    printf("Sifrenizi tekrar girerek onaylayiniz lutfen:");
    scanf("%d",&sifre2);
    while(hesap1.sifre!=sifre2)
    {
        printf("UYARI!! Sifreyi yanlis girdiniz, tekrar giriniz:");
        scanf("%d",&sifre2);
    }
    printf("Bakiye = 0 TL\n");
    printf("Islem basarili,Hesabiniz olusturuldu.");

    fprintf(aptr,"Hesap Bilgisi\n------------\nIsim:%s\nSoyisim:%s\nSifre:%d\nBakiye=0 TL",hesap1.isim,hesap1.soyad,hesap1.sifre);

}

