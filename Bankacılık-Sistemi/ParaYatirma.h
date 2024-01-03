
//Bayram Enes Atay 23181616059
//Muhammed Ali Atik 23181616601
//ParaYatirma Fonksıyonu

// Programın derlenmesi için gerekli olan kütüphaneler.
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>

//Geri donus degeri integer olan ParaYatirma fonksiyonu tanımlandı ve parametre olarak char türünde kullanıcı dizisi alındı.
int ParaYatirma(char kullanici[])
{
    FILE *dosya;  //FILE(dosya) turunde ismi dosya olan bir pointer tanimlandi.
    int i;  //Döngüde kullanılacak olan i değişkeni integer türünde tanımlandı.
    char satir5[30]; //Char türünde satir5 dizisi tanımlandı.
    int bakiye;//Integer türünde bakiye değişkeni tanımlandı.
    int para; //Integer türünde para değişkeni tanımlandı.


//Bu satır kullanıcının adıyla aynı ada sahip bir dosyayı "r"(okuma)modunda açar.
    dosya=fopen(kullanici,"r");
//Dosyanın bulunup bulunmadigini kontrol eder.
    if(dosya==NULL)
    {
        perror("Error");
        printf("Error number:%d\n",errno);
    }
//Dosya bulunursa asagidaki islemler gerceklestirilir.
    else
    {
        //Bu döngü dosyadaki ilk 5 satırı okur ve "satir5" dizisine atar.
        for(i=0;i<5;i++)
        {
            fgets(satir5,sizeof(satir5)+1,dosya);
        }
        //Bu satır, dosya okuma işaretçisini bulundugu konumda bırakır.
        fseek(dosya, 0, SEEK_CUR);
        //Bu satır, "satir5" dizisindeki 5. öğeyi (bakiye) tamsayıya dönüştürür ve "bakiye" değişkenine atar.
        sscanf(satir5,"%*s%*c%*c%*c%d%*c%*s",&bakiye);
        //Kullanıcıdan yatırılacak olan para istenir.
        printf("Yatirmak istediginiz parayi giriniz:");
        //Kullanıcıdan alınan degeri "para" değişkenine atar.
        scanf("%d",&para);
//Bu satır bakiyeye yatırılacak parayı ekler.
        bakiye+=para;
        //Bu satır güncellenmiş bakiyeyi ekrana yazdırır.
        printf("Toplam bakiyeniz: %d TL\n",bakiye);
        
// Bu satır, dosya okuma işaretçisini dosyanın başına getirir.
        fseek(dosya,0,SEEK_SET);
        //Bu satır, dosyadaki ilk 4 satırı saklamak için dört dizi tanımlar.
        char cumle[30],cumle2[30],cumle3[30],cumle4[30];
        
//Dosyadaki ilk satırı okur ve "cumle" dizisine atar.
        fgets(cumle,30,dosya);
        //Bu satır, "cumle" dizisindeki \n(yeni satır) karakterini siler.
        cumle[strcspn(cumle,"\n")]=0;
        //Bu satır, dosyadaki ikinci satırı okur ve "cumle2" dizisine atar.
        fgets(cumle2,30,dosya);
        //Bu satır, "cumle2" dizisindeki \n(yeni satir) karakterini siler.
        cumle2[strcspn(cumle2,"\n")]=0;
        //Bu satır, dosyadaki üçüncü satırı okur ve "cumle3" dizisine atar.
        fgets(cumle3,30,dosya);
        //Bu satır, "cumle3" dizisindeki \n(yeni satir) karakterini siler.
        cumle3[strcspn(cumle3,"\n")]=0;
        //Bu satır, dosyadaki dördüncü satırı okur ve "cumle4" dizisine atar.
        fgets(cumle4,30,dosya);
        //Bu satır "cumle4" dizisindeki \n(yeni satir) karakterini siler.
        cumle4[strcspn(cumle4,"\n")]=0;
        //Bu satirda fclose fonksiyonu ile dosya kapatilir.
        fclose(dosya);

        FILE *dosya2;
        //FILE(dosya) türünde "dosya2"adında pointer tanımlanmıştır.
        dosya2=fopen(kullanici,"w");
        // Bu satır, kullanıcının adıyla aynı ada sahip bir dosyayı "w" modunda açar. "w" modu, dosyanın üzerine yazılabilir olduğunu belirtir.

        if(dosya2==NULL) //Bu satır, dosyanın açılıp açılmadığını kontrol eder. Dosya açılamazsa, bir hata mesajı yazdırılır ve fonksiyon sona erer.
        {
            perror("Error");
            printf("Error number : %d\n",errno);
        }
        else//Dosya açılırsa aşağıdaki işlemler gerçekleştirilir.
        {
            fprintf(dosya2,"%s\n",cumle);
            //Bu satır, "cumle" dizisini "dosya2" dosyasına yazar.
            fprintf(dosya2,"%s\n",cumle2);
            //Bu satır, "cumle2" dizisini "dosya2" dosyasına yazar.
            fprintf(dosya2,"%s\n",cumle3);
            //Bu satır, "cumle3" dizisini "dosya2" dosyasına yazar.
            fprintf(dosya2,"%s\n",cumle4);
            //Bu satır, "cumle4" dizisini "dosya2" dosyasına yazar.
            fprintf(dosya2,"Bakiye : %d TL",bakiye);
            //Bu satır, güncellenmiş bakiyeyi "dosya2" dosyasına yazar.
            fclose(dosya2);
            //Bu satirda fclose fonksiyonu ile dosya kapatilir.
        }
    }
    return para;
    //Bu satır, "para" değişkenini fonksiyondan döndürür.
}
