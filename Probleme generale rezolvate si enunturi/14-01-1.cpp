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

    bool comparare(Node *nod1, Node *nod2)
    {
        if(nod1->medie>nod2->medie||(nod1->medie==nod2->medie&&nod1->nume.compare(nod2->nume)<0))
            return 1;
        else
            return 0;
    }


    int partition(int low, int high)

    {
        Node *pivot = v[high];

        int i = low-1;

        for (int j = low; j < high; j++)
        {
            if (comparare(v[j],pivot)>0)
            {
                i++;
                swap(v[i], v[j]);
                swap(fin[i], fin[j]);
            }
        }

        swap(v[i+1], v[high]);
        swap(fin[i+1], fin[high]);

        return i+1;
    }

    void quickSort(int low, int high)
    {
        if (low < high)
        {
            int pi = partition(low, high);
            quickSort(low, pi - 1);
            quickSort(pi + 1, high);
        }
    }


    vector<int> returneazaIndecsiSortati()
    {
        quickSort(0,v.size()-1);
        return fin;
    };

};
