#include <iostream>
#include <fstream>

using namespace std;

void slucUdaje (char* f1, char* f2, char* output)
{
    ifstream i1 (f1);
    ifstream i2 (f2);

    ofstream o(output);

    int cislo1; i1 >> cislo1; bool pl1 = true;
    int cislo2; i2 >> cislo2; bool pl2 = true;
    while (!i1.eof() or !i2.eof())
    {
        if (i1.eof())
        {
            o << cislo2 << endl;
            i2 >> cislo2;
            if (i2.eof()) o << cislo2 << endl;
        }
        else if (i2.eof())
        {
            o << cislo1 << endl;
            i1 >> cislo1;
            if (i1.eof()) o << cislo1 << endl;
        }
        else
        {
            if (cislo1 < cislo2)
            {
                o << cislo1 << endl;
                i1 >> cislo1;
                if (i1.eof()) o << cislo1 << endl;
            }
            else
            {
                o << cislo2 << endl;
                i2 >> cislo2;
                if (i2.eof()) o << cislo2 << endl;
            }
        }
    }

    o.close();

    i1.close();
    i2.close();
}

void odduplikuj (char* in, char* out)
{
    ifstream inf (in);
    ofstream outf (out);

    int cisloN;
    int cisloS; inf >> cisloS; outf << cisloS << endl;
    bool dup = false;
    bool s = true;
    while (inf >> cisloN)
    {
        if (cisloS == cisloN)
        {
            dup = true;
        }
        else
        {
            if (dup)
            {
                dup = false;
            }
            outf << cisloN << endl;
        }

        cisloS = cisloN;
    }

    outf.close();
    inf.close();
}

int main()
{
    slucUdaje("1.txt", "2.txt", "sluc.txt");
    odduplikuj("sluc.txt", "sinDup.txt");

    return 0;
}
