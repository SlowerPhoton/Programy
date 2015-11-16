#include <iostream>
#include <string.h>
#include <stdio.h>
#include <fstream>

using namespace std;

int main()
{
    cout << "Zadej klic!" << endl;
    cout << ">";

    char key[256];
    gets(key);
    //cout << key.length() << endl;

    // priprav array S podle klice
    int S[256];
    for(int i = 0; i < 256; i++){
        S[i] = i;
    }
    int j = 0;
    for(int i = 0; i < 256; i++){ cout << "i: " << i << '\t';
        j = (j + S[i] + key[i % strlen(key)] - 'a')%256; cout << "j: " << j<< '\t';
        if(j < 0){
            cout << endl;
            cout << "POZOR! ";
            cout << "S[i] " << S[i] << '\t' << "key(i%strlen(key)) " << int (key[i%strlen(key)]) << endl;
        }
        int pom = S[j]; cout << "S[i]: " << S[i]<< '\t'; cout << "S[j]: " << S[j]<< '\t';
        S[j] = S[i];
        S[i] = pom;
        cout << endl;
    }
    ofstream debug;
    debug.open("debug.txt");

    for(int i = 0; i < 256; i++)
            debug << S[i] << endl;
    /*for(int i = 0; i < 256; i++){
        cout << S[i] << endl;
    }*/


    int i = 0;
    j = 0;
    for(int a = 0; a < 8; a++){
        i = (i + 1) % 256;
        j = (j + S[i]) % 256;
        int pom = S[i];
        S[i] = S[j];
        S[j] = pom;
        cout << (S[(S[i] + S[j]) % 256]) << " ";
    }

    return 0;
}
