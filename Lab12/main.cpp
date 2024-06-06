#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Miasto
{
public:
    string nazwa;
    int liczba;
    Miasto(string, int);
};

bool mieszkancyMalejaco(Miasto a, Miasto b) {return a.liczba > b.liczba;}
bool nazwaAlfabetycznie(Miasto a, Miasto b) {return a.nazwa < b.nazwa;}
bool nazwaMieszkancy(Miasto a, Miasto b)
{
    if(a.nazwa == b.nazwa)
        return mieszkancyMalejaco(a, b);
    return nazwaAlfabetycznie(a, b);
}
void wypiszVector(vector<Miasto> v)
{
    for(int i = 0; i < v.size(); i++)
        cout << v[i].nazwa << " " << v[i].liczba << endl;
}

int main()
{
    vector<Miasto> miasta;
    miasta.push_back(Miasto("Losice", 13000));
    miasta.push_back(Miasto("Bialystok", 1500000));
    miasta.push_back(Miasto("Warszawa", 3000000));

    wypiszVector(miasta);
    cout << endl;

    sort(miasta.begin(), miasta.end(), mieszkancyMalejaco);
    wypiszVector(miasta);
    cout << endl;

    sort(miasta.begin(), miasta.end(), nazwaAlfabetycznie);
    wypiszVector(miasta);
    cout << endl;

    sort(miasta.begin(), miasta.end(), nazwaMieszkancy);
    wypiszVector(miasta);
    cout << endl;

    return 0;
}

Miasto::Miasto(string naz, int li) {nazwa = naz; liczba = li;}
