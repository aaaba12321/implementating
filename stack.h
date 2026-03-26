#pragma once
#include "list.h"
class stack {
	int siz;
	list l;
public:
	stack() {
		siz = 0;
		l = list();
	}
	~stack() {
		l.~list();
	}
	void push(int v) {
		siz++;
		l.push_back(v);
	}
	void pop() {
		assert(siz);
		l.pop_back();
		siz--;
	}
	int top() {
		assert(siz);
		return l.getback();
	}
	int size() {
		return siz;
	}
};