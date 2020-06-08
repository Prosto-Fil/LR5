#pragma once

#include <iostream>

using namespace std;

template <typename T>
class vector
{
private:
	T* data;
	int size;
	int capacity;
public:
	vector();
	vector(T* str, int len);
	vector(vector& str);
	vector& operator=(vector& str);
	T at(int i);
	T front();
	T back();
	bool empty();
	void reserve(int res);
	void clear();
	void insert(int pos, T val);
	void erase(int pos);
	void erase(int pos1, int pos2);
	void push_back(T push);
	void pop_back();
	void resize(int newsize);
	void swap(vector& str);
	T& operator[](int i);
	void print();
	~vector();
	int get_size();
	int get_capacity();
	T* get_data();
};