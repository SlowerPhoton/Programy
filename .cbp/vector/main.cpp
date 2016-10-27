#include <iostream>
#include <vector>

using namespace std;


    int push666 (vector<int>& vect){

        vect.push_back(666);
    }

    int main()
    {

        vector<int> a;
        a.reserve(1);
        push666(a);

        cout << a[0];

        return 0;
    }
