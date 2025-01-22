class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int m=g.size();
        int n=s.size();
        int i=0,j=0,cnt=0;
        while(i<m&&j<n){
            if(s[j]>=g[i]){
                cnt++;
                i++;j++;
            }
            else{
                j++;
            }
        }
        return cnt;
    }
};