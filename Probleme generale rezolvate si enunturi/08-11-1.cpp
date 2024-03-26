#ifndef SDA1_LIST_H
#define SDA1_LIST_H
#include <iostream>
using namespace std;
template <class T>
class List;

template <class T>
class Node
{
    T data;
    Node<T>* next;

public:
    Node()
    {
        next=nullptr;
        data=0;
    }

    explicit Node(T _data)
    {
        data=_data;
        next= NULL;
    }

    ~Node()
    {
        delete next;
    }

    Node<T>* Next()
    {
        return this->next;
    }

    bool isEnd()
    {
        return next==nullptr;
    }

    T Data()
    {
        return data;
    }

    friend class List<T>;
};

template <class T>
class List
{
    Node<T> *inc, *crt, *sf;
    int addFirst(T data)
    {
        inc= new Node<T> (data);
        sf=inc;
        crt=inc;
        return 0;
    }

public:
    List()
    {
        inc=crt=sf=NULL;
    }

    ~List()
    {
        Node<T>* tmp;
        if(inc)
        {
            tmp = inc->next;
            inc->next = NULL;
            delete tmp;
        }
    }

    /*Node<T>*give_inc()
    {
    return inc;
    }

    Node<T>*give_sf()
    {
    return sf;
    }

    void afisare()
    {
    begin();
    while(crt->data)
    {
    cout<<crt->data<<" ";
    crt=crt->next;
    }
    begin();
    cout<<'\n';
    }*/

    void push_front(T data)
    {
        if(inc==NULL)
            addFirst(data);
        else
        {
            Node<T> *tmp=new Node<T>;
            tmp=inc;
            inc=new Node<T> (data);
            inc->next=tmp;
        }
    }


    Node<T>* begin()
    {
        crt=inc;
        return crt;
    }


    void insert(Node<T> *crt1, T data)
    {
        Node<T> *tmp=new Node<T> (data);
        tmp->next=crt1->next;
        crt1->next=tmp;
    }

    void erase(Node<T> *crt)
    {
        crt->next->data=0;
        crt->next=crt->next->next;
    }

    void Prelucrare(float P1, float P2)
    {
        bool OK=0;
        int k=1;
        while(OK==0)
        {
            OK=1;
            begin();
            while(crt!=sf)
            {
                if(abs(crt->data-crt->next->data)>P1)
                {
                    insert(crt,(crt->data+crt->next->data)/2);
                    OK=0;
                }
                if(abs(crt->data-crt->next->data)<P2)
                {
                    erase(crt);
                    OK=0;
                }
                k++;
                crt=crt->next;
            }
        }
    }


};
#endif

