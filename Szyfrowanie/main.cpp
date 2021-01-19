#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string szyfrCezar(string tekst , int prz ){
    string szyfr="";
    for (int i = 1; i < tekst.length(); i++)
    {
        char znak  = tekst[i];  // odczytanie pojedyjczego znaku
        if (znak == ' ')
           szyfr = szyfr+'_';
        else
        {
            int kod = (int)znak;   // konwersja na kod
            kod = kod - (int)'a';   // odjecia kodu znaku a by mieć nr litery z alfabetu
            kod = kod + prz;      // przesuniecie o klucz
            kod  = kod % 26;      // zwijamy za literą z na a
            kod = kod + (int)'a';  /// dodanie kodu znaku a by wrócic na kody ascii
            znak = (char)kod;     // konwersja na znak ASCII
            szyfr=szyfr+znak;
        }
    }
    return szyfr;
}

int main(int argc, char const *argv[])
{
    fstream plik, wynik;
    plik.open("dane.txt",ios::in);
    wynik.open("wynik.txt",ios::out);
    while (!plik.eof())
    {
       string slowo;
       int klucz ;

       plik >> klucz;
       getline(plik,slowo);

       cout <<klucz<< " - " << slowo << endl;
       cout << szyfrCezar(slowo,klucz)<< endl;
       wynik <<klucz<< " " << szyfrCezar(slowo,klucz)<< endl;

    }

 /*   for(int i = 0 ; i < 255 ; i++){
        cout << i << " " << (char)i << endl;
    }
 */

    plik.close();
    wynik.close();

    return 0;
}
