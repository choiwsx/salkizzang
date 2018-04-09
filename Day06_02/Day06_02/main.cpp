#include "stdio.h"
#include "stdlib.h"
#include <stack>

class AStack
{
protected:
	int* Data;
	int Capacity;
	int Size;
	int Top;

public:
	void Init(int _Size);
	int Pop();
	void Push(int Value);
	int Length();
	int Peek();
};

void AStack::Init(int _Size = 10)
{
	Data = new int[_Size];
	Capacity = _Size;
	Size = 0;
	Top = -1;
}

int AStack::Pop()
{
	int Value = 0;

	if (Size > 0)
	{
		Value = Data[Top];
		Top--;
		Size--;
	}

	return Value;
}

void AStack::Push(int Value)
{
	if (Capacity > Size)
	{
		Top++;
		Data[Top] = Value;
		Size++;
	}
	else
	{
		//저장공간 늘리기
		Capacity = Capacity * 2;
		int* NewData = new int[Capacity];
		memcpy(NewData, Data, (sizeof(int) * Size));
		delete[] Data;
		Data = NewData;

		//자료 집어 넣기
		Top++;
		Data[Top] = Value;
		Size++;
	}

}

int AStack::Length()
{
	return Size;
}

int AStack::Peek()
{
	return Data[Top];
}


int main()
{
	AStack a;
	a.Init();

	for (int i = 100; i >= 1; --i)
	{
		a.Push(i);
	}

	while (a.Length() != 0)
	{
		int c = a.Pop();
		printf("%d\n", c);
	} 

	return 0;
}
