class Solution {
public:
    bool isPal(string& s, int i, int j){
        if(i>=j){
            return true;
        }
        if(s[i]==s[j]){
            return isPal(s,i+1,j-1);
        }else{
            return false;
        }
    }
    string longestPalindrome(string s) {
        int n=s.length();
        int maxLength=0;
        int start=-1;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPal(s,i,j)){
                    if(maxLength<j-i+1){
                        maxLength=j-i+1;
                        start=i;
                    }
                }
            }
        }
        return s.substr(start,maxLength);
    }
};