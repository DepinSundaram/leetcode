#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*

Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

WordDictionary() Initializes the object.
void addWord(word) Adds word to the data structure, it can be matched later.
bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.
 

Example:

Input
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
Output
[null,null,null,null,false,true,true,true]

Explanation
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True

*/


class WordDictionary {
    vector<WordDictionary*> children;
    bool isEndOfword;
public:
    /** Initialize your data structure here. */

    WordDictionary():isEndOfword(false) {
        children = vector<WordDictionary*>(26, NULL);
    }
    
    void addWord(string word) {
        WordDictionary* curr = this;
        for(char c: word)
        {
            if((curr->children[c-'a'])==NULL)
            {
                curr->children[c-'a'] = new WordDictionary();
            }
            curr = curr->children[c-'a'];
        }

        curr->isEndOfword = true;
    }
    
    bool search(string word) {

        WordDictionary* curr = this;
        for(int i = 0; i < word.length(); ++i){
            char c = word[i];
            if(c == '.'){
                for(auto ch: curr->children)
                    if(ch && ch->search(word.substr(i+1))) return true;
                return false;
            }
            if(curr->children[c - 'a'] == nullptr) return false;
            curr = curr->children[c - 'a'];
        }

        return curr && curr->isEndOfword;
        
    }
};


int main()
{
  WordDictionary* obj = new WordDictionary();
  string word = "apple";
  obj->addWord(word);
  bool param_2 = obj->search("..ple");
    cout << "END";
}
/**
 * Your WordDictionary object will be instantiated and called as such:

 */