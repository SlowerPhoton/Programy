#include "key.h"
#include <iostream>
#include <limits.h>
#include <fstream>
#include <stdio.h>
#include <string>

void getKey(int key[], size_t keySize){

    // clear the buffer after cin used to get the message
    std::cin.clear(); std::cin.ignore(INT_MAX,'\n');

    // get the key
    std::cout << "Enter the key <string>: " << std::endl;
    std::string keyWord;
    getline(std::cin, keyWord);

    // in case the last position of keyWord is '\n' delete it
    if(keyWord[keyWord.length() - 1] == '\n'){
        keyWord[keyWord.length() - 1] = '\0';
    }

    keyTo8Bytes(keyWord, key, keySize);

    // overwrite keyWord
    for (int i = 0, n = keyWord.length(); i < n; i++)
        keyWord[i] = '0';
}

void keyTo8Bytes(std::string keyWord, int key[], size_t keySize){
    // prepare array S with numbers from 0 to 255
    int S[256];
    for(int i = 0; i < 256; i++){
        S[i] = i;
    }

    // shuffle S
    int j = 0;
    int length = keyWord.length();
    for(int i = 0; i < 256; i++){
        j = (j + S[i] + keyWord[i % length])%256;
        int pom = S[j];
        S[j] = S[i];
        S[i] = pom;
    }

    // use first 8 indexes from S (and shuffle them again)
    int i = 0;
    j = 0;
    for(size_t a = 0; a < keySize; a++){
        i = (i + 1) % 256;
        j = (j + S[i]) % 256;
        int pom = S[i];
        S[i] = S[j];
        S[j] = pom;
        key[a] = S[(S[i] + S[j]) % 256];
    }

    // overwrite S
    for(int i = 0; i < 256; i++){
        S[i] = 0;
    }
}
