#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main()
{
    int n,i,c,Min,aux,j;
    double err = 0.0000000000001, err2 = 0.1;
    vector<int>  a,grad,fin,auxil;
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>c;
        a.push_back(c);
    }
    for(i=0; i<n-1; i++)
        grad.push_back(a[i]-a[i+1]);
    grad.push_back(a[n-1]-a[0]);
    a.clear();
    Min=grad[0];
    for(i=1; i<n; i++)
        if(grad[i]<Min)
            Min=grad[i];
    for(i=0; i<n; i++)
    {
        if(abs(grad[i]-Min)<err)
        {
            if(fin.size()!=n)

            {
                for(j=i; j<n; j++)
                    fin.push_back(grad[j]);
                for(j=0; j<i; j++)
                    fin.push_back(grad[j]);
            }

            else
            {
                auxil.clear();
                for(j=i; j<n; j++)
                    auxil.push_back(grad[j]);
                for(j=0; j<i; j++)
                    auxil.push_back(grad[j]);
                for(j=1; j<n; j++)
                    if(abs(auxil[j]-fin[j])>err2)
                    {
                        if(auxil[j]<fin[j])
                        {
                            fin=auxil;
                            break;
                        }
                        else
                            break;
                    }
            }
        }
    }
    for(i=0; i<n; i++)
        cout<<fin[i]<<" ";
    return 0;
}
