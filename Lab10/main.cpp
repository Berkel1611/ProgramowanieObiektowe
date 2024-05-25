#include <iostream>
#include <fstream>

using namespace std;

class Produkt
{
    string nazwa;
    int ilosc, id;
    float cena;
public:
    Produkt();
    void wypisz();
    string getNazwa();
    float getCena();
    int getIlosc();
    int getId();
    void setNazwa(string);
    void setCena(float);
    void setIlosc(int);
    void setId(int);
};

class Automat
{
    Produkt *produkty;
    int licznik, ile;
public:
    Automat();
    void wypisz();
    void dodajProdukt(string, float, int);
    void uzupelnijProdukt();
    void dodajListeProduktow();
    void produktyDoUzupelnienia();
    void zapiszDane();
    void produktyZaCene(float);
    int kupProdukt(int, int, float);
};

int main()
{
    Automat x;
    x.dodajProdukt("abc", 12.50, 5);
    x.dodajProdukt("cba", 5.99, 0);
    //x.wypisz();
    //cout << "Po uzupelnieniu ---" << endl << endl;
    x.uzupelnijProdukt();
    /*
    x.wypisz();
    cout << "Po dodaniu listy ---" << endl << endl;
    x.dodajListeProduktow();
    x.wypisz();
    x.produktyDoUzupelnienia();*/
    //x.produktyZaCene(12.5);
    int mana;
    cout << "Wrzuc pieniadze: ";
    cin >> mana;
    int id, il;
    while(true)
    {
        cout << "Podaj numer (wpisz '-1', aby zakonczyc): ";
        cin >> id;
        if(id == -1)
        {
            cout << "Reszta: " << mana << endl;
            break;
        }
        cout << "Podaj ilosc: ";
        cin >> il;
        mana -= x.kupProdukt(id, il, mana);
    }
    x.zapiszDane();
    return 0;
}

Produkt::Produkt()
{
    nazwa = "<brak danych>";
    cena = 0;
    ilosc = 0;
    id = 0;
}
void Produkt::wypisz()
{
    cout << "ID: " << id << endl
    << "Nazwa: " << nazwa <<endl
    << "Cena: " << cena << endl
    << "Ilosc: " << ilosc << endl;
}
string Produkt::getNazwa() {return nazwa;}
float Produkt::getCena() {return cena;}
int Produkt::getIlosc() {return ilosc;}
int Produkt::getId() {return id;}
void Produkt::setNazwa(string naz) {nazwa = naz;}
void Produkt::setCena(float cen) {cena = cen;}
void Produkt::setIlosc(int il) {ilosc = il;}
void Produkt::setId(int i) {id = i;}

Automat::Automat():ile(10), licznik(0) {produkty = new Produkt[ile];}
void Automat::wypisz()
{
    for(int i = 0; i < licznik; i++)
    {
        (produkty+i)->wypisz();
        cout << endl;
    }
}
void Automat::dodajProdukt(string naz, float cen, int ile)
{
    produkty[licznik].setNazwa(naz);
    produkty[licznik].setCena(cen);
    produkty[licznik].setIlosc(ile);
    produkty[licznik].setId(licznik);
    licznik++;
}
void Automat::uzupelnijProdukt()
{
    for(int i = 0; i < licznik; i++)
        if(produkty[i].getIlosc() == 0)
            produkty[i].setIlosc(10);
}
void Automat::dodajListeProduktow()
{
    string naz;
    float cen;
    int ile;
    fstream file;
    file.open("dane.txt", ios::in);
    if(file.good())
    {
        while(!file.eof())
        {
            file>>naz;
            file>>cen;
            file>>ile;
            dodajProdukt(naz, cen, ile);
        }
    }
    else
        cout << "Nie udalo sie otworzyc pliku!" << endl;
    file.close();
}
void Automat::produktyDoUzupelnienia()
{
    fstream file;
    file.open("zam.txt", ios::out);
    for(int i = 0; i < licznik; i++)
        if(produkty[i].getIlosc() <5)
            file<<produkty[i].getId()<<" "<<produkty[i].getNazwa()<<endl;
    file.close();
}
void Automat::zapiszDane()
{
    fstream file;
    file.open("stanAktualny.txt", ios::out);
    for(int i = 0; i < licznik; i++)
        file<<produkty[i].getId()<<" "<<produkty[i].getNazwa()<<" "<<produkty[i].getIlosc() << endl;
    file.close();
}
void Automat::produktyZaCene(float c)
{
    for(int i = 0; i < licznik; i++)
    {
        if(produkty[i].getCena() == c)
            produkty[i].wypisz();
    }
}
int Automat::kupProdukt(int i, int il, float mana)
{
    for(int i = 0; i < licznik; i++)
    {
        if(produkty[i].getId() == i)
        {
            if(produkty[i].getIlosc() >= il && produkty[i].getCena()*il <= mana)
            {
                produkty[i].setIlosc(produkty[i].getIlosc()-il);
                cout << "Wydaje: " << il << " x " << produkty[i].getNazwa() << endl;
                return produkty[i].getCena()*il;
            }
        }
    }
    cout << "Transakcja nie powiodla sie." << endl;
    return 0;
}
