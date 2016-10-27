#include <iostream>
#include <istream>
#include <cstdlib>
#include <fstream>
#include <string.h>


using namespace std;

int main()
{
    ifstream original;
    //original.open("sifra.txt");

    fstream newOne;
    //newOne.open("newOne.txt");

    char input [260] = "nothing";

    //cout << strlen(input);

    // fill newOne with original
    original.open("sifra.txt");
    newOne.open("newOne.txt");

    while(1){

        char pass;
        original.get(pass);

        if(!original.eof()) newOne << pass;
        else break;
    }

    original.close();
    newOne.close();

    do
    {
        cin >> input;

        if (strlen(input) == 2)
        {
            // capitalize
            if(input[0] >= 'a' and input[0] <= 'z')
            {
                input[0] -= 'a' - 'A';
            }


            if (input[0] >= 'A' and input[0] <= 'Z')
            {

                // start from the beginning
                newOne.open("newOne.txt");
                char newToString[1000];
                int i = 0;

                while(1){
                    char pass;
                    newOne.get(pass);

                    if (newOne.eof()){break;}
                    if (pass == input[0]){
                            pass = input[1];
                    }

                    newToString [i] = pass; i++;

                }
                newOne.close();

                newOne.open("newOne.txt");

                for(int a = 0, length = strlen(newToString); a < length - 1; a++){
                    newOne << newToString[a];
                }

                newOne.close();

            }

            else {
                cout << "Command doesn't exist." << endl;
            }
        }

        if(strcmp(input, "original")==0){

            original.open("sifra.txt");
            char output;

            while(1){
                original.get(output);
                //original >> output;
                if(!original.eof()){
                    cout << output;
                }
                else break;
            }

            cout << endl;

            original.close();
        }

        if(strcmp(input, "new")==0){

            newOne.open("newOne.txt");
            char output;

            while(1){
                newOne.get(output);
                if (!newOne.eof()) cout << output;
                else break;
            }

            cout << endl;

            newOne.close();
        }

        // count the characters
        if(strlen(input) == 1){

            // capitalize
            if(input[0] >= 'a' and input[0] <= 'z')
            {
                input[0] -= 'a' - 'A';
            }

            original.open("sifra.txt");

            int number = 0;

            while(1){
                    char test;
                    original.get(test);

                    if (original.eof()){break;}
                    if (test == input[0]){
                            number++;
                    }
            }

            cout << "number of " << input[0] << ": " << number << endl;

            original.close();
        }

        //count all characters
        if(strcmp(input, "data")==0){

            // capitalize
            if(input[0] >= 'a' and input[0] <= 'z')
            {
                input[0] -= 'a' - 'A';
            }

            for (int i = 'A'; i <= 'Z'; i++){
                original.open("sifra.txt");

                int number = 0;

                while(1){
                        char test;
                        original.get(test);

                        if (original.eof()){break;}
                        if (test == i){
                                number++;
                        }
                }

                cout << "number of " << (char) i << ": " << number << endl;

                original.close();
            }
        }

        // fill newOne with original
        if(strcmp(input, "reset") == 0){
            original.open("sifra.txt");
            newOne.open("newOne.txt");

            while(1){

                char pass;
                original.get(pass);

                if(!original.eof()) newOne << pass;
                else break;
            }

            original.close();
            newOne.close();
        }


    }
    while (strcmp(input, "end") != 0);

    return 0;
}
