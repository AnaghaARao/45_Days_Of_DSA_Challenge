#include<bits/stdc++.h>
using namespace std;

class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    TrieNode *root;

   public:
    int count;

    Trie() {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool insertWord(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            if (!root->isTerminal) {
                root->isTerminal = true;
                return true;
            } else {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        return insertWord(child, word.substr(1));
    }

    void insertWord(string word) {
        if (insertWord(root, word)) {
            this->count++;
        }
    }

    bool checkPrefix(TrieNode* root, string word){
        if(word.length() == 0) return true;
        int index = word[0]-'a';
        if(root->children[index] == nullptr) return false;

        return checkPrefix(root->children[index], word.substr(1));
    }

    TrieNode* getRoot(TrieNode* root, string pattern){
        while(pattern.length()!=0){
            int index = pattern[0]-'a';
            root = root->children[index];
            pattern = pattern.substr(1);
        }
        return root;
    }

    void helper(TrieNode* root, string curr_word, unordered_set<string>& words){
        if(root->isTerminal){
            words.insert(curr_word);
        }
        for(int i = 0 ; i < 26 ; i++){
            if(root->children[i] != nullptr){
                char c = char(i+97);
                // curr_word += c;      DON'T DO THIS....INCORRECT WORDS MAY GET GENERATED
                helper(root->children[i], curr_word+c, words); // INSTEAD PASS IT AS A NEW WORD TO THE RECURSIVE FUNCTION
            }
        }
        return;
    }

    void autoComplete(vector<string> input, string pattern) {
        if(pattern.length() == 0 || input.size() == 0) return;
        // Write your code here
        TrieNode* root = new TrieNode('\0');
        for(int i = 0 ; i < input.size() ; i++){
            insertWord(root,input[i]);
        }

        bool exists = checkPrefix(root, pattern);
        if(exists){
            unordered_set<string> words;
            string curr_word = pattern;
            TrieNode* newRoot = getRoot(root, pattern);
            helper(newRoot, curr_word, words);
            for(auto ele : words){
                cout<<ele<<endl;
            }
        }else return;
    }
};