 #include <iostream>
#include <bits/stdc++.h>
using namespace std;
set <int> l[100001];
int visited[100001];

void bfs(int n){


    set<int>::iterator it;
    queue<int> q;

    for(int i=1;i<=n;i++){
        double e=0,v=1;

      //extracting component
        if(!visited[i]){
             q.push(i);
             visited[i]=true;
            while(!q.empty()){
                int t=q.front();
                q.pop();
                it=l[t].begin();
                for(;it!=l[t].end();){
                     e++;

                    if(!visited[*it]){
                        visited[*it]=true;
                        q.push(*it);
                      v++;
                    }

                    //deletion of edges
                    int z=*it;
                    l[t].erase(z);
                    l[z].erase(t);
                   it=l[t].begin();
                }

            }
           cout<<i<<" "<<v<<" "<<e<<endl;

        }

    }


}

int main()
{
   int n,m,u,v;
   cin>>n>>m;

   for(int i=0;i<m;i++){
       cin>>u>>v;
       l[u].insert(v);
       l[v].insert(u);
   }
   bfs(n);

    return 0;
}
