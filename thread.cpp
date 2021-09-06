#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;

void* func(void *input) 
{
    cout<<"Hello";
    sleep(3);
    cout<<"Bye";
}
int main()
{
    pthread_t t1,t2;
    pthread_create(&t1, NULL,&func,NULL);
    pthread_create(&t2,NULL,&func,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    return 0;
}