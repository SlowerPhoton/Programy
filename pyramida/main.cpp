#include <iostream>

using namespace std;

int main()
{   int height;
    cin>>height;
    int hvezda=2;

if(height<41 and height>0){
    for(int x=0; x<height;x++){
        int pocetznaku=height*2;
        for(int z=0; z<(pocetznaku-hvezda)/2;z++)
            cout<<" ";
        for(int z=0; z<hvezda;z++ )
            cout<<"*";
        for(int z=0; z<(pocetznaku-hvezda)/2;z++ )
            cout<<" ";
        cout<<endl; hvezda+=2;}}
else cout<<"out of range"<<endl;



    return 0;
}
