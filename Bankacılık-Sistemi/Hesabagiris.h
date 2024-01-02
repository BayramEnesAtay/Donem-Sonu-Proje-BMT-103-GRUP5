//Bayram Enes Atay 23181616059
//Hesaba giris fonksıyonudur.
#include<stdio.h>
#include<errno.h>
#include<string.h>//Fonksiyon icin gerekli olan kutuphaneler burada tanimlanmistir.
#include <ctype.h>
#include<stdlib.h>

int Hesabagiris(char kullanici[])//Geri donus turu olarak integer olan ve parametre olarak kullanici adli char turunde bir dizi alan fonksiyon tanimlanmistir.
{

    struct Hesabagir{//Hesaba gir adinda yapi(structer) tanimlanmistir ve bu yapi kullanicinin isim,soyisim ve sifresini char turunde bir dizi olarak saklar.

        char isim[20];
        char soyisim[20];
        char sifre[4];

    };
    struct Hesabagir hesap;//Turu struct Hesabagir olan hesap adinda bir degisken tanimlanmistir.
    char satir1[30];
    char satir2[30];//Turu char olan 3 tane satir dizileri tanimlanmistir.
    char satir3[30];
    int sayac=0,i,sayac2=0,sayac3=0;//Turu integer olan 4 tane degisken tanimlanmis ve 3 tanesine ilk degerleri atanmistir.

    FILE *giris;//Bu satir dosya(FILE) turunde ismi giris olan bir pointer tanimlar.
    giris=fopen(strcat(kullanici,".txt"),"r");// Bu satirda,strcat fonksıyonu gerekli olan parametreler(kullanici adli dizi,".txt") ile kullanilarak
    // giris pointeri ile dosyayi"r"(okuma) modunda acilmistir.

    if(giris==NULL) // Burada dosyanin acilip acilmadigini kontrol eder.
    {
        perror("Error"); // Error numarasi ve Error turu ekrana yazdirilmistir.
        printf("Error number:%d",errno);
    }
    else {


        printf("------------------\nIsminizi giriniz(Buyuk-kucuk harflere dikkat edin):");
        fgets(hesap.isim, sizeof(hesap.isim),stdin);
        //fgets fonksiyonu ile kullanicidan isim alinmistir.//fgets fonksiyonu parametre olarak verinin aktarilacagi bir dizi veya degisken,maximum karakter
        //sayisi,dosya akisi alarak dizi veya degiskene kopyalar.
        
        //fgetsle aldigimiz bilgilerde fgets kendisi satir sonuna otomatikman '\n'(yeni satir karakteri) ekler.
        //Asagidaki satirda ise strcspn fonksiyonu ile sondaki '\n'(yeni satir karakteri) hesap.isim dizisinden cikarilmistir.
        //strcspn fonksıyonu iki tane parametre alir.Bunlardan ilki bir string ikincisi ise karakter kumseidir.
        // Ve 2.parametrenin 1.parametre icindeki yerini(indis olarak) geri dondurur.Eger stringin icinde o karakter kumesi yoksa stringin uzunlugunu dondurur.
        hesap.isim[strcspn(hesap.isim,"\n")] = 0;
        
        char*kelime1,*kelime2;
        //Char turunde kelime1 ve kelime2 adli pointerlar tanimlanmistir.
        kelime1=strtok(hesap.isim," ");
        //Bu satirda strtok fonksıyonu ile hesap.isim adli diziyi " "(bosluk) karakterine gore ayrilmis ve kelime1 adli pointera atanmistir.
        kelime2=strtok(NULL," ");
        //Bu satirda strtok fonksıyonu ile hesap.isim adli dizinin geri kalan kisimlari " "(bosluk) karakterine gore ayrilmis ve kelime2 adli pointera atanmistir.
        //strtok fonksiyonu karakter dizisini sirali parcalara ayirmak icin kullanilir.Parametre olarak parcalanacak olan string ve ayrac alir.
        //Daha sonraki cagrilarda bu parametreye NULL verilerek ayni karakter dizisi uzerinde gezinmeye devam eder.
        if(kelime2==NULL) //Bu satir hesap.isim dizisinde ikinci bir kelime olup olmadigini kontrol eder.Ikinci kelime yoksa asagidaki islemler gerceklestirilir.
        {
            strcpy(hesap.isim,kelime1);
            //strcpy fonksiyonu ile kelime1 adli char pointeri hesap.isim adli degiskene kopyalanmistir.
            //strcpy fonksıyonu(string copy), 2 string parametre alarak 2.parametreyi 1. parametreye kopyalar.
        }   
        else{
            strcat(kelime1,kelime2);
            // strcat fonkiyonu parametre olarak iki string(karakter dizisi) alir ve iki karakter dizisini birlestirip 1.parametreye dondurur.
            //Ustteki satirda ise kelime1 ve kelime2 adli char pointerlari strcat ile birlestirilerek kelime1 pointerina dondurulmustur.
            strcpy(hesap.isim,kelime1);
            //Burada ise strcpy fonksiyonu ile kelime1 isimli char pointeri hesap.isim adli diziye kopyalanmistir.
        }
        // fgets ile giris pointerina ordan da dosyaya ulasarak dosyadan maksimum 30 karakterlik satir alinarak satir1 dizisine aktarilmistir.
        //Ve bu islem dosyanin sonuna gelene kadar donguye alinmistir.
        while (fgets(satir1, 30, giris) != NULL) {
            
            //Asagidaki satirda strcspn fonksiyonu ile sondaki '\n'(yeni satir karakteri) satir1 dizisinden cikarilmistir.
            satir1[strcspn(satir1, "\n")] = 0;
            // kelime adli char turunde bir pointer tanimlanmistir.strtok fonksiyonu ile satir1 dizisi " "(bosluk) karakterine gore ayrilmistir.
            char *kelime = strtok(satir1, " ");
            // satir sonuna gelinesiye kadar(kelime degeri NULL oluncaya kadar) donguye alinmistir.
            while (kelime != NULL) {
                //strcmp(string compare) fonksiyonu ile hesap.isim ile kelime karsilastirilmis ve sonuc "0" ise karar yapisinin icine girilmesi saglanmistir.
                //strcmp fonksiyonu aldigi iki string parametrelerini karsilastirir ve ayni ise "0" degerini dondurur.
                if (strcmp(kelime, hesap.isim) == 0) {
                    printf("------------------\nDogru girdiniz.\n");
                    sayac3+=1;
                }
                kelime = strtok(NULL, " ");
                // Kalan kisim strtok ile " "(bosluga) gore ayrilmistir.
            }
        }
        if(sayac3==0)
        {
            printf("------------------\nYanlis girdiniz.\n");
            fclose(giris);//Dosya fclose fonksiyonu ile kapatilmistir.
            return 0;
        }
        fseek(giris, 0, SEEK_SET);// fseek fonksiyonu icindeki parametreler ile baslangic noktasini dosyanin basina alir.

        printf("------------------\nSoyisminizi giriniz(Buyuk-kucuk harflere dikkat edin):");
        fgets(hesap.soyisim, sizeof(hesap.soyisim),stdin);//sizeof() operatoru , icine yazilan verinin bellekte ne kadar yer kapladigini gosterir.
        hesap.soyisim[strcspn(hesap.soyisim,"\n")] = 0;
        //fgetsle alindigi icin strcspn fonksiyonu ile "\n" karakteri hesap.soyisim den cikarilmistir.

        // fgets ile giris pointerindan dosyaya ulasarak maksimum 30 karakter alinarak satir2 ye aktarilmistir ve dosyanin sonuna gelinene kadar donguye alinmistir.
        while (fgets(satir2, 30, giris) != NULL) {
            satir2[strcspn(satir2, "\n")] = 0;//satir2 dizisinden "\n" karakteri strcspn fonk. ile cikarilmistir.
            char *kelime3 = strtok(satir2, " ");
            while (kelime3 != NULL) {
                //strcmp fonksiyonu ile kelime3 ve hesap.soyisim degeri ayni olup olmadigi karsilastirilmistir.
                if (strcmp(kelime3, hesap.soyisim) == 0) {
                    printf("------------------\nDogru girdiniz.");
                    sayac+=1;
                }
                kelime3 = strtok(NULL, " ");
            }
        }
        if(sayac==0)
        {
            printf("Yanlis girdiniz.");
            fclose(giris);//Dosya fclose ile kapatilmistir.
            return 0;
        }
        fseek(giris, 0, SEEK_SET);//fseek fonksiyonu ile baslangic noktasi Dosyanin basina getirilmistir.

        printf("\n------------------\nSifrenizi giriniz:");
        fgets(hesap.sifre,sizeof(hesap.sifre)+1,stdin);
        hesap.sifre[strcspn(hesap.sifre,"\n")] = 0;
        //hesap.sifre dizisinden strcspn fonksiyonu ile "\n" (yeni satir karakteri) cikarilmistir.


        
        while(fgets(satir3,30,giris)!=NULL)
        {
            satir3[strcspn(satir3,"\n")]=0;
            char*kelime4=strtok(satir3," ");
            //kelime4 degeri NULL olasiya kadar yani satir sonuna ulasilana kadar while ile donguye alinmistir.
            while(kelime4!=NULL)
            {
                if(strcmp(kelime4,hesap.sifre)==0) {
                    printf("------------------\nDogru girdiniz.");
                    sayac2+=1;
                    printf("\n------------------\nHesaba basarili bir sekilde giris yapildi!!\n");
                    return 1;
                }
                kelime4=strtok(NULL," ");
                //strtok ile satirin kalani ayrilmistir.
            }

        }
        if(sayac2==0)
        {
            printf("------------------\nYanlis girdiniz.");
            printf("\n------------------\nHesaba giris yapilamadi!!\n");
            fclose(giris);//fclose ile dosya kapatilmistir.
            return 0;
        }
    }
}
