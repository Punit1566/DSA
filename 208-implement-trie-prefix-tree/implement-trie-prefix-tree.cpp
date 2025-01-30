class Trie {
public:
    class TrieNode{
        public:
        bool isEnd;
        TrieNode* children[26];

        TrieNode(){
            isEnd=false;
            for(int i=0;i<26;i++){
                children[i]=NULL;
            }
        }
    };
    TrieNode *root;

    Trie() {
        root=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* crawler=root;
        for(int i=0;i<word.length();i++){
            char ch=word[i];
            int idx=ch-'a';
            if(crawler->children[idx]==NULL){
                TrieNode* node=new TrieNode();
                crawler->children[idx]=node;
            }
            crawler=crawler->children[idx];
        }
        crawler->isEnd=true;
    }
    
    bool search(string word) {
        TrieNode* crawler=root;
        for(int i=0;i<word.length();i++){
            char ch=word[i];
            int idx=ch-'a';
            if(crawler->children[idx]==NULL){
                return false;
            }
            crawler=crawler->children[idx];
        }
        if(crawler!=NULL && crawler->isEnd==true)return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode* crawler=root;
        for(int i=0;i<prefix.length();i++){
            char ch=prefix[i];
            int idx=ch-'a';
            if(crawler->children[idx]==NULL){
                return false;
            }
            crawler=crawler->children[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */