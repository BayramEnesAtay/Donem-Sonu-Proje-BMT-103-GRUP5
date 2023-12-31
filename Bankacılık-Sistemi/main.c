//Abdülselam İsmail 23181616010
//Bu bankacılık programımız için gerekli olan "menu" için yazılmış kodtur. Buraya diğer tüm fonksiyonlar atılacak
//Menu daha yapımaşamasında
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "gecmis.h"
#include "HesapOlusturma.h"

int main() {;
    while (1){
        char komut[10];
        printf("Komut giriniz(komut listesi icin 'yardim' yaziniz):\n");
        scanf("%s", &komut);
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
            scanf("%s",&kullanci);
            printf("hesabagir()\n");
            if (1){
                gecmis(("%s hesaptan giris yapildi",kullanci));
                printf("Hesaba giris basariyla tamamladi\n");

            }
            else
                printf("Kullanci bulunmadi (kullancı ismini doğru yazdiginizdan emin olun");
        }
        else if (!(strcmp(komut,"olustur")))
            Hesapolusturma();
        else
            printf("Gecerli komut giriniz(Türkçe harfleri kullanmamaya ve komutlari küçük harf\n");



    }
    return 0;
}


