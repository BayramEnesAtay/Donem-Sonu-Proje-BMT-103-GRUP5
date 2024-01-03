//Muhammed Ali Atik 23181616601
//Bakiye sorgulama fonksiyonu hazirlanmistir.

#include<stdio.h>        // Bu satirlar, programin derlenmesi icin gerekli olan iki kütüphaneyi dahil eder.
#include<stdlib.h>

void BakiyeSorgulama(char kullanici[50]) {  //Bu satir, "BakiyeSorgulama" adinda bir fonksiyon tanımlar. Bu fonksiyon, kullanicinin bakiyesini sorgulamak icin kullanilir. Fonksiyon, "kullanici" adinda bir parametre alir. Bu parametre, kullanicinin adini  ve soyadini iceren bir dizidir.
    char dosya_adi[100];  //Bu satir, "dosya_adi" adinda bir dizi tanimlar. Bu dizi, kullanicinin dosya adini saklamak icin kullanilir.


    snprintf(dosya_adi, sizeof(dosya_adi), "%s", kullanici);   //Bu satir, "kullanici" dizisinin icerigini "dosya_adi" dizisine kopyalar.
    FILE *dosya = fopen(dosya_adi, "r");  //Bu satir, "dosya_adi" adli dosyayi "r" modunda acar. "r" modu, dosyanin yalnizca okunabilir oldugunu belirtir.
    if (dosya == NULL) {    //Bu satir, dosyanin acilip acilmadigini kontrol eder. Dosya acilamazsa, "Dosya acilamadi!" mesaji yazdirilir.
        printf(dosya_adi);
        printf("------------------\nDosya acilamadi!\n");

    }
    else{
    int bakiye;  // Bu satir, "bakiye" adinda bir tamsayi degiskeni tanımlar. Bu degisken, kullanicinin bakiyesini saklamak icin kullanilir.
    char satir6[30];  //Bu satir, "satir6" adinda bir dizi tanımlar. Bu dizi, dosyadan okunan satirlari saklamak icin kullanilir.
    for (int i = 1; i <= 5; i++) {  //Bu dongu, dosyadaki ilk 5 satiri okur.
        fgets(satir6, 30, dosya);  //Bu satir, "dosya" dosyasindan bir satir okur ve "satir6" dizisine kopyalar.
        if (i == 5) {  //Bu satir, dongunun son satirina geldiginde "satir6" dizisinin icerigini yazdirir.
            printf("------------------\n%s\n", satir6);
            break;
        }
    }
    }
    fclose(dosya);  //Bu satir, "dosya" dosyasini kapatir.


}
