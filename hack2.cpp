#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Person
{
    protected:
    string name;
    int age;
    public:
    virtual void getdata(){}
    virtual void putdata(){}
};
class Professor:public Person
{
    int id;
    int publ;
    public:
    static int cur_id;
    void getdata()
    {
        cur_id++;
        id = cur_id;
        cin>>name;
        cin>>age>>publ;
    }
    void putdata()
    {
        cout<<name<<" "<<age<<" "<<publ<<" "<<id<<endl;
    }
};
int Professor::cur_id = 0;
class Student:public Person
{
    int id;
    vector<int> marks;
    public:
    static int cur_id;
    void getdata()
    {
        cur_id++;
        id = cur_id;
        cin>>name;
        cin>>age;
        int x;
        for(int i=0;i<6;i++)
        {
            cin>>x;
            marks.push_back(x);
        }
    }
    void putdata()
    {
        int sum = 0;
        for(int i=0;i<6;i++)
            sum+=marks[i];
        cout<<name<<" "<<age<<" "<<sum<<" "<<id<<endl;
    }
};
int Student::cur_id = 0;
int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
