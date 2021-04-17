/*
 kompresor plików tekstowych algorytmem LZW
 wejście : plik tekstowy zawierający znaki alfabetu łacińskiego  oraz cyfry <A-Z><a-z><0-9>
 wyjście plik zawierający kody wynikowe z kompresji algorytmem LZW

 dodać znaki specjalne do programu
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
    cout << "Podaj nazwe pliku do de/kompresji: ";
    cin >> sciezkaWejscie;
    cout << "Podaj nazwe pliku wynikowego: ";
    cin >> sciezkaWyjscie;

  // sciezkaWejscie = "lzwdane.txt";     // do testów kompresji
  // sciezkaWyjscie = "lzwwynik.txt";

  // sciezkaWejscie = "lzwwynik.txt";     // do testów dekompresji
  // sciezkaWyjscie = "lzwdekompresja.txt";
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
    cout << "Podaj rozmiar slownika min 500 :";
    cin >> rozmiarSlownika;
    slownik = new string[rozmiarSlownika];
    // <a-z><A-Z><0-9> (26+26+10)
    for (int i = 0; i < 94; i++) // zwiekszenie liczby do 94 znaków, tyle jest znaków specjalnych, liter i cyfr 
    {
        slownik[i] = (char)(i+32); // znaki zaczynaja sie od 32
    }
    ileWslowniku = 94; // w słowniku jest 94 znaki

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
  /*  string slowo;
    string dwa;
    int index;
    index = 1;
    slowo = slownik[index];  // slownik -> [ala,kasia,as]    slowo <- kasia
    char znak = slowo[0];   // slowo -> kasia -> [k|a|s|i|a]     znak <- k

    znak = slownik[index][0];
    slownik[ileWslowniku++]=dwa+znak; <-> slownik[ileWslowniku++]=dwa+slownik[index][0];
    string scscs = slowo+slowo[0];
    */

   int pk ,k ;
   string pc , scscs;
   wejscie >> pk;
   wyjscie << slownik[pk];
   while(wejscie >> k ){
       pc = slownik[pk];
       if ( k < ileWslowniku) { //dodaj do słownika pc + pierwszy symbol ciągu słownik[k]),
                                //a na wyjście wypisz cały ciąg słownik[k].
        slownik[ileWslowniku++] = pc +slownik[k][0];
        wyjscie << slownik[k];
       }
       else{
         slownik[ileWslowniku++] = pc+pc[0]  ;
         wyjscie << pc+pc[0];
       }
       pk = k;
   }


}

int main(int argc, char const *argv[])
{

    if (!otworzPliki())  // blokuje/w komentarz do testów dekompresji
      return 0;
    cout << "czas na kompresję ;)"   << endl;
    inicjacjaSlownika();
    kompresjaLZW();

    wejscie.close();
    wyjscie.close();


    cout << "czas na dekompresję ;)"   << endl;
    if (!otworzPliki())
      return 0;
    inicjacjaSlownika();
    dekompresjaLZW();


    return 0;
}
