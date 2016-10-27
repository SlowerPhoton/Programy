#include <iostream>

using namespace std;

bool repetition(int record[], int i);

int main()
{
    // nacti N
    cout << "Jake je N?" << endl;
    int N; cin >> N;
    if(N == 1) return 1;

    // nacti cisla a, b, c
    cout << "Zadej a, b, c:" << endl;
    int a; cin >> a;
    int b; cin >> b;
    int c; cin >> c;

    // priprav si record
    int *record;
    record = new int[N*N*N];
    cout << "Zadej prvni tri cipy:" << endl;
    for(int i = 0; i < 3; i++){
        cin >> record[i];
    }


    int i = 3;
    while(true){
        record[i] = (a*record[i-3] + b*record[i-2] + c*record[i-1])%N;
        //cout << record[i] << "\t";
        if(repetition(record, i))
            return 2;

        // uz skoncila perioda?
        if(record[i] == record[2] && record[i-1] == record[1] && record[i-2] == record[0])
            break;

        i++;
    }

    // vypis periodu
    cout << "Perioda je: " << i-2 << endl;

    // vypis record
    for(int k = 0; k <= i - 3; k++){
        cout << record[k] << "\t";
        if((k+1)%10==0) cout << endl;
    }

    return 0;
}

bool repetition(int record[], int i){
    for(int k = 3; k < i; k++)
        if(record[k] == record[i-2] && record[k+1] == record[i-1] && record[k+1] == record[i])
            return true;
    else
        return false;
}
