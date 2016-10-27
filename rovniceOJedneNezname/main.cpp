#include <iostream>
#include <cmath>

#define PRESNOST 0.0001
using namespace std;

/*
double pow (double x, int n)
{
    double sum = x;
    for (int i = 1; i < n; i++)
        sum *= x;
    return sum;
}*/

double rovnice (double x)
{
    return pow(x,5) - 3*pow(x,4) - 23*pow(x,3)+51*x*x+94*x-120;
}

double derivace (double x)
{
    //return 2*x;
    return 5*pow(x,4) - 12*pow(x,3) - 69*x*x + 102*x + 94;
}

// zpresnovani korenu
double puleni ( double a, double b, double presnost)
{
    while ( abs(b-a) > presnost )
    {
        double s = (a+b)/2;
        if ( rovnice(s) < 0 )
        {
            if (rovnice(a) < 0 ) // potom koren musi byt mezi s a b
                a = s;
            else
                b = s;
        }
        else
        {
            if (rovnice(a) > 0 ) // potom koren musi byt mezi s a b
                a = s;
            else
                b = s;
        }
    }

    return (a+b)/2; // vrat stred v intervalu, ktery vyhovuje zadane presnosti
}

double tecny ( double x0, double presnost )
{
    // xn ... nove x, xs ... stare (predchozi) x
    double xs = x0;
    double xn = xs - (rovnice(xs)/derivace(xs));

    while ( abs(xn-xs) > presnost )
    {
        double pom = xn;
        xn = xs - (rovnice(xs)/derivace(xs));
        xs = pom;
    }

    return xn;
}

int main()
{
    // najdi znamenkovo zmenu
    double levaHranice; cout << "Zadej hodnotu -moc: "; cin >> levaHranice;
    double pravaHranice; cout << "Zadej hodnotu +moc: "; cin >> pravaHranice;
    double interval; cout << "Zadej hodnotu kroku: "; cin >> interval;

    // true pokud +, false otherwise
    bool posledniZnaminko;
    if ( rovnice(levaHranice) > 0)
        posledniZnaminko = true;
    else
        posledniZnaminko = false;

    for (double i = levaHranice + interval; i < pravaHranice; i+= interval)
    {
        if ( rovnice(i) > 0 )
        {
            if (posledniZnaminko == false)
            {
                cout << "v intervalu od " << i-interval << " do " << i << " dochazi ke zmene znamenka" << endl;
                cout << "zde nalezeny koren metodou puleni s prenosti " << PRESNOST << " je: " << puleni(i-interval, i, PRESNOST) << endl;
                cout << "zde nalezeny koren metodou tecen s prenosti " << PRESNOST << " je: " << tecny(i, PRESNOST) << endl;
            }
            posledniZnaminko = true;
        }

        else
        {
            if (posledniZnaminko == true)
            {
                cout << "v intervalu od " << i-interval << " do " << i << " dochazi ke zmene znamenka" << endl;
                cout << "zde nalezeny koren metodou puleni s prenosti " << PRESNOST << " je: " << puleni(i-interval, i, PRESNOST) << endl;
                cout << "zde nalezeny koren metodou tecen s prenosti " << PRESNOST << " je: " << tecny(i, PRESNOST) << endl;
            }
            posledniZnaminko = false;
        }
    }

    return 0;
}
