#include "Stack.h"
#include <iostream>

struct Stack* buffer = new struct Stack;

using namespace std;

// backend
void stack::Init(int data) // Создание стека
{
	Node* node = new Node;
	node->Next = node->Prev = nullptr;
	buffer->Head = buffer->Tail = node;
	node->Data = data;
}

void stack::Push(int data) // Добавление в стек
{
	Node* newNode = new Node;
	Node* node = new Node;
	node = buffer->Tail;
	newNode->Data = data;
	newNode->Next = nullptr;
	newNode->Prev = node;
	node->Next = newNode;
	buffer->Tail = newNode;
}

int stack::Pop()// Удаление из стека
{
	Node* node = new Node;
	node = buffer->Tail;

	if (buffer->Tail == buffer->Head)
	{
		int data = buffer->Tail->Data;
		buffer->Head = buffer->Tail = nullptr;
		delete node;
		return data;
	}

	int data = buffer->Tail->Data;
	node->Prev->Next = nullptr;
	buffer->Tail = node->Prev;
	delete node;
	return data;
}

void stack::Clear() // ОЧистка стека
{
	Node* node = buffer->Tail->Prev;
	while (node != nullptr)
	{
		Pop();
		node = node->Prev;
	}
	Pop();
}

// frontend
void stack::Output() // Вывод в консоль стека
{
	cout << "Стек: ";
	Node* node = buffer->Head;
	while (node != nullptr)
	{
		cout << node->Data << " ";
		node = node->Next;
	}
	cout << endl;
}

int stack::Menu()
{
	cout << "МЕНЮ СТЕКА" << endl;
	cout << "1. Создать новый стек" << endl;
	cout << "2. Вставить новый элемент из стека" << endl;
	cout << "3. Удалить самый новый элемент из стека" << endl;
	cout << "4. Очистить стек" << endl;
	cout << "5. Выход в главное меню" << endl;
	Output();
	cout << "Введите команду: ";

	int act = -1; cin >> act;
	return act;
}

void stack::Stack()
{
	bool work = true;
	while (work == true)
	{
		switch (Menu())
		{
		case 1:
		{
			cout << "Введите элемент, который Вы хотите вставить: ";
			int act = -1; cin >> act;
			Init(act);
			break;
		}
		case 2:
		{
			if (IsInit() == false)
			{
				cout << "Введите элемент, который Вы хотите вставить: ";

				int act = -1; cin >> act;
				Init(act);
			}
			else
			{
				cout << "Введите элемент, который Вы хотите вставить: ";

				int act = -1; cin >> act;
				Push(act);
			}
			break;
		}
		case 3:
		{
			if (IsInit() == true)
			{
				Pop();
			}
			break;
		}
		case 4:
		{
			if (IsInit() == true)
			{
				Clear();
			}
			cout << "Стек был очищен." << endl;
			break;
		}
		default:
		{
			cout << "Вы будете возвращены в главное меню. . ." << endl;
			return;
		}
		}
	}
	cout << endl;
}

void stack::AutoInit() // Автоматическое создание стека
{
	if (IsInit() == false)
	{
		cout << "Стек был создан автоматически!" << endl;
		cout << "Введите элемент, который Вы хотите вставить: ";

		int act = -1; cin >> act;
		Init(act);
	}
}

bool stack::IsInit() // Проверка на наличие стека
{
	Node* node = new Node;
	node = buffer->Head;
	if (node == nullptr)
	{
		return false;
	}
	return true;
}