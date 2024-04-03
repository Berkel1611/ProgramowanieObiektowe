#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int string_to_int(string str);
string to_YYYY(int Y);
string to_MM(int M);
string to_DD(int D);
string YearOfDate(string date);
string MonthOfDate(string date);
string DayOfDate(string date);
int intYearOfDate(string date);
int intMonthOfDate(string date);
int intDayOfDate(string date);
string imieFromImie_nazwisko(string imie_nazwisko);
string nazwiskoFromImie_nazwisko(string imie_nazwisko);

class Osoba
{
public:
    string imie = "<brak danych>", nazwisko = "<brak danych>", dataUr = "????-??-??";
    bool isValidYear(int Y);
    bool isValidMonth(int M);
    bool isValidDay(int D);
public:
    const static int minYear = 1990, maxYear = 3000, rok_teraz = 2023;
    Osoba(){}
    Osoba(string im, string nazw, string du)
    {
        imie = im;
        nazwisko = nazw;
        int Y = intYearOfDate(du), M = intMonthOfDate(du), D = intDayOfDate(du);
        string strY = "????", strM = "??", strD = "??";
        if(isValidYear(Y)) strY = to_YYYY(Y);
        if(isValidMonth(M)) strM = to_MM(M);
        if(isValidDay(D)) strD = to_DD(D);
        dataUr = strY + "-" + strM + "-" + strD;
    }
    Osoba(string im, string nazw, int Y, int M, int D)
    {
        imie = im;
        nazwisko = nazw;
        string strY = "????", strM = "??", strD = "??";
        if(isValidYear(Y)) strY = to_YYYY(Y);
        if(isValidMonth(M)) strM = to_MM(M);
        if(isValidDay(D)) strD = to_DD(D);
        dataUr = strY + "-" + strM + "-" + strD;
    }
    Osoba(string imie_nazwisko, string du)
    {
        imie = imieFromImie_nazwisko(imie_nazwisko);
        nazwisko = nazwiskoFromImie_nazwisko(imie_nazwisko);
        int Y = intYearOfDate(du), M = intMonthOfDate(du), D = intDayOfDate(du);
        string strY = "????", strM = "??", strD = "??";
        if(isValidYear(Y)) strY = to_YYYY(Y);
        if(isValidMonth(M)) strM = to_MM(M);
        if(isValidDay(D)) strD = to_DD(D);
        dataUr = strY + "-" + strM + "-" + strD;
    }
    Osoba(string imie_nazwisko, int Y, int M, int D)
    {
        imie = imieFromImie_nazwisko(imie_nazwisko);
        nazwisko = nazwiskoFromImie_nazwisko(imie_nazwisko);
        string strY = "????", strM = "??", strD = "??";
        if(isValidYear(Y)) strY = to_YYYY(Y);
        if(isValidMonth(M)) strM = to_MM(M);
        if(isValidDay(D)) strD = to_DD(D);
        dataUr = strY + "-" + strM + "-" + strD;
    }
    void set_imie(string potential_imie);
    void set_nazwisko(string potential_nazw);
    void set_dataUr(string potential_dataUr);
    void set_dataUr_Year(int potential_year);
    void set_dataUr_Month(int potential_month);
    void set_dataUr_Day(int potential_day);
    void wypisz();
    friend bool isSameYear(Osoba &a, Osoba &b);
    int wiek();
};

int main()
{
    Osoba os1 = Osoba("Piotr Stomma  ", "2002-07-06");
    os1.wypisz();
    return 0;
}

void Osoba::set_imie(string potential_imie){Osoba::imie = potential_imie;}
void Osoba::set_nazwisko(string potential_nazw){Osoba::nazwisko = potential_nazw;}
void Osoba::set_dataUr(string potential_dataUr)
{
    if(Osoba::isValidDay(intDayOfDate(potential_dataUr)) && Osoba::isValidMonth(intMonthOfDate(potential_dataUr)) && Osoba::isValidYear(intYearOfDate(potential_dataUr)))
        Osoba::dataUr = potential_dataUr;
    else
        cout << "Niepoprawna data!" << endl;
}
void Osoba::set_dataUr_Year(int potential_year)
{
    if(Osoba::isValidYear(potential_year))
        Osoba::dataUr = to_string(potential_year) + "-" + MonthOfDate(Osoba::dataUr) + "-" + DayOfDate(Osoba::dataUr);
    else
        cout << "Niepoprawny rok!" << endl;
}
void Osoba::set_dataUr_Month(int potential_month)
{
    if(Osoba::isValidMonth(potential_month))
        Osoba::dataUr = YearOfDate(Osoba::dataUr) + "-" + to_string(potential_month) + "-" + DayOfDate(Osoba::dataUr);
    else
        cout << "Niepoprawny miesi¹c!" << endl;
}
void Osoba::set_dataUr_Day(int potential_day)
{
    if(Osoba::isValidDay(potential_day))
        Osoba::dataUr = YearOfDate(Osoba::dataUr) + "-" + MonthOfDate(Osoba::dataUr) + "-" + to_string(potential_day);
    else
        cout << "Niepoprawny dzieñ!" << endl;
}
void Osoba::wypisz()
{
    cout << "imie: " << imie << endl <<
    "nazwisko: " << nazwisko << endl <<
    "dataUrodzenia [YYYY-MM-DD]: " << dataUr << endl;
}
bool Osoba::isValidYear(int Y){return Y >= Osoba::minYear && Y <= Osoba::maxYear ? true : false;}
bool Osoba::isValidMonth(int M){return M > 0 && M < 13 ? true : false;}
bool Osoba::isValidDay(int D){return D > 0 && D < 32 ? true : false;}
int Osoba::wiek()
{
    int year = intYearOfDate(Osoba::dataUr);
    if(year == -1)
        return year;
    return Osoba::rok_teraz-year;
}
bool isSameYear(Osoba &a, Osoba &b){return intYearOfDate(a.dataUr) == intYearOfDate(b.dataUr);}
int string_to_int(string str)
{
    int num = 0;
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] >= '0' && str[i] <= '9')
            num += (str[i]-48)*pow(10, str.length()-1-i);
        else
            return -1;
    }
    return num;
}
string to_YYYY(int Y)
{
    string year = to_string(Y);
    return string(4-year.length(), '0')+year;
}
string to_MM(int M)
{
    string month = to_string(M);
    return string(2-month.length(), '0')+month;
}
string to_DD(int D)
{
    string day = to_string(D);
    return string(2-day.length(), '0')+day;
}
string YearOfDate(string date){return date.substr(0, 4);}
string MonthOfDate(string date){return date.substr(5, 2);}
string DayOfDate(string date){return date.substr(8, 2);}
int intYearOfDate(string date){return string_to_int(YearOfDate(date));}
int intMonthOfDate(string date){return string_to_int(MonthOfDate(date));}
int intDayOfDate(string date){return string_to_int(DayOfDate(date));}
string imieFromImie_nazwisko(string imie_nazwisko)
{
    int i = 0, j;
    while(imie_nazwisko[i++] == ' ');
    j = i;
    while(imie_nazwisko[j++] != ' ');
    return imie_nazwisko.substr(i-1, j-i);
}
string nazwiskoFromImie_nazwisko(string imie_nazwisko)
{
    int i = 0, j;
    while(imie_nazwisko[i++] == ' ');
    while(imie_nazwisko[i++] != ' ');
    while(imie_nazwisko[i++] == ' ');
    j = i;
    while(imie_nazwisko[j++] != ' ');
    return imie_nazwisko.substr(i-1, j-i);
}
