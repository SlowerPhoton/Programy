#include <iostream>

using namespace std;

void prevod10do2(unsigned char vstup, char *vystup)
{
    for (int i = 0; i < 8; i++)
    {
        vystup[7-i] = vstup%2 + '0';
        vstup /= 2;
    }
    vystup[8] = '\0';
}

void prevod2do10(char *vstup, unsigned char *vystup)
{
    unsigned char sum = 0; unsigned char k = 128;
    for (int i = 0; i < 8; i++)
    {
        sum += (vstup[i] - '0')*k;
        k/=2;
    }
    *vystup = sum;
}

int main()
{
    unsigned char vstup = 55;
    char vystup[8];
    prevod10do2(55, vystup);
    cout << vystup << endl;
    prevod2do10(vystup, &vstup);
    cout << (int) vstup << endl;

    return 0;
}
