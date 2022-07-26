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



/*
Implementation-1:
Following Functions are avaible:
--> void insert(string word)
--> int countWordsEqualTo(string &word)
--> int countWordsStartingWith(string & word)
--> void erase(string & word)
*/

struct Node {
    Node * links[26];
    int cntEndWith = 0;
    int cntPrefix = 0;

    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }
    
    Node * get(char ch) {
        return links[ch - 'a'];
    }
    
    void put(char ch, Node * node) {
        links[ch - 'a'] = node;
    }
    
    void increaseEnd() {
        cntEndWith++;
    }
    
    void increasePrefix() {
        cntPrefix++;
    }
    
    void deleteEnd() {
        cntEndWith--;
    }
    
    void reducePrefix() {
        cntPrefix--;
    }
    
    int getEnd() {
        return cntEndWith;
    }
    
    int getPrefix() {
        return cntPrefix;
    }
};

class Trie {
private:
    Node * root;

public:
    /** Initialize your data structure here. */
    Trie() {
      root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node * node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node -> containsKey(word[i])) {
                node -> put(word[i], new Node());
            }
            node = node -> get(word[i]);
            node -> increasePrefix();
        }
        node -> increaseEnd();
    }

    /** count the occurance of word in the trie. */
    int countWordsEqualTo(string &word){
        Node *node = root;
        for (int i = 0; i < word.length(); i++){
            if (node->containsKey(word[i])){
                node = node->get(word[i]);
            }else{
                return 0;
            }
        }
        return node->getEnd();
    }

    /** count the occurance of word that starts with given word in the trie. */
    int countWordsStartingWith(string & word) {
        Node * node = root;
        for (int i = 0; i < word.length(); i++) {
            if (node -> containsKey(word[i])) {
                node = node -> get(word[i]);
            }else{
                return 0;
            }
        }
        return node -> getPrefix();
    }

    /** delete a word from the trie. */
    void erase(string & word) {
        Node * node = root;
        for (int i = 0; i < word.length(); i++) {
            if (node -> containsKey(word[i])) {
                node = node -> get(word[i]);
                node -> reducePrefix();
            }else{
                return;
            }
        }
        node -> deleteEnd();
    }
};
