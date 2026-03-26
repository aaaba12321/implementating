#pragma once
#include <iostream>
#include <cassert>
struct node {
	int v;
	node* r;
	node() {
		v = 0;
		r = nullptr;
	}
	node(int _v) {
		v = _v;
		r = nullptr;
	}
};
class list {
	node* root;
	int size;
	node* back;
	node* getnode(size_t pos) {
		assert(pos < size);
		node* ret = root;
		for (int i = 0; i < pos; i++) {
			ret = ret->r;
		}
		return ret;
	}
public:
	list() {
		root = nullptr;
		back = nullptr;
		size = 0;
	}
	~list() {
		while (root) {
			node* temp = root;
			if (!root->r) {
				break;
			}
			root = root->r;
			delete temp;
		}
	}
	void push_back(int v) {
		node* n = new node(v);
		size++;
		if (back) {
			back->r = n;
		}
		else {
			root = n;
		}
		back = n;
	}
	void pop_back() {
		assert(size);
		if (size == 1) {
			node* t = root;
			root = nullptr;
			back = nullptr;
			size = 0;
			delete t;
			return;
		}
		node* t = back;
		back = getnode(size - 2);
		size--;
		delete t;
	}
	void traverse() {
		node* c = root;
		while (c) {
			std::cout << c->v << ' ';
			if (!c->r) {
				break;
			}
			c = c->r;
		}
		std::cout << '\n';
	}
	void insert(int pos, int v) {
		if (pos >= size) {
			push_back(v);
			return;
		}
		if (!pos) {
			node* x = new node(v);
			x->r = root;
			root = x;
			size++;
			return;
		}
		node* f = getnode(pos - 1);
		node* s = f->r;
		node* t = new node(v);
		f->r = t;
		t->r = s;
		size++;
	}
	void erase(int pos) {
		if (pos >= size || !size) {
			return;
		}
		if (!pos) {
			node* r = root;
			if (size == 1) {
				root = nullptr;
				back = nullptr;
			}
			else {
				if (root->r) {
					root = root->r;
				}
			}
			delete r;
			return;
		}
		node* f = getnode(pos - 1);
		node* s = f->r;
		if (s->r) {
			node* t = s->r;
			f->r = t;
		}
		else {
			back = f;
			f->r = nullptr;
		}
		delete s;
	}
	int getback() {
		assert(size);
		return back->v;
	}
	int getfront() {
		assert(size);
		return root->v;
	}
	void pop_front() {
		assert(size);
		if (size == 1) {
			node* t = root;
			root = nullptr;
			back = nullptr;
			size = 0;
			delete t;
			return;
		}
		node* t = root;
		root = root->r;
		delete t;
	}
};