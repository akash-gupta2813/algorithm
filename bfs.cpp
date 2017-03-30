#include <bits/stdc++.h>
using namespace std;

void bfs(list <int> *l,int V,int s){
    bool visited[V+1];
    for(int i=1;i<=V;i++)
    visited[i]=false;

    queue <int> q;
    q.push(s);
    visited[s]=true;

    list<int>::iterator it;

    while(!q.empty()){
        int t=q.front();
        cout<<t<<" ";
        q.pop();

        for(it=l[t].begin();it!=l[t].end();it++){
            if(!visited[*it]){
                visited[*it]=true;
                q.push(*it);

            }
        }
    }
}



int main() {
     int V,e,u,v;
     cin>>V>>e;
     list <int> l[V+1];

     for(int i=0;i<e;i++){
         cin>>u>>v;
         l[u].push_back(v);
         l[v].push_back(u);
     }

         int s;
         cin>>s;
         bfs(l,V,s);
	return 0;
}
