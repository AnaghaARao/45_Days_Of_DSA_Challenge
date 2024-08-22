// Problem statement
// Given a string 'S', you are supposed to return the number of distinct substrings(including empty substring) of the given string. 
// You should implement the program using a trie.

// Note :
// A string ‘B’ is a substring of a string ‘A’ if ‘B’ that can be obtained by deletion of, several characters(possibly none) 
// from the start of ‘A’ and several characters(possibly none) from the end of ‘A’. 
// Two strings ‘X’ and ‘Y’ are considered different if there is at least one index ‘i’  such that the character of ‘X’ at index ‘i’ 
// is different from the character of ‘Y’ at index ‘i’(X[i]!=Y[i]).

#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    char data;
    vector<TrieNode*> children;
    bool isTerminal;

    TrieNode(char data){
        this->data = data;
        children = vector<TrieNode*>children(26, nullptr);
        isTerminal = false;
    }
};

void helper(TrieNode* root, string word, int& cnt){
    if(word.length() == 0) return;

    int index = word[0]-'a';
    TrieNode* child;
    if(root->children[index] == nullptr){
        cnt++;
        child = new TrieNode(word[0]);
        root->children[index] = child;
    }else{
        child = root->children[index];
    }
    helper(child, word.substr(1), cnt);
}

int countDistinctSubstrings(string &s){
    TrieNode* root = new TrieNode('\0');
    int cnt = 0;
    for(int i = 0 ; i < s.length() ; i++){
        helper(root, s.substr(i), cnt);
    }
    return ++cnt;
}