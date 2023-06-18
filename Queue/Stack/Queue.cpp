#include "Queue.h"
#include <iostream>

using namespace std;

struct Stack* part1 = new struct Stack;
struct Stack* part2 = new struct Stack;

// backend
void QueueStack::Init(int data) // �������� �������
{
	Node* node = new Node;
	node->Data = data;
	node->Next = node->Prev = nullptr;
	part1->Head = part1->Tail = node;
}

void QueueStack::Enqueue(int data) // ������� �������� � �������
{

	Node* newNode = new Node;
	Node* node = new Node;
	node = part1->Tail;
	newNode->Data = data;
	if (part1->Head == nullptr && part1->Tail == nullptr) 
	{
		node = part2->Head;
		newNode->Next = node;
		newNode->Prev = nullptr;
		node->Prev = newNode;
		part2->Head = newNode;
	}
	else 
	{
		newNode->Next = nullptr;
		newNode->Prev = node;
		node->Next = newNode;
		part1->Tail = newNode;
	}



}

void QueueStack::Dequeue() // �������� ������ ������� �������� �� �������
{
	if (part1->Head != nullptr && part2->Head == nullptr)
	{
		if (part1->Head == part1->Tail)
		{
			Node* temp = new Node;
			temp = part1->Head;
			cout << "��������� �������" << temp->Data;
			delete temp;
			part1->Head = part1->Tail = nullptr;
		}
		else
		{
			Node* temp = new Node;
			temp = part1->Tail;
			Node* temp2 = new Node;
			temp2->Data = temp->Data;
			temp2->Next = temp2->Prev = nullptr;
			part2->Head = part2->Tail = temp2;
			temp = temp->Prev;
			delete temp->Next;
			temp->Next = nullptr;
			while (temp->Prev != nullptr)
			{
				Node* unit = new Node;
				temp2 = part2->Tail;
				unit->Data = temp->Data;
				unit->Prev = temp2;
				temp2->Next = unit;
				part2->Tail = unit;
				unit->Next = nullptr;
				temp = temp->Prev;
				delete temp->Next;
				temp->Next = nullptr;
			}
			delete temp;
			part1->Head = part1->Tail = nullptr;
		}
	}
	else if (part2->Head != nullptr)
	{
		Node* temp = new Node;
		temp = part2->Tail;
		if (temp->Prev != nullptr)
		{
			temp = temp->Prev;
			delete temp->Next;
			temp->Next = nullptr;
			part2->Tail = temp;
		}
		else
		{
			delete temp;
			part2->Head = part2->Tail = nullptr;
		}
	}
}

void QueueStack::Clear(Stack* buffer) // ������� �������
{
	if (buffer->Head != nullptr)
	{
		Node* temp = new Node;
		temp = buffer->Head;
		while (temp->Next != nullptr)
		{
			temp = temp->Next;
			delete temp->Prev;
			temp->Prev = nullptr;
			buffer->Head = temp;
		}
		delete temp;
		buffer->Head = buffer->Tail = nullptr;
	}
}

void QueueStack::Peek() // ������ ���������� �������� �������
{
	if (part1->Head != nullptr && part2->Head == nullptr)
	{
		cout << endl << "�����: " << part1->Head->Data << endl;
	}
	else if (part2->Head != nullptr) 
	{
		cout << endl << "�����: " << part2->Tail->Data << endl;
	}
}



// frontend
void QueueStack::Output() // ����� �������
{
	cout << endl << "����� 1: ";
	if (part1->Head != nullptr)
	{
		Node* temp = new Node;
		temp = part1->Head;
		while (temp != nullptr)
		{
			cout << temp->Data << " ";
			temp = temp->Next;
		}
		cout << endl;
		delete temp;
	}
	cout << endl << "����� 2: ";
	if (part2->Head != nullptr)
	{
		Node* temp = new Node;
		temp = part2->Head;
		while (temp != nullptr)
		{
			cout << temp->Data << " ";
			temp = temp->Next;
		}
		cout << endl;
		delete temp;
	}
}


int QueueStack::Menu() // ���� ��� �������
{

	cout << "������� �� ���� 2-� ������" << endl;
	cout << "1. ������� ����� �������" << endl;
	cout << "2. �������� ����� ������� � �������" << endl;
	cout << "3. ������� ����� ������ ������� �� �������" << endl;
	cout << "4. �������� �������" << endl;
	cout << "5. ��������, �� �� ������" << endl;
	Output();
	cout << "������� �������: ";

	int act = -1; cin >> act;
	return act;


}

void QueueStack::QueueStack()// ���������� ������� ���� ��� �������		
{

	while (true)
	{
		switch (Menu())
		{
		case 1:
		{
			cout << "������� �������, ������� �� ������ ��������: ";
			int act = -1; cin >> act;
			Init(act);
			break;
		}
		case 2:
		{
			if (IsInit() == false)
			{
				cout << "���� ��� ������ �������������!";
				cout << "������� �������, ������� �� ������ ��������: ";
				int act = -1; cin >> act;
				Init(act);
			}
			else
			{
				cout << "������� �������, ������� �� ������ ��������: ";
				int act = -1; cin >> act;
				Enqueue(act);
			}
			break;
		}
		case 3:
		{
			if (IsInit() == true)
			{
				Dequeue();
			}
			break;
		}
		case 4:
		{
			if (IsInit() == true)
			{
				Clear(part1);
				Clear(part2);
			}
			cout << "���� ��� ������!" << endl;
			break;
		}
		case 5: {
			if (IsInit() == true)
			{
				Peek();
			}
			break;
		}
		default:
		{
			cout << "�� ������ ������� �� �����" << endl;
			return;
		}
		}
	}
}

void QueueStack::AutoInit() // �������������� �������� �������
{
	if (IsInit() == false)
	{
		cout << "������� ���� ������� �������������!";
		cout << "������� �������, ������� �� ������ ��������: ";
		int act = -1; cin >> act;
		Init(act);

	}
}

bool QueueStack::IsInit() // �������� �� ������� �������
{
	Node* node1 = new Node;
	Node* node2 = new Node;
	node1 = part1->Head;
	node2 = part2->Head;
	if (node1 == nullptr && node2 == nullptr)
	{
		return false;
	}
	return true;
}