#include <iostream>

using namespace std;

void orezMezery(char* s)
{
    // find length
    size_t n = 0;
    while(s[n] != '\0') n++;

    // umaz mezery zezacatku
    size_t i = 0;
    size_t posun = 0;
    while(i < n and s[i] == ' ')
    {
         posun++;
         i++;
    }
    cout << posun << endl;
    for (int j = 0; j <= n-posun; j++){
        *(s+j) = *(s+posun+j);
    }

    // umaz mezery odkonce
    i = n-posun-1;
    while(i >= 0 and s[i] == ' ')
    {
        s[i] = '\0';
        i--;
    }
}

void setToNull (char* s){
    *s = '\0';
}

void pridejZpetneLomitko(char *s)
{
    // find length
    size_t n = 0;
    while(s[n] != '\0') n++;

    if (s[n-1] == '\\') return;
    //cout << s[n-1] << endl;
    s[n] = '\\';
    s[n+1] = '\0';
}

void strdel(char *s, int pozice, int pocet)
{
    // find length
    size_t n = 0;
    while(s[n] != '\0') n++;

    for (int j = 0; j < n-pocet-pozice+1; j++){
        *(s+pozice+j) = *(s+pozice+j+pocet);
    }
    s[n-pocet] = '\0';
}

int main()
{
    char test[] = "tak ja testuju \\";
    //cout << sizeof(test) << endl;
    cout << "|" << test << "|" << endl;
    // cout << "|" << test[19] << "|" << endl;
    orezMezery(test);
    cout << "|" << test << "|" << endl;
    pridejZpetneLomitko(test);
    cout << "|" << test << "|" << endl;
    strdel(test, 2, 4);
    cout << "|" << test << "|" << endl;
    return 0;
    /*char s[] = "hovno";
    cout << (int) s << endl;
    setToNull(s);
    cout << (int) s;
    cout << s;*/
}
