#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;

int primes[10] = {2,3,5,7,11,13,17,19,23,29};
string temp[10] = {"one","two","three","four","five","six","seven","eight","nine","ten"};

void* func(void* arg)
{
    // sleep(1);
    // string s = *(string*)arg;
    string s = *(string*)arg;
    // printf("%s ",s);
    cout<<s<<" ";
    free(arg);
}
int main()
{
    pthread_t th[10];
    for(int i=0;i<10;i++)
    {
        string *a = new string(temp[i]);
        // int *a = new int;
        // *a = i;
        if(pthread_create(&th[i],NULL,&func,a))
        {
            perror("Failed to create thread\n");
        }
    }
    for(int i=0;i<10;i++)
    {
        if(pthread_join(th[i],NULL))
        {
            perror("Failed to join thread\n");
        }
    }
}