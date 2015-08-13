//
//  vector.h
//  Vector
//
//  Created by Tingting Wang on 7/15/15.
//  Copyright (c) 2015 Tingting Wang. All rights reserved.
//

#ifndef __Vector__vector__
#define __Vector__vector__

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

template <class T>

class Vector
{
private:
	static const int kInitialCapacity = 11;
	static const int kMaxCapacity = 1073741823;
	int count = 0;
	T *array = NULL;
	int currentCapacity = kInitialCapacity;
	void enlargeArray();
	void reduceArray();
	void append(T inputVal);
	bool reduce_capacity_check(int inputNum);
	void reduce_capacity();
	bool erase_range_check(int eraseFront, int eraseBack);
	void cannot_erase_message();
	bool check_Empty();
	bool max_size_check();


public:
	Vector();
	Vector(const Vector<T>& rightVector);
	Vector(int count, T value);
	~Vector();
	void push_back(T inputVal);
	bool pop_back();
	int getCount() const { return count; }
	int size() const;
	int capacity() const;
	void assign(int size, T inputValue);
	T at(int index) const;
	T back() const;
	void clear();
	bool empty();
	//void erase(int eraseIndex);
	//void erase(int eraseFrint, int eraseBack);
	T front() const;
	void insert(int position, T value);
	int max_size() const;
	void print();
	void operator=(const Vector &rightVector);
	T operator[](int index) const;
	void reserve(int reserveNum);
	void resize(int resizeNum);
	void swap(Vector& someVector);
	void shrink_to_fit();
};

#endif