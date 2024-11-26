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
