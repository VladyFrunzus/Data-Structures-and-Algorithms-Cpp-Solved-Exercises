#include <bits/stdc++.h>
#include <fstream>

using namespace std;

ifstream f("date.in");

class Node
{
    int val;
    deque <Node*> vecini;

public:

    Node()
    {
        val=0;
    }

    Node(int val1)
    {
        val=val1;
    }

    void parc(int a, int b)
    {
        if(this->val==a)
        {
            Node*aux=new Node(b);
            this->vecini.push_back(aux);
        }

        for(int i=0; i<this->vecini.size(); i++)
            this->vecini[i]->parc(a,b);

    }

    bool verif(int a, int b, bool &OK1, bool &OK2)
    {
        if(this->val==a)
            OK1=1;
        if(this->val==b)
            OK2=1;

        for(int i=0; i<this->vecini.size(); i++)
            this->vecini[i]->verif(a,b,OK1,OK2);

        if(OK1&&OK2)
            return 1;
        else
            return 0;
    }

    int parcurgere(int a,int b, int &Max)
    {
        bool OK1=0,OK2=0;
        if(this->verif(a,b,OK1,OK2))
            Max=this->val;

        for(int i=0; i<this->vecini.size(); i++)
            this->vecini[i]->parcurgere(a,b,Max);

        return Max;
    }

    void afis()
    {
        cout<<this->val<<" ";

        for(int i=0; i<this->vecini.size(); i++)
            this->vecini[i]->afis();
    }

    friend class Arbore;
};

class Arbore
{
    Node *rad;

public:

    Arbore()
    {
        rad=nullptr;
    }

    void ad_nod(int t, int f)
    {
        if(rad==nullptr)
        {
            rad=new Node(t);
            Node *aux=new Node(f);
            rad->vecini.push_back(aux);
        }
        else
        {
            rad->parc(t,f);
        }
    }


    void prelucrare(int a, int b)
    {
        int Max=rad->val;
        cout<<rad->parcurgere(a,b,Max);
    }

    void afisare()
    {
        if(rad)
            rad->afis();
    }
};

int main()
{
    int a,b,d1,d2;
    Arbore arb;
    cin>>a;
    while(1)
    {
        cin>>a;
        if(a==0)
            break;
        else
        {
            cin>>b;
            arb.ad_nod(a,b);
        }
    }
    cin>>d1>>d2;
    arb.prelucrare(d1,d2);
    return 0;
}
