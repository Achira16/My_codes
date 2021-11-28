#include<bits/stdc++.h>
using namespace std;

string findCost(int tableSize,int cardinality,string indexType){
    int thresh = 1000000;
    double cost;
    if(indexType == "standard"){
        long val = (30L * min(tableSize,thresh))/100;
        if(tableSize <= thresh)
            cost = (double)cardinality/val;
        else{
            val += (15L * (tableSize-thresh))/100;
            cost = (double)cardinality/val;
        }
    }
    else{
        long val = (10L * min(tableSize,thresh))/100;
        if(tableSize <= thresh)
            cost = (double)cardinality/val;
        else{
            val += (5L * (tableSize-thresh))/100;
            cost = (double)cardinality/val;
        }
    }
    if(cost < 1) return "Yes";
    return "No";
}
int main(){
    int t,c;
    string ind;
    cin>>t>>c>>ind;
    cout<<findCost(t,c,ind);
}