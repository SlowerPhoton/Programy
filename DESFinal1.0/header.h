#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

void debugArray(int arr[], int arrSize, int lom);
void debugArray(char arr[], int lom, bool character);
void debugArray(bool arr[], int arrSize, int lom);
void debugSubkeys(bool subKeys[16][48]);

void permutation(int permutation[], bool toPermute[], bool outcome[], int sizeOfPermutation);
int toDecimal(bool binary[], int noOfNumbers);

int padding(int numbersInMessage);
void messageExpand(int message[], int numbersInMessage);
void toBinary(int origin[], bool binary[], int noOfNumbers);

void divideBinary(bool binary[], int sizeOfBinary, bool LB[], bool RB[]);

void getKey(int key[8]);
int getSizeOfMessage();
void getMessage(int message[], int numbersInMessage);

/* POZN. existuji dalsi pomocne zde nevypsane funkce*/
void createSubkeys(bool binaryKey[8*8], bool subkeys[16][48]);
void encodeMessage(bool binaryMessage[64], bool subkeys[16][48], bool encrypted[64]);

int test = 5;

bool encr = false;
void encrypt();

int return5(void);

#endif // HEADER_H_INCLUDED
