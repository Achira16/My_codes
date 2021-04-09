#include<bits/stdc++.h>
using namespace std;

void removeDuplicates(int arr[],int arr_len)
{
    for(int i=0;i<arr_len-1;i++)
    {
        int j = i+1;
        while(j<arr_len)
        {
            if(arr[i] == arr[j])
            {
                if(j == arr_len-1)
                    arr[j] = -1;
                else
                {
                    for(int k=j;k<arr_len-1;k++)
                    {
                        arr[k] = arr[k+1];
                    }
                    arr[arr_len-1] = INT32_MIN;// indicates deleted element
                    arr_len--;
                }
            }
            else
                j++;
        }
    }
}
int main()
{
    int arr[] = {2,2,2,4,3,2,5,3,4,2,2,9,10,100,10};
    removeDuplicates(arr,sizeof(arr)/sizeof(arr[0]));
    for(int i:arr)
    {
        cout<<i<<" ";
    }
}