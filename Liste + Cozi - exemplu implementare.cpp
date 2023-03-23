#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>

using namespace std;

ifstream f("date.in");

class Lista
{

    struct Node
    {
        string nume;
        double medie;
        Node *next;
    };

    Node *inc, *cur, *sf;
    vector <Node*> v;
    vector <int> fin;

public:

    Lista()
    {
        inc=cur=sf=nullptr;
    };

    virtual ~Lista()
    {
        Node* current = inc;
        while (current)
        {
            Node* urm = current->next;
            delete current;
            current = urm;
        }
    };


    void adaugaStudent(string nume, double medie)
    {
        if(inc==nullptr)
        {
            sf=inc=new Node;
            sf->medie=inc->medie=medie;
            sf->nume=inc->nume=nume;
            v.push_back(inc);
            fin.push_back(0);
            sf->next=inc->next=nullptr;
        }
        else
        {
            sf->next=new Node;
            sf->next->medie=medie;
            sf->next->nume=nume;
            v.push_back(sf->next);
            fin.push_back(fin.back() + 1);
            sf=sf->next;
            sf->next=nullptr;
        }
    };





    //sau






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
