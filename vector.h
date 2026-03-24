#pragma once
#include <cassert>
template <typename T>
class vector {
private:
	T* mem;
	size_t _size, cap;
	void makenew(size_t s) {
		cap = s;
		T* newmem = new T[s];
		for (int i = 0; i < _size; i++) {
			newmem[i] = mem[i];
		}
		delete[] mem;
		mem = newmem;
	}
public:
	vector() {
		mem = new T[2];
		cap = 2;
		_size = 0;
	}
	vector(size_t insize) {
		mem = new T[insize];
		cap = insize;
		_size = insize;
	}
	vector(size_t insize, T val) {
		mem = new T[insize];
		cap = insize;
		_size = insize;
		for (int i = 0; i < insize; i++) {
			mem[i] = val;
		}
	}
	~vector() {
		delete[] mem;
	}
	void push_back(const T& v) {
		if (_size == cap) {
			makenew(cap * 2);
		}
		mem[_size++] = v;
	}
	T operator[](size_t idx) {
		assert(idx < _size);
		return mem[idx];
	}
	void operator+=(T val) {
		push_back(val);
	}
	void pop_back() {
		assert(_size > 0);
		_size--;
	}
	size_t size() {
		return _size;
	}
	size_t capacity() {
		return cap;
	}
	void reserve(size_t k) {
		if (k <= cap) return;
		makenew(k);
	}
	void resize(size_t s) {
		if (s > cap) {
			makenew(s);
			return;
		}
		_size = s;
	}
	void insert(size_t pos, T v) {
		assert(pos < _size);
		if (_size == cap) {
			makenew(cap * 2);
		}
		for (int i = _size; i > pos; i--) {
			mem[i] = mem[i - 1];
		}
		mem[pos] = v;
		_size++;
	}
	T at(size_t pos) {
		assert(pos < _size);
		
	}
};