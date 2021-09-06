#include<bits/stdc++.h>
using namespace std;

atomic_int a;

void func(char ch)
{
    printf("(%c) enters\n",ch);
    if(++a > 1)
    {
        this_thread::sleep_for(std::chrono::microseconds(100));
        printf("(%c) returned\n",ch);
        return;
    }
    this_thread::sleep_for(std::chrono::microseconds(100));
    a.store(0);
    printf("(%c) returns\n",ch);
}
int main()
{
    a.store(0);
    thread th[5];
    for(int i=0;i<5;i++)
    {
        th[i] = thread(func,i+'a');
    }
    for(int i=0;i<5;i++)
    {
        th[i].join();
    }
}