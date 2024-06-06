#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

/*void printVector(vector<int> v)
{
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
    vector <int>::iterator itV = v.begin();
    for(; itV != v.end(); itV++)
        cout << *itV << " ";
    cout << endl;
}*/

class Pacjent
{
protected:
    string imie, nazwisko, PESEL, nazwaOddzialu;
    int liczbaDniPobytu, wiek;
public:
    Pacjent(string, string, string, string, int);
    string getImie();
    string getNazwisko();
    string getPESEL();
    string getNazwaOddzialu();
    int getLiczbaDniPobytu();
    int getWiek();
    void setImie(string);
    void setNazwisko(string);
    void setPESEL(string);
    void setNazwaOddzialu(string);
    void setLiczbaDniPobytu(int);
    void setWiek(int);
    bool sprawdzCzyPowyzej(int);
    void dodajKolejnyDzien();
    bool sprawdzOddzial(string);
    void wyswietl();
};

class Szpital
{
    int maxPacjentow;
    vector<Pacjent> listaPacjentow;
public:
    Szpital(int, vector<Pacjent>);
    Szpital();
    int getMaxPacjentow();
    void setMaxPacjentow(int);
    void wyswietlPacjentowOddzialu(string);
    float zwrocSredniaDniPobytu();
    void dodajPacjenta(Pacjent);
    int zwrocNajPobyt();
    int zwrocIlePowyzejWieku(int);
};

int main()
{
    /*
    // ZAD 1.
    srand(time(NULL));
    vector <int> lista;
    // zape³nianie kontenera
    for(int i = 0; i < 20; i++)
        lista.push_back(rand()%100+1);
    // wyœwietlenie zawartoœci
    printVector(lista);
    // usuniêcie ostatniej liczby
    lista.pop_back();
    printVector(lista);
    // usuniêcie pierwszej liczby
    lista.erase(lista.begin());
    printVector(lista);
    // usuniêcie czwartej liczby
    lista.erase(lista.begin()+3);
    printVector(lista);
    // usuniêcie wszystkich parzystych
    for(int i = 0; i < lista.size(); i++){
        if(lista[i]%2 == 0){
            lista.erase(lista.begin()+i);
            i--;
        }
    }
    printVector(lista);
    */
    vector<Pacjent> pacjenci;
    pacjenci.push_back(Pacjent("Bartek", "Kozluk", "84422935742", "Szpital w Losicach", 20));
    pacjenci.push_back(Pacjent("Gabriel", "Domanski", "57733921047", "Szpital w Bialymstoku", 14));
    pacjenci.push_back(Pacjent("Adzia", "Zastawna", "10033629523", "Szpital Wojewodzki w Supraœlu", 29));


    return 0;
}

Pacjent::Pacjent(string im, string nazw, string pes, string oddzial, int w):
    imie(im), nazwisko(nazw), PESEL(pes), nazwaOddzialu(oddzial), liczbaDniPobytu(0), wiek(w){}
string Pacjent::getImie(){return imie;}
string Pacjent::getNazwisko(){return nazwisko;}
string Pacjent::getPESEL(){return PESEL;}
string Pacjent::getNazwaOddzialu(){return nazwaOddzialu;}
int Pacjent::getLiczbaDniPobytu(){return liczbaDniPobytu;}
int Pacjent::getWiek(){return wiek;}
void Pacjent::setImie(string im){imie = im;}
void Pacjent::setNazwisko(string nazw){nazwisko = nazw;}
void Pacjent::setPESEL(string pes){PESEL = pes;}
void Pacjent::setNazwaOddzialu(string oddzial){nazwaOddzialu = oddzial;}
void Pacjent::setLiczbaDniPobytu(int dni){liczbaDniPobytu = dni;}
void Pacjent::setWiek(int w){wiek = w;}
bool Pacjent::sprawdzCzyPowyzej(int dni){return liczbaDniPobytu > dni;}
void Pacjent::dodajKolejnyDzien(){liczbaDniPobytu++;}
bool Pacjent::sprawdzOddzial(string oddzial){return nazwaOddzialu == oddzial;}
void Pacjent::wyswietl()
{
    cout << "Imie: " << imie << endl
    << "Nazwisko: " << nazwisko << endl
    << "PESEL: " << PESEL << endl
    << "Nazwa oddzialu: " << nazwaOddzialu << endl
    << "Liczba dni pobytu: " << liczbaDniPobytu << endl
    << "Wiek: " << wiek << endl << endl;
}

Szpital::Szpital(int mx, vector<Pacjent> v): maxPacjentow(mx), listaPacjentow(v){}
Szpital::Szpital():maxPacjentow(10){}
int Szpital::getMaxPacjentow(){return maxPacjentow;}
void Szpital::setMaxPacjentow(int mx){maxPacjentow = mx;}
void Szpital::wyswietlPacjentowOddzialu(string oddzial)
{
    for(int i = 0; i < int(listaPacjentow.size()); i++)
        if(listaPacjentow[i].getNazwaOddzialu() == oddzial)
            cout << listaPacjentow[i].getImie() << " " << listaPacjentow[i].getNazwisko() << endl;
}
float Szpital::zwrocSredniaDniPobytu()
{
    int sum = 0;
    for(int i = 0; i < int(listaPacjentow.size()); i++)
        sum += listaPacjentow[i].getLiczbaDniPobytu();
    return sum/listaPacjentow.size();
}
void Szpital::dodajPacjenta(Pacjent p){listaPacjentow.push_back(p);}
int Szpital::zwrocNajPobyt()
{
    int najPobyt = 0;
    for(int i = 0; i < int(listaPacjentow.size()); i++)
        if(listaPacjentow[i].getLiczbaDniPobytu() > najPobyt)
            najPobyt = listaPacjentow[i].getLiczbaDniPobytu();
    return najPobyt;
}
int Szpital::zwrocIlePowyzejWieku(int w)
{
    int powyzej = 0;
    for(int i = 0; i < int(listaPacjentow.size()); i++)
        if(listaPacjentow[i].getWiek() > w)
            powyzej++;
    return powyzej;
}
