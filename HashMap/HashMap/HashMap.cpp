#include<iostream>
#include <string>

using namespace std;
#define HashMapSize 3
template<typename T, typename V>
class Node
{
public:
	T key;
	V value;
	Node<T,V>* next = NULL;
	Node(T key, V value) :key(key), value(value) {}
};
template<typename T, typename V>
class LinkedList
{
private:
	int size = 0;
public:
	Node<T,V>* head = NULL;

	void Add(T key, V value)
	{
		if (head == NULL)
		{
			head = new Node<T,V>(key,value);
		}
		else
		{
			Node<T, V>* cursor = head;
			while (cursor->next != NULL)
			{
				cursor = cursor->next;
			}
			cursor->next = new Node<T,V>(key,value);
		}
		size++;
	}

	V Get(const T& key)
	{
		while (head != NULL)
		{
			if (head->key == key)
			{
				return head->value;
			}
			head = head->next;
		}
		return NULL;
	}
	int GetLength()
	{
		return size;
	}

	void Remove(T key)
	{
		if (head->key == key)
		{
			head = head->next;
			return;
		}
		while (head->next != NULL)
		{
			if (head->next->key == key)
			{
				delete head->next;
				head->next = head->next->next;
				return;
			}
			head = head->next;
		}
	}
};

template<typename T, typename V>
class HashMap
{
private:
	LinkedList<T, V>* container[HashMapSize];

	int hash(T key)
	{
		int hashCode = -1;
		int temp = 0;

		string s = to_string(key);
		for (int i = 0; i < s.size(); ++i)
		{
			temp += (int)s[i];
		}
		hashCode = temp % HashMapSize;
		return hashCode;
	}

	Node<T, V>* FindNodeByKey(T key, Node<T,V>* nowNode)
	{
		Node<T, V>* cursor = nowNode;
		while (cursor != NULL)
		{
			if (cursor->key == key)
			{
				return cursor;
			}
			cursor = cursor->next;
		}

		return cursor;
	}

public:
	HashMap()
	{
		for (int i = 0; i < HashMapSize; ++i)
		{
			container[i] = new LinkedList<T, V>();
		}
	}
	void put(T key, V value)
	{
		int hashCode = hash(key);
		LinkedList<T,V>* link = container[hashCode];
		Node<T, V>* node = FindNodeByKey(key, link->head);

		if (node != NULL)
		{
			node->value = value;
		}
		else
		{
			link->Add(key, value);
		}
	}

	V get(T key)
	{
		int hashCode = hash(key);

		LinkedList<T, V>* link = container[hashCode];
		V get = link->Get(key);

		if (get == NULL)
		{
			cout << "키를 찾을 수 없습니다.";
			return -1;
		}

		return get;
	}
	void remove(T key)
	{
		int hashCode = hash(key);
		LinkedList<T, V>* link = container[hashCode];
		Node<T, V>* node = FindNodeByKey(key, link->head);
		if (node == nullptr)
		{
			cout << "key가 존재하지 않습니다." << endl;
		}
		else
		{
			link->Remove(key);
		}
	}
	void print()
	{
		for (int i = 0; i < HashMapSize; ++i)
		{
			LinkedList<T, V>* link = container[i];
			Node<T, V>* head = link->head;
			while (head != NULL)
			{
				cout << "Key : " << head->key << "value : " << head->value << endl;
				head = head->next;
			}
		}
	}
	~HashMap()
	{
		for (int i = 0; i < HashMapSize; ++i)
		{
			delete container[i];
		}
	}
};
int main()
{
	HashMap<int, int> hashMap;
	for (int i = 0; i < 100; ++i)
	{
		hashMap.put(i, 1);
	}
	//hashMap.remove(4);
	for (int i = 0; i < 90; ++i)
	{
		hashMap.remove(i);
	}
	int t = hashMap.get(90);
	cout << t << endl;
	hashMap.print();
}
