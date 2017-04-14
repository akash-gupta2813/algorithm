#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
list<pii> l[10000001];
long long dis[1000001];

void dijkstra(int s,int n){
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    list<pii>::iterator it;

    memset(dis, 0x3f, sizeof(dis));

    pq.push(pii(0,s));
    dis[s]=0;

    while(!pq.empty()){
        int u=pq.top().second;
        int dist=pq.top().first;
        pq.pop();

        for(it=l[u].begin();it!=l[u].end();it++){
            int a=(*it).second;
            int b=(*it).first;

            if(dis[a]>dis[u]+b){
                dis[a]=dis[u]+b;
                pq.push(pii(dis[a],a));
            }
        }
    }

    for(int i=1;i<=n;i++)
    cout<<dis[i]<<endl;
}

int main(){
    int n,m;
    cin>>n>>m;

   for(int i=0;i<m;i++){
       int u,v,w;
       cin>>u>>v>>w;
       l[u].push_back(make_pair(w,v));
       l[v].push_back(make_pair(w,u));
   }
   int s;
   cin>>s;

   dijkstra(s,n);
 return 0;
}
