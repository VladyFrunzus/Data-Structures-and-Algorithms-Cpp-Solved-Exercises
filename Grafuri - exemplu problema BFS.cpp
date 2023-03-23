#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <cstdlib>
#include <bits/stdc++.h>

using namespace std;

ifstream f("entries.in");
ofstream g("entries.out");

class Node
{
public:
    int nr;
    vector<int> adjList;

    Node(int nr1)
    {
        nr=nr1;
    }

};

class Graf
{
    vector<Node> noduri;

public:

    void ad_muchie(int src, int dest)
    {
        bool oks=0, okd=0;
        int auxs,auxd;
        for(int i=0; i<noduri.size(); i++)
        {
            if(noduri[i].nr==src)
            {
                oks=1;
                auxs=i;
            }
            if(noduri[i].nr==dest)
            {
                okd=1;
                auxd=i;
            }
        }
        if(oks==0)
        {
            Node n(src);
            noduri.push_back(n);
            noduri[noduri.size()-1].adjList.push_back(dest);
        }
        else
            noduri[auxs].adjList.push_back(dest);
        if(okd==0)
        {
            Node n(dest);
            noduri.push_back(n);
            noduri[noduri.size()-1].adjList.push_back(src);
        }
        else
            noduri[auxd].adjList.push_back(src);
    }

    void afisare()
    {
        for(int i=0; i<noduri.size(); i++)
        {
            cout<<noduri[i].nr<<" cu vecinii ";
            for(int j=0; j<noduri[i].adjList.size(); j++)
                cout<<noduri[i].adjList[j]<<" ";
            cout<<'\n';
        }
    }

    bool BFS(int src, int dest)
    {
        bool visited[noduri.size()];
        for(int i=0; i<noduri.size(); i++)
            visited[i]=false;

        for(int i=0; i<noduri.size(); i++)
            if(noduri[i].nr==src)
            {
                visited[i]=true;
                break;
            }

        list<int> queue;
        queue.push_back(src);



        while(!queue.empty())
        {
            int aux=-1;
            int cur=queue.front();

            if(cur==dest)
                return 1;
            queue.pop_front();

            for(int i=0; i<noduri.size(); i++)
                if(noduri[i].nr==cur)
                {
                    aux=i;
                    break;
                }

            if(aux!=-1)
                for(int i=0; i<noduri[aux].adjList.size(); i++)
                {
                    int aux2;
                    for(int j=0; j<noduri.size(); j++)
                        if(noduri[j].nr==noduri[aux].adjList[i])
                        {
                            aux2=j;
                            break;
                        }
                    if(!visited[aux2])
                    {
                        queue.push_back(noduri[aux].adjList[i]);
                        visited[aux2]=true;
                    }
                }
        }

        return 0;
    }
};
