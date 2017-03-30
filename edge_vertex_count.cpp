#include <bits/stdc++.h>
using namespace std;

list <int> l[100001];

void dfs(int s,bool visited[]){
   visited[s]=true;
   cout<<s<<" ";

   list<int>::iterator it;

   for(it=l[s].begin();it!=l[s].end();it++){
       if(!visited[*it])
        dfs(*it,visited);
   }

}


int main() {
     int V,u,v,e;
     cin>>V>>e;


      bool visited[V+1];
      for(int i=1;i<=V;i++)
      visited[i]=false;

     for(int i=0;i<e;i++){
         cin>>u>>v;
        l[u].push_back(v);
        l[v].push_back(u);
     }

         int s;
         cin>>s;
         dfs(s,visited);
	return 0;
}
