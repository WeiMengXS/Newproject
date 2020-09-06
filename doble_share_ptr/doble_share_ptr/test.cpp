#include<iostream>
#include<mutex>
using namespace std;
template<class T>
class share_ptr{
public:
	share_ptr(T* ptr)
		:p(ptr),
		: count(new int(1)),
		_mutex(new mutex)
	{

	}
	share_ptr(const share_ptr<T>& ptr)
	{
		p = ptr->p;
		count = ptr->count;
		_mutex = ptr->_mutex;
		add_count();
	}
	share_ptr<T>& operator=(const share_ptr<T>& ptr)
	{
		if (this != ptr)
		{
			relese();
			p = ptr->p;
			count = ptr->count;
			_mutex = ptr->_mutex;
			add_count();
		}
		
		return *this;
	}
	~share_ptr()
	{
		relese();
	}
	void add_count()
	{
		_mutex.lock();
		++(*count);
		_mutex.unlock();
	}
	void relese()
	{
		bool flog = false;
		_mutex.lock();
		if (--(*count) == 0 && p)
		{
			delete p;
			p = nullptr;
			delete count;
			count = nullptr;
			_mutex.lock();

			flog = true;
		}
		if (flog == true)
		{
			delete mutex;
		}
		T* operator->()
		{
			return _p;
		}
		T& operator*()
		{
			return *p;
		}
	}
private:
	T *p;
	int *count;
	mutex _mutex;
};
int main()
{

}