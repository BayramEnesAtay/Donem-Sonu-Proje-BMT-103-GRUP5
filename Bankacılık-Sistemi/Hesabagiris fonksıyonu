//Bayram Enes Atay 23181616059
//Hesaba giris fonksıyonunun taslak halıdır.
#include<stdio.h>
#include<string.h>
#include<errno.h>
#include <ctype.h>

//kullanici ismini alarak dosyaya erısecem.
//giris basarili ise 1 degilse 0 dondurcem.
//sonra tek tek bilgileri istiyecem ve dosyadakilerle karsilastircam.
//ama dosaydan cekmek ıstersem ozel kelımeleri cekmem gerekıyo onu nasıl yapıcam?



int Hesabagiris(char kullanici[]);

int main()
{
    char kullanici[50];

    printf("On kosul olarak lutfen isim ve soyisim giriniz(kucuk harfle ve bitisik olarak):");
    scanf("%s",&kullanici);

    Hesabagiris(kullanici);
    return 0;


}

int Hesabagiris(char kullanici[])
{
    int len = strlen(kullanici);
    for (int i = 0; i < len; i++) {
        kullanici[i] = tolower(kullanici[i]);
    }


    struct Hesabagiris{

        char isim[20];
        char soyisim[20];
        int sifre;

    };

    char satir1[50],satir2[50],satir3[50];
    int sonuc;

    struct Hesabagiris hesap;

    FILE *giris;

    kullanici[strcspn(kullanici, "\n")] = 0;

    giris=fopen(strcat(kullanici,".txt"),"r");

    if(giris==NULL)
    {
        perror("Error");
        printf("Error number = %d",errno);
    }
    else{

        printf("Isminizi giriniz:");
        fgets(hesap.isim,20,stdin);

        hesap.isim[strcspn(hesap.isim,"\n")]=0;

        while((fgets(satir1,sizeof(satir1),strcat(kullanici,".txt")))!=NULL)
        {
            char *kelime=strtok(satir1," ");

            while(kelime!=NULL)
            {
                if((strcmp(kelime,hesap.isim))==0)
                {
                    printf("Dogru girdiniz.\n");break;
                }

                kelime=strtok(NULL," ");


            }


        }

        printf("Soyisminizi giriniz:");
        scanf("%s",&hesap.soyisim);



        fseek(giris, 0, SEEK_SET);

        while((fgets(satir2,sizeof(satir2),strcat(kullanici,".txt")))!=NULL)
        {
            char *kelime2=strtok(satir2," ");

            while(kelime2!=NULL)
            {
                if((strcmp(kelime2,hesap.soyisim))==0)
                {
                    printf("Dogru girdiniz.\n");break;
                }

                kelime2=strtok(NULL," ");


            }
        }
        fclose(giris);
    }
}
