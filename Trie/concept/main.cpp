/*
Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
 

 Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
 


*/
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
class Trie {
    Trie* children[26];
    bool isEndOfWord;
public:

    /** Initialize your data structure here. */
    Trie() {
        isEndOfWord = false;
        for(int i =0; i < 26; ++i)
        {
            children[i] = NULL;
        }
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* curr = this;
        for(char c: word)
        {
            if(!(curr->children[c-'a']))
                curr->children[c-'a'] = new Trie;
            curr = curr->children[c-'a'];
        }
        curr->isEndOfWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* curr = this;
        for(char c: word)
        {
            curr = curr->children[c-'a'];
            if(!(curr))
                return false;
        }
        if(curr->isEndOfWord)
            return true;
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* curr = this;
        for(char c: prefix)
        {
            curr = curr->children[c-'a'];
            if(!(curr))
                return false;
        }
        return true;
    }
};

int main()

{


 Trie* obj = new Trie();
 Trie* obj2 = new Trie();
 // string word, prefix;
 
 obj->insert("apple");
 bool param_2 = obj2->search("apple");
 bool param_3 = obj2->search("app");
 bool param_4 = obj2->startsWith("app");

 cout << "End" ;

}