#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 30;

int ind[N], outd[N];
int p[N];
int m;

int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    char str[1010];
    
    int T; scanf("%d", &T);
    while(T--)
    {
        memset(ind, 0, sizeof ind);
        memset(outd, 0, sizeof outd);
        for(int i = 0; i < 26; i++) p[i] = i;
        
        int m; scanf("%d", &m);
        for(int i = 0; i < m; i++)
        {
            scanf("%s", str);
            int len = strlen(str);
            int a = str[0] - 'a', b = str[len - 1] - 'a';
            outd[a]++, ind[b]++;
            p[find(a)] = find(b);
        }
        
        bool success = true;
        
        int start = 0, end = 0, other = 0;
        for(int i = 0; i < 26; i++)
        {
            if(ind[i] != outd[i])
            {
                if(ind[i] + 1 == outd[i]) start++;
                else if(ind[i] == outd[i] + 1) end++;
                else other++;
            }
        }
        
        if(!start && !end && !other || start == 1 && end == 1 && !other) success = true;
        else success = false;
        
        int pre = -1;
        for(int i = 0; i < 26; i++)
        {
            if(ind[i] || outd[i])
            {
                int father = find(i);
                if(pre == -1) pre = father;
                else if(pre != father) success = false;
            }
        }
        
        
        if(!success) printf("The door cannot be opened.\n");
        else printf("Ordering is possible.\n");
    }
    
    return 0;
}
