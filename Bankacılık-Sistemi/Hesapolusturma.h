//Bayram Enes Atay 23181616059
//hesapolusturma fonksıyonu.//En yeni olan bu.
#include<stdio.h>
#include<string.h>
#include <ctype.h>


void Hesapolusturma() {
    int sifre2;

    struct hesap {
        char isim[20];
        char soyad[20];
        int sifre;
        int bakiye;

    };

    FILE *aptr;

    struct hesap hesap1;
    char dosyaismi[50];

    printf("Hesabinizin bankada var olabilmesi icin oncelike isim ve soyisim giriniz(kucuk harf ve bitisik olarak):");
    fgets(dosyaismi, 50, stdin);

    int len = strlen(dosyaismi);
    for (int i = 0; i < len; i++)
        dosyaismi[i] = tolower(dosyaismi[i]);



        //dosya ismini fgetsle aldigimiz icin otomatikman sonuna\n(yeni satir karakteri) eklenecek.
        //onu da karakter dizisinin icinden cikarmak icin strcspn fonksıyonunu kullanacagım.
        //strcspn(dosyaismi,"aeou")->bu bize dosyaismi stringinin icinde yazilan 2.parametreden herhangı bır karakterin
        //konumunu soyler yani bunun sonucu bir integer olur.Ama konum indis gibi dusunulmelidir.
        //strcat fonksıyonu ise 2 string parametresi alarak ikinci parametreyi birince parametreye ekleyerek
        //sonucu geri dondurur.

        char*kelime1,*kelime2;
        dosyaismi[strcspn(dosyaismi, "\n")] = 0;//Aldigimiz stingden \n karakterini cikariyorum.

        aptr = fopen(strcat(dosyaismi, ".txt"), "w");

        if (aptr == NULL) {
            printf("Hesap olusturulamadi.");
        } else {
            printf("Olusturmak istediginiz hesabin ismini giriniz:");
            fgets(hesap1.isim, 20, stdin);
            hesap1.isim[strcspn(hesap1.isim,"\n")]=0;
            kelime1=strtok(hesap1.isim," ");
            kelime2=strtok(NULL," ");
            if(kelime2==NULL)
            {
                kelime2="";
            }

            printf("Soyismini giriniz:");
            fgets(hesap1.soyad, 20, stdin);
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


            fprintf(aptr, "Hesap Bilgisi\nIsim : %s%s\nSoyisim : %sSifre : %d\nBakiye : 0 TL",kelime1,kelime2,hesap1.soyad, hesap1.sifre);
            fclose(aptr);
        }

    }
