//Abdülselam İsmail 23181616010
//Bu pragramımızda yapılan işlemleri zaman ve tarihi ile bir dosyaya yazılması sağlanıyor

//ilk önce gereken header dosyalar eklendi
#include <stdio.h>
#include <stdlib.h>
#include <time.h>





//Burda gecmis() fonksiyonumuz tanımlandı
void gecmis(char *islem[100]) {

    //<time.h> header' ait olan time_t şeklinde "zaman" belirledik
    //Ve ona time() fonksiyonu kullanarak zaman değerini veriyoruz
    time_t zaman = time(NULL);

    //ctime() fonksiyonu kullanarak zaman değerimizi okunabilir hale getiriyoruz ve string_zaman string(karakter dizi)'ye atıyoruz
    char *string_zaman = ctime(&zaman);

    //Dosya ile işlem yapailmek gecmiş() pointeri tanımlandı
    FILE *gecmis;

    //gecmis pointerimize dosyanızı açıyoruz ve "w" kullanarak yazma metodu ile açıyoruz
    gecmis = fopen("gecmis.txt","w");

    //fprintf () kullanarak "gecmis.txt" dosyamıza parametre olan islem ile zaman ve tarihimizi yazıyoruz
    fprintf(gecmis, "\n%s: %s", islem, string_zaman);

    //fonksiyonumuz sonlandırmadan önce dosyamızı kapatılıyor
    fclose(gecmis);

}
