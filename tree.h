#pragma once
#include <iostream>
#include <queue>
#include <vector>
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
	int sot;
	void insert_r(int x, node* cur) {
		if (x < cur->v) {
			if (!cur->l) {
				sot++;
				cur->l = new node();
				cur->l->v = x;
				return;
			}
			insert_r(x, cur->l);
			return;
		}
		if (x > cur->v) {
			if (!cur->r) {
				sot++;
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
			sot--;
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
	void clear_r(node* node) {
		if (node->l) {
			clear_r(node->l);
		}
		if (node->r) {
			clear_r(node->r);
		}
		delete node;
		sot--;
	}
public:
	tree() {
		root = nullptr;
	}
	void insert(int x) {
		if (!root) {
			root = new node();
			sot++;
			root->v = x;
			return;
		}
		insert_r(x, root);
	}
	void bfs() { //show empty
		if (!root) {
			return;
		}
		std::queue<node*> q;
		std::queue<int> work;//-1:do from q, else:output empty space(amount:the value)
		q.push(root);
		work.push(-1);
		while (!q.empty()) {
			int s = work.size();
			for (int i = 0; i < s; i++) {
				int v = work.front();
				work.pop();
				if (v != -1) {
					for (int j = 0; j < v; j++) {
						std::cout << "- ";
					}
					work.push(v * 2);
					continue;
				}
				node* t = q.front();
				q.pop();
				std::cout << t->v << ' ';
				if (t->l) {
					q.push(t->l);
					work.push(-1);
				}
				else {
					work.push(1);
				}
				if (t->r) {
					q.push(t->r);
					work.push(-1);
				}
				else {
					work.push(1);
				}
			}
			std::cout << '\n';
		}
	}
	void remove(int x) {
		if (!root) {
			return;
		}
		remove_r(root, x);
	}
	void clear() {
		if (!root) {
			return;
		}
		clear_r(root);
		root = nullptr;
	}
	int size() {
		return sot;
	}
};
