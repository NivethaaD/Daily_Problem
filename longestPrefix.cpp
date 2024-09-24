struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
    }
};
class Trie {
private:
    TrieNode* root;

public:
    // Constructor
    Trie() {
        root = new TrieNode();
    }

    // Insert a word into the Trie
    void insert(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->isEndOfWord = true;
    }

    // Search for a word in the Trie
    int getPrefixLength(string word) {
        TrieNode* node = root;
        int count=0;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                 break;
            }
            node = node->children[ch];
            count++;
        }
        return count;
    }

    // Check if there is any word that starts with a given prefix
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char ch : prefix) {
            if (node->children.find(ch) == node->children.end()) {
                return false;
            }
            node = node->children[ch];
        }
        return true;
    }
};
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie t;
        for(auto it:arr1){
            t.insert(to_string(it));
        }
        int maxi=-1;
        for(auto it:arr2){
          maxi=max(maxi,t.getPrefixLength(to_string(it)));
        }
        return maxi;
    }
};
