#include"Queue.h"


int main()
{
    int p,c,d,b,in,pret,contoro=0,contorp=0,Max,OK=1;
    char nume[20];
    Queue<int> q;
    cin>>p>>c>>d>>b;
    while(cin>>in)
    {
        contoro++;
        q.push(contoro,in);
        q.change_pinc(contorp+1);
        Max=0;
        while(OK)
        {
            cin>>nume;
            if(strcmp(nume,"T")!=0)
            {
                contorp++;
                cin>>pret;
                if(pret>Max)
                    Max=pret;
                q.add_p_tot(pret);
            }
            else
                break;
        }
        q.change_psf(contorp);
        q.change_p_max(Max);
    }
    q.prelucrare(p,c,d,b);
    return 0;
}
