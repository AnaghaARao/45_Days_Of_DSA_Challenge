#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
        char data;
        vector<TrieNode*> children(26, nullptr);
        bool isTerminal;

        TrieNode(char data){
            this->data = data;
            isTerminal = false;
        }
};