#include<iostream>
#include<mutex>
#include<thread>
using namespace std;
template<class T>
class shared_ptr
{
public:
	shared_ptr(T* ptr)
		:_ptr(ptr),
		_count(new int(1)),
		_mtx(new mutex)
	{
		//(*count)++;
	}
	shared_ptr(const shared_ptr<T>& sp)
		:_ptr(sp._ptr)
		, _count(sp._count)
		, _mtx(sp._mtx)
	{

		
		add_count();

	}
	~shared_ptr()
	{
		releas();
	}
	T& operator*()
	{
		return *_ptr;
	}

	void add_count()
	{
		_mtx->lock();
		(*_count)++;
		_mtx->unlock();
	}
	void releas()
	{
		bool flog = false;
		_mtx->lock();
		if (--(*_count) == 0&&_ptr)
		{
			cout << "delete:" << _ptr << endl;
			delete _ptr;
			_ptr = nullptr;
			delete _count;
			_count = nullptr;
			flog = true;
		}
		_mtx->unlock();
		if (flog == true)
		{
			delete _mtx;
		}
	}
	shared_ptr<T>& operator=(const shared_ptr<T>& sp)
	{
		if (sp._ptr != _ptr){
			//shared_ptr<T> _sp;
			releas();
	}
		_ptr = sp._ptr;
		_count = sp._count;
		_mtx = sp._mtx;
		add_count();

		return *this;
	}

	T* operator->()
	{
		return _ptr;
	}
	int user_count()
	{
		return *_count;
	}
private:
	T* _ptr;
	int *_count;
	mutex* _mtx;
};
int main()
{
	shared_ptr<int> sp1(new int);
	int n = 10000;
	std::thread t1([&](){
		for (int i = 0; i < n; i++){
			shared_ptr<int> sp2(sp1);

		}
	});

	std::thread t2([&](){
		for (int i = 0; i < n; i++){
			shared_ptr<int> sp3(sp1);

		}
	});
	t1.join();
	t2.join();
	cout << sp1.user_count() << endl;
	system("pause");

	return 0;

}
