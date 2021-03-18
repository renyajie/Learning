#include<cstdio>
#include<cstring>
using namespace std;

const int N=10;
char g[N][N],bg[N][N];

int dir[5][2]={{-1,0},{1,0},{0,-1},{0,1},{0,0}};
void turn(int x,int y)
{
    for(int i=0;i<5;i++)
    {
        int nx=dir[i][0]+x,ny=dir[i][1]+y;
        if(nx<0||nx>=5||ny<0||ny>=5)continue;
        g[nx][ny]=g[nx][ny]=='1'?'0':'1';
    }
}

int main()
{
    int T;scanf("%d",&T);
    while(T--)
    {
        for(int i=0;i<5;i++)scanf("%s",bg[i]);
        int ans=10;
        for(int i=0;i<1<<5;i++)
        {
            int cnt=0;
            memcpy(g,bg,sizeof g);
            for(int j=0;j<5;j++) if(i>>j&1) {turn(0,j);cnt++;}
            for(int j=1;j<5;j++)
                for(int k=0;k<5;k++)
                    if(g[j-1][k]=='0') {turn(j,k);cnt++;}
            bool ok=true;
            for(int j=0;j<5;j++) if(g[4][j]=='0') ok=false;
            if(ok&&cnt<ans)ans=cnt;
        }
        if(ans>6)ans=-1;
        printf("%d\n",ans);
    }
    return 0;
}
