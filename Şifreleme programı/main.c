#include <stdio.h>
#include <ctype.h>

char sifreleme(char ch, int kayma) {
    if (isalpha(ch)) {  // isalpha ile girdideki her bir eleman�n ingilizce alfabenin bir eleman� olup olmad���n� kontrol ediyoruz
        char baslangicdegeri = islower(ch) ? 'a' : 'A';       
		/*burada girdideki her bir eleman�n b�y�k yada k���k harf olup olmad���na bak�yoruz. 
		Burada "a" ve "A" harflerini kullanarak base de�eri al�yoruz,
		b�ylece sonu� olarak bu ileriki sat�rlarda sonu�lar� ingilizce alfabenin bir eleman� olmas�n� sa�lamam�za yard�mc� oluyor.*/
        return ((ch - baslangicdegeri + kayma) % 26) + baslangicdegeri;  //Burada "baslangicdegeri"'ni kullanarak kayd�r�lan elemanlar� ingilizce alfabenin i�inde tutuyoruz.
    }
    return ch;
}

char cozme(char ch, int kayma) {
    if (isalpha(ch)) {
        char bitisdegeri = islower(ch) ? 'z' : 'Z'; 
		//sifreleme fonksiyonunda yap�lan �eyin biti�in ilerisini ba�lang�ca d�nd�rmek de�il, ba�lang�c�n gerisini biti�e d�nd�rme hali.
        return ((ch - bitisdegeri + kayma) % 26) + bitisdegeri;
    }
    return ch;
}


int main() {
	
	
    char girdi[] = "\nThe quick brown fox \n jumps over the lazy dog";
    int kayma = 3;
    int i = 0;
    //de�i�ken atama k�sm�.
    
   printf("Asil mesaj: %s\n \n ", girdi);
   
   
    for (; girdi[i] != '\0'; ++i) {
        girdi[i] = sifreleme(girdi[i], kayma);
    }
    //mesaj bu for d�ng�s�nde "sifreleme()" fonksiyonu arac�l��� ile �ifreleniyor.	

    printf("Sifrelenmis mesaj: %s\n \n ", girdi);
    
kayma=kayma*-1;
i=0;
  /*�ifreyi ��zmek i�in �ifrelenmi� kod �zerindeki kayma de�erinin tam tersini -1 ile �arparak buluyoruz. 
  for d�ng�s� i�inde kullan�lan "i" de�erini ba�ka bir for d�ng�s�nde kullanabilmek i�in 0'a e�itliyoruz.*/
  
  for(;girdi[i] != '\0'; ++i){
  	girdi[i] = cozme(girdi[i], kayma);
  }
  //Bu for d�ng�s�nde "cozme" fonksiyonu ile �ifrelenmi� mesaj� ��z�yoruz.
 
  printf("Sifresi cozulmus mesaj: %s ",girdi);

  

    return 0;
}
