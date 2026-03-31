#pragma once
#include <vector>
#include <iostream>
struct node {
	int key;
	int hash;
	int bukit;
	node* next;
	node() {
		key = 0;
		hash = 0;
		bukit = 0;
		next = nullptr;
	}
};
class uset {
	std::vector<node*> v;
	const int s = 31, m = 107;
	int _size;
	bool find(int val) {
		int hash = (val * m) % s;
		node* c = v[hash];
		while (c) {
			if (c->key == val) {
				return 1;
			}
			c = c->next;
		}
		return 0;
	}
	void push_back(int _v) {
		node* n = new node();
		n->key = _v;
		n->hash = (_v * m);
		n->bukit = n->hash % s;
		n->next = nullptr;
		node* c = v[n->bukit];
		if (!c) {
			v[n->bukit] = n;
			return;
		}
		while (c->next) {
			c = c->next;
		}
		c->next = n;
	}
public:
	uset() {
		v = std::vector<node*>(s);
		for (int i = 0; i < s; i++) {
			v[i] = nullptr;
		}
		_size = 0;
	}
	~uset() {
	}
	void insert(int val) {
		if (find(val)) {
			return;
		}
		_size++;
		push_back(val);
	}
	bool count(int val) {
		return find(val);
	}
	void erase(int val) {
		int h = (val * m) % s;
		int hash = (val * m) % s;
		node* c = v[hash];
		if (!c) return;
		if (c->key == val) {
			v[hash] = c->next;
			delete c;
			return;
 		}
		while (c) {
			if (!c->next) {
				c = nullptr;
				break;
			}
			if (c->next->key == val) {
				break;
			}
			c = c->next;
		}
		if (c == nullptr) {
			return;
		}
		_size--;
		node* s = c->next;
		node* d = s->next;
		c->next = d;
		delete s;
	}
	int size() {
		return _size;
	}
	bool empty() {
		return !_size;
	}
	void traverse() {
		for (int i = 0; i < s; i++) {
			node* c = v[i];
			while (c) {
				std::cout << c->key << ' ';
				c = c->next;
			}
			std::cout << '\n';
		}
	}
};