#include <iostream>
#include <string>

using namespace std;

class Zespolona
{
    double re, im;
    friend Zespolona operator*(double, Zespolona);
    friend Zespolona operator+(double, Zespolona);
public:
    Zespolona();
    Zespolona(double, double);
    double getRe();
    double getIm();
    void setRe(double);
    void setIm(double);
    static void state();
    ~Zespolona();
};
ostream& operator<<(ostream&, Zespolona&);
Zespolona operator+(Zespolona&, Zespolona&);
Zespolona operator+(Zespolona&, double);
bool operator==(Zespolona&, Zespolona&);
Zespolona& operator+=(Zespolona&, Zespolona&);
Zespolona& operator!(Zespolona&);

class Licznik
{
public:
    static int i;
};

int main()
{
    /*
    Zespolona z1(1,3), z2(1,4), z3;
    cout << Licznik::i << endl;
    Zespolona z4 = new Zespolona(50, 50);
    cout << Licznik::i << endl;
    delete z4;
    cout << Licznik::i << endl;
    z3=z1+4;
    if(z1==z2)
        z3+=z1;
    else
        z3=!z1;
    cout << z3 << endl;
    z3 = 2.5 * z1;
    z3 = 2 + z1;
    cout << z3;
    */
    Zespolona z1;
    Zespolona::state();
    Zespolona z2;
    Zespolona::state();
    Zespolona *z3 = new Zespolona;
    Zespolona::state();
    delete z3;
    Zespolona::state();
    return 0;
}

ostream& operator<<(ostream& stm, Zespolona& z)
{
    string strRe = to_string(z.getRe()), strIm = to_string(z.getIm())+"i", sign = z.getIm() > 0 ? "+" : "";
    if(z.getRe() == 0)
    {
        strRe = "";
        if(z.getIm() > 0)
            sign = "";
    }
    if(z.getIm() == 0)
        strIm = "";
    stm << strRe << sign << strIm;
    return stm;
}
Zespolona operator+(Zespolona& z1, Zespolona& z2)
{
    Zespolona z(z1.getRe()+z2.getRe(), z1.getIm()+z2.getIm());
    return z;
}
Zespolona operator+(Zespolona& z1, double a)
{
    Zespolona z(z1.getRe()+a, z1.getIm());
    return z;
}
bool operator==(Zespolona& z1, Zespolona& z2) {return z1.getRe() == z2.getRe() && z1.getIm() == z2.getIm();}
Zespolona& operator+=(Zespolona& z1, Zespolona& z2)
{
    z1.setRe(z1.getRe()+z2.getRe());
    z1.setIm(z1.getIm()+z2.getIm());
    return z1;
}
Zespolona& operator!(Zespolona& z)
{
    z.setIm(0-z.getIm());
    return z;
}
Zespolona::Zespolona()
{
    re = im = 0;
    Licznik::i++;
}
Zespolona::Zespolona(double r, double i)
{
    re = r, im = i;
    Licznik::i++;
}
Zespolona::~Zespolona() {Licznik::i--;}
double Zespolona::getRe() {return re;}
double Zespolona::getIm() {return im;}
void Zespolona::setRe(double r) {re = r;}
void Zespolona::setIm(double i) {im = i;}
Zespolona operator*(double a, Zespolona z1)
{
    Zespolona z(z1.re*a, z1.im*a);
    return z;
}
Zespolona operator+(double a, Zespolona z1)
{
    Zespolona z(z1.re+a, z1.im);
    return z;
}
int Licznik::i = 0;
void Zespolona::state()
{
    string state;
    if(Licznik::i > 2)
        state = "duzo";
    else if(Licznik::i == 0)
        state = "brak";
    else
        state = "nieduzo";
    cout << "Obecnie mamy " << state << " obiektow." << endl;
}
