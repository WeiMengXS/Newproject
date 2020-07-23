#include<iostream>
#include<thread>
#include<mutex>
#include<atomic>
std::mutex tex;
/*void Add(int n)
{
	tex.lock();
	for (int i = 0; i < n; i++)
	{
		++x;
	}
	tex.unlock();
}
*/
int main()
{
	std::atomic<int> x = 0;

	auto Add=[&x](int n)
	{
		for (int i = 0; i < n;i++)
		++x;
	};
	std::thread t1(Add,10000);
	std::thread t2(Add,10000);

	std::cout << t1.get_id() << std::endl;
	std::cout << t2.get_id() << std :: endl;

	t1.join();
	t2.join();

	std::cout << x << std::endl;
	system("pause");
	return 0;
}