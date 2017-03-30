 #include <bits/stdc++.h>
using namespace std;

//int MAX=100001;
typedef pair<int,int> pii;
int visited[100001];
vector <pii> vec[100001];

int prims(int x){

   priority_queue <pii,vector <pii>,greater <pii> > q;
   int mincost=0;

   q.push(make_pair(0,x));

   while(!q.empty()){
       pii p=q.top();
       q.pop();
       int x=p.second;

       if(visited[x])
       continue;

       visited[x]=1;
       mincost+=p.first;

       for(int i=0;i<vec[x].size();i++){
           int y=vec[x][i].second;
           if(!visited[y])
               q.push(vec[x][i]);
         }

   }
   return mincost;
}

int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++){
        int u,v,cst;
        cin>>u>>v>>cst;
       vec[u].push_back(make_pair(cst,v));
       vec[v].push_back(make_pair(cst,u));
    }

    for(int i=1;i<100001;i++)
    visited[i]=0;

    int mincost=prims(1);
    cout<<mincost<<endl;
    return 0;
}
