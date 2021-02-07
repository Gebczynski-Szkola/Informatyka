/* napisz generator 5000 hasel
 hasla skladają się z małych liter
 mają dlugość od 3 do 10 znaków
 hasla zapisz do pliku hasla.txt i nakońcu pliku zapisz odpowiedzi do pytań
 podaj  :
 1)ile ma parzystą dlugość
 2)ile jest palindromami
 3)ile ma takie same litery obok siebie
 4) hasla z najwięszą ilością powtórzonego znaku
    jeśli jest więcej o takiej samej ilośći powtórzeń podaj pierwsze haslo  i
    ilość hasel z taką sama ilością powtórzen
*/


#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;
bool czyParzystaDlugosc(string haslo){  //dop
  int lenght = haslo.size();
   if ((lenght%2)==0){
       return true;
   }
   else return false;
}

bool czyPalindrom(string haslo){  //dst
  int i=0, j = (haslo.size()-1);

	while(i<j)
	{
		if(haslo[i]!=haslo[j])
			return false;
		++i;
		--j;
	}
	return true;
}
bool czyTakieSameZnakiObok(string haslo){  //db

}
int ilePowtorzenZnaku(string haslo){  //bdb

}


int main(int argc, char const *argv[])
{
    fstream plikHasla;
    plikHasla.open("hasla.txt",ios::out);
    srand(time(NULL));
    for(int i = 0 ; i < 5000 ; i++){
        string haslo ="";
        int dl = rand()%8+3;
        //cout << dl << endl;
        for ( int z = 0 ; z < dl ;z++){
           int litera =  rand()%26;   // losowoanie nr litery
           int kodASCII = litera + 97;   // poprawka na kody ascii - dodaje kod litery 'a'
           char znak = (char)kodASCII;   // kowersja na znak ASCII
           //cout << znak << endl;
           haslo = haslo + znak;
        }
      //  cout << haslo << endl;
        plikHasla << haslo << endl;
    }
    plikHasla.close();
    // statystyka
    plikHasla.open("hasla.txt",ios::in);
   /* while (!plikHasla.eof())
    {
       string haslo;
       plikHasla >> haslo;
       std::cout << haslo << std::endl;
    }
     */
    string haslo;
    int ileParzystych = 0;
    int ilePalindromow = 0;
    int ileTakieSameZanakiObok = 0;
    string hasloZaNajwPowt = "";
    int ilehasloZaNajwPowt = 0;
    while (plikHasla >> haslo){
       std::cout << haslo << std::endl;
       if( czyParzystaDlugosc(haslo) ) ileParzystych++;
       if (czyPalindrom(haslo)) ilePalindromow++;
       if (czyTakieSameZnakiObok(haslo)) ileTakieSameZanakiObok ++;
       /*
            sprawdzic ile powtorzen znaków ma biezące analizowane haslo i porównać
            z ilością powtórzen w haślie obecnie zapemiętanym w hasloZaNajwPowt
            jeśli ma ich więcej to zastąpić zawartość zmiennej  hasloZaNajwPowt biezacym haslem i
            ustawić ilehasloZaNajwPowt na jeden
            jeśli tyle samo to zwiększyć wartość ilehasloZaNajwPowt
            jeśli mniej to iśc do nastepnego hasła
       */


    }


    return 0;
}
