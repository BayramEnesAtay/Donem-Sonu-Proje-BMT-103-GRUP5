//Abdülselam İsmail 23181616010
//Bu bankacılık programımız için gerekli olan "menu" için yazılmış kodtur. Buraya diğer tüm fonksiyonlar header şeklinde atıldı

//Başlamadan önce gerekli header dosyaları eklendi
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "gecmis.h"
#include "Hesapolusturma.h"
#include "bakiyeSorgulama.h"
#include "Hesabagiris.h"
#include "ParaCekme.h"
#include "ParaYatirma.h"

int main() {

    //geçmiş() fonksiyonu için "islemler" değşkeni belirlendi
    char islemler[100];

    //Menu çok kullanışlı olması için o döngüye alındı
    while (1){

        //Kullancının yazacağı komutlar için string(dizi) formatında "komut"  belirlendi
        char komut[10];

        //Her dönüşte memset() yardımıyla "işlemler" stingi boşaltılıyor
        memset(islemler,0,sizeof(islemler));
        printf("------------------\nKomut giriniz(komut listesi icin 'yardim' yaziniz):\n");

        //fgets() Fonksiyonunu kullanarak kullancıdan input alınıyor. strcspn() fonksiyonu ile inpu sonundaki "\n" karakteri gideriliyor
        fgets(komut,sizeof(komut),stdin);
        komut[strcspn(komut,"\n")] = 0;

        //Aşağıdaki döngü ile komutların hem büyük hem de küçük harfle yazılabilmesi sağlanıyor
        int len = strlen(komut);
        for (int i = 0; i < len; i++) {
            komut[i] = tolower(komut[i]);
        }

        //Aşağıda if/else if/else komutlarıyla komuta göre işlemleri belirtiyoruz
        if (!(strcmp(komut,"yardim"))){
            printf("------------------\nHesaba gir->gir \nHesap olustur->olustur\nProgramdan cik->cik\n");
        }

        else if (!(strcmp(komut,"cik")))
            
            //break kullanarak döngüdün çıkamsını dolaysıyla programdan çıkması sağlanıyor
            break;

        else if (!(strcmp(komut,"gir"))){

            //İlerde farklı fonksiyonlar için gerekli parametre olacak  "kullanci" String(dizi) oluşturuldu
            char kullanci[50];
            printf("------------------\nKullanci ad-soyad bosluk birakmadan yazniz:");

            //fgets() kullanarak kullancı ismini standart inputtan alıyoruz. strcspn() fonksyonu yardımıyla input sonundaki "\n" karakterin giderilmesi sağlanıyor
            fgets(kullanci,sizeof(kullanci)+1,stdin);
            kullanci[strcspn(kullanci,"\n")] = 0;

            //Hesabagiris() fonksiyonu dönüş değeri olarak 1 ya da 0 veriyor ona göre if/else kullanılarak eğer dönüş 1'se kullancının devam etmesi sağlanıyor
            if (Hesabagiris(kullanci)==1){

                //strcat() ve gecmis() fonksiyonları kullanarak "gecmis.txt" dosyamıza işlem geçmişi yazılması sağlanıyor
                strcat(islemler,kullanci);
                strcat(islemler," giris yapildi");
                gecmis(islemler);

                //Aşağıda kullancı menüsü çok kullanışlı olması adına o döngüye alındı
                while (1){

                    //Her dönüşte memset() yardımıyla "işlemler" stingi boşaltılıyor
                    memset(islemler,0,sizeof(islemler));

                    printf("------------------\nYapmak istediginiz islem giriniz\n------------------\nBakiye Sorgulama->bakiye\nPara cekme->cek\nPara yatirma->yatir\nHesaptan cik->cik\n------------------\n");

                    //fflush standart inputtaki "\n"yi temizlemek için kullanıldı
                    fflush(stdin);

                    //fgets() Fonksiyonunu kullanarak kullancıdan input alınıyor. strcspn() fonksiyonu ile inpu sonundaki "\n" karakteri gideriliyor
                    fgets(komut,sizeof(komut)+1,stdin);
                    komut[strcspn(komut,"\n")] = 0;

                    //Aşağıdaki döngü ile komutların hem büyük hem de küçük harfle yazılabilmesi sağlanıyor
                    int len = strlen(komut);
                    for (int i = 0; i < len; i++) {
                        komut[i] = tolower(komut[i]);
                    }

                    //Aşağıda if/else if/else komutlarıyla komuta göre işlemleri belirtiyoruz
                    if (!(strcmp(komut,"bakiye"))){

                        //Aşağıda  BakiyeSorgulama() fonksşyonu ile bakiyenin kullancı dosyasından okuyup yazılması sağlanıyor
                        BakiyeSorgulama(kullanci);

                        //strcat() ve gecmis() fonksiyonları kullanarak "gecmis.txt" dosyamıza işlem geçmişi yazılması sağlanıyor
                        strcat(islemler,kullanci);
                        strcat(islemler," bakiye sorgulama");
                        gecmis(islemler);
                    }

                    else if (!(strcmp(komut,"yatir"))){

                        //ParaYatırma() fonksiyonu geri dönüş olarak int değerinde yatırılan para mktarını veriyor. Onu saklamak içn int ve string formatındaki değişken belirlendi
                        int paraInt = ParaYatirma(kullanci);
                        char paraStr[6];

                        //sprintf() kullanılarak int değerindeki para miktarını string'e çevirip paraStr değişkenimizde saklıyor
                        sprintf(paraStr,"%d",paraInt);

                        //strcpy(), strcat() ve gecmis() fonksiyonları kullanarak "gecmis.txt" dosyamıza işlem geçmişi yazılması sağlanıyor
                        strcpy(islemler,kullanci);
                        strcat(islemler," ");
                        strcat(islemler, paraStr);
                        strcat(islemler,"TL yatirildi");
                        gecmis(islemler);
                    }

                    else if (!(strcmp(komut,"cek"))){

                        //ParaCekme() fonksiyonu geri dönüş olarak int değerinde cekilen para mktarını veriyor. Onu saklamak içn int ve string formatındaki değişken belirlendi
                        int paraInt = ParaCekme(kullanci);
                        char paraStr[6];

                        //strcpy(), strcat() ve gecmis() fonksiyonları kullanarak "gecmis.txt" dosyamıza işlem geçmişi yazılması sağlanıyor
                        sprintf(paraStr,"%d",paraInt);
                        strcpy(islemler,kullanci);
                        strcat(islemler," ");
                        strcat(islemler, paraStr);
                        strcat(islemler,"TL cekildi");
                        gecmis(islemler);

                    }
                    else if (!(strcmp(komut,"cik"))){

                        //strcat() ve gecmis() fonksiyonları kullanarak "gecmis.txt" dosyamıza işlem geçmişi yazılması sağlanıyor
                        strcat(islemler,kullanci);
                        strcat(islemler," cikis yapildi");
                        gecmis(islemler);

                        //break kullanarak döngüdün çıkamsını dolaysıyla programdan çıkması sağlanıyor
                        printf("------------------\nCikis basariyla yapildi\n");
                        break;
                    }
                    else

                        //Geçersiz komut yazıldığında programın uyarı vermesş sağlanıyor
                        printf("Gecerli komut giriniz!!");
                }


            }

        }
        else if (!(strcmp(komut,"olustur"))){

            //İlerde Hesapolusturma() fonksiyonu için gerekli parametre olacak  "kullanci" String(dizi) oluşturuldu
            char kullanci[50];
            Hesapolusturma(kullanci);

            //strcat() ve gecmis() fonksiyonları kullanarak "gecmis.txt" dosyamıza işlem geçmişi yazılması sağlanıyor
            strcat(islemler,kullanci);
            strcat(islemler," hesap olusturuldu");
            gecmis(islemler);
        }
        else

            //Geçersiz komut yazıldığında programın uyarı vermesş sağlanıyor
            printf("Gecerli komut giriniz(Turkce harfleri kullanmayin\n");



    }
    return 0;
}

