#include<stdarg.h>
#include<string>
#include<iostream>
#include<iomanip>
using namespace std;
void function(string message, ...)
{
    va_list ptr;
    char* number;
    va_start(ptr, message);
    number = va_arg(ptr,char*);
    number = va_arg(ptr,char*);
    number = va_arg(ptr,char*);
    cout << number;
}
int printf(const char* format,...) 
{
    va_list arg;
    va_start(arg,format);
    int done;
    done = vfprintf(stdout,format,arg);
    va_end(arg);
    return done;
}
int main()
{
    // function("InterviewMania", "a","bc","hasfjs","ajf");
    double d = 10.321;
    // printf("%d",d);
    // cout<<setfill('x')<<setw(4)<<"ab"<<setw(7)<<d;
    // char *arr[] = {"afe","uhwe","whfjwe","sjf"};
    // char *(*p)[4] = &arr;
    // cout<<++(*p)[2];
    int a[] = {1,2,3,4};
    int (*p)[4] = &a;
    // cout<<a<<" "<<a+1<<" "<<*a<<" "<<*(*(a+1)+1);
    return 0;
}
