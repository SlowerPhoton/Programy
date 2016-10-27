#include <iostream>

using namespace std;

class TSetridenePole
{
    int pocetPrvku;
    int *polePrvku;

    int maximum;

    public:
    TSetridenePole(int mx)
    {
        polePrvku = new int[mx];
        pocetPrvku = 0;
        maximum = mx;
    }

    int vlozDoPole (int cislo)
    {
        if (pocetPrvku == maximum)
            return -1;
        int i = 0;
        while (i < pocetPrvku and cislo > polePrvku[i])
            i++;
        // vloz cislo a zacni posouvat prvky za nim
        int pom = polePrvku[i];
        polePrvku[i] = cislo;
        i++;
        while (i <= pocetPrvku)
        {
            int pom2 = pom;
            pom = polePrvku[i];
            polePrvku[i] = pom2;
            i++;
        }
        pocetPrvku++;
        return 0;
    }

    void tiskniPole()
    {
        for (int i = 0; i < pocetPrvku; i++)
            cout << polePrvku[i] << endl;
        cout << endl;
    }
};

int main()
{
    TSetridenePole pole(10);
    pole.vlozDoPole(2);
    pole.vlozDoPole(5);
    pole.vlozDoPole(7);
    pole.vlozDoPole(1);
    pole.vlozDoPole(0);
    pole.tiskniPole();

    return 0;
}
