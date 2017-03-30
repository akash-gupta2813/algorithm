 #include <bits/stdc++.h>
using namespace std;

pair<int, pair<int,int> > p[100001];
int parent[100001];

int find(int x){
    while(parent[x]!=x){
        parent[x]=parent[parent[x]];
        x=parent[x];
    }
    return x;
}

void unionn(int x,int y){
    int p=find(x);
    int q=find(y);
    parent[p]=parent[q];
}



int kruskal(int m){
    int sum=0;

    for(int i=0;i<m;i++){
        int x=p[i].second.first;
        int y=p[i].second.second;

        if(find(x)!=find(y)){
            sum+=p[i].first;
            unionn(x,y);
        }
    }
    return sum;
}

int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=0;i<100001;i++)
    parent[i]=i;

    for(int i=0;i<m;i++){
        int u,v,cst;
        cin>>u>>v>>cst;
        p[i]=make_pair(cst,make_pair(u,v));

    }
    sort(p,p+m);
    int sum=kruskal(m);
    cout<<sum<<endl;
    return 0;
}
