#pragma once
#include "list.h"
class queue {
	int siz;
	list l;
public:
	queue() {
		siz = 0;
		l = list();
	}
	~queue() {
		l.~list();
	}
	void push(int v) {
		siz++;
		l.push_back(v);
	}
	void pop() {
		assert(siz);
		l.pop_front();
		siz--;
	}
	int front() {
		assert(siz);
		return l.getfront();
	}
	int back() {
		assert(siz);
		return l.getback();
	}
	int size() {
		return siz;
	}
};