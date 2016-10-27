#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(NULL));

    int n;
    cin >> n;

    int delegatZvolen = 0;
    for (int i = 0; i < n; i++)
    {
        int A = 0, B = 0, C = 0;
        for (int j = 0; j < 5; j++)
        {
            int hlas = rand()%3;
            switch(hlas)
            {
                case 0: A++; break;
                case 1: B++; break;
                case 2: C++; break;
            }
        }
        if ( A>=3 or B>=3 or C>=3 ) delegatZvolen++;
    }

    cout << (double)delegatZvolen / (double)n << endl;

    return 0;
}
