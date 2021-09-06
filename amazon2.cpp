#include<bits/stdc++.h>
using namespace std;

void func(string& s1,int k,string& max)
{
    if(k == 0)        //when no swaps are left
      return;
   int n = s1.length();
   for (int i = 0; i < n - 1; i++) {        //for every digits og given number
      for (int j = i + 1; j < n; j++) {
         if (s1[i] < s1[j]) {             //when ith number smaller than jth number
            swap(s1[i], s1[j]);
            if (s1.compare(max) > 0)      //when current number is greater, make it maximum
               max = s1;
            func(s1, k - 1, max);   //go for next swaps
            swap(s1[i], s1[j]);        //when it fails, reverse the swapping
         }
      }
   }
}
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    cout<<func(s1,s2);
}