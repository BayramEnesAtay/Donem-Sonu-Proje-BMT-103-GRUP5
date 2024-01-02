//Bayram Enes Atay 23181616059
//Hesap Olusturma fonksiyonu.
#include<stdio.h>
#include<string.h>//Fonksiyon icin gerekli olan kutuphaneler tanimlanmistir.
#include <ctype.h>

//Geri donus degeri olmayan(void) ,parametre olarak char turunde dosyaisminde bir dizi alan Hesapolustuma adinda bir fonksiyon tanimladik.
void Hesapolusturma(char dosyaismi[50]) {
    int sifre2;

    struct hesap {
        char isim[20];
        char soyad[20];//hesap etiket isimli yapi tanimlanmistir.Bu yapi(structer) 4 tane degisken tutar.
        int sifre;
        int bakiye;

    };
    //FILE turunde dosya isimli bir pointer tanimlanmistir.
    FILE *dosya;
    //struct hesap turunde hesap1 degiskeni tanimlanmistir.
    struct hesap hesap1;

    printf("------------------\nHesabinizin bankada var olabilmesi icin oncelike isim ve soyisim giriniz(bitisik olarak):");
    //fgets kullanilarak standartinput(klavyeden) deger alinmis ve dosyaismi adli diziye aktarilmistir.
    fgets(dosyaismi, 51,stdin);
    dosyaismi[strcspn(dosyaismi,"\n")] = 0;
    //dosyaismi dizisi fgetsle alindigi icin sonuna otomatikman "\n" karakteri ekleniyor.
    //Bize sorun cikarmamasi icin strcspn fonksiyonu ile "\n" karakterinin indisi bulunup "0" a esitleniyor.
    fflush(stdin);
    //Dosyaya yazdirdigimiz degerler hemen dosyaya gitmez.Once gecici bir sure bellekte durur bizim buffer dedigimiz yerde.
    //Bu fflush fonksiyonu ise aninda buffer i bosaltir ve verilerin aninda dosyaya yazilmasini saglar.

    int len = strlen(dosyaismi);
    for (int i = 0; i < len; i++)
        dosyaismi[i] = tolower(dosyaismi[i]);
    //Yukaridaki kod parcasi stringlerin her harfini kucuk harfe cevirmek icin kullanilir.

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
                kelime2="";//Eger kullanici tek isimli ise kelime2 null degerine atanmasin diye "" olarak aldim.
            }

            printf("------------------\nSoyismini giriniz(buyuk kucuk harfe dikkat edin):");
            scanf("%s",&hesap1.soyad);
            printf("------------------\nHesaba giris sifrenizi belirleyiniz(4 haneli):");
            scanf("%d", &hesap1.sifre);
            //Girilen sifrenin 4 haneli olmasini istedigimiz icin asagidaki gibi bir donguye aldik.
            while (hesap1.sifre < 999 || hesap1.sifre > 9999) {
                //Girilen sifre 4 haneli olasiya kadar tekrar tekrar sifre isteyecektir. 
                printf("------------------\nSifrenizin 4 haneli olmasi gerekir,lutfen 4 haneli sifre giriniz:");
                scanf("%d", &hesap1.sifre);
            }
            //Sifreyi onaylamak icin tekrar sifreyi girmenizi istiyoruz.
            printf("------------------\nSifrenizi tekrar girerek onaylayiniz lutfen:");
            scanf("%d", &sifre2);
            //Eger girdiginiz sifre onceki sifreyle uyusmassa dogru giresiye kadar donguye alir.
            while (hesap1.sifre != sifre2) {
                printf("------------------\nUYARI!! Sifreyi yanlis girdiniz, tekrar giriniz:");
                scanf("%d", &sifre2);
            }
            //Bakiye degerini Hesap yeni olusturuldugu icin 0 Tl olarak aldik.
            printf("Bakiye = 0 TL\n");
            printf("------------------\nIslem basarili,Hesabiniz olusturuldu\n");

            
            fprintf(dosya, "Hesap Bilgisi\nIsim : %s%s\nSoyisim : %s\nSifre : %d\nBakiye : 0 TL",kelime1,kelime2,hesap1.soyad, hesap1.sifre);
            //Alinan degerler fprintf fonksiyonu yardimiyla dosyaya yazdirilmistir.
            //fprintf fonksiyonu 2 parametre alir,bu parametrelerden ilki dosyayi tutan pointerdir.Ikincisi ise yazdirilmak istenen verilerdir.

            //fclose ile dosya kapatilmistir.
            fclose(dosya);
            fflush(stdin);//fflush bufferi bosaltarak verilerin dosyaya aninda yazdirilmasini saglar.
        }

    }
