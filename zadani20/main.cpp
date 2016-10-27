#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;

struct{
    char jmeno[50];
    int plat;
    char funkce[30];
} TPRACOVNIK;

int main()
{
    ifstream vstup;
    vstup.open("csv.txt");

    ofstream vystup;
    vystup.open("bin.txt", ios::binary | ios::out);

    char line[90];
    while ( vstup.getline(line, 90) )
    {
        string str(line);
        int i;
        int n = str.length();
        for (i = 0; i < n; i++)
        {
            if (str[i] == ';')
                break;
        }
        i++;
        for (int a = 0; i < n; i++, a++)
        {
            if (str[i] == ';')
                break;
            TPRACOVNIK.jmeno[a] = str[i];
        }
        i++;
        string platS = "";
        for (int a = 0; i < n; i++, a++)
        {
            if (str[i] == ';')
                break;
            platS.append(&str[i]);
        }
        i++;

        // convert platS to int plat and save it
        TPRACOVNIK.plat = atoi(platS.c_str());

        for (int a = 0, n = str.length(); i < n; i++, a++)
        {
            if (str[i] == ';')
                break;
            TPRACOVNIK.funkce[a] = str[i];
        }

        cout << TPRACOVNIK.jmeno << "\t" << TPRACOVNIK.plat << "\t" << TPRACOVNIK.funkce << endl;

        vystup.write((char*)&TPRACOVNIK, sizeof(TPRACOVNIK));

    }

    vystup.close();
    vstup.close();
    return 0;
}
