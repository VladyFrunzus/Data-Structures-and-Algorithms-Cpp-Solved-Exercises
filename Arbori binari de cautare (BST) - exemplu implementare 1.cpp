#include <bits/stdc++.h>
#include <fstream>

using namespace std;

ifstream f("date.in");

template <class T>
class ArboreBST;

template <class T>

class Node
{
    int nr, depth;
    Node<T> *st, *dr;

public:

    Node<T> ()
    {
        nr=depth=0;
        st=dr=nullptr;
    }

    Node<T> (int nr1, int depth1)
    {
        nr=nr1;
        depth=depth1;
        st=dr=nullptr;
    }

    int postordine_ad(int &Max)
    {
        if(depth>Max)
            Max=depth;

        if(st)
            st->postordine_ad(Max);

        if(dr)
            dr->postordine_ad(Max);

        return Max;
    }

    void inordine_af()
    {
        if(st)
            st->inordine_af();

        cout<<this->nr<<" ";

        if(dr)
            dr->inordine_af();
    }

    //preordine = nod -> stanga -> dreapta
    //inordine = stanga -> nod -> dreapta (ordine crescatoare a<b)
    //postordine = stanga -> dreapta -> nod (notat gresit in cod)

    int postordine_ech(bool &OK)
    {
        int stang=this->depth,dreap=this->depth;
        if(st)
            stang=st->postordine_ad(stang);
        if(dr)
            dreap=dr->postordine_ad(dreap);
        if(abs(stang-dreap)>1)
            OK=0;

        if(st&&OK!=0)
            st->postordine_ech(OK);

        if(dr&&OK!=0)
            dr->postordine_ech(OK);

        return OK;
    }

    friend class ArboreBST<T>;
};

template <class T>

class ArboreBST
{
    Node<T> *rad, *crt;

public:

    ArboreBST<T>()
    {
        rad=nullptr;
    }

    void adauga(T const & val)
    {
        if(rad==nullptr)

            rad=new Node<T>(val,1);

        else

        {
            crt=rad;

            while(crt!=nullptr)
            {
                if(val>crt->nr&&crt->dr!=nullptr)
                    crt=crt->dr;

                else if(val>crt->nr)
                {
                    crt->dr=new Node<T>(val,crt->depth+1);
                    crt=nullptr;
                }

                else if(val<crt->nr&&crt->st!=nullptr)
                    crt=crt->st;

                else if(val<crt->nr)
                {
                    crt->st=new Node<T>(val,crt->depth+1);
                    crt=nullptr;
                }
            }
        }
    }

    void afisare()
    {
        rad->inordine_af();
    }

    int postordine_ad()
    {
        int Max=0;

        if(rad)

            return rad->postordine_ad(Max);
    }

    int calculeazaAdancime()
    {
        return this->postordine_ad();
    }

    bool esteEchilibrat()
    {
        bool OK=1;

        if(rad)

            return rad->postordine_ech(OK);
    }
};

int main()
{
    ArboreBST<int> arb;
    int n;

    while(f>>n)
        arb.adauga(n);

    cout<<arb.calculeazaAdancime()<<" "<<arb.esteEchilibrat();
    return 0;
}
