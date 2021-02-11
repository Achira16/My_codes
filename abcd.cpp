#include<bits/stdc++.h>
using namespace std;
int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
    int n = A.size();
    int count = 0;
    for(int i=0;i<n;i++)
    {
        int sum3 = 0-A[i];
        for(int j=0;j<n;j++){
            int sum2 = sum3 - B[j];
            unordered_map<int,int> complements;
            for(int k=0;k<n;k++){
                 complements[sum2 - C[k]]++;
            }
            for(int l=0;l<n;l++)
            {
                if(complements.find(D[l]) != complements.end())
                    count += complements[D[l]];
            }
            complements.clear();
        }
    }
    return count;
}
int main()
{
    int n;
    cin>>n;
    vector<int> A(n),B(n),C(n),D(n);
    for(int i=0;i<n;i++)
        cin>>A[i];
    for(int i=0;i<n;i++)
        cin>>B[i];
    for(int i=0;i<n;i++)
        cin>>C[i];  
    for(int i=0;i<n;i++)
        cin>>D[i];
    int count = fourSumCount(A,B,C,D);
    cout<<count;
}