#include <algorithm>
#include <cassert>
#include <string>

using namespace std;

// Trie Node
struct TrieNode {

	// assuming the alphabet to be consisting of 26 lowercase chars [a ... z]
	const static int alphabetSize = 26;
	const static char baseChar = 'a';

	TrieNode *child[alphabetSize];

    // how many words have been inserted till now
	int numberOfWords;

	// how many words with the current prefix are there
	int prefCount;

	// constructor
	TrieNode() {
		numberOfWords = 0;
		prefCount = 0;
	}

	// whether the child nodes have the character c or not
	bool ContainsLetter(char c) {
		return child[c-baseChar] != nullptr;
	}

	// making a new child
	void MakeChild(char c, TrieNode *node) {
		child[c-baseChar] = node;
	}

	// return child node
	TrieNode* GetChild(char c) {
		return child[c-baseChar];
	}

	// increase the prefCount
	void PrefixFound() {
		prefCount++;
	}

	// decrease the prefCount
	void PrefixDelete() {
		prefCount--;
	}

	// finding the last node
	void isLastWord() {
		numberOfWords++;
	}

	// deleting a word
	void deleteWord() {
		numberOfWords--;
	}
};

// Trie Class
class Trie {

private:
	// root of the trie ds
    TrieNode *root;

public:
	// constructor which initializes the trie
	Trie() {
		root = new TrieNode();
	}

	// to insert a word in the trie
	void InsertWord(const string& word) {
		TrieNode *node = root;
		for(char i : word){
			if(!node->ContainsLetter(i)){
				node->MakeChild(i, new TrieNode());
			}
			node = node->GetChild(i);
			node->PrefixFound();
		}
		node->isLastWord();
	}

	// to search a word in the trie
	bool SearchWord(const string& word) {
		TrieNode *node = root;
		for(char i : word){
			if(node->ContainsLetter(i)){
				node = node->GetChild(i);
			}	
			else return false;
		}
		return node->numberOfWords > 0;
	}

	// to delete a word in the trie
	void DeleteWord(const string& word) {
		assert(SearchWord(word));
		TrieNode *node = root;
		for(char i : word) {
			node->PrefixDelete();
			node = node->GetChild(i);
		}
		node->deleteWord();
	}
};