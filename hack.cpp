#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

class Box
{
    int l,b,h;
    public:
    Box():l(0),b(0),h(0){}
    Box(int l,int b,int h):l(l),b(b),h(h){}
    Box(Box &B):l(B.l),b(B.b),h(B.h){}
    int getLength(); 
    int getBreadth (); 
    int getHeight ();  
    long long CalculateVolume();
    bool operator<(Box &B)
    {
        if(l<B.l)
            return 1;
        else if(b<B.b && l==B.l)
            return 1;
        else if(h<B.h && b==B.b && l==B.l)
            return 1;
        return 0;
    }
    friend ostream& operator<<(ostream& out, Box& B)
    {
        out<<B.l<<" "<<B.b<<" "<<B.h;
        return out;
    }
};
int Box::getLength(){return l;}
int Box::getBreadth(){return b;}
int Box::getHeight(){return h;}
long long Box::CalculateVolume(){return l*b*h;}


void check2()
{
    IOS;
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
    IOS;
	check2();
}