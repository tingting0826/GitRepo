//
//  vector.cpp
//  Vector
//
//  Created by Tingting Wang on 7/15/15.
//  Copyright (c) 2015 Tingting Wang. All rights reserved.
//

#include "vector.h"

template<class T>
Vector<T>::Vector()
{
	array = new T[kInitialCapacity];

}

template<class T>
Vector<T>::Vector(const Vector<T> &rightVector)
{
	array = rightVector.array;
	count = rightVector.count;
	currentCapacity = rightVector.currentCapacity;
}

template<class T>
Vector<T>::Vector(int initCount, T value)
{
	if (initCount <= kInitialCapacity)
	{
		count = initCount;
	}

	else
	{
		while (initCount > currentCapacity)
		{
			enlargeArray();
		}
		count = initCount;
	}

	for (int i = 0; i < count; ++i)
	{
		array[i] = value;
	}
}

template<class T>
void Vector<T>::push_back(T inputVal)
{
	// check if the array has already reached its capacity
	if (count == currentCapacity)
	{
		enlargeArray();
	}

	append(inputVal);
}

template<class T>
bool Vector<T>::max_size_check()
{
	if (currentCapacity * 2 > kMaxCapacity)
	{
		cout << "Cannot enlarge! Reached max capacity!" << endl;
		return false;
	}

	return true;
}

template<class T>
void Vector<T>::enlargeArray()
{
	if (!max_size_check())
	{
		return;
	}
	// enlarge size
	currentCapacity *= 2;

	// create new array
	T *newArray = new T[currentCapacity];

	// copy data to the new array
	for (int i = 0; i < count; ++i)
	{
		newArray[i] = array[i];
	}

	// delete previous array
	delete array;

	array = newArray;
}

template<class T>
void Vector<T>::append(T inputVal)
{
	array[count] = inputVal;
	count++;
}

template<class T>
void Vector<T>::print()
{
	if (check_Empty())
	{
		return;
	}

	for (int i = 0; i < count; ++i)
	{
		cout << array[i] << " ";
	}

	cout << endl;

}

template<class T>
bool Vector<T>::check_Empty()
{
	if (count == 0)
	{
		cout << "Empty array!";
		return true;
	}

	return false;

}

template<class T>
bool Vector<T>::reduce_capacity_check(int inputNum)
{
	// check if array needs to be reduced in size
	if (inputNum * 4 < currentCapacity && inputNum * 4 > kInitialCapacity)
	{
		return true;
	}

	return false;
}

template<class T>
void Vector<T>::reduce_capacity()
{
	currentCapacity /= 2;
}

template<class T>
void Vector<T>::reduceArray()
{
	// decrease size
	count--;

	if (!reduce_capacity_check(count))
	{
		return;
	}

	reduce_capacity();
	// shrink array

	// create a new array with size currentCapacity
	T *newArray = new T[currentCapacity];

	// copy value from the array to new array until the value before the last element
	for (int i = 0; i < count - 1; ++i)
	{
		newArray[i] = array[i];
	}

	// delete previous array
	delete array;

	// assign newarray to array
	array = newArray;
}

template<class T>
bool Vector<T>::pop_back()
{
	if (check_Empty())
	{
		return false;
	}

	reduceArray();

	return true;
}

template<class T>
int Vector<T>::size() const
{
	return count;
}

template<class T>
int Vector<T>::capacity() const
{
	return currentCapacity;
}

template<class T>
Vector<T>::~Vector()
{

	delete array;
	count = 0;
	currentCapacity = 0;
}

template<class T>
void Vector<T>::assign(int size, T inputValue)
{
	// size smaller or eauals to the currentCapacity.
	if (reduce_capacity_check(size))
	{
		reduce_capacity();
	}

	// size is bigger than current capacity
	if (size > currentCapacity)
	{
		enlargeArray();

	}

	for (int i = 0; i < size; ++i)
	{
		array[i] = inputValue;
	}

	// change count
	count = size;
}

template<class T>
T Vector<T>::at(int index) const
{
	return array[index];
}

template<class T>
T Vector<T>::back() const
{
	return array[count - 1];
}

template<class T>
void Vector<T>::clear()
{
	//delete array
	delete array;

	// leaveing the conatiner size 0
	array = new T[0];
	count = 0;

}

template<class T>
bool Vector<T>::empty()
{
	return (count == 0);
}

//template<class T>
//// erase a single element at index i
//void Vector<T>::erase(int eraseIndex)
//{
//	if (eraseIndex >= count || eraseIndex < 0)
//	{
//		cannot_erase_message();
//		return;
//	}
//	if (reduce_capacity_check(--count))
//	{
//		reduce_capacity();
//	}
//
//	for (int i = eraseIndex; i < count; ++i)
//	{
//		array[i] = array[i + 1];
//	}
//}
//
//template<class T>
//// erase elements in a range
//void Vector<T>::erase(int eraseFront, int eraseBack)
//{
//	if (!erase_range_check(eraseFront, eraseBack))
//	{
//		return;
//	}
//
//	count = count - (eraseBack - eraseFront);
//
//	for (int i = eraseFront; i < count; ++i)
//	{
//		array[i] = array[eraseBack + i];
//	}
//
//	if (reduce_capacity_check(count))
//	{
//		reduce_capacity();
//	}
//}

template<class T>
void Vector<T>::cannot_erase_message()
{
	cout << "Invalid! Cannot erase!" << endl;

}

template<class T>
bool Vector<T>::erase_range_check(int eraseFront, int eraseBack)
{
	if (eraseFront >= eraseBack || eraseFront >= count || eraseBack >= count || eraseFront < 0 || eraseBack < 0)
	{
		cannot_erase_message();
		return false;
	}

	return true;
}

template<class T>
T Vector<T>::front() const
{
	return array[0];
}

template<class T>
// insert before index i
void Vector<T>::insert(int position, T value)
{

	count++;

	if (count == currentCapacity)
	{
		if (!max_size_check())
		{
			return;
		}
		enlargeArray();
	}

	for (int i = count - 1; i > position; --i)
	{
		array[i] = array[i - 1];
	}

	array[position] = value;
}

template<class T>
int Vector<T>::max_size() const
{
	return kMaxCapacity;
}

template<class T>
void Vector<T>::operator=(const Vector &rightVector)
{
	currentCapacity = rightVector.currentCapacity;
	count = rightVector.count;

	/*if (rightVector.currentCapacity >= currentCapacity)
	{
	currentCapacity = rightVector.currentCapacity;
	}

	if (rightVector.currentCapacity < currentCapacity)
	{
	if (reduce_capacity_check(rightVector.count))
	{
	reduce_capacity();
	}
	}*/

	for (int i = 0; i < count; ++i)
	{
		array[i] = rightVector.array[i];
	}
}

template<class T>
T Vector<T>::operator[](int index) const
{
	return array[index];
}

template<class T>
void Vector<T>::reserve(int reserveNum)
{
	if (reserveNum > kMaxCapacity)
	{
		cout << "Cannot reserve space, already reached max capacity!" << endl;
	}

	if (reserveNum > currentCapacity)
	{
		currentCapacity = reserveNum;
	}
}

template<class T>
void Vector<T>::resize(int resizeNum)
{
	if (resizeNum < 0)
	{
		cout << "Invalid resize number!" << endl;
	}

	if (resizeNum > count)
	{
		if (!max_size_check())
		{
			return;
		}

		if (resizeNum > currentCapacity)
		{
			currentCapacity = resizeNum;
		}
	}

	else if (resizeNum < count)
	{
		currentCapacity = resizeNum;
		count = resizeNum;


		T *newArray = new T;
		for (int i = 0; i < resizeNum; ++i)
		{
			newArray[i] = array[i];
		}
		array = newArray;
		delete newArray;
	}
}

template<class T>
void Vector<T>::swap(Vector& someVector)
{
	Vector currentVector = someVector;
	someVector = *(this);
	*(this) = currentVector;

	/*Vector currentVector = someVector;
	someVector.array = array;
	someVector.currentCapacity = currentCapacity;
	someVector.count = count;

	array = currentVector.array;
	currentCapacity = currentVector.currentCapacity;
	count = currentVector.count;

	delete currentVector.array;*/
}

template<class T>
void Vector<T>::shrink_to_fit()
{
	currentCapacity = count;
}

template class Vector<char>;
template class Vector<int>;
