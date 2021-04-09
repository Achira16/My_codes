#include<bits/stdc++.h>
using namespace std;

void printCommon(int arr1[],int arr2[],int arr1_len,int arr2_len)
{
    int i = 0,j = 0;
    while(i<arr1_len && j<arr2_len)
    {
        if(arr1[i] < arr2[j])
            i++;
        else if(arr2[j] < arr1[i])
            j++;
        else
        {
            cout<<arr1[i]<<",";
            while(i<arr1_len-1 && arr1[i]==arr1[i+1])i++;//checking for duplicates..we dont want to print duplicates
            while(j<arr2_len-1 && arr2[j]==arr2[j+1])j++;
            i++;j++;
        }
    }
}
int main()
{
    int arr1[] = {8,8,12,13,14,14};
    int arr2[] = {8,14};
    printCommon(arr1,arr2,sizeof(arr1)/sizeof(arr1[0]),sizeof(arr2)/sizeof(arr2[0]));
}