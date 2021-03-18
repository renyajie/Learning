// Forward declaration of compare API.
// bool compare(int a, int b);
// return bool means whether a is less than b.

class Solution {
public:
    vector<int> specialSort(int N) {
        vector<int> ans(1,1);
        for(int i=2;i<=N;i++)
        {
            int l=0,r=ans.size();//ע���Ҳ�Ҫ��һ������Ϊ���Զ���iС
            while(l<r)
            {
                int mid=l+r>>1;
                if(compare(i,ans[mid]))r=mid;//��i�����С���±�
                else l=mid+1;
            }
            ans.push_back(i);
            for(int j=ans.size()-2;j>=r;j--)swap(ans[j],ans[j+1]);
        }
        return ans;
    }
};
