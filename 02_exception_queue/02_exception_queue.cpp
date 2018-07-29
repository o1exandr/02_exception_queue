/*
Завдання 2. Доповнити шаблон класу Черга
o	Метод вилучення елемента з черги повинен викидати виключення, якщо черга порожня
o	Метод додавання елемента у чергу повинен викидати виключення, якщо черга заповнена.

*/

#include "stdafx.h"
#include <iostream> 
#include <string>

using namespace std;


template<typename T>
class Queue
{
	enum size { MAXSIZE = 10, EMPTY = -1 };
private:
	T queue[MAXSIZE];
	int size;

public:
	Queue()
	{
		size = -1;
	}

	~Queue()
	{
	}

	// Метод вилучення елемента з черги повинен викидати виключення, якщо черга порожня
	bool isEmpty()const
	{
		try
		{
			if (size == EMPTY)
				throw QueueEmpty();
			return 0;
		}

		catch (QueueEmpty & ex)
		{
			cout << ex.what();
		}
		return 1;
	}

	// Метод додавання елемента у чергу повинен викидати виключення, якщо черга заповнена.
	bool isFull()const
	{
		try
		{
			if (size == MAXSIZE - 1)
				throw QueueFull();
			return 0;
		}

		catch (QueueFull & ex)
		{
			cout << ex.what();
		}
			return 1;
	}

	void add(const T & elem)
	{
		if (isFull()) 
			cerr << "Method Add";
		else
		{
			++size;
			queue[size] = elem;
		}
	}

	T extract()
	{
		if (isEmpty()) 
			cerr << "Method Extract";
		else
		{
			T first = front();
			for (int i = 0; i < size; i++)
				queue[i] = queue[i + 1];
			--size;
			return 	first;
		}
	}

	T front()
	{
		if (isEmpty())
			cerr << "Method Front";
		else
			return queue[0];
	}

	T back()
	{
		if (isEmpty())
			cerr << "Method Back";
		else
			return queue[size];
	}

	void print()const
	{
		if (isEmpty())
			cout << "Method Print\n";
		else
		{
			cout << endl;
			for (int i = 0; i <= size; i++)
				cout << queue[i] << "  ";
			cout << endl;
		}
	}

	
	class QueueEmpty : public logic_error
	{
	public:
		QueueEmpty(const char* mes = "\nError: Queue is empty. ") : logic_error(mes) {}
	};

	class QueueFull : public logic_error
	{
	public:
		QueueFull(const char* mes = "\nError: Queue is full. ") : logic_error(mes) {}
	};

	friend std::ostream & operator  << <T> (std::ostream & os, const Queue <T> & que);
	friend std::istream & operator  >> <T> (std::istream & is, Queue <T> & que);

};

//Перевантажити для шаблону класу операції виведення (<<) та  введення(>>).
// <<
template<typename T>
std::ostream & operator << (std::ostream & os, const Queue<T> & que)
{
	if (que.isEmpty())
		os << "Method Cout <<\n";
	else
	{
		os << endl;
		for (int i = 0; i <= que.size; i++)
			os << que.queue[i] << "  ";
		os << endl;
	}
	return os;
}

// >>
template<typename T>
std::istream & operator  >> (std::istream & is, Queue <T> & que)
{
	T n;
	cout << endl << "Enter element of Queue: ";
	is >> n;
	que.add(n);
	return is;
}





int main()
{
	Queue<int> qu;
	cout << "\n\t= Int =\n";
	for (int i = 0; i < 11; ++i)
		qu.add(10 + i); // на 11 ітерації видасть помилку заповнення черги

	cout << endl << qu;
	cout << "Extract: " << qu.extract() << endl;
	cout << qu;
	cout << "Front: " << qu.front() << endl;
	cout << "Back: " << qu.back() << endl;

	for (int i = 0; i < 10; ++i)
		qu.extract(); // на 10 ітерації видасть помилку порожньої черги
	qu.front(); // помилка при спробі доступитись до першого елемента порожньої черги
	cout << qu; // помилка при спробі вивести порожню чергу





	cout << endl;
	system("pause");
	return 0;

}

