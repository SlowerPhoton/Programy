#include <iostream>

using namespace std;

struct host{
    int vyska;
    host *next = NULL;
    host *prev = NULL;
};

host *head = NULL;

bool pridejHosta(int vyska){
    host *ptr = head;
    while(ptr != NULL and vyska > 0){
        if(ptr -> vyska == vyska){
            vyska--; ptr = head;
        }
        ptr = ptr -> next;
    }
    if(vyska <= 0){
        return 1;
    }

    // pridej tedy noveho hosta do LIFO
    host *novy;
    novy = new host;
    novy -> vyska = vyska;
    novy -> next = head;
    head = novy;
    if(novy -> next != NULL)
        novy -> next -> prev = novy;

    return 0;
}

int main()
{   int p [100000];
    while(1){
        int dalsiHost;
        cin >> dalsiHost;
        if(pridejHosta(dalsiHost)) break;
    }

    return 0;
}
