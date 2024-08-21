#include "TrieNode.h";
using namespace std;

class Trie{
    TrieNode* root;

    void insertWordHelper(TrieNode* node, string word){
        // base case
        if(word.size() == 0){
            root->isTerminal = true;
            return;
        }

        // induction step
        int index = word[0]-'a';
        TrieNode* child;
        if(root->children[index] != nullptr){
            child = root->children[index];
        }else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // recusrive call
        insertWordHelper(child, word.substr(1));
    }

    bool searchWordHelper(TrieNode* root, string word){
        // base case
        int index = word[0]-'a';
        if(root->children[index] == nullptr) return false;

        if(word.length() == 0 && root->isTerminal) return true;
        else if(word.length() == 0 && !root->isTerminal) return false;

        return searchWordHelper(root->children[index], word.substr(1));
    }

    void removeWordHelper(TrieNode* root, string word){
        int index = word[0]-'a';
        if(root->children[index]==nullptr) return;

        if(word.length() == 0){
            root->isTerminal = false;
            return;
        }

        removeWordHelper(root->children[index], word.substr(1));
    }

    public:
        Trie(){
            root = new TrieNode('\0');
        }

        void insertWord(string word){
            insertWordHelper(root, word);
        }

        bool searchWord(string word){
            return searchWordHelper(root, word);
        }

        void removeWord(string word){
            removeWordHelper(root, word);
            return;
        }
};