#include<iostream>
#include<queue>
using namespace std;

int main()
{
    int T;scanf("%d",&T);
    while(T--)
    {
        int id,n;scanf("%d%d",&id,&n);
        printf("%d %d\n",id,n+1>>1);
        priority_queue<int> down;
        priority_queue<int,vector<int>,greater<int>> up;
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            int t;scanf("%d",&t);
            if(down.empty()||t<=down.top())down.push(t);
            else up.push(t);
            if(down.size()>up.size()+1)up.push(down.top()),down.pop();
            else if(up.size()>down.size())down.push(up.top()),up.pop();
            if(i&1)
            {  
                printf("%d ",down.top());
                cnt++;
                if(cnt%10==0)printf("\n");
            }
            
        }
        if(cnt%10)printf("\n");
    }
    return 0;
}
