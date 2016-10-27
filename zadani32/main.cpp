#include <iostream>

using namespace std;

int strlen (char *s)
{
    int n = 0;
    while (s[n] != '\0')
        n++;
    return n;
}

void strdel(char *s, int pozice, int pocet)
{
    int n = strlen (s);
    for (int i = 0; i <= n-pozice; i++)
    {
        s[pozice+i] = s[pozice+pocet+i];
    }
}

void strins(char *s1, char *s2, int pozice)
{
    int n1 = strlen (s1);
    int n2 = strlen (s2);
    char s[n1+n2-1];

    int i;
    for (i = 0; i < pozice; i++)
    {
        s[i] = s1[i];
    }
    for (i = 0; i < n2; i++)
    {
        s[pozice + i] = s2[i];
    }
    for (i = pozice; i <= n1; i++)
    {
        s[n2 + i] = s1[i];
    }

    for (int i = 0; i <= n1+n2-1; i++)
    {
        s1[i] = s[i];
    }
}

int main()
{
    char a[] = "Hello world!";
    strdel (a, 1, 2);
    cout << a << endl;
    strins (a, "el", 1);
    cout << a;

    return 0;
}
