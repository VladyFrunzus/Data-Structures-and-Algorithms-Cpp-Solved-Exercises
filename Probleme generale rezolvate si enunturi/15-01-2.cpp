#include <bits/stdc++.h>

using namespace std;

class Node
{
    int data;
    Node *st,*dr;

public:

    Node()
    {
        data=0;
        st=dr=nullptr;
    }

    Node(int _data)
    {
        data=_data;
        st=dr=nullptr;
    }

    ~Node() {};

    int adaugare_nod(int data1)
    {
        if(data1>data)
        {
            if(dr)
                dr->adaugare_nod(data1);
            else
            {
                dr=new Node(data1);
                return 0;
            }
        }
        else
        {
            if(st)
                st->adaugare_nod(data1);
            else
            {
                st=new Node(data1);
                return 0;
            }
        }
    }

    void afisare_postordine()
    {
        if(st)
            st->afisare_postordine();

        if(dr)
            dr->afisare_postordine();

        cout<<this->data<<" ";
    }

    int verificare_postordine(int A, int B, int &dim)
    {
        if(st&&dim!=-1)
            st->verificare_postordine(A,B,dim);

        if(dr&&dim!=-1)
            dr->verificare_postordine(A,B,dim);

        if(this->data<A || this->data>B)
            dim=-1;
        else if(dim!=-1)
            dim++;
        if(dim!=-1)
            return dim;
        else
            return 0;
    }

    int parcurgere_final(int A, int B, int &Max)
    {
        int aux,g=0;
        aux=this->verificare_postordine(A,B,g);
        if(aux>Max)
            Max=aux;

        if(st)
            st->parcurgere_final(A,B,Max);

        if(dr)
            dr->parcurgere_final(A,B,Max);

        return Max;
    }

};

class Arbore
{
    Node *rad;

public:

    Arbore()
    {
        rad=nullptr;
    }

    ~Arbore() {};

    void adaugare_nod(int data1)
    {
        if(rad==nullptr)

            rad=new Node(data1);

        else

            rad->adaugare_nod(data1);
    }

    void afisare_postordine()
    {
        if(rad)
            rad->afisare_postordine();
    }


    void subarbore_maxim(int A, int B)
    {
        int g=0;
        if(rad)
            cout<<rad->parcurgere_final(A,B,g);
    }
};

int main()
{
    Arbore arb;
    int i,n,c,A,B;
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>c;
        arb.adaugare_nod(c);
    }
    cin>>A>>B;
    arb.subarbore_maxim(A,B);
    return 0;
}
