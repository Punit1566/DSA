class Solution {
public:
    void solve(int i, string &digits,string &temp, vector<string>&ans,unordered_map<char,string>&mp){
        if(i==digits.size()){
            ans.push_back(temp);
            return;
        }
        for(auto x:mp[digits[i]]){
            temp.push_back(x);
            solve(i+1,digits,temp,ans,mp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string>mp;
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";mp['5']="jkl";
        mp['6']="mno";mp['7']="pqrs";
        mp['8']="tuv";mp['9']="wxyz";
        vector<string>ans;
        if(digits.size()==0)return ans;
        string temp;
        solve(0,digits,temp,ans,mp);
        return ans;
    }
};