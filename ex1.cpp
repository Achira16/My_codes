#include<iostream>
#include<stdlib.h>
#include<unistd.h>
#include<wait.h>
using namespace std;

int main()
{
    pid_t pid = fork();
    if(pid == 0)
    {
        cout<<"PID of child: "<<getpid()<<endl; 
        execlp("/bin/ls","ls",NULL);
    }
    else
    {
        cout<<"PID of original process: "<<getpid()<<endl;
        wait(NULL);

    }
    // char *arg[] = {"hi","ach",NULL};
    execlp("./ex2","ach");
    cout<<"gezjg";
    cout<<"Back to ex1"<<endl;
}