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
	auto Func([](string s) {
		for (int i = 0; i < 5; ++i)
		{
			cout << this_thread::get_id() << "is Working" << endl;
			cout << s << " : " << i << endl;
		}
		});
	
	static std::mutex m;
	thread t1 = thread(Func,"Hanseul");



	t1.join();
	thread t2 = thread(Func, "HanWool");

	t2.join();
	Func("YeongIn");
	//m.lock();

	/*for (int i = 0; i < 100; ++i)
	{
		cout << i << "锅掳 角青" << endl;
	}*/
	//t1.join();
	//t2.join();
}