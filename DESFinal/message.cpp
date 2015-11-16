#include "message.h"
#include <iostream>

extern bool encr;

int getSizeOfMessage(){
    if(encr)
        std::cout << "Enter the number of characters in the message to encrypt: " << std::endl;
    else
        std::cout << "Enter the number of characters in the encrypted message: " << std::endl;
    int numbersInMessage;
    std::cin >> numbersInMessage;
    return numbersInMessage;
}

int padding(int numbersInMessage){
    return (8 - numbersInMessage%8)%8;
}

void getMessage(int message[], int numbersInMessage){

    if(encr)
        std::cout << "Enter the message to encrypt: " << std::endl;
    else
        std::cout << "Enter the encrypted message: " << std::endl;
    for(int i = 0; i < numbersInMessage; i++){
        unsigned int nmbr; std::cin >> nmbr;
        message[i] = nmbr;
    }

}

void messageExpand(int message[], int numbersInMessage){
    int pad = padding(numbersInMessage);
    for(int i = numbersInMessage; i < pad + numbersInMessage; i++){
        message[i] = 0;
    }
}
