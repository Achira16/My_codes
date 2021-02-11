#include<stdio.h>

int main()
{
    enum days{sun=1,mon,tue,wed,thur,fri,sat};
    int a;
    scanf("%d",&a);
    switch (a)
    {
    case sun:printf("Sunday");
        break;
    case wed:printf("Wednesday");
        break;
    default:printf("Other");
        break;
    }
}