#pragma once
#include <iostream>
#include <queue>
struct node {
	int v;
	node* l;
	node* r;
	node() {
		v = 2147483647;
		l = nullptr;
		r = nullptr;
	}
};
class tree {
private:
	node* root;
	void insert_r(int x, node* cur) {
		if (x < cur->v) {
			if (!cur->l) {
				cur->l = new node();
				cur->l->v = x;
				return;
			}
			insert_r(x, cur->l);
			return;
		}
		if (x > cur->v) {
			if (!cur->r) {
				cur->r = new node();
				cur->r->v = x;
				return;
			}
			insert_r(x, cur->r);
			return;
		}
	}
	node* minnode(node* cur) {
		if (!cur) {
			return nullptr;
		}
		while (cur->l) {
			cur = cur->l;
		}
		return cur;
	}
	node* remove_r(node* cur, int r) {
		if (!cur) {
			return nullptr;
		}
		if (r < cur->v) {
			cur->l = remove_r(cur->l, r);
		}
		else if (r > cur->v) {
			cur->r = remove_r(cur->r, r);
		}
		else {
			if (!cur->l) {
				node* temp = cur->r;
				delete cur;
				return temp;
			}
			else if (!cur->r) {
				node* temp = cur->l;
				delete cur;
				return temp;
			}
			node* temp = minnode(cur->r);
			cur->v = temp->v;
			cur->r = remove_r(cur->r, temp->v);
		}
		return cur;
	}
public:
	tree() {
		root = nullptr;
	}
	void insert(int x) {
		if (!root) {
			root = new node();
			root->v = x;
			return;
		}
		insert_r(x, root);
	}
	void bfs() {
		if (!root) {
			return;
		}
		std::queue<node*> q;
		q.push(root);
		while (!q.empty()) {
			int size = q.size();
			for (int i = 0; i < size; i++) {
				node* t = q.front();
				q.pop();
				std::cout << t->v << ' ';
				if (t->l) {
					q.push(t->l);
				}
				if (t->r) {
					q.push(t->r);
				}
			}
			std::cout << '\n';
		}
	}
	void remove(int x) {
		remove_r(root, x);
	}
};