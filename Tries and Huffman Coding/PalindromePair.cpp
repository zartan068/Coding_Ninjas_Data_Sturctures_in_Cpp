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


#include <string>
#include <vector> 
class TrieNode {
	public :
	char data;
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

	public :
	int count;

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
			} else {
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
    
    bool search(TrieNode *root,string word)
    {
        if(word.size()==0 && root->isTerminal==true)
            return true;
        else if(word.size()==0 && root->isTerminal!=true)
            return false;
        
        int index=word[0]-'a';
        
        if(root->children[index]!=NULL)
            return search(root->children[index],word.substr(1));
        else
            return false;
        
            
    }
    bool search(string word) {
        // Write your code here
        return search(root,word);
        
    }
    string reverse(string word)
    {
        int length=word.size();
        for(int i=0;i<=length/2;i++)
        {
            char temp=word[i];
            word[i]=word[length-i-1];
            word[length-i-1]=temp;
        }
        return word;
    }
  

	

	bool findIfPalindromePair(vector<string> arr) {
		// Complete this function
		// Return true or false.
        
       for(int i=0;i<arr.size();i++)
           insertWord(arr[i]);
       for(int i=0;i<arr.size();i++)
       {
           string word=reverse(arr[i]);
           if(search(word))
               return true;
           else if(search(word.substr(1)))
               return true;
       }
        return false;
	 }
    
};
