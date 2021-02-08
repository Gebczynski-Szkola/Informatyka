/* napisz generator 5000 hasel
 hasla skladaj¹ siê z ma³ych liter
 maj¹ dlugoœæ od 3 do 10 znaków
 hasla zapisz do pliku hasla.txt i nakoñcu pliku zapisz odpowiedzi do pytañ
 podaj  :
 1)ile ma parzyst¹ dlugoœæ
 2)ile jest palindromami
 3)ile ma takie same litery obok siebie
 4) hasla z najwiêsz¹ iloœci¹ powtórzonego znaku
    jeœli jest wiêcej o takiej samej iloœæi powtórzeñ podaj pierwsze haslo  i
    iloœæ hasel z tak¹ sama iloœci¹ powtórzen
*/


#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <time.h>

using namespace std;

string hasla[5000];

bool czyParzystaDlugosc(string haslo){  //dop
    int lenght = haslo.size();
    if ((lenght%2)==0){
        return true;
    }
    else{
      return false;
    }
}

bool czyPalindrom(string haslo){
	int i=0, j = (haslo.size()-1);
	while(i<j){
		if(haslo[i]!=haslo[j]){
      return false;
    }
		else{
        ++i;
    		--j;
      }
}
	return true;
}

bool czyTakieSameZnakiObok(string haslo){  //db
  for(int i=0; i<haslo.size(); i++){
    int znak = haslo[i];
    if(znak == haslo[i+1]){
      return true;
    }
  }
  return false;
}

int ilePowtorzenZnaku(string haslo){  //bdb
    char znak;
    int powtorzenia=0;
    char sprawdzenie;
	for (int i=0; i<(haslo.size()-1); i++){
	    znak=haslo[i];
	    for (int j=0; j<(haslo.size()-1); j++){
                sprawdzenie=haslo[j];
            if((sprawdzenie==znak)&&(i!=j)){
                powtorzenia++;
            }
	    }
    return powtorzenia;
}
}


int main(int argc, char const *argv[]){
    fstream plikHasla;
    plikHasla.open("hasla.txt",ios::out);
    srand(time(NULL));
    for(int i = 0 ; i < 5000 ; i++){
        string haslo ="";
        int dl = rand()%8+3;
        for ( int z = 0 ; z < dl ;z++){
           int litera =  rand()%26;
           int kodASCII = litera + 97;
           char znak = (char)kodASCII;
           haslo = haslo + znak;
        }
        hasla[i]=haslo;
        plikHasla << haslo << endl;
    }
    plikHasla.close();
    plikHasla.open("hasla.txt",ios::in);

    string haslo;
    int ileParzystych = 0;
    int ilePalindromow = 0;
    int ileTakieSameZanakiObok = 0;
    string hasloZaNajwPowt = "";
    int powtorzeniawtymhasle = 0;
    int ilehasloZaNajwPowt = 0;



    while (plikHasla >> haslo){
     std::cout << haslo << std::endl;
       if( czyParzystaDlugosc(haslo)==true ) ileParzystych++;
       if (czyPalindrom(haslo)) ilePalindromow++;
       if (czyTakieSameZnakiObok(haslo)==true) ileTakieSameZanakiObok ++;

       if (ilePowtorzenZnaku(haslo)>powtorzeniawtymhasle){
            powtorzeniawtymhasle = ilePowtorzenZnaku(haslo);
            hasloZaNajwPowt=haslo;
            ilehasloZaNajwPowt=1;
        }
        else if (ilePowtorzenZnaku(haslo)==powtorzeniawtymhasle) ilehasloZaNajwPowt++ ;
    }
    cout<<"_______________________________________________________"<<endl;
    cout<<"Ilosc parzystych: "<<ileParzystych<<endl;
    cout<<"_______________________________________________________"<<endl;

    cout<<"Ilosc palindromow: "<<ilePalindromow<<endl;
    cout<<"_______________________________________________________"<<endl;

    cout<<"Ilosc takich samych obok: "<<ileTakieSameZanakiObok<<endl;
    cout<<"_______________________________________________________"<<endl;

    cout<<"Haslo z najwieksza iloscia powtorzen: "<<hasloZaNajwPowt<<endl;
    cout<<"_______________________________________________________"<<endl;

    return 0;
}
