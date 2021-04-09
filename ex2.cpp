#include<iostream>
#include<stdlib.h>
#include<unistd.h>
using namespace std;

int main()
{
    cout<<"Pid of ex2 is: "<<getpid()<<endl;
    char *arg[] = {"hi","ach"};
    // execv("./ex1",arg);
}