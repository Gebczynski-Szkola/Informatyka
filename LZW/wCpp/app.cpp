/*
 kompresor plików tekstowych algorytmem LZW
 wejście : plik tekstowy zawierający znaki alfabetu łacińskiego  oraz cyfry <A-Z><a-z><0-9>
 wyjście plik zawierający kody wynikowe z kompresji algorytmem LZW
*/

#include <fstream>
#include <iostream>

using namespace std;
fstream wejscie,wyjscie;

string *slownik;
int rozmiarSlownika;
int ileWslowniku;

bool otworzPliki(){
    string sciezkaWejscie , sciezkaWyjscie;
    cout << "Podaj nazwę pliku do kompresji: ";
   // cin >> sciezkaWejscie;
    cout << "Podaj nazwę pliku wynikowego: ";
   // cin >> sciezkaWyjscie;

  // sciezkaWejscie = "lzwdane.txt";     // do testów kompresji
  // sciezkaWyjscie = "lzwwynik.txt";

   sciezkaWejscie = "lzwwynik.txt";     // do testów dekompresji
   sciezkaWyjscie = "lzwdekompresja.txt";



    wejscie.open(sciezkaWejscie,ios::in);
    if(!wejscie.good()){
        cout << "Nie otwarto pliku wejściowego" << endl;
        return false;
    }
    wyjscie.open(sciezkaWyjscie,ios::out);
    if(!wyjscie.good()){
        wejscie.close();
        cout << "Nie otwarto pliku wyjsciowego" << endl;
        return false;
    }
    return true;
}
void inicjacjaSlownika(){
    cout << "Podaj rozmiar slownika min 62 :";
    cin >> rozmiarSlownika;
    slownik = new string[rozmiarSlownika];
    // <a-z><A-Z><0-9> (26+26+10)
    for (int i = 0; i < 26; i++)
    {
        slownik[i] = (char)(i+97);
        slownik[i+26] = (char)(i+65);
        if ( i < 10)
           slownik[i+26+26] = (char)(i+48);
    }
    ileWslowniku = 62;

    for (int i = 0; i < ileWslowniku; i++)
       cout << slownik[i] << " ";

    cout << "slownik gotowy" <<endl;

}
int wSlowniku(string C_S){
    for ( int i = 0 ; i < ileWslowniku ;i++){
        if (slownik[i]==C_S)
           return i;
    }
    return -1;
}
void kompresjaLZW(){
    string C;
    string S;
    string C_S;

    char znak ;
    wejscie >> znak;
    C = znak;

    //while(!wejscie.eof()){
    //    wejscie >> znak;
    while(wejscie >> znak){    // to rozwiazanie nie powoduje dwukratnej ananalizy ostatniego znaku z pliku
        S = znak;
        C_S = C+S;
        int kod = wSlowniku(C_S);
        if(kod>0)
        {
            C= C_S;
        }
        else
        {
            kod  = wSlowniku(C);
            slownik[ileWslowniku++]= C_S;
            C=S;
            wyjscie<<kod<<" ";

        }

    }
    wyjscie<<wSlowniku(C) << " ";


}

void dekompresjaLZW(){
// to do ;)

}

int main(int argc, char const *argv[])
{

 /*   if (!otworzPliki())  // blokuje/w komentarz do testów dekompresji
      return 0;
    cout << "czas na kompresję ;)"   << endl;
    inicjacjaSlownika();
    kompresjaLZW();

    wejscie.close();
    wyjscie.close();
*/
    cout << "czas na dekompresję ;)"   << endl;
    if (!otworzPliki())
      return 0;
    inicjacjaSlownika();
    dekompresjaLZW();


    return 0;
}
