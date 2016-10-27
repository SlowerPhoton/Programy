#include <iostream>

using namespace std;

int N;
int k;

void getN();
void getk();
void getKameny(int tarArr[]);

int countPMP(void);

int muzuPredCislo(int jakeCislo, int predCislo, int kameny[]);

void posun(int jakouPozici, int oKolik, int kameny[]);

void tiskniKameny(int kameny[]){
    for(int i = 0; i < N; i++)
        cout << kameny[i] << '\t';
    cout << endl;
}

int main()
{
    cout << "PICCCCCCCCCCCC";
    getN();
    getk();
    int kameny[N]; getKameny(kameny);

    /// vytrid k == 1
    if(k == 1){ // je-li k = 1, jakykoliv kamen muzeme premistit do jakekoliv pozice, tedy reseni je vzdy
        cout << "ano" << endl;
        return 0;
    }

    int pocetMoznostiPresunu = countPMP();
    if(pocetMoznostiPresunu == N - 1){ // vytrid dasi vzdy vyherni kombinaci
        cout << "ano" << endl;
        return 0;
    }


    while(1){
        int tah; cin >> tah;
        int predCo; cin >> predCo;

        int poloha1 = -1;
        for(int i = 0; i < N; i++){
            if(kameny[i] == tah){
                poloha1 = i;
                break;
            }
        }
        if(poloha1 == -1) continue;

        int answer = muzuPredCislo(poloha1, predCo, kameny);
        cout << "musi se posunout o: " << answer << endl;
        if(answer == -1) continue;

        posun(poloha1, answer, kameny);
        tiskniKameny(kameny);

    }

    cout << endl << endl;
    bool zmena = true;
    /// prochazej kameny[] a premistuj vysinuta cisla, dokud se budou dit zmeny
    /*while(zmena){
        zmena = false;
        for(int i = 0; i < N; i++){
            if((kameny[i] + 1)%(N+1) != kameny[(i+1)%N]){
                int answer = muzuPredCislo(i, (kameny[i] + 1)%(N+1), kameny);
                posun(i, answer, kameny);
                if(answer!=-1){ zmena = true; tiskniKameny(kameny);}
            }
        }
    }
    tiskniKameny(kameny);*/




    return 0;
}

int countPMP(void){
    int n = N;
    n--;
    if(n%k == 0)
        n /= k;
    return n;
}

void getN(){
    cout << "Zadej N:" << endl;
    cin >> N;
}

void getk(){
    cout << "Zadej k:" << endl;
    cin >> k;
}

void getKameny(int tarArr[]){
    cout << "Zadej cisla kamenu, jeden po druhem: " << endl;
    for(int i = 0; i < N; i++){
        cout << ">";
        cin >> tarArr[i];
    }
}

int muzuPredCislo(int polohaCisla, int predCislo, int kameny[]){
    int poloha2;
    for(int i = 0; i < N; i++){
        if(kameny[i] == predCislo){
            poloha2 = i;
            break;
        }
    }

    int kolikSeMusiPosunout = ((N - poloha2)%N + polohaCisla)%N; // funguje vyborne, muze se do te pozice dostat pokud kolikSeMusiPosunout % 2 == 0
    //cout << "kolik se musi posunout: " << kolikSeMusiPosunout << endl;

    if(kolikSeMusiPosunout%k == 0)
        return kolikSeMusiPosunout;
    else
        //cout << "NELZE: MUSELO BY SE POSUNOUT: " << kolikSeMusiPosunout << endl;
        return -1;

}

void posun(int jakouPozici, int oKolik, int kameny[]){
    if(oKolik == -1){
        //cout << "-1! Nelze presunout!" << endl;
        return;
    }

    int cisloKPremisteni = kameny[jakouPozici];
    cout << "cisloKPremisteni: " << kameny[jakouPozici] << endl;

    oKolik = N - oKolik - 1;
    for(int i = 0; i < oKolik; i++){
        cout << "misto " << kameny[(jakouPozici+i)%N] << " bude " << kameny[(jakouPozici+i+1)%N] << endl;
        kameny[(jakouPozici+i)%N] = kameny[(jakouPozici+i+1)%N];
    }
    kameny[(jakouPozici+oKolik)%N] = cisloKPremisteni;
}
