
//Bayram Enes Atay 23181616059
//Muhammed Ali Atik 23181616601
//Para cekme fonksiyonu.

#include<stdio.h>
#include<stdlib.h>//Fonksiyon icin gerekli olan kutuphaneler tanimlanmistir.
#include<errno.h>
#include<string.h>

//Bu satır, "ParaCekme" adında bir fonksiyon tanımlar. Bu fonksiyon, kullanici2 adli char dizisini parametre olarak alir ve geri donus turu integerdir.
int ParaCekme(char kullanici2[])
{
    FILE *belge;
    int i;
    char sira[30];
    int bakiye2;
    int cekilenpara;

//Bu satır, kullanıcı2 nin adıyla aynı ada sahip bir dosyayı "r" modunda açar. "r" modu, dosyanın yalnızca okunabilir olduğunu belirtir.
    belge=fopen(kullanici2,"r");

    // Bu satır, dosyanın bulunup bulunmadigini kontrol eder. Dosya bulunamazsa, bir hata mesajı yazdırılır ve fonksiyon sona erer.
    if(belge==NULL)
    {
        perror("Error");
        printf("Error number:%d\n",errno);
    }

    //Dosya bulunursa, aşağıdaki işlemler gerçekleştirilir:    
    else
    {
        //Bu döngü, dosyadaki ilk 5 satırı okur ve "sira" dizisine atar.
        for(i=0;i<5;i++)
        {
            fgets(sira,sizeof(sira)+1,belge);
            sira[strcspn(sira,"\n")]=0;
        }

        //Bu satır, dosya okuma işaretçisini bulundugu konumda bırakır.
        fseek(belge, 0, SEEK_CUR);
        //Bu satır, "sira" dizisindeki 5. öğeyi (bakiye) tamsayıya dönüştürür ve "bakiye2" değişkenine atar.
        sscanf(sira,"%*s%*c%*c%*c%d%*c%*s",&bakiye2);

        printf("Cekmek istediginiz toplam parayi giriniz:");
        scanf("%d",&cekilenpara);
        
//Bu satır, çekilen paranın bakiyeden fazla olup olmadığını kontrol eder. Eğer fazlaysa, "Yetersiz Bakiye!!" mesajı yazdırılır.
        if(cekilenpara>bakiye2)
        {
            printf("Yetersiz Bakiye!!\n");

        }
            //Bu satır, çekilen paranın bakiyeden az veya eşit olup olmadığını kontrol eder. Eğer az veya eşitse, aşağıdaki işlemler gerçekleştirilir.
        else if(cekilenpara<=bakiye2)
        {
            //Bu satır, bakiye2 den çekilen parayı çıkarır.
            bakiye2 -=cekilenpara;
            //Güncel bakiyeyi ekrana yazdırır.
            printf("Yeni Bakiye:%d TL\n",bakiye2);

            //Bu satır, dosyadaki ilk 4 satırı saklamak için dört dizi tanımlar.
            char cumlee[30],cumlee2[30],cumlee3[30],cumlee4[30];
            //Bu satır, dosya okuma isaretcisini dosyanın başına getirir.
            fseek(belge,0,SEEK_SET);

            //Bu satır, dosyadaki ilk satırı okur ve "cumlee" dizisine atar.
            fgets(cumlee,30,belge);
            //Bu satır, "cumlee" dizisindeki \n(yeni satir) karakterini siler.
            cumlee[strcspn(cumlee,"\n")]=0;
            fgets(cumlee2,30,belge);
            cumlee2[strcspn(cumlee2,"\n")]=0;
            fgets(cumlee3,30,belge);
            cumlee3[strcspn(cumlee3,"\n")]=0;
            fgets(cumlee4,30,belge);
            cumlee4[strcspn(cumlee4,"\n")]=0;
            // Bu satır, "belge" dosyasını kapatır.
            fclose(belge);

            //Bu satır, "yenibelge" adında bir FILE(dosya) türünde pointer tanımlar.
            FILE *yenibelge;

            //Bu satır, kullanıcının adıyla aynı ada sahip bir dosyayı "w" modunda açar. "w" modu, dosyanın üzerine yazılabilir olduğunu belirtir.
            yenibelge=fopen(kullanici2,"w");

            //Bu satır, dosyanın açılıp açılmadığını kontrol eder. Dosya açılamazsa, bir hata mesajı yazdırılır ve fonksiyon sona erer.
            if(yenibelge==NULL)
            {
                perror("Error");
                printf("Error number:%d\n",errno);
            }
                //Dosya açılabilirse, aşağıdaki işlemler gerçekleştirilir:
            else
            {
                //Bu satır, "cumlee" dizisini "yenibelge" dosyasına yazar.
                fprintf(yenibelge,"%s\n",cumlee);
                fprintf(yenibelge,"%s\n",cumlee2);
                fprintf(yenibelge,"%s\n",cumlee3);
                fprintf(yenibelge,"%s\n",cumlee4);
                //Bu satır, güncellenmiş bakiyeyi "yenibelge" dosyasına yazar.
                fprintf(yenibelge,"Bakiye : %d TL",bakiye2);
                //Bu satır, "yenibelge" dosyasını kapatır.
                fclose(yenibelge);

            }
        }
    }
    //Bu satır, "cekilenpara" değişkeninini fonksiyondan döndürür.
    return cekilenpara;
}

