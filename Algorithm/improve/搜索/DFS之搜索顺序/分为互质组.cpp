#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int N=10;
int a[N];
vector<int> g[N];
int n;
int ans=10;
int len=0;

int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}

bool check(int c,int x){
    for(int i=0;i<g[c].size();i++){
        if(gcd(g[c][i],x)>1) return false;
    }
    return true;
}

void dfs(int u){
    if(u==n){
        ans=min(ans,len);
        return;
    }

    //每个元素的方法即——放到当前已经存在的组中  或者  放到新开的组中

    for(int i=0;i<len;i++){
        if(check(i,a[u])){
            g[i].push_back(a[u]);
            dfs(u+1);
            g[i].pop_back();
        }
    }
   //可见这里的len代表着的是当前开辟数组的个数
    g[len++].push_back(a[u]);
    dfs(u+1);
    g[--len].pop_back();
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];

    dfs(0);

    cout<<ans;
    return 0;
}

