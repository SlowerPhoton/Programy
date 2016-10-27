#include <iostream>
#include <fstream>

using namespace std;

void loadKeyArrFromFile (char keyArr[13][13], char* fileName)
{
    ifstream input;
    input.open(fileName);

    for (int r = 0; r < 13; r++)
    {
        for (int c = 0; c < 13; c++)
        {
            char in;
            input.get(in);
            keyArr[r][c] = in;
            cout << in << " ";
        }
        cout << endl;
        input.get();
    }

    input.close();
}

void printKeyArray (char keyArr[13][13])
{
    // print header
    for (int i = 0; i < 13; i++)
        cout << char ('a' + i);
    cout << endl;

    for (int r = 0; r < 13; r++)
    {
        cout << char ('A' + r);
        for (int c = 0; c < 13; c++)
        {
            cout << keyArr[r][c];
        }
        cout << char ('n' + r);
        cout << endl;
    }

    // print footer
    for (int i = 0; i < 13; i++)
        cout << char ('N' + i);
    cout << endl;
}

void doStep (char direction, int *r, int *c)
{
    if (direction == 'n')
        *r = *r-1;
    else if (direction == 'e')
        *c = *c+1;
    else if (direction == 's')
        *r = *r+1;
    else if (direction == 'w')
        *c = *c-1;
}

char encryptLetter (char keyArr[13][13], char toEncrypt)
{
    /*  a -> m
       A      n
       |      |
       v      v
       M      z
        N -> Z  */

    int r, c;
    char direction;

    if (toEncrypt >= 'a' and toEncrypt <= 'm')
    {
        r = 0;
        c = toEncrypt - 'a';
        direction = 's';
    }
    else if (toEncrypt >= 'n' and toEncrypt <= 'z')
    {
        c = 12;
        r = toEncrypt - 'n';
        direction = 'w';
    }
    else if (toEncrypt >= 'A' and toEncrypt <= 'M')
    {
        c = 0;
        r = toEncrypt - 'A';
        direction = 'e';
    }
    else if (toEncrypt >= 'N' and toEncrypt <= 'Z')
    {
        r = 12;
        c = toEncrypt - 'N';
        direction = 'n';
    }
    else
    {
        cout << "UNSUPPORTED CHARACTER" << endl;
        return '\0';
    }

    while (true)
    {
        if (keyArr[r][c] == '\\')
        {
            if (direction == 'n')
                direction = 'w';
            else if (direction == 'e')
                direction = 's';
            else if (direction == 's')
                direction = 'e';
            else if (direction == 'w')
                direction = 'n';
        }
        else if (keyArr[r][c] == '/')
        {
            if (direction == 'n')
                direction = 'e';
            else if (direction == 'e')
                direction = 'n';
            else if (direction == 's')
                direction = 'w';
            else if (direction == 'w')
                direction = 's';
        }

        doStep(direction, &r, &c);
        //cout << "r: " << r << " c:" << c << " dir: " << direction << endl;

        if (r < 0)
            return c+'a';
        if (r > 12)
            return c+'N';
        if (c < 0)
            return r+'A';
        if (c > 12)
            return r+'n';
    }

}


int main()
{
    char keyArr[13][13];
    loadKeyArrFromFile(keyArr, "key.txt");
    printKeyArray(keyArr);

    while (true)
    {
        char in;
        cin >> in;

        cout << encryptLetter(keyArr, in) << endl;
    }

    return 0;
}
