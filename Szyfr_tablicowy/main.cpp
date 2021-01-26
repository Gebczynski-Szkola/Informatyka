#include <iostream>
#include <string>
#include <math.h>

using namespace std;

string szyfrowanie(string tekst){

  float rozmiar;
  rozmiar = tekst.length();

  int wielkosc = 0;

while (wielkosc < sqrt(rozmiar)){
  wielkosc++;
}

cout << wielkosc << "<----- rozmiar tablicy"<< endl;

string tablica[wielkosc][wielkosc];
int miejsce = 0;

for (int i=0;i<wielkosc;i++){
    for (int j=0;j<wielkosc;j++){
        tablica[i][j] = tekst[miejsce];
        cout<<tablica[i][j]<<" ";
        miejsce++;
        }
    cout<<endl;
}

string szyfr;

for (int i=0;i<wielkosc;i++){
    for (int j=0;j<wielkosc;j++){
        szyfr += tablica[j][i];
        }
}

cout << szyfr << endl;

return szyfr;
}

string deszyfrowanie(string tekst){
  int wielkosc = 0;

  wielkosc = tekst.length();
  wielkosc = sqrt(wielkosc);

  string tablica[wielkosc][wielkosc];

  int miejsce = 0;

  for (int i=0;i<wielkosc;i++){
      for (int j=0;j<wielkosc;j++){
          tablica[i][j] = tekst[miejsce];
          cout<<tablica[i][j]<<" ";
          miejsce++;
          }
      cout<<endl;
  }

  string deszyfr;

  for (int i=0;i<wielkosc;i++){
      for (int j=0;j<wielkosc;j++){
          deszyfr += tablica[j][i];
          }
  }

  cout << deszyfr;

  return deszyfr;
}

int main() {
  string text;
  string zaszyfrowany;

  cout << "Wpisz tekst: ";
  getline(cin, text);

  cout << "Wpisz szyfr: ";
  getline(cin, zaszyfrowany);


  szyfrowanie(text);
  cout << "<---------------------------------------->" << endl;
  deszyfrowanie(zaszyfrowany);

  return 0;
}
