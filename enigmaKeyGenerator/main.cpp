#include <iostream>
#include <string.h>
#include <fstream>
#include <cstdlib>
#include <ctype.h>
#include <ctime>

using namespace std;

int main()
{
    srand(time(NULL));
    ofstream target;
    target.open("C:\\Users\\HP\\Desktop\\enigmaTest.txt");

    // priprav promenne
    cout << "Zadejte text k sifrovani: ";
    char openText[256];
    cin >> openText;
    char c;

    // pro kazdy znak z nacteneho textu sifruj
    for(int i = 0, n = strlen(openText); i < n; i++)
    {

        // preved sifrovany text do tiskacich
        c = openText[i];
        c = toupper(c);

        // pokud je sifrovany znak pismeno, jinak ho nech nezmeneny
        if(c >= 'A' and c <= 'Z')
        {

            // zasifruj skrz vsechny scramblery
            for(int j = 0; j < 3; j++)
            {

                // zasifruj znak dle klice v j-tem scrambleru
                if (c - 'A' - shift[j] - rotor[j] < 0)
                {
                    c = scramblers[j][26 + c - 'A' - shift[j] - rotor[j]] + 'A';
                }
                else
                    c = scramblers[j][c - 'A' - shift[j] - rotor[j]] + 'A';

            }

            // zasifruj skrz reflector
            c = reflector[c - 'A'] + 'A';


            // zasifruj skrz vsechny scramblery i cestou zpet
            for(int j = 3; j > 0; j--)
            {

                // zasifruj znak dle klice v j-tem scrambleru
                if (c - 'A' - shift[j] - rotor[j] < 0)
                {
                    c = scramblers[j][26 + c - 'A' - shift[j] - rotor[j]] + 'A';
                }
                else
                    c = scramblers[j][c - 'A' - shift[j] - rotor[j]] + 'A';

            }

            // otoc scramblers
            shift[0]++;
            if(shift[0] == 26)
            {
                shift[1]++;
                shift[0] = 0;

                if(shift[1] == 26)
                {
                    shift[2]++;
                    shift[1] = 0;

                    if(shift[2] == 26)
                    {
                        shift[2] = 0;
                    }
                }
            }

        }

        // vypis zasifrovany znak
        cout << c;
        lastCypher[i] = c;
    }

    //ukonci lastCypher
    lastCypher[strlen(openText)] = NULL;

    // priprav comman line na dalsi get
    cout << endl;
    target.close();
    return 0;
}
