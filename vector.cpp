#include "vector.h"
#include <exception>

template <typename T>
vector<T>::vector() : data(nullptr), size(0), capacity(0) {}

template <typename T>
vector<T>::vector(T* str, int len)
{
	this->size = len;
	this->capacity = static_cast<int>(len * 1.5);
	this->data = new T[this->capacity];
	for (int i = 0; i < len; i++) {
		this->data[i] = str[i];
	}
}

template <typename T>
vector<T>::vector(vector& str)
{
	this->size = str.size;
	this->capacity = str.capacity;
	this->data = new T[this->size];
	for (int i = 0; i < this->size; i++) {
		this->data[i] = str.data[i];
	}
}

template <typename T>
vector<T>& vector<T>::operator=(vector& str)
{
	delete[] this->data;
	this->size = str.size;
	this->capacity = str.capacity;
	this->data = new T[this->size];
	for (int i = 0; i < this->size; i++) {
		this->data[i] = str.data[i];
	}
	return *this;
}

template <typename T>
T vector<T>::at(int i)
{
	if (i >= this->size) {
		throw out_of_range("wrong index");
	}
	return this->data[i];
}

template <typename T>
T vector<T>::front()
{
	return this->data[0];
}

template <typename T>
T vector<T>::back()
{
	return this->data[this->size - 1];
}

template <typename T>
bool vector<T>::empty()
{
	if (this->size == 0)
		return false;
	else
		return true;
}

template <typename T>
void vector<T>::reserve(int res)
{

	if (res > std::numeric_limits<T>::max()) 
	{
		throw length_error("length error");
	}

	if (res > this->capacity)
	{
		this->capacity = res;
		T* buf = new T[res];
		for (int i = 0; i < this->size; i++)
			buf[i] = this->data[i];

		if (this->data != nullptr)
			delete[] this->data;

		this->data = buf;
	}
}

template <typename T>
void vector<T>::clear()
{
	delete[] this->data;
	this->size = 0;
	this->capacity = 0;
}

template <typename T>
void vector<T>::insert(int pos, T val)
{
	if ((pos >= this->size) || (pos < 0)) 
	{
		throw out_of_range("wrong index");
	}
	int newsize;
	if ((this->size <= 1) || (this->capacity > this->size)) 
	{
		newsize = this->size + 1;
	}
	else if (this->capacity == this->size) 
	{
		newsize = static_cast<int>(this->capacity * 1.5);
	}
	else {
		newsize = this->size + 1;
	}
	T* newData = new T[newsize];
	for (int i = 0; i < pos; ++i) {
		newData[i] = this->data[i];
	}
	newData[pos] = val;
	for (int i = pos + 1; i < this->size + 1; i++) 
	{
		newData[i] = this->data[i - 1];
	}
	delete[] this->data;
	this->data = newData;
	this->size += 1;
	this->capacity = newsize;
}

template <typename T>
void vector<T>::erase(int pos)
{
	if ((pos >= this->size) || (pos < 0)) 
	{
		throw out_of_range("wrong index");
	}

	for (int i = 0; i < this->size; i++) 
	{
		if (i >= pos) {
			this->data[i] = this->data[i + 1];
			if (i == this->size - 1) break;
		}
	}
	this->size--;
}

template <typename T>
void vector<T>::erase(int pos1, int pos2)
{
	if ((pos1 >= this->size) || (pos1 < 0)) 
	{
		throw out_of_range("wrong index");
	}
	if ((pos2 >= this->size) || (pos2 < 0)) 
	{
		throw out_of_range("wrong index");
	}
	if (pos1 >= pos2) 
	{
		throw out_of_range("wrong index");
	}
	
	for (int i = pos1; i < this->size; i++)
	{
		if (i < this->size - (pos2 - pos1 + 1))
			this->data[i] = this->data[i + (pos2 - pos1 + 1)];
	}
	this->size = this->size - (pos2 - pos1 + 1);
}

template <typename T>
void vector<T>::pop_back()
{
	erase(this->size - 1);
}

template <typename T>
void vector<T>::resize(int newsize)
{
	if (newsize < 0) 
	{
		throw out_of_range("wrong index");
	}

	if (this->size != newsize)
	{
		this->size = newsize;
		this->capacity = static_cast<int>(newsize * 1.5);

		if (this->capacity > 0)
		{
       	 		T* newdat = new T[this->capacity];
    			for (int i = 0; i < newsize; i++)
		    		newdat[i] = this->data[i];
		    
    			delete[] this->data;
    			this->data = newdat;
		}
		else
		{
	    		delete[] this->data;
			this->data = nullptr;
		}
	}
}

template <typename T>
void vector<T>::swap(vector<T>& str)
{
	vector<T> buf;
	buf = str;
	str = *this;
	*this = buf;
}

template <typename T>
T& vector<T>::operator[](int i)
{
	if (i >= this->size) {
		throw out_of_range("wrong index");
	}
	return this->data[i];
}

template <typename T>
void vector<T>::push_back(T push)
{
	if (this->size > 1 && this->capacity >= this->size + 1)
	{
		this->data[this->size] = push;
		this->size++;
	}
	else
	{
		int capac = 0;
		if (this->capacity == 0) 
			capac = 1;
		else
		{
			if (this->capacity == 1)
				capac = 2;
			else 
				if (this->capacity >= 2)
					capac = static_cast<int>(this->size * 1.5);
		}
		reserve(capac);
	}
}

template <typename T>
void vector<T>::print()
{
	for (int i = 0; i < this->size; i++)
		cout << this->data[i] << " ";
	cout << endl;
}

template <typename T>
vector<T>::~vector()
{
	delete[] this->data;
}

template <typename T>
int vector<T>::get_size()
{
	return this->size;
}

template <typename T>
int vector<T>::get_capacity()
{
	return this->capacity;
}

template <typename T>
T* vector<T>::get_data()
{
	return this->data;
}