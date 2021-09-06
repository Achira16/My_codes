#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;

void* func(void* arg) 
{
    int value = rand()%6+1;
    int *res = new int;
    *res = value;
    // cout<<"Thread res: "<<res<<endl;
    printf("Thread res: %p\n",res);
    return (void*)res;
}
int main()
{
    srand(time(NULL));
    int *res;
    pthread_t t1,t2;
    // for(int i=0;i<8;i++)
    // {
    //     pthread_create(&th[i],NULL,&func, NULL);
    // }
    // for(int i=0;i<8;i++)
    // {
    //     pthread_join(th[i],(void**)&res);
    //     cout<<"Main res: "<<res<<endl;
    //     cout<<"Result: "<<*res<<endl;
    // }
    pthread_create(&t1,NULL,&func,NULL);
    pthread_create(&t2,NULL,&func,NULL);
    pthread_join(t1,(void**)&res);
    printf("Main res: %p\n",res);
    pthread_join(t2,(void**)&res);
    printf("Main res: %p\n",res);
    delete res;
    return 0;
}