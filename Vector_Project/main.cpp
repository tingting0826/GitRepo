//
//  main.cpp
//  Vector
//
//  Created by Tingting Wang on 7/15/15.
//  Copyright (c) 2015 Tingting Wang. All rights reserved.
//

#include <iostream>
#include <vector>
#include "vector.h"
#include <assert.h>
#include <cstdlib>
#include <ctime>

using namespace std;


// Test helper functions
bool areEqual(const Vector<char>& ttVector, const vector<char>& realVector);
void pushBackBoth(Vector<char>& ttVector, vector<char>& realVector, char charToPush);
void popBackBoth(Vector<char>& ttVector, vector<char>& realVector);
int biggerInitCapacity(Vector<char>& ttVector, vector<char>& realVector);
void pushBackBothWithRandValues(Vector<char>& ttVector, vector<char>& realVector, int pushTimes);
int generateRandIndexWithinRange(int count);
void popBackAll(Vector<char>& someVector);
void popBackAll(vector<char>& someVector);


void getGit();
// Test functions
void pushBackTest();
void popBackTest();
void defaultConstructureTest();
void constructWithArgumentTest();
void sizeTest();
void atTest();
void backTest();
void clearTest();
void emptyTest();
void frontTest();
void operatorEqualTest();
void operatorBraketTest();
void reserveTest();
void resizeTest();
//void swapTest();
void shrinkToFitTest();

int main()
{

	pushBackTest();
	popBackTest();
	defaultConstructureTest();
	constructWithArgumentTest();
	sizeTest();
	atTest();
	backTest();
	emptyTest();
	clearTest();
	frontTest();
	operatorEqualTest();
	operatorBraketTest();
	reserveTest();
	resizeTest();
	//swapTest();
	shrinkToFitTest();


	getchar();

	return 0;
}

bool areEqual(const Vector<char>& ttVector, const vector<char>& realVector)
{
	if (ttVector.size() != realVector.size())
	{
		cout << "tingting's vector size does not match the actual vector's size." << endl;
		return false;
	}

	int size = realVector.size();
	for (int i = 0; i < size; ++i)
	{
		if (ttVector[i] != realVector[i])
		{
			cout << "tingting's vector element at index " << i << " does not match the actual vector's element."
				<< endl;

			return false;
		}
	}

	return true;
}

void pushBackTest()
{
	cout << "Executing Test: pushBackTest()..." << endl;

	Vector<char> ttVector;
	vector<char> realVector;

	pushBackBoth(ttVector, realVector, 'a');

	assert(areEqual(ttVector, realVector));

	cout << "Test successful!" << endl;
}

void pushBackBoth(Vector<char> &ttVector, vector<char>& realvector, char chartopush)
{
	ttVector.push_back(chartopush);
	realvector.push_back(chartopush);
}

void popBackBoth(Vector<char> &ttVector, vector<char>& realVector)
{
	ttVector.pop_back();
	realVector.pop_back();
}

void popBackTest()
{
	cout << "Executing Test: PopBackTest()..." << endl;

	Vector<char> ttVector;
	vector<char> realVector;

	pushBackBoth(ttVector, realVector, 'T');
	popBackBoth(ttVector, realVector);

	assert(areEqual(ttVector, realVector));

	cout << "Test successful!" << endl;
}

void defaultConstructureTest()
{
	cout << "Executing Test: defaultConstructureTest()..." << endl;


	Vector<char> ttVector;
	vector<char> realVector;

	assert(areEqual(ttVector, realVector));

	cout << "Test successful!" << endl;

}

void constructWithArgumentTest()
{
	cout << "Executing Test: constructWithArgumentTest()..." << endl;


	Vector<char> ttVector(40, 8);
	vector<char> realVector(40, 8);
	assert(areEqual(ttVector, realVector));

	cout << "Test successful!" << endl;

}

void sizeTest()
{
	cout << "Executing Test: sizeTest()..." << endl;

	Vector<char> ttVector;
	vector<char> realVector;

	pushBackBothWithRandValues(ttVector, realVector, 20);

	if (ttVector.size() == realVector.size())
	{
		cout << "Test successful!" << endl;
	}
}

void pushBackBothWithRandValues(Vector<char>& ttVector, vector<char>& realVector, int pushTimes)
{
	srand(time(NULL));

	for (int i = 0; i < pushTimes; ++i)
	{
		int randNum = rand() % pushTimes;
		pushBackBoth(ttVector, realVector, randNum);
	}
}

void atTest()
{
	cout << "Excuting test: atTest()..." << endl;

	Vector<char> ttVector;
	vector<char> realVector;

	pushBackBothWithRandValues(ttVector, realVector, ttVector.capacity());

	int randIndex = generateRandIndexWithinRange(ttVector.capacity());

	if (ttVector.at(randIndex) != realVector.at(randIndex))
	{
		cout << "Tingting's vector at index " << randIndex << "does not match the real vector!" << endl;
		return;
	}

	cout << "Test successful!" << endl;
}

int generateRandIndexWithinRange(int count)
{
	srand(time(NULL));

	return rand() % count;
}

void backTest()
{
	cout << "Excuting test: backTest()..." << endl;

	Vector<char> ttVector;
	vector<char> realVector;

	pushBackBothWithRandValues(ttVector, realVector, ttVector.capacity());

	int randIndex = generateRandIndexWithinRange(ttVector.capacity());

	assert(areEqual(ttVector, realVector));

	if (ttVector[ttVector.size() - 1] != realVector[realVector.size() - 1])
	{
		cout << "Tingting's vector front value " << randIndex << "does not match the real vector!" << endl;
		return;
	}

	cout << "Test successful!" << endl;
}

void clearTest()
{
	cout << "Excuting test: clearTest()..." << endl;

	Vector<char> ttVector;
	vector<char> realVector;

	pushBackBothWithRandValues(ttVector, realVector, ttVector.capacity());

	ttVector.clear();
	realVector.clear();

	if (ttVector.empty() != true || realVector.empty() != true)
	{
		cout << "Tingting's clear functionality does not match the real vector!" << endl;
		return;
	}

	cout << "Test successful!" << endl;


}

void emptyTest()
{
	cout << "Excuting test: emptyTest()..." << endl;

	Vector<char> ttVector;
	vector<char> realVector;

	pushBackBothWithRandValues(ttVector, realVector, ttVector.capacity());

	popBackAll(ttVector);
	popBackAll(realVector);


	if (ttVector.empty() != true || realVector.empty() != true || ttVector.size() != 0 || realVector.size() != 0)
	{
		cout << "Tingting's vector empty functionality does not match the real vector!" << endl;
		return;
	}

	cout << "Test successful!" << endl;
}

void popBackAll(Vector<char> &someVector)
{
	int popbackTimes = someVector.size();

	for (int i = 0; i < popbackTimes; ++i)
	{
		someVector.pop_back();
	}
}

void popBackAll(vector<char> &someVector)
{
	int popbackTimes = someVector.size();

	for (int i = 0; i < popbackTimes; ++i)
	{
		someVector.pop_back();
	}
}

void frontTest()
{
	cout << "Excuting test: frontTest()..." << endl;

	Vector<char> ttVector;
	vector<char> realVector;

	pushBackBothWithRandValues(ttVector, realVector, ttVector.capacity());

	int randIndex = generateRandIndexWithinRange(ttVector.capacity());

	assert(areEqual(ttVector, realVector));

	if (ttVector.front() != ttVector.at(0) || realVector.front() != realVector.at(0))
	{
		cout << "Tingting's vector front value " << randIndex << "does not match the real vector!" << endl;
		return;
	}

	cout << "Test successful!" << endl;
}

void operatorEqualTest()
{
	cout << "Excuting test: operatorEqualTest()..." << endl;

	Vector<char> ttVector;
	vector<char> realVector;
	Vector<char> testVectorforTt;
	vector<char> testVectorforReal;

	pushBackBothWithRandValues(testVectorforTt, testVectorforReal, testVectorforTt.capacity());

	ttVector = testVectorforTt;
	realVector = testVectorforReal;

	assert(areEqual(ttVector, realVector));

	cout << "Test successful!" << endl;

}

void operatorBraketTest()
{
	cout << "Excuting test: operatorBraketTest()..." << endl;

	Vector<char> ttVector;
	vector<char> realVector;

	pushBackBothWithRandValues(ttVector, realVector, ttVector.capacity());

	for (int i = 0; i < ttVector.size(); ++i)
	{
		if (ttVector[i] != realVector[i])
		{
			cout << "Tingting's vector's functionality does not match the real vector!" << endl;
			return;
		}
	}

	cout << "Test successful!" << endl;
}

void reserveTest()
{
	cout << "Excuting test: reserveTest()..." << endl;

	Vector<char> ttVector;
	vector<char> realVector;
	int biggerCapacity = ttVector.capacity() > realVector.capacity() ? ttVector.capacity() : realVector.capacity();

	ttVector.reserve(biggerCapacity + 1);
	realVector.reserve(biggerCapacity + 1);

	if (ttVector.capacity() != realVector.capacity())
	{
		cout << "Tingting's vector's fuctionality does not match the real vector!" << endl;
		return;
	}

	cout << "Test successful!" << endl;
}

void resizeTest()
{
	cout << "Excuting test: resizeTest()..." << endl;

	Vector<char> ttVector;
	vector<char> realVector;
	int biggerCapacity = ttVector.capacity() > realVector.capacity() ? ttVector.capacity() : realVector.capacity();

	ttVector.resize(biggerCapacity + 1);
	realVector.resize(biggerCapacity + 1);

	if (ttVector.capacity() != realVector.capacity())
	{
		cout << "Tingting's vector's fuctionality does not match the real vector!" << endl;
		return;
	}

	ttVector.resize(biggerCapacity / 2);
	realVector.resize(biggerCapacity / 2);

	if (ttVector.capacity() != realVector.capacity())
	{
		cout << "Tingting's vector's fuctionality does not match the real vector!" << endl;
		return;
	}

	cout << "Test successful!" << endl;
}

void shrinkToFitTest()
{
	cout << "Excuting test: shrinkToFitTest()..." << endl;

	Vector<char> ttVector;
	vector<char> realVector;

	pushBackBoth(ttVector, realVector, 'a');
	ttVector.shrink_to_fit();
	realVector.shrink_to_fit();

	if (ttVector.size() != 1 || realVector.size() != 1)
	{
		cout << "Tingting's vector's functionality does not match real vector's functionality!" << endl;
		return;
	}

	cout << "Test successful!" << endl;


}
//void swapTest()
//{
//	cout << "Excuting test: swapTest()..." << endl;
//
//	Vector<char> ttVector;
//	vector<char> realVector;
//	Vector<char> testVectorforTt;
//	vector<char> testVectorforReal;
//
//	pushBackBothWithRandValues(testVectorforTt, testVectorforReal, testVectorforTt.capacity() + 1);
//	pushBackBothWithRandValues(testVectorforTt, testVectorforReal, testVectorforTt.capacity() + 1);
//	
//	//ttVector.swap(testVectorforTt);
//	/*realVector.swap(testVectorforReal);
//	
//	assert(areEqual(ttVector, realVector));*/
//	
//	cout << "Test successful!" << endl;
//
//}