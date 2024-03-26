#include <bits/stdc++.h>
#include <cmath>

using namespace std;

class Node
{
    int co1, co2, dist;
    Node *next;

public:

    Node()
    {
        dist=co1=co2=0;
        next=nullptr;
    }

    Node(int aco1, int aco2)
    {
        co1=aco1;
        co2=aco2;
        dist=0;
        next=nullptr;
    }

    friend class List;
};

class List
{
    Node *inc, *cur, *sf;

public:

    List()
    {
        inc=sf=nullptr;
    }

    ~List()
    {
        Node* current = inc;
        while (current)
        {
            Node* urm = current->next;
            delete current;
            current = urm;
        }
    };

    double distanta(Node *unu, Node *doi)
    {
        double a=pow(abs(unu->co1-doi->co1),2),b=pow(abs(unu->co2-doi->co2),2);
        return sqrt(a+b);
    }

    void add_point(int aco1, int aco2)
    {
        if(inc==nullptr)

            inc=sf=new Node(aco1,aco2);

        else

        {
            sf->next=new Node(aco1,aco2);
            sf->dist=distanta(sf,sf->next);
            sf->next->dist=distanta(sf->next,inc);
            sf=sf->next;
        }
    }

    void add_inmijl(Node *unu, Node *doi)
    {
        Node *aux=new Node((int)((unu->co1+doi->co2)/2), (int)((unu->co2+doi->co2)/2));
        aux->next=doi;
        unu->next=aux;
        unu->dist=distanta(unu,aux);
        aux->dist=distanta(aux,doi);
        delete[] aux;
    }

    void prelucrare(double D1, double D2)
    {
        double Max=-1,Min=2000;

        cur=inc;

        while(cur!=nullptr)
        {
            if(cur->dist>Max)
                Max=cur->dist;
            if(cur->dist<Min)
                Min=cur->dist;
            cur=cur->next;
        }

        while(!(Max<=D2 && Min>=D1))
        {
            cur=inc;
            while(cur!=nullptr)
            {
                if(cur->dist<D1)

                {
                    if(cur==sf)
                    {
                        inc=inc->next;
                        sf->dist=distanta(sf,inc);
                    }
                    else if(cur->next==sf)
                    {
                        delete[] sf;
                        sf=cur;
                        sf->next=nullptr;
                        sf->dist=distanta(sf,inc);
                    }
                    else
                    {
                        delete[] cur->next;
                        cur->next=cur->next->next;
                        cur->dist=distanta(cur, cur->next);
                    }
                }

                else if(cur->dist>D2)
                {
                    if(cur==sf)
                    {
                        sf->next=new Node((int)((sf->co1+inc->co2)/2), (int)((sf->co2+inc->co2)/2));
                        sf->dist=distanta(sf,sf->next);
                        sf->next->dist=distanta(sf->next, inc);
                        sf=sf->next;
                    }
                    else
                        add_inmijl(cur,cur->next);
                }
                cur=cur->next;
            }

            cur=inc;
            Min=Max=inc->dist;
            while(cur!=nullptr)
            {
                if(Min>cur->dist)
                    Min=cur->dist;
                if(Max<cur->dist)
                    Max=cur->dist;
                cur=cur->next;
            }
        }
    }

    void perimetru()
    {
        cur=inc;
        double S=0,nr=0;
        while(cur!=nullptr)
        {
            S=S+cur->dist;
            nr++;
            cur=cur->next;
        }
        cout<<setprecision(3)<<fixed<<S/nr;
    }

    void afisare()
    {
        cur=inc;
        while(cur!=nullptr)
        {
            cout<<cur->co1<<" "<<cur->co2<<" "<<cur->dist<<'\n';
            cur=cur->next;
        }
        cout<<'\n';
    }
};

int main()
{
    int x,y;
    double d1,d2;
    List l;
    while(1)
    {
        cin>>x;
        if(x==0)
            break;
        else
        {
            cin>>y;
            l.add_point(x,y);
        }
    }
    cin>>d1>>d2;
    l.prelucrare(d1,d2);
    l.perimetru();
    return 0;
}
