#pragma once
#include <iostream>
#include <vector>
#include <queue>
struct node {
	char c;
	bool isend;
	std::vector<node*> child;
};
class trie {
	node* root;
	void insert(const std::string& str, node* cur, int idx) {
		int size = str.size();
		if (idx == size) {
			return;
		}
		for (node* t : cur->child) {
			if (t->c == str[idx]) {
				if (idx == size - 1) {
					t->isend = 1;
					return;
				}
				insert(str, t, idx + 1);
				return;
			}
		}
		node* n = new node();
		n->c = str[idx];
		n->isend = 0;
		if (idx == size - 1) {
			n->isend = 1;
		}
		n->child = std::vector<node*>();
		cur->child.push_back(n);
		insert(str, n, idx + 1);
	}
	bool find(const std::string& str, node* cur, int idx) {
		if (str.size() == idx) {
			return cur->isend;
		}
		for (node* t : cur->child) {
			if (t->c == str[idx]) {
				return find(str, t, idx + 1);
			}
		}
		return 0;
	}
public:
	trie() {
		root = new node();
		root->c = '@';
		root->isend = 0;
		root->child = std::vector<node*>();
	}
	void insert(const std::string& str) {
		insert(str, root, 0);
	}
	void bfs() {
		std::queue<node*> q;
		q.push(root);
		while (!q.empty()) {
			int s = q.size();
			for (int i = 0; i < s; i++) {
				node* t = q.front();
				q.pop();
				std::cout << t->c << ' ';
				for (node* chi : t->child) {
					q.push(chi);
				}
			}
			std::cout << '\n';
		}
	}
	bool find(const std::string& str) {
		return find(str, root, 0);
	}
};