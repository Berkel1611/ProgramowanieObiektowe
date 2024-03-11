#include <iostream>
#include <math.h>
#include <time.h>

using namespace std;

class Punkt
{
public:
    Punkt(){}
    Punkt(double a, double b) {x = a; y = b;}
    Punkt(int a) {x = a; y = a;}

    double x, y;
    void wypisz();
    double odleglosc_od_srodka() {return sqrt(x*x+y*y);}
    void skaluj(double k) {x *= k; y *= k;}
    void setX(double a);
    void setY(double b);
};
void Punkt::wypisz() {cout << "(" << x << "," << y << ")" << endl;}
void Punkt::setX(double a) {x = a;}
void Punkt::setY(double b) {y = b;}
double odleglosc_miedzy_punktami(Punkt p1, Punkt p2) {return sqrt(pow(p2.x-p1.x, 2)-pow(p2.y-p1.y, 2));}

int main()
{
    Punkt p1 = {5, 6};
    Punkt p2 = {2, -3};

    Punkt *p3 = new Punkt;
    p3->x = 1; p3->y = 6;
    Punkt *p4 = new Punkt;
    p4->x = 4; p4->y = -3;
/*
    p1.wypisz();
    p2.wypisz();
    p3->wypisz();
    p4->wypisz();
*//*
    cout << p1.odleglosc_od_srodka() << endl;
*//*
    p1.skaluj(3);
    p1.wypisz();
*//*
    double a, b;
    cin >> a >> b;
    p3->wypisz();
    p3->x = a; p3->y = b;
    p3->wypisz();
*//*
    p4->setX(9);
    p4->setY(-9);
    p4->wypisz();
*//*
    cout << odleglosc_miedzy_punktami(p1, *p3) << endl;
*/
    Punkt p5 = Punkt(4,6);
    Punkt *p6 = new Punkt(3,4);
/*
    p5.wypisz();
    p6->wypisz();
*/
    Punkt *tab = new Punkt[10];
/*
    srand(time(NULL));
    double minn = INT_MAX, sumaX = 0, sumaY = 0;
    int indeks_minn, liczba_punktow_w_1_cwiartce = 0;
    for(int i = 0; i < 10; i++)
    {
        (tab+i)->setX(rand()%19-9);
        (tab+i)->setY(rand()%19-9);
        (tab+i)->wypisz();
        if(minn > (tab+i)->odleglosc_od_srodka())
        {
            minn = (tab+i)->odleglosc_od_srodka();
            indeks_minn = i;
        }
        if((tab+i)->x > 0 && (tab+i)->y > 0) liczba_punktow_w_1_cwiartce++;
        sumaX += (tab+i)->x;
        sumaY += (tab+i)->y;
    }
    cout << "Punkt polozony najblizej srodka: ";
    tab[indeks_minn].wypisz();
    cout << "Liczba punktow w pierwszej cwiartce: " << liczba_punktow_w_1_cwiartce << endl;
    Punkt sumowanyP = Punkt(sumaX, sumaY);
    cout << "Punkt sumowany: ";
    sumowanyP.wypisz();
*/
    delete p3;
    delete p4;
    delete p6;
    delete tab;
    return 0;
}
