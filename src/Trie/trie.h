#ifndef TRIE_H
#define TRIE_H

#include <string>

// Trie Node
struct TrieNode {
    // Assuming the alphabet to consist of 26 lowercase chars [a ... z]
    static const int alphabetSize = 26;
    static const char baseChar = 'a';

    TrieNode *child[alphabetSize];

    // How many words have been inserted till now
    int numberOfWords;

    // How many words with the current prefix are there
    int prefCount;

    // Constructor
    TrieNode();

    // Whether the child nodes have the character c or not
    bool ContainsLetter(char c);

    // Making a new child
    void MakeChild(char c, TrieNode *node);

    // Return child node
    TrieNode* GetChild(char c);

    // Increase the prefCount
    void PrefixFound();

    // Decrease the prefCount
    void PrefixDelete();

    // Finding the last node
    void isLastWord();

    // Deleting a word
    void deleteWord();
};

// Trie Class
class Trie {
private:
    TrieNode *root;

public:
    // Constructor which initializes the trie
    Trie();

    // Destructor to free allocated memory
    ~Trie();

    // To insert a word in the trie
    void InsertWord(const std::string& word);

    // To search a word in the trie
    bool SearchWord(const std::string& word);

    // To delete a word in the trie
    void DeleteWord(const std::string& word);
};

#endif // TRIE_H