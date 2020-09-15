#include<iostream>
#include<mutex>
using namespace std;
template<class T>
class Sharptr
{
public:
	Sharptr(T* ptr)
		:_p(ptr),
		_count(new int(1)),
		_mutex(new mutex)
	{}
	 Sharptr(const Sharptr<T>& ptr)
	{
		 _p = ptr._p;
		 _count = ptr._count;
		 _mutex = ptr._mutex;
		 add();
	}
	 Sharptr<T>& operator=(const Sharptr<T>& ptr)
	 {
		 if (_p != ptr._p)
		 {
			 _p = ptr._p;
			 _count = ptr._count;
			 _mutex = ptr._mutex;

			 add();


		 }
		 return *this;
	 }
	 
	 ~Sharptr()
	 {
		 des();
	 }
	 void add()
	 {
		 _mutex.lock();
		 *_count++;
		 _mutex.unlock();
	 }
	 void des()
	 {
		 bool flog = false;
		 _mutex.lock();
		 if (--(*_count) == 0&&_p)
		 {
			 delete _p;
			 _p = nullptr;
			 delete _count;
			 _count = nullptr;

			 flog = true;
		 }
		 _mutex.unlock();
		 if (flog == true)
			 delete _mutex;

	 }
	T* operator->()
	{
		return _p;
	}
	T& operator*()
	{
		return *_p;
	}
private:
	T* _p=nullptr;
	int *_count;
	mutex _mutex;
};

int main()
{
	return 0;
}