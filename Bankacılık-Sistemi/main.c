//Abdülselam İsmail 23181616010
//Bu bankacılık programımız için gerekli olan "menu" için yazılmış kodtur. Buraya diğer tüm fonksiyonlar atılacak
//Menu daha yapımaşamasında
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "gecmis.h"
#include "Hesapolusturma.h"
#include "ParaCekme-Yatirma_bakiyeSorgulama.h"

int main() {;
    char islemler[70];
    while (1){
        char komut[10];
        memset(islemler,0,sizeof(islemler));

        printf("Komut giriniz(komut listesi icin 'yardim' yaziniz):\n");
        fgets(komut, 10, stdin);
        komut[strcspn(komut, "\n")] = 0;
        int len = strlen(komut);
        for (int i = 0; i < len; i++) {
            komut[i] = tolower(komut[i]);
        }
        if (!(strcmp(komut,"yardim"))){
            printf("----------------\nHesaba gir->gir \nHesap olustur->olustur\nProgramdan cik->cik\n----------------\n");
        }
        else if (!(strcmp(komut,"cik")))
            break;
        else if (!(strcmp(komut,"gir"))){
            char kullanci[50];
            printf("Kullanci ad-soyad bosluk birakmadan yazniz:");
            fgets(kullanci, sizeof(kullanci), stdin);
            komut[strcspn(komut, "\n")] = 0;
            printf("hesabagir()\n");
            if (1){
                gecmis(("%s hesaptan giris yapildi",kullanci));
                printf("Hesaba giris basariyla tamamladi\n");
                strcat(islemler,kullanci);
                strcat(islemler,"giris yapildi");
                gecmis(islemler);
                while (1){
                    printf("Yapmak istediğiniz işlem giriniz\nBakiye Sorgulama->bakiye\nPara cekme->cek\nPara yatirma->yatir\nHesaptan cik->cik\n");
                    fgets(komut, 10, stdin);
                    komut[strcspn(komut, "\n")] = 0;
                    int len = strlen(komut);
                    for (int i = 0; i < len; i++) {
                        komut[i] = tolower(komut[i]);
                    }
                    if (!(strcmp(komut,"bakiye"))){
                        int bakiye;
                        bakiye=BakiyeSorgulama(kullanci);
                        printf("%d", bakiye);
                    }
                    else if (!(strcmp(komut,"cik")))
                        break;
                }


            }
            else
                printf("Kullanci bulunmadi (kullancı ismini doğru yazdiginizdan emin olun");
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
