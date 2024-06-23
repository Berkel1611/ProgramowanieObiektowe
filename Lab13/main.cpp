#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

class Osoba
{
public:
    string imie;
    int rokUrodzenia, wiek;
    Osoba(string im, int rok):
        imie(im), rokUrodzenia(rok)
        {wiek = 2024-rokUrodzenia;}
};

class Pracownik: public Osoba
{
public:
    float wyplata;
    Pracownik(string im, int rok, float wypl):
        Osoba(im, rok), wyplata(wypl){}
};

class Student: public Osoba
{
public:
    float srednia;
    Student(string im, int rok, float sr): Osoba(im, rok), srednia(sr){}
};

class Kierownik: public Pracownik
{
public:
    string zawod;
    Kierownik(string im, int rok, float wypl, string zaw):
        Pracownik(im, rok, wypl), zawod(zaw){}
};

string toString(int a){return to_string(a);}
bool byAge(Osoba a, Osoba b){return a.wiek < b.wiek;}
ostream& operator<<(ostream& stm, Osoba *o)
{
    stm << (*o).wiek;
    return stm;
}

int main()
{
    vector<Osoba> osoby = {
        Osoba("Bartlomiej", 2003),
        Osoba("Gabriel", 2010),
        Osoba("Adrianna", 1950),
        Osoba("Albert", 2020),
        Osoba("Geralt", 1150)};

    int maxWiek = 0, minWiek = INT_MAX;
    string imieMinWiek;
    vector<Osoba>::iterator it;
    for(int i = 0; i < osoby.size(); i++)
    {
        cout << osoby[i].imie << " " << osoby[i].rokUrodzenia << endl;
        if(osoby[i].wiek > maxWiek)
            maxWiek = osoby[i].wiek;
        if(osoby[i].wiek < minWiek)
        {
            imieMinWiek = osoby[i].imie;
            minWiek = osoby[i].wiek;
        }
    }
    cout << endl;
    for(it = osoby.begin(); it != osoby.end(); it++)
        cout << (*it).imie << " " << (*it).rokUrodzenia << endl;


    cout << endl;
    cout << "Najstarsza osoba ma " << maxWiek << " lat" << endl;
    cout << "Najmlodsza osoba ma na imie " << imieMinWiek << endl;

    cout << endl;
    sort(osoby.begin(), osoby.end(), byAge);
    for(it = osoby.begin(); it != osoby.end(); it++)
        cout << (*it).imie << " " << (*it).rokUrodzenia << endl;

    fstream file;
    file.open("plik.txt", ios::in);
    while(!file.eof())
    {
        string imie;
        int rok;
        file >> imie >> rok;
        osoby.push_back(Osoba(imie, rok));
    }
    osoby.pop_back();
    file.close();
    cout << endl;
    for(it = osoby.begin(); it != osoby.end(); it++)
        cout << (*it).imie << " " << (*it).rokUrodzenia << " " <<
        (*it).wiek << endl;

    Osoba *o1 = new Osoba("Ala", 2000);
    Osoba *o2 = new Pracownik("Ewa", 1995, 3456.67);
    Osoba *o3 = new Student("Kuba", 2000, 3.89);
    Pracownik *p1 = new Kierownik("Adam", 1990, 4128.78, "Informatyk");
    cout << o1->wiek << endl;
    cout << p1->wiek << endl;
    cout<<o1; //wyœwietli siê wiek osoby o1
    return 0;
}
