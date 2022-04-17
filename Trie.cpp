#include <string>
#include <iostream>
using namespace std;
const int ALPHABET_SIZE = 26;
struct TrieNode
{
	struct TrieNode* children[ALPHABET_SIZE];
	bool isEndOfWord;
};
struct Trie
{
	struct TrieNode* root = getNode();
	struct TrieNode* getNode(void)
	{
		struct TrieNode* pNode = new TrieNode;
		pNode->isEndOfWord = false;
		for (int i = 0; i < ALPHABET_SIZE; i++) pNode->children[i] = NULL;
		return pNode;
	};
	void insert(string key)
	{
		struct TrieNode* pCrawl = root;
		for (int i = 0; i < key.length(); i++)
		{
			int index = key[i] - 'a';
			if (!pCrawl->children[index]) pCrawl->children[index] = getNode();
			pCrawl = pCrawl->children[index];
		}
		pCrawl->isEndOfWord = true;
	};
	bool search(string key)
	{
		struct TrieNode* pCrawl = root;
		for (int i = 0; i < key.length(); i++)
		{
			int index = key[i] - 'a';
			if (!pCrawl->children[index]) return false;
			pCrawl = pCrawl->children[index];
		}
		return (pCrawl != NULL && pCrawl->isEndOfWord);
	};
	bool isEmpty()
	{
		for (int i = 0; i < ALPHABET_SIZE; i++) if (root->children[i]) return false;
		return true;
	};
	TrieNode* remove(string key, int depth = 0)
	{
		if (!root) return NULL;
		if (depth == key.size())
		{
			if (root->isEndOfWord) root->isEndOfWord = false;
			if (isEmpty())
			{
				delete (root);
				root = NULL;
			}
			return root;
		}
		int index = key[depth] - 'a';
		root->children[index] = remove(root->children[index], key, depth + 1);
		if (isEmpty() && root->isEndOfWord == false)
		{
			delete (root);
			root = NULL;
		}
		return root;
	};
	TrieNode* remove(TrieNode* root, string key, int depth = 0)
	{
		if (!root) return NULL;
		if (depth == key.size())
		{
			if (root->isEndOfWord) root->isEndOfWord = false;
			if (isEmpty())
			{
				delete (root);
				root = NULL;
			}
			return root;
		}
		int index = key[depth] - 'a';
		root->children[index] = remove(root->children[index], key, depth + 1);
		if (isEmpty() && root->isEndOfWord == false)
		{
			delete (root);
			root = NULL;
		}
		return root;
	};
};
int main()
{
	Trie hey;
	string keys[] = { "the", "a", "there",
					"answer", "any", "by",
					"bye", "their", "hero", "heroplane" };
	int n = sizeof(keys) / sizeof(keys[0]);
	for (int i = 0; i < n; i++) hey.insert(keys[i]);
	hey.search("the") ? cout << "Yes\n" : cout << "No\n";
	hey.search("these") ? cout << "Yes\n" : cout << "No\n";
	hey.remove("heroplane");
	hey.search("hero") ? cout << "Yes" : cout << "No";
}
