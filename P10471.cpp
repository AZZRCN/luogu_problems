#include <bits/stdc++.h>
using namespace std;
class IONode {
public:
	IONode* next_[2];
	bool end_;
	IONode(void) {
		memset(next_, 0, sizeof(next_)); end_ = false;
	}
};
class intTrie {
public:
	IONode* root;
	int length=32;
	intTrie() { root = new IONode(); }
	void set_long(int O) { length = O; }
	void insert(std::string word) {
		reverse(word.begin(), word.end());
		word.resize(32, '0');
		reverse(word.begin(), word.end());
		IONode* p = root;
		for (int cur = 0; cur < word.length(); cur++) {
			if (p->next_[word[cur] - '0'] == nullptr) { p->next_[word[cur] - '0'] = new IONode(); }
			p = p->next_[word[cur] - '0'];
		}
		p->end_ = true;
	}
	bool search(std::string word) {
		reverse(word.begin(), word.end());
		word.resize(32, '0');
		reverse(word.begin(), word.end());
		IONode* p = root;
		for (char c : word) { if (p->next_[c - '0'] == nullptr) { return false; }p = p->next_[c - '0']; }
		return p->end_;
	}
	void del(std::string word) {
		reverse(word.begin(), word.end());
		word.resize(32, '0');
		reverse(word.begin(), word.end());
		IONode* p = root;
		for (char c : word) { if (p->next_[c - '0'] == nullptr) { return; }p = p->next_[c - '0']; }
		p->end_ = false;
	}
	unsigned int search_max_xor(std::string word) {
		reverse(word.begin(), word.end());
		word.resize(32, '0');
		reverse(word.begin(), word.end());
		IONode* p = root;
		unsigned int n = 0;
		int cur = 31;
        bool flag;
		for (char c : word) {
			cur--;
            flag = p->next_[c-'0'] == nullptr;
			if (flag) {
				p = p->next_[(c - '0') ^ 1];
			}
			else {
                if(c == '1') {n |= (1 << cur);}
				p = p->next_[c - '0'];
			}
		}
		return n;
	}
};
int main(){
    intTrie trie;
    trie.insert("10");
    trie.insert("11");
    cout << trie.search_max_xor("01");
}