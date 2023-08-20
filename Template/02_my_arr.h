#pragma once
// 02_my_arr.h

#include<iostream>

template <typename T>

class MYArray
{
public:
	MYArray(int loength)
		:loength(loength)
	{
		arr = new T[loength];
	}


	~MYArray()
	{
		delete[] arr;
	}

	void prinf();

private:
	T* arr = nullptr;
	int loength = 0;
};

//1.
//template<typename T>
//inline void MYArray<T>::prinf()
//{
//}




//3.
#include"02_my_arr.inl"