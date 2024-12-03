﻿#include <iostream>
#include <list>
#include <vector>
#include <deque>

// STL 과 Adapter
// 1. C++ 표준 라이브러리인 STL 에는 이미 list가 있습니다.
// 2. 그런데, stack 이 필요합니다. (stack 도 이미 있지만, 없다고 가정해 봅시다.)

// list 의 함수 이름만 변경해서 stack 처럼 보이게 하자.
template<typename T> 
class stack : public std::list<T>
{
public:
	void push(const T& e)	{ std::list<T>::push_back(e); }
	void pop()				{ std::list<T>::pop_back(); }
	T& top()                { return std::list<T>::back(); }
};


int main()
{
	stack<int> s;
	s.push(10);
}
