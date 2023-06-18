#pragma once
#include "Stack.h"

namespace QueueStack
{

	void Init(int data);
	void Enqueue(int data);
	void Dequeue();
	void Peek();
	void Clear(Stack* buffer);


	void Output();
	int Menu();
	void QueueStack();
	void AutoInit();
	bool IsInit();
}