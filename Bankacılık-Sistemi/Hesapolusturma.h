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

    printf("------------------\nHesabinizin bankada var olabilmesi icin oncelike isim ve soyisim giriniz(kucuk harf ve bitisik olarak):");
    fgets(dosyaismi, 51,stdin);
    dosyaismi[strcspn(dosyaismi,"\n")] = 0;
    fflush(stdin);


    int len = strlen(dosyaismi);
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
            printf("------------------\nHesap olusturulamadi.");
        } else {
            char *kelime1,*kelime2;

            printf("------------------\nOlusturmak istediginiz isminizi giriniz(buyuk kucuk harfe dikkat edin):");
            fgets(hesap1.isim, sizeof(hesap1.isim)+1,stdin);
            hesap1.isim[strcspn(hesap1.isim,"\n")] = 0;
            kelime1=strtok(hesap1.isim," ");
            kelime2=strtok(NULL," ");
            if(kelime2==NULL)
            {
                kelime2="";
            }

            printf("------------------\nSoyismini giriniz(buyuk kucuk harfe dikkat edin):");
            scanf("%s",&hesap1.soyad);
            printf("------------------\nHesaba giris sifrenizi belirleyiniz(4 haneli):");
            scanf("%d", &hesap1.sifre);
            while (hesap1.sifre < 999 || hesap1.sifre > 9999) {
                printf("------------------\nSifrenizin 4 haneli olmasi gerekir,lutfen 4 haneli sifre giriniz:");
                scanf("%d", &hesap1.sifre);
            }
            printf("------------------\nSifrenizi tekrar girerek onaylayiniz lutfen:");
            scanf("%d", &sifre2);
            while (hesap1.sifre != sifre2) {
                printf("------------------\nUYARI!! Sifreyi yanlis girdiniz, tekrar giriniz:");
                scanf("%d", &sifre2);
            }
            printf("Bakiye = 0 TL\n");
            printf("------------------\nIslem basarili,Hesabiniz olusturuldu\n.");


            fprintf(dosya, "Hesap Bilgisi\nIsim : %s%s\nSoyisim : %s\nSifre : %d\nBakiye : 0 TL",kelime1,kelime2,hesap1.soyad, hesap1.sifre);

            fclose(dosya);
            fflush(stdin);
        }

    }
