#include<bits/stdc++.h>
using namespace std;
int main()
{
    int *mat = (int*)malloc(2*2*sizeof(int));
    cout<<mat<<" "<<mat+1<<" "<<mat+2<<" "<<mat+1*2+0;
    free(mat);
}