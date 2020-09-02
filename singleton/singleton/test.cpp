#include <iostream>
#include<vector>
#include<thread>
#include<cstdlib>
//#include<unistd.h>
#include<mutex>
using namespace std;
namespace bit{
	class Singleton
	{
		//¶öººÄ£Ê½
	public:
		static Singleton* Getsingleton()
		{
			if (p == nullptr)
			{
				_mutex.lock();
				if (p == nullptr)
				{
					//sleep(1);
					p = new Singleton;
				}
				_mutex.unlock();
			}


			return p;
		}
		class GC
		{
		public:
			~GC()
			{
				if (Singleton::p != nullptr)
					delete Singleton::p;
			}
		};
		GC ga;
	private:
		Singleton(){}
		Singleton(const Singleton&) = delete;
		Singleton& operator=(const Singleton&) = delete;
		static std::mutex _mutex;
		static Singleton* p;
	};
	Singleton::GC ga;
	Singleton* Singleton::p = nullptr;
	std::mutex Singleton::_mutex;
}

class Singleton{
public:
	static Singleton* Getincetance()
	{
		return &p;
	}

private:
	Singleton(){}
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
	static Singleton p;
};
Singleton Singleton::p;
int main() {

	//std::vector<std::thread> vthreads;
	cout << Singleton::Getincetance() << std::endl;
	system("pause");



	return 0;
}


