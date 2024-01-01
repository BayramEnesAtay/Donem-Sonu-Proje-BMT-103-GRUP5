//Bayram Enes Atay 23181616059
//Hesaba giris fonksıyonunun son halidir.
#include<stdio.h>
#include<errno.h>
#include<string.h>
#include <ctype.h>
#include<stdlib.h>

int Hesabagiris(char kullanici[])
{

    struct Hesabagir{

        char isim[20];
        char soyisim[20];
        char sifre[4];

    };
    struct Hesabagir hesap;
    char satir1[30];
    char satir2[30];
    char satir3[30];
    int sayac=0,i,sayac2=0,sayac3=0;

    FILE *giris;
    giris=fopen(strcat(kullanici,".txt"),"r");

    if(giris==NULL)
    {
        perror("Error");
        printf("Error number:%d",errno);
    }
    else {
        printf("\nIsminizi giriniz(Bitisik yaziniz):");
        scanf("%s",&hesap.isim);
        printf("test");
        char*kelime1,*kelime2;
        kelime1=strtok(hesap.isim," ");
        kelime2=strtok(NULL," ");
        printf("test");
        if(kelime2==NULL)
        {
            strcpy(hesap.isim,kelime1);
        }
        else{
            strcat(kelime1,kelime2);
            strcpy(hesap.isim,kelime1);
        }
        while (fgets(satir1, 30, giris) != NULL) {
            satir1[strcspn(satir1, "\n")] = 0;
            char *kelime = strtok(satir1, " ");
            while (kelime != NULL) {
                if (strcmp(kelime, hesap.isim) == 0) {
                    printf("Dogru girdiniz.");
                    sayac3+=1;
                }
                kelime = strtok(NULL, " ");
            }
        }
        if(sayac3==0)
        {
            printf("Yanlis girdiniz.");
            return 0;
        }
        fseek(giris, 0, SEEK_SET);

        printf("\nSoyisminizi giriniz:");
        scanf("%s",&hesap.soyisim);


        while (fgets(satir2, 30, giris) != NULL) {
            satir2[strcspn(satir2, "\n")] = 0;
            char *kelime3 = strtok(satir2, " ");
            while (kelime3 != NULL) {
                if (strcmp(kelime3, hesap.soyisim) == 0) {
                    printf("Dogru girdiniz.");
                    sayac+=1;
                }
                kelime3 = strtok(NULL, " ");
            }
        }
        if(sayac==0)
        {
            printf("Yanlis girdiniz.");
            return 0;
        }
        fseek(giris, 0, SEEK_SET);

        printf("\nSifrenizi giriniz:");
        scanf("%4s",&hesap.sifre);




        int dosyasifresi;

        while(fgets(satir3,30,giris)!=NULL)
        {
            satir3[strcspn(satir3,"\n")]=0;
            char*kelime4=strtok(satir3," ");
            while(kelime4!=NULL)
            {
                if(strcmp(kelime4,hesap.sifre)==0) {
                    printf("Dogru girdiniz.");
                    sayac2+=1;
                    printf("\nHesaba basarili bir sekilde giris yapildi!!");
                    return 1;
                }
                kelime4=strtok(NULL," ");
            }

        }
        if(sayac2==0)
        {
            printf("Yanlis girdiniz.");
            printf("\nHesaba giris yapilamadi!!");
            fclose(giris);
            return 0;
        }
    }
}
