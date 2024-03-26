#ifndef SDA1_LIST_H
#define SDA1_LIST_H

template <class T>
class List;

template <class T>
class Node
{
    T data;
    int nr_es;
    Node<T>* next;

public:
    Node()
    {
        next=nullptr;
        nr_es=0;
        data=0;
    }

    explicit Node(T _data)
    {
        data=_data;
        nr_es=0;
        next= NULL;
    }

    void update_node(T _data)
    {
        data=_data;
    }

    unsigned long long Data();

    ~Node()
    {
        delete next;
    }

    Node<T>* Next()
    {
        return next;
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
        if(inc)
        {
            inc->next = NULL;
            inc->data=0;
            inc->nr_es=0;
            inc=NULL;
        }
    }


    void push_front(T data)
    {
        if(inc==NULL)
            addFirst(data);
        else
        {
            Node<T> *tmp=new Node<T>;
            tmp=sf;
            tmp->data=sf->data;
            tmp->nr_es=sf->nr_es;
            sf = new Node<T>(data);
            tmp->next=sf;
        }
    }


    Node<T>* begin()
    {
        return inc;
    }



    void Prelucrare(int dif)
    {
        List<T> l_aux, l_aux2;
        crt=begin();
        while(crt!=NULL)
        {
            if(l_aux2.inc == NULL)
            {
                l_aux2.addFirst(crt->data);
                if(l_aux.inc==NULL)
                {
                    l_aux.inc=new Node<T>;
                    l_aux.inc->data=0;
                    l_aux.inc->nr_es=1;
                    l_aux.sf=l_aux.inc;
                    l_aux.inc->next=NULL;
                    l_aux.crt=l_aux.inc;
                }
                else
                {
                    l_aux.push_front(0);
                    l_aux.crt=l_aux.crt->next;
                    l_aux.crt->nr_es=1;
                }
            }
            else if(abs(crt->data-l_aux2.inc->data)<=dif)
            {
                l_aux2.push_front(crt->data);
                l_aux2.crt=l_aux2.crt->next;
                l_aux.crt->nr_es++;
            }
            else
            {
                T auxil;
                Node<T> *aux0;
                l_aux2.crt=l_aux2.begin();
                auxil=l_aux2.inc->data;
                l_aux2.crt=l_aux2.crt->next;
                while(l_aux2.crt!=NULL)
                {
                    auxil=auxil+l_aux2.crt->data;
                    l_aux2.crt=l_aux2.crt->next;
                }
                l_aux.crt->update_node(auxil/l_aux.crt->nr_es);
                l_aux2.~List();
                aux0=crt;
                crt=begin();
                while(crt->next!=aux0)
                    crt=crt->next;
            }
            crt=crt->next;
        }
        T auxil;
        l_aux2.crt=l_aux2.begin();
        auxil=l_aux2.inc->data;
        l_aux2.crt=l_aux2.crt->next;
        while(l_aux2.crt!=NULL)
        {
            auxil=auxil+l_aux2.crt->data;
            l_aux2.crt=l_aux2.crt->next;
        }
        l_aux.crt->update_node(auxil/l_aux.crt->nr_es);
        l_aux2.~List();
        this->~List();
        inc=new Node<T>;
        inc->data=l_aux.inc->data;
        inc->nr_es=l_aux.inc->nr_es;
        crt=l_aux.inc->next;
        inc->next=crt;
        l_aux.crt=l_aux.inc->next;
        while(l_aux.crt!=NULL)
        {
            crt=l_aux.crt;
            crt->data=l_aux.crt->data;
            crt->nr_es=l_aux.crt->nr_es;
            crt->next=l_aux.crt->next;
            l_aux.crt=l_aux.crt->next;
            crt=crt->next;
        }
    }


};
#endif
