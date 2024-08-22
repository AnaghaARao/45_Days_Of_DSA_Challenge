// Problem statement
// You are given an array ‘ARR’ consisting of ‘N’ strings. 
// Your task is to find the longest common prefix among all these strings. 
// If there is no common prefix, you have to return an empty string.
// A prefix of a string can be defined as a substring obtained after removing some or all characters from the end of the string.

// For Example:
// Consider ARR = [“coding”, ”codezen”, ”codingninja”, ”coders”]
// The longest common prefix among all the given strings is “cod” as it is present as a prefix in all strings. 
// Hence, the answer is “cod”.

#include<bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    char data;
    vector<TrieNode*> children;
    bool isTerminal;

    TrieNode(char data) {
        this->data = data;
        children = vector<TrieNode*>(26, nullptr);  // Correct initialization of the children vector
        isTerminal = false;
    }
};
class Trie{
    public:
    TrieNode* root;
    Trie(){
        root = new TrieNode('\0');
    }

    // helper function to find the largest common prefix
    int helper(TrieNode* root, string word){
        int maxC = INT_MIN;
        int cnt = 0;
        int flag = 0;

        while (word.length() != 0) {
            int index = word[0] - 'a';
            // Trie* child;
            if (root->children[index] == nullptr) {
                //  UNNECESARY COMPUTATION
                // cnt = 0; // reset the count for next longest possible prefix
                // TrieNode *child = new TrieNode(word[0]);
                // root->children[index] = child; 
                flag = 1;
            } else {
                cnt++;
            }
            maxC = max(maxC, cnt); // update maxC after every character
            if(flag == 1) break;
            root = root->children[index];
            word = word.substr(1);
        }
        return maxC;
    }

    // general insertion operation
    void insertWord(TrieNode* root, string word){
        if(word.length() == 0) return;

        int index = word[0]-'a';
        TrieNode* child;
        if(root->children[index] == nullptr){
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }else{
            child = root->children[index];
        }
        insertWord(child, word.substr(1));
    }

    string longestCommonPrefix(vector<string> &arr, int n)
    {
        int res = INT_MAX;
        // Write your code here
        TrieNode* root = new TrieNode('\0');
        insertWord(root, arr[0]); // insert the first word as it is
        for(int i = 1 ; i < n ; i++){
            int cnt = helper(root, arr[i]);
            res = min(res, cnt); // find the min commonality among all word
        }

        // substring is starting from 0 position cause we are finding common prefix
        string result=arr[0].substr(0, res); // .substr(starting position, length)
        return result;

    }
};

