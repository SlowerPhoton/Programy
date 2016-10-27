#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{   srand(time(NULL));
int gold=0,silver=0;
int ans;
for(int i=0; i<50;i++){
    int box = rand()%3;
    if(box==0) {ans=0; cout<<box<<" "<<endl;}
    if(box==1) {ans=1; cout<<box<<" "<<endl;}
    else{
    box=rand()%2;
    if(box==0) {ans=0; cout<<"box 3, "<<box<<endl;}
    if(box==1) {ans=1; cout<<"box 3, "<<box<<endl;}
    }

    if(ans==0)gold++;
    if(ans==1)silver++;
    }
    double h=100*silver/(gold+silver);
    cout << h << endl;
    cout << gold << endl;
    cout << silver << endl;
    return 0;
}
