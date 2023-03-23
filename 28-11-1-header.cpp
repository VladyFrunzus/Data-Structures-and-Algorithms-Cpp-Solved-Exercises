#ifndef SDA_QUEUE_H
#define SDA_QUEUE_H
#include <iostream>
#include <cstring>

using namespace std;


template <class T>
class Queue;

template <class T>
class Node
{
    T nrc,pinc,psf,p_max,tinc,p_tot;
    Node<T>* next{},*ant{};

public:
    Node()
    {
        nrc=pinc=psf=p_max=tinc=p_tot=0;
        next=NULL;
        ant=NULL;
    }

    explicit Node(T nrc1, T tinc1)
    {
        nrc=nrc1;
        tinc=tinc1;
        pinc=psf=p_max=p_tot=0;
        next=NULL;
        ant=NULL;
    }

    ~Node()
    {

    }

    friend class Queue<T>;
};

template <class T>
class Queue
{
    Node<T>* inc{};
    Node<T>* sf{},*crt{};

    void addFirst(T nrc1, T tinc1)
    {

        inc->nrc=nrc1;
        inc->tinc=tinc1;
        inc->pinc=0;
        inc->psf=0;
        inc->p_max=0;
        inc->p_tot=0;
        inc->next=new Node<T>;

    }


public:
    Queue()
    {
        inc = crt = sf = new Node<T>;
    }

    ~Queue()
    {
        delete inc;
        delete sf;
        delete crt;
    }

    void push(T nrc1, T tinc1)
    {
        if(inc->next==NULL)

            addFirst(nrc1, tinc1);

        else

        {
            sf->next = new Node<T>(nrc1,tinc1);
            sf->next->ant=sf;
            sf = sf->next;
        }

    }

    void change_pinc(T pinc1)
    {
        sf->pinc=pinc1;
    }

    void change_psf(T psf1)
    {
        sf->psf=psf1;
    }

    void change_p_max(T p_max1)
    {
        sf->p_max=p_max1;
    }

    void add_p_tot(T p_tot1)
    {
        sf->p_tot=sf->p_tot+p_tot1;
    }

    void pop()
    {
        sf=sf->ant;
        delete sf->next;
    }

    bool empty()
    {
        if(inc)
            return 0;
        else
            return 1;
    }

    T return_time()
    {
        return 3*(crt->psf-crt->pinc+1);
    }

    T front()
    {
        crt=inc;
        return 0;
    }

    T back()
    {
        crt=sf;
        return 0;
    }

    void prelucrare(int p, int c, int d, int b)
    {
        int cbc=0,timp=inc->tinc,SBC=0,SB50=0,TA=0,CA=1,OK,i;
        Node<T> *aux;
        int CB=-1;
        front();
        while(crt!=NULL)
        {
            if(crt!=inc&&timp-crt->ant->tinc>TA)
            {
                TA=timp-crt->ant->tinc;
                CA=crt->ant->nrc;
            }
            timp=timp+return_time();
            OK=0;
            for(i=crt->pinc; i<=crt->psf; i++)
                if(i%p==0)
                {
                    OK=1;
                    break;
                }
            if(crt->nrc%c==0&&OK==1)
            {
                if(crt->p_max/2>d)
                {
                    cbc++;
                    SB50=SB50+crt->p_max/2;
                }
                else
                {
                    SBC=SBC+min(d,crt->p_tot);
                }
            }
            else if(crt->nrc%c==0&&OK==0)
            {
                SBC=SBC+min(d,crt->p_tot);
            }
            else if(crt->nrc%c!=0&&OK==1)
            {
                cbc++;
                SB50=SB50+crt->p_max/2;
            }
            if(cbc==b&&CB==-1)
            {
                CB=0;
                aux=crt->next;
                while(aux!=NULL)
                {
                    if(aux->tinc<=timp)
                        CB++;
                    else
                        break;
                    aux=aux->next;
                }
            }
            crt=crt->next;
        }
        if(timp-sf->tinc>TA)
        {
            TA=timp-sf->tinc;
            CA=sf->nrc;
        }
        cout<<CB<<" "<<SB50<<" "<<SBC<<" "<<CA<<" "<<TA;
    }

};

#endif
