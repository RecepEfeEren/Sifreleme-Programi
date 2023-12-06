#include <stdio.h>
#include <ctype.h>

char sifreleme(char ch, int kayma) {
    if (isalpha(ch)) {  // isalpha ile girdideki her bir elemanýn ingilizce alfabenin bir elemaný olup olmadýðýný kontrol ediyoruz
        char baslangicdegeri = islower(ch) ? 'a' : 'A';       
		/*burada girdideki her bir elemanýn büyük yada küçük harf olup olmadýðýna bakýyoruz. 
		Burada "a" ve "A" harflerini kullanarak base deðeri alýyoruz,
		böylece sonuç olarak bu ileriki satýrlarda sonuçlarý ingilizce alfabenin bir elemaný olmasýný saðlamamýza yardýmcý oluyor.*/
        return ((ch - baslangicdegeri + kayma) % 26) + baslangicdegeri;  //Burada "baslangicdegeri"'ni kullanarak kaydýrýlan elemanlarý ingilizce alfabenin içinde tutuyoruz.
    }
    return ch;
}

char cozme(char ch, int kayma) {
    if (isalpha(ch)) {
        char bitisdegeri = islower(ch) ? 'z' : 'Z'; 
		//sifreleme fonksiyonunda yapýlan þeyin bitiþin ilerisini baþlangýca döndürmek deðil, baþlangýcýn gerisini bitiþe döndürme hali.
        return ((ch - bitisdegeri + kayma) % 26) + bitisdegeri;
    }
    return ch;
}


int main() {
	
	
    char girdi[] = "\nThe quick brown fox \n jumps over the lazy dog";
    int kayma = 3;
    int i = 0;
    //deðiþken atama kýsmý.
    
   printf("Asil mesaj: %s\n \n ", girdi);
   
   
    for (; girdi[i] != '\0'; ++i) {
        girdi[i] = sifreleme(girdi[i], kayma);
    }
    //mesaj bu for döngüsünde "sifreleme()" fonksiyonu aracýlýðý ile þifreleniyor.	

    printf("Sifrelenmis mesaj: %s\n \n ", girdi);
    
kayma=kayma*-1;
i=0;
  /*Þifreyi çözmek için þifrelenmiþ kod üzerindeki kayma deðerinin tam tersini -1 ile çarparak buluyoruz. 
  for döngüsü içinde kullanýlan "i" deðerini baþka bir for döngüsünde kullanabilmek için 0'a eþitliyoruz.*/
  
  for(;girdi[i] != '\0'; ++i){
  	girdi[i] = cozme(girdi[i], kayma);
  }
  //Bu for döngüsünde "cozme" fonksiyonu ile þifrelenmiþ mesajý çözüyoruz.
 
  printf("Sifresi cozulmus mesaj: %s ",girdi);

  

    return 0;
}
