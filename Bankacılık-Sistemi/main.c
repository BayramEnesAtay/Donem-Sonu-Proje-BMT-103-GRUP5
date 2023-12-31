//Abdülselam İsmail 23181616010
//Bu bankacılık programımız için gerekli olan "menu" için yazılmış kodtur. Buraya diğer tüm fonksiyonlar atılacak
//Menu daha yapımaşamasında
#include <stdio.h>
#include <string.h>

int main() {;
    //Komutları sürekli yazabilmesinş sağlamak adına while döngüyü kullandım
    while (1){
      //Müşteriye kolaylık sağlamak adına komutları string türünden aldık
        char komut[10];
        printf("Komut giriniz(komut listesi icin 'yardim' yaziniz):\n");
        scanf("%s", &komut);
      //Stringleri karşılamak için strcmp() fonksiyonunu kullandım. Fonksiyon dönüşte sıfır verdiği için önüne değil operatörü(!) kulllandım
        if (!(strcmp(komut,"yardim"))){
            printf("----------------\nHesaba gir->gir \nHesap olustur->olustur\nProgramdan cik->cik\n----------------\n");
        }
        else if (!(strcmp(komut,"cik")))
            break;
        else if (!(strcmp(komut,"gir")))
            printf("hesabagir()\n");
        else if (!(strcmp(komut,"olustur")))
            printf("hesapolustur()\n");
        else
            printf("Gecerli komut giriniz\n");



    }
    return 0;
}

