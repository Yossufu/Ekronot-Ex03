#include "Vector.h"
#include <iostream>

using std::cout;
using std::endl;

Vector::Vector(int n)
{
	n = n < 2 ? 2 : n;//if n is lesser then 2 it will be set to 2
	this->_elements = new int[n];
	this->_capacity = n;
	this->_size = 0;
	this->_resizeFactor = n;
}

Vector::~Vector()
{
	delete[] this->_elements;
}

int Vector::size() const
{
	return this->_size;
}

int Vector::capacity() const
{
	return this->_capacity;
}

int Vector::resizeFactor() const
{
	return this->_resizeFactor;
}

bool Vector::empty() const
{
	return this->_size == 0;
}

void Vector::push_back(const int& val)
{
	if (this->_size == this->_capacity)
	{
		int* tempArr = new int[this->_capacity + this->_resizeFactor];
		for (int i = 0; i < this->_size; i++)
		{
			tempArr[i] = this->_elements[i];
		}
		delete[] this->_elements;
		this->_elements = tempArr;
		this->_capacity += this->_resizeFactor;
	}
	this->_elements[this->_size] = val;
	this->_size++;
}

int Vector::pop_back()
{
	if (this->_size == 0)
	{
		std::cout << "error: pop from empty vector\n" << std::endl;
		return -9999;
	}
	this->_size--;
	return this->_elements[this->_size];
}

void Vector::reserve(const int n)
{
	if (this->_capacity >= n)
	{
		return;
	}
	while (this->_capacity < n)
	{
		this->_capacity += this->_resizeFactor;
	}
	int* tempArr = new int[this->_capacity];
	for (int i = 0; i < this->_size; i++)
	{
		tempArr[i] = this->_elements[i];
	}
	delete[] this->_elements;
	this->_elements = tempArr;
}

void Vector::resize(const int n)
{
	if (n > this->_capacity)
	{
		reserve(n);
	}
	for (int i = this->_size; i < n; i++)
	{
		this->_elements[i] = 0;
	}
	this->_size = n;
}

void Vector::assign(const int val)
{
	for (int i = 0; i < this->_size; i++)
	{
		this->_elements[i] = val;
	}
}

void Vector::resize(const int n, const int& val)
{
	if (n > this->_capacity)
	{
		reserve(n);
	}
	for (int i = this->_size; i < n; i++)
	{
		this->_elements[i] = val;
	}
	this->_size = n;
}

Vector::Vector(const Vector& other) : _capacity(other._capacity), _size(other._size), _resizeFactor(other._resizeFactor)
{
	this->_elements = new int[this->_capacity];
	for (int i = 0; i < this->_size; i++)
	{
		this->_elements[i] = other._elements[i];
	}
}

Vector& Vector::operator=(const Vector& other)
{
	if (this == &other)
		return *this;
	delete[] this->_elements;
	this->_capacity = other._capacity;
	this->_size = other._size;
	this->_resizeFactor = other._resizeFactor;
	this->_elements = new int[this->_capacity];
	for (int i = 0; i < this->_size; i++)
	{
		this->_elements[i] = other._elements[i];
	}
	return *this;
}

int& Vector::operator[](int n) const
{
	if (n < 0 || n >= this->_size)
	{
		std::cout << "error: index out of bounds\n" << std::endl;
		return this->_elements[0];
	}
	return this->_elements[n];
}
