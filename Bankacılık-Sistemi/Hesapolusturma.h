//Bayram Enes Atay 23181616059
//hesapolusturma fonksıyonu.//En yeni olan bu.
#include<stdio.h>
#include<string.h>
#include <ctype.h>


void Hesapolusturma(char dosyaismi[50]) {
    int sifre2;

    struct hesap {
        char isim[20];
        char soyad[20];
        int sifre;
        int bakiye;

    };

    FILE *dosya;

    struct hesap hesap1;

    printf("Hesabinizin bankada var olabilmesi icin oncelike isim ve soyisim giriniz(kucuk harf ve bitisik olarak):");
    scanf("%s",dosyaismi);

    int len = strlen(dosyaismi);
    printf("test");
    for (int i = 0; i < len; i++)
        dosyaismi[i] = tolower(dosyaismi[i]);


        //dosya ismini fgetsle aldigimiz icin otomatikman sonuna\n(yeni satir karakteri) eklenecek.
        //onu da karakter dizisinin icinden cikarmak icin strcspn fonksıyonunu kullanacagım.
        //strcspn(dosyaismi,"aeou")->bu bize dosyaismi stringinin icinde yazilan 2.parametreden herhangı bır karakterin
        //konumunu soyler yani bunun sonucu bir integer olur.Ama konum indis gibi dusunulmelidir.
        //strcat fonksıyonu ise 2 string parametresi alarak ikinci parametreyi birince parametreye ekleyerek
        //sonucu geri dondurur.


        dosya = fopen(strcat(dosyaismi, ".txt"), "w");

        if (dosya == NULL) {
            printf("Hesap olusturulamadi.");
        } else {
            printf("Olusturmak istediginiz isminizi giriniz(buyuk kucuk harfe dikkat edin;birden fazla isminiz varsa bitişik yaziniz ):");
            scanf("%s",&hesap1.isim);
            printf("Soyismini giriniz(buyuk kucuk harfe dikkat edin):");
            scanf("%s",&hesap1.soyad);
            printf("Hesaba giris sifrenizi belirleyiniz(4 haneli):");
            scanf("%d", &hesap1.sifre);
            while (hesap1.sifre < 999 || hesap1.sifre > 9999) {
                printf("Sifrenizin 4 haneli olmasi gerekir,lutfen 4 haneli sifre giriniz:");
                scanf("%d", &hesap1.sifre);
            }
            printf("Sifrenizi tekrar girerek onaylayiniz lutfen:");
            scanf("%d", &sifre2);
            while (hesap1.sifre != sifre2) {
                printf("UYARI!! Sifreyi yanlis girdiniz, tekrar giriniz:");
                scanf("%d", &sifre2);
            }
            printf("Bakiye = 0 TL\n");
            printf("Islem basarili,Hesabiniz olusturuldu.");


            fprintf(dosya, "Hesap Bilgisi\nIsim : %s\nSoyisim : %s\nSifre : %d\nBakiye : 0 TL",hesap1.isim,hesap1.soyad, hesap1.sifre);
            fclose(dosya);
        }

    }
