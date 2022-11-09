#include <thread>
#include <mutex>
#include <iostream>

using namespace std;
class Animal
{
public:
	Animal()
	{
		cout << "Animal 积己" << endl;
	}
	virtual ~Animal()
	{
		cout << "Animal 家戈" << endl;
	}
};
class Rabbit : public Animal
{
public:
	Rabbit()
	{
		cout << "Rabbit 积己" << endl;
	}
	virtual  ~Rabbit()
	{
		cout << "Rabbit 家戈" << endl;
	}
};

int main()
{
	static condition_variable g_controller;
	static std::mutex m;
	auto Func([](string s) {
		//for (int i = 0; i < 5; ++i)
		//{
		//	//
		//	
		//	//m.lock();
		//	this_thread::sleep_for(chrono::milliseconds(1));
		//	std::lock_guard<std::mutex> guard(m);

		//	cout << this_thread::get_id() << "is Working" << endl;

		//	cout << s << " : " << i << endl;
		//	//m.unlock();
		//}
		while (true)
		{
			std::unique_lock<std::mutex> lock(m);
			g_controller.wait(lock);
			cout << "Hello" << s << endl;
		}
		});
	

	thread t1 = thread(Func,"Hanseul");
	thread t2 = thread(Func, "HanWool");


	while (true)
	{
		string line;
		cin >> line;
		if (line == "q")
		{
			t1.detach();
			t2.detach();
			break;
		}
		unique_lock<std::mutex> lock(m);
		g_controller.notify_all();
	}
	//Func("YeongIn");
	//m.lock();

	/*for (int i = 0; i < 100; ++i)
	{
		cout << i << "锅掳 角青" << endl;
	}*/
	//t1.join();
	//t2.join();
}