struct Node {
    bool isEnd;
    vector<Node*> pointer;

    Node() {
        this->isEnd = false;
        this->pointer.resize(26, NULL);
    }
};

class WordDictionary {
public:
    Node* root;

    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* parser = root;
        for(auto& it: word) {
            int index = it - 'a';
            if(!parser->pointer[index]) {
                parser->pointer[index] = new Node();
            }
            parser = parser->pointer[index];
        }
        parser->isEnd = true;
    }

    bool searchUtil(Node* parser, string word) {
        for(int i=0; i<word.size(); i++) {
            auto it = word[i];

            // special case
            if(it == '.') { 
                // t.ie 
                // at . try a, b, c, d, e, .... z
                for(int index=0; index<26; index++) {
                    if(parser->pointer[index]) { // if "t" contains "r" then go ahead and try further
                        if(searchUtil(parser->pointer[index], word.substr(i+1))) {
                            return true;
                        }
                    }
                }
                return false;
            }

            int index = it - 'a';
            if(!parser->pointer[index]) {
                return false;
            }
            parser = parser->pointer[index];
        }
        return parser->isEnd;
    }
    
    bool search(string word) {
        Node* parser = root;
        return searchUtil(parser, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */