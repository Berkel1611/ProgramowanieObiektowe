#include <iostream>

using namespace std;

/*
class Figura
{
protected:
    string typ;
    double pole, obwod;
public:
    void wypisz();
};

class Kolo: public Figura
{
    double promien;
public:
    double policzPole();
    double policzObwod();
    Kolo(double);
};

class Kwadrat: public Figura
{
    double bok;
public:
    double policzPole();
    double policzObwod();
    Kwadrat(double);
};

class Prostokat: public Figura
{
    double a, b;
public:
    double policzPole();
    double policzObwod();
    Prostokat(double, double);
};
*/
class Figura
{
protected:
    float pole;
public:
    virtual float obliczPole() = 0;
    void wyswietlPole();
    virtual string nazwaFigury() = 0;
};

class Kwadrat: public Figura
{
    float a;
public:
    float obliczPole();
    Kwadrat(float);
    string nazwaFigury();
};

class Kolo: public Figura
{
    float r;
public:
    float obliczPole();
    Kolo(float);
    string nazwaFigury();
};

int main()
{
    /*
    Kolo o1(3);
    o1.wypisz();
    cout << endl;
    Kwadrat kw1(3);
    kw1.wypisz();
    cout << endl;
    Prostokat pr1(2, 3);
    pr1.wypisz();
    return 0;
    */
    Figura *tab[4] = {new Kwadrat(2), new Kwadrat(3), new Kolo(4), new Kolo(2)};
    for(int i = 0; i < 4; i++)
    {
        cout << tab[i]->nazwaFigury() << endl;
        tab[i]->wyswietlPole();
        cout << endl;
    }
}

void Figura::wyswietlPole()
{
    cout << "Pole: " << pole << endl;
}
float Kwadrat::obliczPole() {return a*a;}
Kwadrat::Kwadrat(float aa):a(aa) {pole = obliczPole();}
string Kwadrat::nazwaFigury() {return "Kwadrat";}
float Kolo::obliczPole() {return 3.14*r*r;}
Kolo::Kolo(float rr):r(rr) {pole = obliczPole();}
string Kolo::nazwaFigury() {return "Kolo";}

/*
void Figura::wypisz()
{
    cout << "Typ: " << typ << endl
    << "Pole: " << pole << endl
    << "Obwod: " << obwod << endl;
}
double Kolo::policzPole() {return 3.14*promien*promien;}
double Kolo::policzObwod() {return 2*3.14*promien;}
Kolo::Kolo(double r):promien(r)
{
    typ = "Kolo";
    pole = policzPole();
    obwod = policzObwod();
}

double Kwadrat::policzPole() {return bok*bok;}
double Kwadrat::policzObwod() {return 4*bok;}
Kwadrat::Kwadrat(double a):bok(a)
{
    typ = "Kwadrat";
    pole = policzPole();
    obwod = policzObwod();
}

double Prostokat::policzPole() {return a*b;}
double Prostokat::policzObwod() {return 2*a+2*b;}
Prostokat::Prostokat(double aa, double bb):a(aa),b(bb)
{
    typ = "Prostokat";
    pole = policzPole();
    obwod = policzObwod();
}
*/
