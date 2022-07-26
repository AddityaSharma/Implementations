/*
Implementation-1:
Following Functions are avaible:
--> void insert(string word)
--> bool search(string word)
--> bool startsWith(string prefix)
*/

struct Node{
    Node* links[26];
    bool flag = 0;
    
    bool cantainsKey(char ch){
        return (links[ch - 'a'] != NULL);
    }
    
    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }
    
    Node* get(char ch){
        return links[ch - 'a'];
    }
    
    void setEnd(){
        flag = 1;
    }
    
    bool isEnd(){
        return flag;
    }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(int i = 0; i < word.size(); i++){
            if(!node->cantainsKey(word[i])){
                node->put(word[i], new Node());
            }
            // moves to the reference trie.
            node = node->get(word[i]);
        }
        // marks the word to be completed.
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node = root;
        for(int i = 0; i < word.size(); i++){
            if(!node->cantainsKey(word[i])){
                return 0;
            }
            // moves to the reference trie.
            node = node->get(word[i]);
        }
        
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i = 0; i < prefix.size(); i++){
            if(!node->cantainsKey(prefix[i])){
                return 0;
            }
            // moves to the reference trie.
            node = node->get(prefix[i]);
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
