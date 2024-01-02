//Abdülselam İsmail 23181616010
//Bu bankacılık programımız için gerekli olan "menu" için yazılmış kodtur. Buraya diğer tüm fonksiyonlar header şeklinde atıldı

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "gecmis.h"
#include "Hesapolusturma.h"
#include "bakiyeSorgulama.h"
#include "Hesabagiris.h"
#include "ParaCekme.h"
#include "ParaYatirma.h"

int main() {;
    char islemler[100];
    while (1){
        char komut[10];
        memset(islemler,0,sizeof(islemler));
        printf("------------------\nKomut giriniz(komut listesi icin 'yardim' yaziniz):\n");
        fgets(komut,sizeof(komut),stdin);
        komut[strcspn(komut,"\n")] = 0;

        int len = strlen(komut);
        for (int i = 0; i < len; i++) {
            komut[i] = tolower(komut[i]);
        }
        if (!(strcmp(komut,"yardim"))){
            printf("------------------\nHesaba gir->gir \nHesap olustur->olustur\nProgramdan cik->cik\n");
        }
        else if (!(strcmp(komut,"cik")))
            break;
        else if (!(strcmp(komut,"gir"))){
            char kullanci[50];
            printf("------------------\nKullanci ad-soyad bosluk birakmadan yazniz:");
            fgets(kullanci,sizeof(kullanci)+1,stdin);
            kullanci[strcspn(kullanci,"\n")] = 0;
            if (Hesabagiris(kullanci)==1){
                strcat(islemler,kullanci);
                strcat(islemler," giris yapildi");
                gecmis(islemler);
                while (1){
                    memset(islemler,0,sizeof(islemler));
                    printf("------------------\nYapmak istediginiz islem giriniz\n------------------\nBakiye Sorgulama->bakiye\nPara cekme->cek\nPara yatirma->yatir\nHesaptan cik->cik\n------------------\n");
                    //fflush inputtaki \n'yi temizlemek için kullanıldı
                    fflush(stdin);
                    fgets(komut,sizeof(komut)+1,stdin);
                    komut[strcspn(komut,"\n")] = 0;
                    int len = strlen(komut);
                    for (int i = 0; i < len; i++) {
                        komut[i] = tolower(komut[i]);
                    }
                    if (!(strcmp(komut,"bakiye"))){
                        BakiyeSorgulama(kullanci);
                        strcat(islemler,kullanci);
                        strcat(islemler," bakiye sorgulama");
                        gecmis(islemler);
                    }
                    else if (!(strcmp(komut,"yatir"))){
                        int paraInt = ParaYatirma(kullanci);
                        char paraStr[6];

                        sprintf(paraStr,"%d",paraInt);
                        strcpy(islemler,kullanci);
                        strcat(islemler," ");
                        strcat(islemler, paraStr);
                        strcat(islemler,"TL yatirildi");
                        gecmis(islemler);
                    }

                    else if (!(strcmp(komut,"cek"))){
                        int paraInt = ParaCekme(kullanci);
                        char paraStr[6];

                        sprintf(paraStr,"%d",paraInt);
                        strcpy(islemler,kullanci);
                        strcat(islemler," ");
                        strcat(islemler, paraStr);
                        strcat(islemler,"TL cekildi");
                        gecmis(islemler);

                    }
                    else if (!(strcmp(komut,"cik"))){
                        strcat(islemler,kullanci);
                        strcat(islemler," cikis yapildi");
                        gecmis(islemler);
                        printf("------------------\nCikis basariyla yapildi\n");
                        break;
                    }
                    else
                        printf("Gecerli komut giriniz!!");
                }


            }

        }
        else if (!(strcmp(komut,"olustur"))){
            char kullanci[50];
            Hesapolusturma(kullanci);

            strcat(islemler,kullanci);
            strcat(islemler," hesap olusturuldu");
            gecmis(islemler);
        }
        else
            printf("Gecerli komut giriniz(Turkce harfleri kullanmayin\n");



    }
    return 0;
}


