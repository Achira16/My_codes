#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Spell { 
    private:
        string scrollName;
    public:
        Spell(): scrollName("") { }
        Spell(string name): scrollName(name) { }
        virtual ~Spell() { }
        string revealScrollName() {
            return scrollName;
        }
};

class Fireball : public Spell { 
    private: int power;
    public:
        Fireball(int power): power(power) { }
        void revealFirepower(){
            cout << "Fireball: " << power << endl;
        }
};

class Frostbite : public Spell {
    private: int power;
    public:
        Frostbite(int power): power(power) { }
        void revealFrostpower(){
            cout << "Frostbite: " << power << endl;
        }
};

class Thunderstorm : public Spell { 
    private: int power;
    public:
        Thunderstorm(int power): power(power) { }
        void revealThunderpower(){
            cout << "Thunderstorm: " << power << endl;
        }
};

class Waterbolt : public Spell { 
    private: int power;
    public:
        Waterbolt(int power): power(power) { }
        void revealWaterpower(){
            cout << "Waterbolt: " << power << endl;
        }
};

class SpellJournal {
    public:
        static string journal;
        static string read() {
            return journal;
        }
}; 
string SpellJournal::journal = "";

int lcs(string a,string b)
{
    int n = a.size()+1,m = b.size()+1;
    int dp[n][m];
    for(int i=0;i<n;i++)
        dp[i][0] = 0;
    for(int i=0;i<m;i++)
        dp[0][i] = 0;
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(a[i-1]==b[j-1])
                dp[i][j] = dp[i-1][j-1]+1;
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n-1][m-1];
}
void counterspell(Spell *spell) {
    string sp = spell->revealScrollName();
    if(sp == "")
    {
        if(dynamic_cast<Fireball*>(spell)!=NULL)
        {
            Fireball* fp = dynamic_cast<Fireball*>(spell);
            fp->revealFirepower();
        }
        else if(dynamic_cast<Frostbite*>(spell)!=NULL)
        {
            Frostbite* fp = dynamic_cast<Frostbite*>(spell);
            fp->revealFrostpower();
        }
        else if (dynamic_cast<Thunderstorm*>(spell)!=NULL)
        {
            Thunderstorm* fp = dynamic_cast<Thunderstorm*>(spell);
            fp->revealThunderpower();
        }
        else if (dynamic_cast<Waterbolt*>(spell)!=NULL)
        {
            Waterbolt* fp = dynamic_cast<Waterbolt*>(spell);
            fp->revealWaterpower();
        }
    }
    else
    {
        cout<<lcs(sp,SpellJournal::journal)<<endl;   
    }
}

class Wizard {
    public:
        Spell *cast() {
            Spell *spell;
            string s; cin >> s;
            int power; cin >> power;
            if(s == "fire") {
                spell = new Fireball(power);
            }
            else if(s == "frost") {
                spell = new Frostbite(power);
            }
            else if(s == "water") {
                spell = new Waterbolt(power);
            }
            else if(s == "thunder") {
                spell = new Thunderstorm(power);
            } 
            else {
                spell = new Spell(s);
                cin >> SpellJournal::journal;
            }
            return spell;
        }
};

int main() {
    int T;
    cin >> T;
    Wizard Arawn;
    while(T--) {
        Spell *spell = Arawn.cast();
        counterspell(spell);
    }
    return 0;
}