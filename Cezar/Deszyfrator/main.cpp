#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string deszyfrCezar(string tekst , int prz ){
    string szyfr=" ";
    for (int i = 1; i < tekst.length(); i++)
    {
        char znak  = tekst[i];  // odczytanie pojedyjczego znaku
        if (znak == '_')
           szyfr = szyfr+' ';
        else
        {
            int kod = (int)znak;   // konwersja na kod
            kod = kod - (int)'a';   // odjecia kodu znaku a by mieć nr litery z alfabetu
            kod = kod - prz; // przesuniecie o klucz
            kod  = kod % 26; // zwijamy za literą z na a
            if(kod<0){
              kod = kod+26;
            }
            kod = kod + (int)'a';  /// dodanie kodu znaku a by wrócic na kody ascii
            znak = (char)kod;     // konwersja na znak ASCII
            szyfr=szyfr+znak;
        }
    }
    return szyfr;
}

int main(int argc, char const *argv[])
{
    fstream wynik;
    wynik.open("wynik.txt",ios::in);
    while (!wynik.eof())
    {
       string slowo;
       int klucz ;

       wynik >> klucz;
       getline(wynik,slowo);

       cout <<klucz<< " - " << slowo << endl;
       cout << deszyfrCezar(slowo,klucz)<< endl;

    }
    wynik.close();

    return 0;
}
