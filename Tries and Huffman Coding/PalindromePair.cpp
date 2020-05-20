Palindrome Pair
Givan n number of words, you need to find if there exist any two words which can be joined to make a palindrome or any word itself is a palindrome.
Return true or false.
Input Format :
Line 1 : Integer n
Line 2 : n words (separated by space)
Output Format :
true ot false
Sample Input 1 :
4
abc def ghi cba
Sample Output 2 :
true
Sample Output 1 Expalanation :
"abc" and "cba" forms a palindrome
Sample Input 2 :
4
abc def ghi hg
Sample Output 2 :
true
Sample Output 2 Expalanation :
"ghi" and "hg" forms a palindrome



/*************************************************************** SOLUTION **********************************************************/


#include<bits/stdc++.h>
using namespace std;
class TrieNode {
    public : char data;
    TrieNode **children;
    bool isTerminal;
    int childCount;
    TrieNode(char data) {
        this -> data = data;
        children = new TrieNode*[26];
        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
    }
};
class Trie {
    TrieNode *root;
    public : int count;
    Trie() { 
        this->count = 0;
        root = new TrieNode('\0');
    }
    bool insertWord(TrieNode *root, string word) {
        // Base case 
        if(word.size() == 0) {
            if (!root->isTerminal) {
                root -> isTerminal = true;
                return true;
            }
            else { 
                return false;
            }
        }
        // Small Calculation 
        int index = word[0] - 'a'; 
        TrieNode *child;
        if(root -> children[index] != NULL) {
            child = root -> children[index]; 
        }
        else { 
            child = new TrieNode(word[0]);
            root -> children[index] = child;
            root->childCount++; 
        }
        // Recursive call 
        return insertWord(child, word.substr(1));
    }
    // For user 
    void insertWord(string word) {
        if (insertWord(root, word)) {
            this->count++;
        }
    }
    pair<bool,int> search(TrieNode* root,string word) {
        // Write your code here
        if(word.size()==0){ 
            if(root->isTerminal){ 
                pair<bool,int> ret;
                ret.first = true;
                ret.second = 0;
                return ret;
            }
            else{
                pair<bool,int> ret;
                ret.first = false;
                ret.second = 0;
                return ret;
            }
        }
        int index = word[0] - 'a';
        if(root->children[index]==NULL){
            pair<bool,int> ret;
            ret.first = false; 
            ret.second = word.size();
            return ret;
        }
        else{
            return search(root->children[index],word.substr(1)); 
        }
    }
    pair<bool,int> search(string word){ 
        return search(root,word); 
    }
    bool findIfPalindromePair(vector<string> arr) {
        // Complete this function 
        // Return true or false. 
        for(int i=0;i<arr.size();++i){
            string tmp = arr[i];
            reverse(tmp.begin(),tmp.end());
            if(tmp==arr[i])
                return true;
            insertWord(tmp);
        }
        for(int i=0;i<arr.size();++i){ 
            pair<bool,int> tmp = search(arr[i]);
            if(tmp.first)
                return true;
            else{
                int j = arr[i].length()-1;
                int count = 0;
                string hold; 
                while(count<tmp.second){
                    hold += arr[i][j];
                    --j;
                    ++count;
                } 
                string buck = hold;
                reverse(hold.begin(),hold.end());
                if(buck==hold) 
                    return true;
            } 
        } 
        return false;
    }
};
