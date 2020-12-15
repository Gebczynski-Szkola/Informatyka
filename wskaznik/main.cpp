#include <iostream>
using namespace std;
struct Element
{
    int id;
    string wartosc;
    Element *nast;
};

Element *glowa;

Element *nowyElement()
{
    Element *wskElement;
    wskElement = new Element;
    cout << " podaj dane nowego elementu" << endl;
    cout << "ID:";
    cin >> wskElement->id;
    cout << "Wartosc:";
    cin >> wskElement->wartosc;
    wskElement->nast = NULL;
    return wskElement;
}

void wyswietlElement(Element *wskElement)
{
    if (wskElement == NULL)
    {
        cout << " pusty wskaźnik" << endl;
        return;
    }
    cout << "Dane elementu -> " << wskElement->id << ":" << wskElement->wartosc << endl;
}

void dodajNaListePocz(Element *wskElement)
{
    if (wskElement == NULL)
    {
        cout << " pusty wskaźnik" << endl;
        return;
    }
    if (glowa == NULL)
    {
        glowa = wskElement;
    }
    else
    {
        wskElement->nast = glowa;
        glowa = wskElement;
    }
}
void wypiszListe()
{
    if (glowa == NULL)
    {
        cout << " lista jest pusta " << endl;
        return;
    }
    Element *wskElement = glowa;
    cout << " wyswietlam listę: " << endl;
    while (wskElement != NULL)
    {
        wyswietlElement(wskElement);
        wskElement = wskElement->nast;
    }
}

void usunPierwszy()
{
    if (glowa == NULL)
    {
        cout << " lista jest pusta" << endl;
        return;
    }
    Element *wskTMP = glowa;
    glowa = glowa->nast;
    delete (wskTMP);
}

void usunOstatni()
{
    if (glowa == NULL)
    {
        cout << " lista jest pusta" << endl;
        return;
    }
    if (glowa->nast == NULL)
    {
        delete (glowa);
        glowa = NULL;
        return;
    }

    Element *wskTMP = glowa;
    while (wskTMP->nast->nast != NULL)
    {
        wskTMP = wskTMP->nast;
    }
    delete (wskTMP->nast);
    wskTMP->nast = NULL;
}

void dodajNaListeKoniec(Element *wskElement)
{
    if (glowa == NULL)
    {
        glowa = wskElement;
    }
    else
    {
        Element *wskTMP = glowa;
        while (wskTMP->nast != NULL)
        {
            wskTMP = wskTMP->nast;
        }
        wskTMP->nast = wskElement;
    }
}

int rozmiarListy()
{
    if (glowa == NULL)
        return 0;
    Element *wskTmp = glowa;
    int ilosc = 1;
    while (wskTmp->nast != NULL)
    {
        wskTmp = wskTmp->nast;
        ilosc++;
    }
    return ilosc;
}

void usunElement(int index)
{
    if (index == 1)
        usunPierwszy();
    if (index == rozmiarListy())
        usunOstatni();
    if (index > rozmiarListy())
    {
        cout << " lista jest mniejsza" << endl;
        return;
    }

    if (glowa == NULL)
    {
        cout << " lista jest pusta" << endl;
        return;
    }
    Element *wskTmp = glowa;
    int wskIndex = 1;
    while (wskTmp->nast != NULL)
    {
        if (wskIndex == index - 1)
            break;
        wskTmp = wskTmp->nast;
        wskIndex++;
    }
    Element *wskTMPDelete = wskTmp->nast;
    wskTmp->nast = wskTMPDelete->nast;
    delete (wskTMPDelete);
}

bool testID(int szukaneID){
    Element *wskElement =  glowa;

    if (glowa != NULL){
       while(wskElement != NULL){
           if (wskElement->id == szukaneID){
             return true;
           }
           wskElement = wskElement->nast;
       }
       return false;
   }
   return false;
}

string odczytzID(int szukaneID){
  Element *wskElement =  glowa;
  while(wskElement != NULL){
      if (wskElement->id == szukaneID){
        string wartoscOdDanegoID = wskElement->wartosc;
        return wartoscOdDanegoID;
      }
      wskElement = wskElement->nast;
  }
}

int silnia(int a)
{
    int wynik;
    // obliczamy wynik na podstawie a
    return wynik;
}

int main(int argc, char const *argv[])
{
    /*Element tmp;
    tmp.id =10;
    double temperatura[10000];
    temperatura[10];
    double *wskTab;
    int ilosc =10;
    //cin >> ilosc;
    wskTab = new double[ilosc];
    */
    // List<String> lista = new ArrayList<String>;

    glowa = NULL;
    Element *jeden = nowyElement(); //   Element *wsk = new Element;
    Element *dwa = nowyElement();
    Element *trzy = nowyElement();
    Element *cztery = nowyElement();
    wyswietlElement(jeden);
    /*
    dodajNaListePocz(jeden);
    dodajNaListePocz(dwa);
    dodajNaListePocz(trzy);
   */
    dodajNaListeKoniec(jeden);
    dodajNaListeKoniec(dwa);
    dodajNaListeKoniec(trzy);
    dodajNaListeKoniec(cztery);
    wypiszListe();
    usunElement(2);
    wypiszListe();

    int szukaneID;
    cout << "Wpisz szukane id: ";
    cin >> szukaneID;

    bool wpisaneID;
    wpisaneID = testID(szukaneID);
    if(wpisaneID==1){
      cout << "Wartosc tego ID: " << odczytzID(szukaneID);
    }
    else{
      cout << "nie ma takiego ID";
    }

    return 0;
}
