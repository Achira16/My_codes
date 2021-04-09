#include<bits/stdc++.h>
using namespace std;
class Graph{
    int v;
    vector <int> *l;
    public:
        Graph(int v){
            this->v = v;
            this->l = new vector<int> [v];
        }
        void Addedges(int x, int y){
            l[x].push_back(y);
            l[y].push_back(x);
        }
        void Printgraph(){
            for(int i=0;i<v;i++)
            {
                cout << i << "->";
                for(auto j:l[i]){
                    cout << j<<", ";
                }
                cout <<endl;
        }
        }
};
int main()
{
    Graph g(4);
    g.Addedges(0,1);
    g.Addedges(0,2);
    g.Addedges(2,3);
    g.Addedges(1,2);
    g.Printgraph();
}