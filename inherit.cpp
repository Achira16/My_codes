#include <iostream>
    using namespace std;
    class BaseClass
    {
        public:
        virtual void print()  = 0;
    };
    class DerivedClassOne
    {
        public:   
        int i;  
        void print() 
        {
            cout << "Derived class One\n";
        }
    };
    class DerivedClassTwo
    {
        public:
        int i;
        void print()
        {
            cout << "Derived class Two\n";
        }     
    }; 
    class MultipleClass : public DerivedClassOne,public DerivedClassTwo
    {
        public:
        void print()
        {
            DerivedClassOne :: print();
        } 
    }; 
    int main()
    {
        // int i;
        MultipleClass both; 
        // DerivedClassOne one; 
        // DerivedClassTwo two; 
        // BaseClass *array[ 3 ]; 
        // // DerivedClassOne &dr = both;
        // array[ 0 ] = &both;
        // array[ 1 ] = &one;
        // array[ 2 ] = &two;
        // cout<<both.DerivedClassOne::i;
        int i = 320;
        char *p = (char*)&i;
        printf("%d",*p);
        return 0;
    }