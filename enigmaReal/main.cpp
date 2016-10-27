#include <iostream>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include <ctime>

#define SCRAMBLERS 3

using namespace std;

int main()
{
    srand(time(NULL));

    int scramblers[SCRAMBLERS][26];
    int shift[SCRAMBLERS] = {0,0,0};
    int rotor[SCRAMBLERS] = {0,0,0};
    char lastCypher[256];


    char get[50];
    do{
       cin >> get;

        if(strcmp(get, "help") == 0){
            cout << "help";
        }
        else if(strcmp(get, "setKey") == 0){

            // get the address of the file with the key
            cout << "from what file should we upload the key?" << endl;
            char name[50];
            cin >> name;
            char where[256] = "C:\\Users\\HP\\Desktop\\";
            for(int i = 20; i < strlen(name) + 20; i++)
                where[i] = name[i-20];
            where[strlen(where)] = '.';
            where[strlen(where)] = 't';
            where[strlen(where)] = 'x';
            where[strlen(where)] = 't';

            // open the file
            ifstream file;
            file.open(where);

            // actually upload the key
            for(int j = 0; j < SCRAMBLERS; j++){
                for(int i = 0; i < 26; i++){
                    file >> scramblers[j][i];
                }
            }

            // check for possible errors, finish it and tide up
            if(file == NULL){
                cout << "there was an error uploading the key" << endl;
            }
            else {
                cout << "the key has been uploaded from " << where << endl;
                file.close();
            }
        }

        else if(strcmp(get, "printScramblers") == 0){

            // print the current scramblers settings
            cout << "the current scramblers' settings are: "<< endl;
            for(int i = 0; i < 26; i++){
                    cout << scramblers[0][i] << "\t" << scramblers[1][i] << "\t" << scramblers[2][i] << endl;
            }
            cout << endl;
       }

        else if(strcmp(get, "generateKey") == 0){

            // get the address and save it to where
            cout << "to what file should we upload the generated key?" << endl;
            char name[50];
            cin >> name;
            char where[256] = "C:\\Users\\HP\\Desktop\\";
            for(int i = 20; i < strlen(name) + 20; i++)
                where[i] = name[i-20];
            where[strlen(where)] = '.';
            where[strlen(where)] = 't';
            where[strlen(where)] = 'x';
            where[strlen(where)] = 't';

            // open the file
            ofstream file;
            file.open(where);

            // actually generate and upload the key
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

                    // najdi x-tou pozici
                    for(int a = 0; a <= 26; a++)
                    {

                        if(moznePosuny[a] != -1)
                        {

                            if(x == 0)
                            {
                                file << moznePosuny[a] << endl;
                                moznePosuny[a] = -1;
                                break;
                            }

                            // jdi dal
                            x--;
                        }

                    }
                }

                file << endl;
            }


            // finish it and tide up
            cout << "the key has been saved to " << where << endl;
            file.close();

        }
        if(strcmp(get, "resetShift") == 0){

            // zresetuj shift na {0, 0, 0}
            for(int i = 0; i < SCRAMBLERS; i++){
                shift[i] = 0;
            }

            // resetovani probehlo uspesne
            cout << "shift byl uveden do polohy: " << "\t" << 0 << "\t" << 0 << "\t" << 0 << endl;
        }

        if(strcmp(get, "setShift") == 0){

            // nastav kazdou slozku shift[]
            for(int i = 0; i < SCRAMBLERS; i++){

                // priprav si promenne
                cout << "Do jake polohy chcete uvest shift[" << i <<"]? ";
                int a;
                cin >> a;

                // shift je platne cislo
                if(a >= 0 and a < 26){
                    shift[i] = a;
                }

                // shift neni platne cislo, zkus znovu
                else {
                    cout << "neplatny shift, zadej znovu" << endl;
                    i--;
                }
            }

            // nech si to uzivatele zkontrolovat
            cout << "shift byl uveden do polohy: " << "\t" << shift[0] << "\t" << shift[1] << "\t" << shift[2] << endl;
        }

        if(strcmp(get, "printShift") == 0){

            // vypis shift[]
            cout << "shift je v poloze: " << "\t" << shift[0] << "\t" << shift[1] << "\t" << shift[2] << endl;
        }

        if(strcmp(get, "cypher") == 0){

            // priprav promenne
            cout << "Zadejte text k sifrovani: ";
            char openText[256];
            cin >> openText;
            char c;

            // pro kazdy znak z nacteneho textu sifruj
            for(int i = 0, n = strlen(openText); i < n; i++){

                // preved sifrovany text do tiskacich
                c = openText[i];
                c = toupper(c);

                // pokud je sifrovany znak pismeno, jinak ho nech nezmeneny
                if(c >= 'A' and c <= 'Z'){

                    // zasifruj skrz vsechny scramblery
                    for(int j = 0; j < SCRAMBLERS; j++){

                        // zasifruj znak dle klice v j-tem scrambleru
                        if (c - 'A' - shift[j] - rotor[j] < 0){
                            c = scramblers[j][26 + c - 'A' - shift[j] - rotor[j]] + 'A';
                        }
                        else
                            c = scramblers[j][c - 'A' - shift[j] - rotor[j]] + 'A';

                    }

                    // otoc scramblers
                    shift[0]++;
                    if(shift[0] == 26){
                        shift[1]++;
                        shift[0] = 0;

                        if(shift[1] == 26){
                            shift[2]++;
                            shift[1] = 0;

                            if(shift[2] == 26){
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
       }

        if(strcmp(get, "decypher") == 0){

            // priprav si promenne
            cout << "Zde zadejte text k desifrovani: ";
            char openText[256];
            cin >> openText;
            char c;
            int a;

            // zkontroluj, jestli uzivatel nechce vyuzit lastCypher
            if(strcmp(openText,"-lc") == 0){
                // napln openText lastCypher
                for(int i = 0, length = strlen(lastCypher); i < length; i++)
                    openText[i] = lastCypher[i];
                // zresetuj shift na {0, 0, 0}
                for(int i = 0; i < SCRAMBLERS; i++){
                    shift[i] = 0;
                }
            }
            openText[strlen(lastCypher)] = NULL;

            // proved pro kazdy znak z openText
            for(int i = 0, n = strlen(openText); i < n; i++){

                // preved sifrovany text do tiskacich
                c = openText[i];
                c = toupper(c);

                // pokud je sifrovany znak pismeno, jinak ho nech nezmeneny
                if(c >= 'A' and c <= 'Z'){

                    // desifruj skrze vsechny scramblers
                    for(int j = SCRAMBLERS - 1; j >= 0; j--){

                        // najdi c ve scramblers
                        a = 0;
                        while(scramblers[j][a] != c - 'A'){
                            a++;
                        }

                        // (semi)desifruj c
                        if(a + shift[j] + rotor[j] >= 26){
                            c = a + shift[j] + 'A' - 26 + rotor[j];
                        }
                        else
                            c = a + shift[j] + 'A' + rotor[j];

                    }

                    // zvys shift
                    shift[0]++;
                    if(shift[0] == 26){
                        shift[1]++;
                        shift[0] = 0;

                        if(shift[1] == 26){
                            shift[2]++;
                            shift[1] = 0;

                            if(shift[2] == 26){
                                shift[2] = 0;
                            }
                        }
                    }
                }

                // vypis desifrovany znak
                cout << c;

            }

            // priprav se na dalsi get
            cout << endl;
        }

        if(strcmp(get, "setRotor") == 0){

            // nastav kazdou slozku rotor[]
            for(int i = 0; i < SCRAMBLERS; i++){

                // priprav si promenne
                cout << "Do jake polohy chcete uvest rotor[" << i <<"]? ";
                int a;
                cin >> a;

                // rotor je platne cislo
                if(a >= 0 and a < 26){
                    rotor[i] = a;
                }

                // shift neni platne cislo, zkus znovu
                else {
                    cout << "neplatny rotor, zadej znovu" << endl;
                    i--;
                }
            }

            // nech si to uzivatele zkontrolovat
            cout << "rotor byl uveden do polohy: " << "\t" << rotor[0] << "\t" << rotor[1] << "\t" << rotor[2] << endl;
        }
        if(strcmp(get, "printRotor") == 0){

            // vypis rotor[]
            cout << "rotor je v poloze: " << "\t" << rotor[0] << "\t" << rotor[1] << "\t" << rotor[2] << endl;
        }

        if(strcmp(get, "resetRotor") == 0){

            // zresetuj rotor na {0, 0, 0}
            for(int i = 0; i < SCRAMBLERS; i++){
                rotor[i] = 0;
            }

            // resetovani probehlo uspesne
            cout << "rotor byl uveden do polohy: " << "\t" << 0 << "\t" << 0 << "\t" << 0 << endl;
        }

    // zde konci do-while
    }
    while (strcmp(get, "end"));

    return 0;
}
