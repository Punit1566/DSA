class Solution {
public:
    int solve(pair<int,int>p1,pair<int,int>p2,pair<int,int>p3){
        int x1=p1.first,x2=p2.first,x3=p3.first;
        int y1=p1.second,y2=p2.second,y3=p3.second;
        return (y2-y1)*(x3-x2)-(y3-y2)*(x2-x1);
    }
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        sort(trees.begin(),trees.end());
        vector<vector<int>>ans;
        vector<pair<int,int>>lower,upper;
        for(auto pt:trees){
            int l=lower.size();
            int u=upper.size();
            while(l>=2 &&solve(lower[l-1],lower[l-2],{pt[0],pt[1]})<0){
                lower.pop_back();
                l--;
            }
            while(u>=2 &&solve(upper[u-1],upper[u-2],{pt[0],pt[1]})>0){
                upper.pop_back();
                u--;
            }
            lower.push_back({pt[0],pt[1]});
            upper.push_back({pt[0],pt[1]});
        }
        set<pair<int,int>>st;
        for(auto pt:lower){
            st.insert(pt);
        }
        for(auto pt:upper){
            st.insert(pt);
        }
        for(auto pt:st){
            ans.push_back({pt.first,pt.second});
        }
        return ans;
    }
};