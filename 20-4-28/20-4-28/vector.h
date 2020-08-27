#pragma once
#include<iostream>
namespace bit
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		vector() :_start(nullptr), _finish(nullptr), _endofstorage(nullptr)
		{}
		~vector()
		{
			delete[] _start;
			_start = _finish = _endofstorage = nullptr;
		}
		void reverse(size_t n)
		{
			if (n > capacity())
			{	
				size_t oldsize = size();
				T* tmp = new T[n];

				if (_start)
				{
					for (size_t i = 0; i < oldsize; ++i)
					{
						tmp[i] = _start[i];
					}
				}

				_start = tmp;
				_finish = _start + size();
				_endofstorage = _start + n;
			}
			
		}
		void push_back(const T&x)
		{
			insert(end(), x);

		}
		void pop_back();
		iterator insert(iterator pos,const T&x)
		{
			if (_finish == _endofstorage)
			{
				int newcapacity = capacity() == 0 ? 2 : capacity() * 2;
				reverse(newcapacity);
				pos=_start+size();
			}
			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = x;
			++_finish;
			return pos;
		}
		iterator erase();
		void show()
		{
			for (auto x :this)
			{
				cout << x << endl;
			}
		}
		iterator end()
		{
			return size();
		}
		size_t size()
		{
			return _finish - _start;
		}
		size_t capacity()
		{
			return _endofstorage - _start;
		}
		//iterator& operator[]();
	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;


	};
	void test_vector()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(1);
		v.push_back(1);
		v.push_back(1);
		v.show();
	}
}