#include <iostream>
#include <string.h>
#include <fstream>
#include <cstdlib>
#include <ctype.h>
#include <ctime>

using namespace std;

int main()
{

    // get the name of the file we are gonna import it in
    char name[20];
    cin >> name;

    // put it on the desktop
    char where[256] = "C:\\Users\\HP\\Desktop\\";
    for(int i = 20; i < strlen(name) + 20; i++)
        where[i] = name[i-20];
    where[strlen(where)] = '.';
    where[strlen(where)] = 't';
    where[strlen(where)] = 'x';
    where[strlen(where)] = 't';
    cout << "the key will be placed in " << where;

    // prepare the file
    srand(time(NULL));
    ofstream target;
    target.open(where);

    for(int scramblers = 0; scramblers < 3; scramblers++)
    {
        // napln array vsemi moznymi cisly
        int moznePosuny[26];
        for(int i = 0; i < 26; i++)
            moznePosuny[i] = i;

        // ted tato cisla nahodne rozdel
        for(int i = 0; i < 26; i++)
        {
            // kolikate cislo z moznePosuny mam brat
            int x = rand()%(26 - i);
            /*cout << " x: " << x;*/

            // najdi x-tou pozici
            for(int a = 0; a <= 26; a++)
            {

                if(moznePosuny[a] != -1)
                {

                    if(x == 0)
                    {
                        /* cout << " moznePosuny[a]: " << moznePosuny[a] << endl; */

                        /*
                        if(0 > moznePosuny[a] - i){
                            target << 26 + moznePosuny[a] - i << endl;
                        }
                        else
                            target << moznePosuny[a] - i << endl;
                        */

                        target << moznePosuny[a] << endl;
                        moznePosuny[a] = -1;
                        break;
                    }

                    // jdi dal
                    x--;
                }

            }
        }

        target << endl;
    }


    target.close();
    return 0;
}
