#include<bits/stdc++.h>
using namespace std;
int main()
{
    int **a = (int**)malloc(2*sizeof(int*));
    for(int i=0;i<2;i++)
    {
        a[i] = (int*)malloc(2*sizeof(int));
    }
    cout<<a<<" "<<" "<<*a<<" "<<a[0]<<" "<<a[1]<<" "<<&a[0][0]<<" "<<&a[0][1]<<" "<<&a[1][0]<<" "<<&a[1][1]<<endl;
    cout<<*(*(a+1)+1);
    cout<<sizeof(a[1]);
    free(a);
}