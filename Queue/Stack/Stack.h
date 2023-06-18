#pragma once

struct Node
{
	int Data;
	Node* Next = nullptr;
	Node* Prev = nullptr;
};

struct Stack
{
	Node* Head = nullptr;
	Node* Tail = nullptr;
};

namespace stack
{
	// backend
	void Init(int data);
	void Push(int data);
	int Pop();
	void Clear();

	// frontend
	void Output();
	int Menu();
	void Stack();
	void AutoInit();
	bool IsInit();
}