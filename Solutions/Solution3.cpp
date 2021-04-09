#include<bits/stdc++.h>
using namespace std;

void printContiguous(int arr[],int arr1_len)
{
    int maxlen = 1;
    for(int i=1;i<arr1_len;i++)
    {
        bool a = 0,b = 0;
        for(int j=i-1;j>=max(0,i-1-maxlen);j--)
        {
            if(arr[i] == arr[j]-1)
                a = 1;
            else if(arr[i] == arr[j]+1)
                b = 1;
        }
        if(a && b)
            maxlen +=2;
        else if(a || b)
            maxlen +=1;
    }
    cout<<maxlen;
}
int main()
{
    int arr[] = {89,1,56,58,57,90,92,94,93,91,45};
    printContiguous(arr,11); 
}