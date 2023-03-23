template <class T>
class ArboreBST;

template <class T>
class Node
{
    T data;
    Node<T> *st,*dr;
    int level;

public:

    Node(T const & _data, int _level)
    {
        data=_data;
        st=dr=nullptr;
        level=_level+1;
    }

    ~Node()
    {

    };

    void adancime_max(int &Max)
    {
        if(this->level>Max)
            Max=this->level;
    }

    int preordine_adancime(int &Max)
    {
        this->adancime_max(Max);

        if(st)
            st->preordine_adancime(Max);
        if(dr)
            dr->preordine_adancime(Max);

        return Max;
    }

    bool preordine_echilibru(int Max1, int Max2, bool &OK)
    {
        Max1=1;
        Max2=1;
        int ad1,ad2;
        if(this->st==nullptr)
            ad1=0;
        else
            ad1=this->st->preordine_adancime(Max1)-this->level;
        if(this->dr==nullptr)
            ad2=0;
        else
            ad2=this->dr->preordine_adancime(Max2)-this->level;

        if(abs(ad1-ad2)>1)
            OK=0;

        if(st)
            st->preordine_echilibru(Max1, Max2, OK);
        if(dr)
            dr->preordine_echilibru(Max1, Max2, OK);

        return OK;
    }

    friend class ArboreBST<T>;
};

template <class T>
class ArboreBST
{

    Node <T> *rad;

public:

    ArboreBST()
    {
        rad=nullptr;
    }

    void adauga(T const & val)

    {
        Node<T> *aux=rad;

        if(aux==nullptr)

            rad=new Node<T>(val, 0);

        else

            while(1)
            {
                if(val<aux->data && aux->st!=nullptr)
                    aux=aux->st;
                else if(val<aux->data && aux->st==nullptr)
                {
                    aux->st=new Node<T>(val, aux->level);
                    break;
                }
                else if(val>aux->data && aux->dr!=nullptr)
                    aux=aux->dr;
                else
                {
                    aux->dr=new Node<T>(val, aux->level);
                    break;
                }
            }
    }

    int calculeazaAdancime()
    {
        int Max=1;

        if(rad==nullptr)

            return 0;

        else

            return rad->preordine_adancime(Max);
    }

    bool esteEchilibrat()
    {
        int Max1=1, Max2=1;
        bool OK=1;

        if(rad==nullptr)

            return 1;

        else

            return rad->preordine_echilibru(Max1, Max2, OK);
    }

    void afisare_inordine()
    {
        if(rad)
            rad->afisare_inordine();
    }
};
