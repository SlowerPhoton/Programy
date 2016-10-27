#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define SIZE_OF_MESSAGE 256

using namespace std;

void debugArray(int arr[], int arrSize, int lom);
void debugArray(char arr[], int lom, bool character);
void debugArray(bool arr[], int arrSize, int lom);
void debugSubkeys(bool subKeys[16][48]);

void permutation(int permutation[], bool toPermute[], bool outcome[], int sizeOfPermutation);
int toDecimal(bool binary[], int noOfNumbers);

void messageExpand(char message[]);
void toBinary(char origin[], bool binary[]);

void divideBinary(bool binary[], int sizeOfBinary, bool LB[], bool RB[]);

void getKey(char key[8]);

/* POZN. existuji dalsi pomocne zde nevypsane funkce*/
void createSubkeys(bool binaryKey[8*8], bool subkeys[16][48]);
void encodeMessage(bool binaryMessage[64], bool subkeys[16][48], bool encrypted[64]);

char* binToString(bool binary[], int noOfChars);
int main()
{
    char message[SIZE_OF_MESSAGE];
    cout << "Zadejte zpravu k zasifrovani: ";
    gets(message);

    messageExpand(message); // the number of characters in the message must be a multiple of 8

    bool binaryMessage[strlen(message)*8];

    /* DEBUG purposes
    bool binaryMessage[] = {0,0,0,0, 0,0,0,1, 0,0,1,0, 0,0,1,1, 0,1,0,0, 0,1,0,1, 0,1,1,0, 0,1,1,1, 1,0,0,0, 1,0,0,1, 1,0,1,0, 1,0,1,1, 1,1,0,0, 1,1,0,1, 1,1,1,0, 1,1,1,1};
    */

    toBinary(message, binaryMessage);


    /* PROC SE TO VUBEC DELA? */
    bool leftBM[strlen(message)*8/2], rightBM[strlen(message)*8/2];
    divideBinary(binaryMessage, strlen(message)*8, leftBM, rightBM);

    char key[8];
    getKey(key);

    bool binaryKey[8*8];
    toBinary(key, binaryKey);

    /* DEBUG purposes
    bool binaryKey[64] = {0,0,0,1,0,0,1,1, 0,0,1,1,0,1,0,0, 0,1,0,1,0,1,1,1, 0,1,1,1,1,0,0,1, 1,0,0,1,1,0,1,1, 1,0,1,1,1,1,0,0, 1,1,0,1,1,1,1,1, 1,1,1,1,0,0,0,1};
    */

    /// Step 1: Create 16 subkeys, each of which is 48-bits long.
    bool subkeys[16][48];
    createSubkeys(binaryKey, subkeys);

    /// Step 2: Encode each 64-bit block of data.
    for(int i = 0, length = strlen(message)*8; i < length; i+=64){
        bool C[64]; // to store the encrypted message
        encodeMessage(binaryMessage+i, subkeys, C);

        // couting the encrypted message
        for(int j = 0; j < 64; j+=8){
            cout << toDecimal(C+j, 8);
            cout << "\t";
        }
        cout << endl;

    }




    return 0;
}

void debugArray(int arr[], int arrSize, int lom){
    int i = 0;
    while(i < arrSize){
        cout << arr[i] << "\t";
        if((i+1)%lom == 0)
            cout << endl;

        i++;
    }
    cout << endl;
}

void debugArray(bool arr[], int arrSize, int lom){
    int i = 0;
    while(i < arrSize){
        cout << arr[i] << "\t";
        if((i+1)%lom == 0)
            cout << endl;

        i++;
    }
    cout << endl;
}

void debugArray(char arr[], int lom, bool character){
    unsigned int i = 0;
    while(i < strlen(arr)){
        if(character == true)cout << arr[i] << "\t";
        else cout << (int) arr[i] << "\t";

        if((i+1)%lom == 0)
            cout << endl;

        i++;
    }
    cout << endl;
}

void debugSubkeys(bool subKeys[16][48]){
    for(int i = 0; i < 16; i++){
        for(int j = 0; j < 48; j++){
            cout << subKeys[i][j];
            if((j+1)%6==0)
                cout << "\t";
        }
        cout << endl;
    }
}

int toDecimal(bool binary[], int noOfNumbers){
    int powOf2 = 1;
    int decimal = 0;

    for(int i = noOfNumbers-1; i >= 0; i--){
        decimal += powOf2*binary[i];
        powOf2*=2;
    }

    return decimal;
}

char* binToString(bool binary[], int noOfChars){
    char answer[noOfChars];
    for(int i = 0; i < noOfChars*8; i+=8){
        int dec = toDecimal(binary+i, 8);
        cout << dec << " ";
        answer[i/8] = char (dec);
    }
    return answer;
}

void toBinary(char origin[], bool binary[]){
    int powOf2;
    for(unsigned int i = 0; i < strlen(origin); i++){
        bool zasobnik[8] = {0,0,0,0,0,0,0,0};
        int toProcess = origin[i];
        // 8 bitu -> nejvetsi mozne cislo (unsigned) je 255
        // prvni misto bytu predstavuje 128
        int n;
        for(powOf2 = 128, n=0; n<8; powOf2/=2, n++){
            if(powOf2 <= toProcess){
                toProcess -= powOf2;
                zasobnik[n] = 1;
            }
        }

        // nakopiruj zasobik do odpovidajiciho indexu binary[]
        for(int j = 0; j < 8; j++)
            binary[i*8+j] = zasobnik[j];
    }
}

void messageExpand(char message[]){
    int charsToAdd = (8 - strlen(message)%8)%8;
    for(int i = 0; i < charsToAdd; i++){
        message[strlen(message)+1] = '\0';
        message[strlen(message)] = '0';
    }
}

void divideBinary(bool binary[], int sizeOfBinary, bool LB[], bool RB[]){
    int half = sizeOfBinary/2;
    /// LB - prvni pulka
    int i = 0;
    for(; i < half; i++){
        LB[i] = binary[i];
    }
    /// RB - druha pulka
    for(; i < half*2; i++){
        RB[i - half] = binary[i];
    }
}

void getKey(char key[8]){
    cout << "Zadej klic o 8 znacich: " << endl;
    for(int i = 0; i < 8; i++){
        //cout << ">";
        char character;
        cin >> character;
        //cout << '\r';
        key[i] = character;
    }
    cout << endl;
}

void permutation(int permutation[], bool toPermute[], bool outcome[], int sizeOfPermutation){
    for(int i = 0; i < sizeOfPermutation; i++){
        outcome[i] = toPermute[permutation[i] - 1];
    }
}

// funkce pro potreby createSubkeys
void leftShift(bool toShift[28], int noOfShifts, bool destination[28]){

    for(int i = 0; i < 28; i++){
        destination[(i - noOfShifts + 28)%28] = toShift[i];
    }
}

void createSubkeys(bool binaryKey[8*8], bool subkeys[16][48]){

    int pc_1[56] = {
        57, 49, 41, 33, 25, 17,  9,
         1, 58, 50, 42, 34, 26, 18,
        10,  2, 59, 51, 43, 35, 27,
        19, 11,  3, 60, 52, 44, 36,
        63, 55, 47, 39, 31, 23, 15,
         7, 62, 54, 46, 38, 30, 22,
        14,  6, 61, 53, 45, 37, 29,
        21, 13,  5, 28, 20, 12,  4
    };
    bool keyPermutation[56];

    /// podle pc_1 vytvor z 64 bitoveho key 56 bitove keyPermutaion
    for(int i = 0; i < 56; i++){
        keyPermutation[i] = binaryKey[pc_1[i]-1];
    }

    /// zde se budou ukladat C a D: [C/D] [index] [28 boolu]
    bool CD[2][16+1][56/2];

    /// rozpul keyPermutation do C0 a D0 - kazde ma 28 bitu
    divideBinary(keyPermutation, 56, CD[0][0], CD[1][0]);

    /// podle C0, D0 a shifts vytvor C1, D1 -> C16, D16
    int shifts[16] = { 1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1 };
    for(int i = 1; i < 17; i++){
        leftShift(CD[0][i-1], shifts[i-1], CD[0][i]);
        leftShift(CD[1][i-1], shifts[i-1], CD[1][i]);
    }

    // vyznam pro debug - vypisuje CD
/*
        for(int r = 0; r < 17; r++){
            for(int a = 0; a < 2; a++){
                 if(a == 0)
                        cout << "C" << r << ": ";
                else
                    cout << "D" << r << ": ";
                for(int i = 0; i<28; i++){
                    cout << CD[a][r][i];
                }
                cout << endl;
            }
            cout << endl;
        }
    cout << endl;
*/

    /// kazdy subKey ze 16 vychazi z jednoho ze sestnacti CD podle pc_2 predpisu
    int pc_2[48] = {
        14,    17,   11,    24,     1,    5,
         3,    28,   15,     6,    21,   10,
        23,    19,   12,     4,    26,    8,
        16,     7,   27,    20,    13,    2,
        41,    52,   31,    37,    47,   55,
        30,    40,   51,    45,    33,   48,
        44,    49,   39,    56,    34,   53,
        46,    42,   50,    36,    29,   32
    };

    for(int i = 0; i < 16; i++){
        for(int j = 0; j < 48; j++){

            /// rozhodni, do ktere casti CD se divat - tzn. C, nebo D? pro C je CorD 0, pro D je 1
            int kde = pc_2[j] - 1;
            bool CorD = 0;
            if(kde >= 56/2){
                CorD = 1;
                kde-=56/2; // sniz kde o 28, abychom byli v pripade D opet indexovani od 0
            }

            subkeys[i][j] = CD[CorD][i+1][kde];
        }
    }
}

// pro potreby encodeMessage():

void rewrite(bool co[], bool cim[], int noOfIndexes){
    for(int i = 0; i < noOfIndexes; i++)
        co[i] = cim[i];
}

bool XOR(bool a, bool b){
    return (a+b)%2;
}

void XOR(bool kam[], bool scitanec1[], bool scitanec2[], int noOfNumbers){
    for(int i = 0; i < noOfNumbers; i++){
        kam[i] = (scitanec1[i] + scitanec2[i])%2;
    }
}

int lookUpInSBox(int which, bool address[6], bool binaryOutcome[4]){
    int SBoxes[8][4][16] = {

                             /*S1*/

   { {14,  4,  13,  1,   2, 15,  11,  8,   3, 10,   6, 12,   5,  9,   0,  7},
     { 0, 15,   7,  4,  14,  2,  13,  1,  10,  6,  12, 11,   9,  5,   3,  8},
     { 4,  1,  14,  8,  13,  6,   2, 11,  15, 12,   9,  7,   3, 10,   5,  0},
     {15, 12,   8,  2,   4,  9,   1,  7,   5, 11,   3, 14,  10,  0,   6, 13}    },

                             /*S2*/

   { {15,  1,   8, 14,   6, 11,   3,  4,   9,  7,   2, 13,  12,  0,   5, 10,},
     { 3, 13,   4,  7,  15,  2,   8, 14,  12,  0,   1, 10,   6,  9,  11,  5,},
     { 0, 14,   7, 11,  10,  4,  13,  1,   5,  8,  12,  6,   9,  3,   2, 15,},
     {13,  8,  10,  1,   3, 15,   4,  2,  11,  6,   7, 12,   0,  5,  14,  9}    },

                             /*S3*/

   { {10,  0,   9, 14,   6,  3,  15,  5,   1, 13,  12,  7,  11,  4,   2,  8,},
     {13,  7,   0,  9,   3,  4,   6, 10,   2,  8,   5, 14,  12, 11,  15,  1,},
     {13,  6,   4,  9,   8, 15,   3,  0,  11,  1,   2, 12,   5, 10,  14,  7,},
     { 1, 10,  13,  0,   6,  9,   8,  7,   4, 15,  14,  3,  11,  5,   2, 12}     },

                             /*S4*/

   { { 7, 13,  14,  3,   0,  6,   9, 10,   1,  2,   8,  5,  11, 12,   4, 15,},
     {13,  8,  11,  5,   6, 15,   0,  3,   4,  7,   2, 12,   1, 10,  14,  9,},
     {10,  6,   9,  0,  12, 11,   7, 13,  15,  1,   3, 14,   5,  2,   8,  4,},
     { 3, 15,   0,  6,  10,  1,  13,  8,   9,  4,   5, 11,  12,  7,   2, 14}     },

                             /*S5*/

   { { 2, 12,   4,  1,   7, 10,  11,  6,   8,  5,   3, 15,  13,  0,  14,  9,},
     {14, 11,   2, 12,   4,  7,  13,  1,   5,  0,  15, 10,   3,  9,   8,  6,},
     { 4,  2,   1, 11,  10, 13,   7,  8,  15,  9,  12,  5,   6,  3,   0, 14,},
     {11,  8,  12,  7,   1, 14,   2, 13,   6, 15,   0,  9,  10,  4,   5,  3}     },

                             /*S6*/

   { {12,  1,  10, 15,   9,  2,   6,  8,   0, 13,   3,  4,  14,  7,   5, 11,},
     {10, 15,   4,  2,   7, 12,   9,  5,   6,  1,  13, 14,   0, 11,   3,  8,},
     { 9, 14,  15,  5,   2,  8,  12,  3,   7,  0,   4, 10,   1, 13,  11,  6,},
     { 4,  3,   2, 12,   9,  5,  15, 10,  11, 14,   1,  7,   6,  0,   8, 13}     },

                             /*S7*/

   { { 4, 11,   2, 14,  15,  0,   8, 13,   3, 12,   9,  7,   5, 10,   6,  1,},
     {13,  0,  11,  7,   4,  9,   1, 10,  14,  3,   5, 12,   2, 15,   8,  6,},
     { 1,  4,  11, 13,  12,  3,   7, 14,  10, 15,   6,  8,   0,  5,   9,  2,},
     { 6, 11,  13,  8,   1,  4,  10,  7,   9,  5,   0, 15,  14,  2,   3, 12}     },

                             /*S8*/

   { {13,  2,   8,  4,   6, 15,  11,  1,  10,  9,   3, 14,   5,  0,  12,  7,},
     { 1, 15,  13,  8,  10,  3,   7,  4,  12,  5,   6, 11,   0, 14,   9,  2,},
     { 7, 11,   4,  1,   9, 12,  14,  2,   0,  6,  10, 13,  15,  3,   5,  8,},
     { 2,  1,  14,  7,   4, 10,   8, 13,  15, 12,   9,  0,   3,  5,   6, 11}     }

                        };

    /// row corresponds to the binary number consisting of the first and last index of address
    bool row[2];
    row[0] = address[0]; row[1] = address[5];

    /// column corresponds to the middle 4 bits of address
    bool column[4];
    rewrite(column, address+1, 4);

    int number = SBoxes[which][toDecimal(row, 2)][toDecimal(column, 4)];

    /// preved number na binary cislo ulozene v answer
    bool answer[4] = {0,0,0,0}; int numberNotOverwrite = number;
    int powOf2 = 8;
    for(int i = 0; i < 4; i++){
        if(numberNotOverwrite >= powOf2){
            answer[i] = 1;
            numberNotOverwrite -= powOf2;
        }

        powOf2/=2;
    }

    /// prekopiruj answer do binaryOutcome
    rewrite(binaryOutcome, answer, 4);

    return number;

}

void f(bool R[32], bool K[48], bool outcome[32]){

    /// expand each R from 32 to 48 bits to E
    int E_BIT[48] = {

                 32,     1,    2,     3,     4,    5,
                  4,     5,    6,     7,     8,    9,
                  8,     9,   10,    11,    12,   13,
                 12,    13,   14,    15,    16,   17,
                 16,    17,   18,    19,    20,   21,
                 20,    21,   22,    23,    24,   25,
                 24,    25,   26,    27,    28,   29,
                 28,    29,   30,    31,    32,    1
    };

    bool E[48];
    for(int i = 0; i < 48; i++){
        E[i] = R[E_BIT[i]-1];
    }

    /// XOR Kn and  E(Rn-1)
    bool KxorE[48];
    for(int i = 0; i < 48; i++){
        KxorE[i] = XOR(K[i], E[i]);
    }

    /* JEN PRO TESTOVANI!!!! NASLEDNE SMAZAT
    bool TESTING_PLS_DELETE_ME[] = {0,1,1,0,0,0, 0,1,0,0,0,1, 0,1,1,1,1,0, 1,1,1,0,1,0, 1,0,0,0,0,1, 1,0,0,1,1,0, 0,1,0,1,0,0, 1,0,0,1,1,1};
    rewrite(KxorE, TESTING_PLS_DELETE_ME, 48);
    KONEC MAZANI */

    /// Kazde sesticisli z KxorE nyni pouzijeme jako adresu v jednom z S boxu, zpet dostaneme 4 bitove cislo
    bool S[32];
    for(int i = 0; i < 48; i+=6){
        bool answer[4];
        lookUpInSBox(i/6, KxorE+i, answer); // do answer uloz to, co najdeme v S boxech
        rewrite(S+(i/6)*4, answer, 4);
    }

    /// now we use P to permute S[] to finally create the outcome
    int P[32] = {
                         16,   7,  20,  21,
                         29,  12,  28,  17,
                          1,  15,  23,  26,
                          5,  18,  31,  10,
                          2,   8,  24,  14,
                         32,  27,   3,   9,
                         19,  13,  30,   6,
                         22,  11,   4,  25
    };

    for(int i = 0; i < 32; i++){
        outcome[i] = S[P[i]-1];
    }

}
void encodeMessage(bool binaryMessage[64], bool subkeys[16][48], bool encrypted[64]){
    /// permutuj binaryMessage podle IP do permutatedMessage
    int IP[64] = {
            58,    50,   42,    34,    26,   18,    10,    2,
            60,    52,   44,    36,    28,   20,    12,    4,
            62,    54,   46,    38,    30,   22,    14,    6,
            64,    56,   48,    40,    32,   24,    16,    8,
            57,    49,   41,    33,    25,   17,     9,    1,
            59,    51,   43,    35,    27,   19,    11,    3,
            61,    53,   45,    37,    29,   21,    13,    5,
            63,    55,   47,    39,    31,   23,    15,    7
    };

    bool permutatedMessage[64];

    for(int i = 0; i < 64; i++){
        permutatedMessage[i] = binaryMessage[IP[i]-1];
    }

    /// vytvor L0 and R0 rozdelenim permutatedMessage, prvni index predstavuje L [0], nebo R [1]
    bool LR[2][17][64/2];
    divideBinary(permutatedMessage, 64, LR[0][0], LR[1][0]);

    for(int i = 1; i <= 16; i++){

        rewrite(LR[0][i], LR[1][i-1], 64/2); // Ln = Rn-1
        // Rn = Ln-1 + f(Rn-1,Kn):
        bool outcome[32]; f(LR[1][i-1], subkeys[i-1] /* POZN. v me terminologii jsou klice cislovany od 0*/, outcome); // zavolej funkci f na Rn-1, Kn, jeji vysledek uloz do outcome[]
        bool soucet[32];
        XOR(soucet, LR[0][i-1], outcome, 32);

        /// soucet, ktery odpovida vyrazu Ln-1 + f(Rn-1,Kn) ted uz jen staci nakopirovat do Rn
        rewrite(LR[1][i], soucet, 32);
        /*DEBUG
        if(i == 16){
            // debugArray(LR[0][0], 32, 4); // L0 funguje
            debugArray(LR[0][16], 32, 4);
            debugArray(LR[1][16], 32, 4);
        }*/

    }

    /// R16L16 po permutaci IP-1 odpovidaji zasifrovane zprave C

    int IP_1[64] = {
            40,     8,   48,    16,    56,   24,    64,   32,
            39,     7,   47,    15,    55,   23,    63,   31,
            38,     6,   46,    14,    54,   22,    62,   30,
            37,     5,   45,    13,    53,   21,    61,   29,
            36,     4,   44,    12,    52,   20,    60,   28,
            35,     3,   43,    11,    51,   19,    59,   27,
            34,     2,   42,    10,    50,   18,    58,   26,
            33,     1,   41,     9,    49,   17,    57,   25
    };

    bool R16L16[64];
    rewrite(R16L16, LR[1][16], 32); // R16
    rewrite(R16L16 + 32, LR[0][16], 32); // L16

    bool C[64];
    permutation(IP_1, R16L16, C, 64);

    rewrite(encrypted, C, 64);
    // debugArray(C, 64, 8);
}
