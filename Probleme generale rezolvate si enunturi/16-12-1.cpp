template <class T>
class ArboreBST;

template <class T>
class Node
{
    T data;
    Node<T> *st,*dr;

public:

    Node(T const & _data)
    {
        data=_data;
        st=dr=nullptr;
    }

    ~Node()
    {

    };

    void postordine(std::vector<T> const & postOrdine, std::vector<T> &aux, int i)
    {
        int j=i,k=i;
        Node<T> *aux1;
        while(postOrdine[j]>=postOrdine[i]&&j>=0)
            j--;
        if(j<0)
            this->st=nullptr;
        else
        {
            if(aux[j]!=0)
            {
                aux[j]=0;
                this->st=new Node<T>(postOrdine[j]);
            }
            else
                this->st=nullptr;
        }
        if(this->st!=nullptr)
        {
            aux1=this->st;
            aux1->postordine(postOrdine, aux, j);
        }
        while(postOrdine[k]<=postOrdine[i]&&k>=0)
            k--;
        if(k<0)
            this->dr=nullptr;
        else
        {
            if(aux[k]!=0)
            {
                aux[k]=0;
                this->dr=new Node<T>(postOrdine[k]);
            }
            else
                this->dr=nullptr;
        }
        if(this->dr!=nullptr)
        {
            aux1=this->dr;
            aux1->postordine(postOrdine, aux, k);
        }
    }

    void sortare_inordine(std::vector<T> &Messi)
    {
        if(st)
            st->sortare_inordine(Messi);

        Messi.push_back(this->data);

        if(dr)
            dr->sortare_inordine(Messi);
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

    void afisare_inordine()
    {
        if(rad)
            rad->afisare_inordine();
    }

    void construiesteDinPostOrdine(std::vector<T> const & postOrdine)
    {
        std::vector<T> aux=postOrdine;
        int i=postOrdine.size()-1;
        rad=new Node<T>(postOrdine[i]);
        rad->postordine(postOrdine, aux, i);
    }

    T const & operator[] (int k) const
    {
        std::vector<T> static Messi;
        rad->sortare_inordine(Messi);
        return Messi[k];
    }

};
