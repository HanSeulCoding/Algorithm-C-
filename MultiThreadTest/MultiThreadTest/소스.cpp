#include <thread>
#include <mutex>
#include <iostream>
#include <atomic>
using namespace std;
class Animal
{
public:
	Animal()
	{
		cout << "Animal 持失" << endl;
	}
	virtual ~Animal()
	{
		cout << "Animal 社瑚" << endl;
	}
};
class Rabbit : public Animal
{
public:
	Rabbit()
	{
		cout << "Rabbit 持失" << endl;
	}
	virtual  ~Rabbit()
	{
		cout << "Rabbit 社瑚" << endl;
	}
};
static std::mutex m;
std::atomic<int> g_sum = 0;
void Add()
{
	for (int i = 0; i < 10000000; ++i)
	{
		//ock_guard<std::mutex> guard(m);
		g_sum++;
	}
}
void Sub()
{
	for (int i = 0; i < 10000000; ++i)
	{
		//lock_guard<std::mutex> guard(m);
		g_sum--;
	}
}
int main()
{
	static condition_variable g_controller;
	
	int x = 0;
	//auto Func([](string s) {
	//	for (int i = 0; i < 5; ++i)
	//	{
	//		
	//		

	//		//this_thread::sleep_for(chrono::milliseconds(1));
	//		////m.lock();
	//		//std::lock_guard<std::mutex> guard(m);
	//		//cout << this_thread::get_id() << "is working" << endl;

	//		//cout << s << " : " << i << endl;
	//		////m.unlock();
	//	}
	//	});


	thread t1 = thread(Add);
	thread t2 = thread(Sub);


	t1.join();
	t2.join();
	cout << g_sum << endl;
}