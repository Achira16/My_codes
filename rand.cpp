#include<bits/stdc++.h>
using namespace std;
int main()
{
    srand(unsigned(time(NULL)));
    int l = -100,h = -50,range;
    if(l<0 && h>0)
    {
        range = h + abs(l) + 1;
    }
    else
    {
        range = (h-l)+1;
    }
    int randint;
    for(int i=0;i<20;i++){
    randint = rand()%range + l;
    cout<<randint<<"   ";
    }
}