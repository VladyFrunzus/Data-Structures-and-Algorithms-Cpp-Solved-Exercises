#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main()
{
    int n,i,a,k=1;
    vector<int> v;
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    for(i=0; i<n; i++)
        if(v[i]>k)
        {
            v[i]=k;
            k++;
        }
        else
            k=v[i]+1;
    cout<<v.back()+1;
    return 0;
}
