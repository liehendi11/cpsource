#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

class PriorityQueue
{
	vector<int> data;
public:
	void push(int);
	void pop();
	int top();
	bool empty();
private:
	void shiftDown(int);
	void shiftUp(int);
};
 
void PriorityQueue::push(int number)
{
	data.push_back(number);
	shiftUp(data.size()-1);
}

void PriorityQueue::shiftUp(int index)
{
	if (index != 0)
	{
		int parentIndex = (index-1)/2;
		if (data[parentIndex] > data[index])
		{
			int temp = data[parentIndex];
			data[parentIndex] = data[index];
			data[index] = temp;
			shiftUp(parentIndex);
		}
	}
}

int PriorityQueue::top()
{
	return data[0];
}

bool PriorityQueue::empty()
{
	return (data.size() ==0);
}

void PriorityQueue::pop()
{
	data[0] = data[data.size()-1];
	data.erase(data.end());

	shiftDown(0);
}

void PriorityQueue::shiftDown(int index)
{
	if (((index*2)+1) < data.size())
	{
		//masih anak
		int left = (index*2)+1;
		int right = (index*2)+2;

		if (right < data.size())
		{
			//right is still inside
			if ((data[left] < data[right]) && (data[left] < data[index]))
			{
				//left is smallest
				int temp = data[left];
				data[left] = data[index];
				data[index] = temp;
				shiftDown(left);
			}
			else
			if ((data[right] < data[left]) && (data[right] < data[index]))
			{
				int temp = data[right];
				data[right] = data[index];
				data[index] = temp;
				shiftDown(right);
			}
		}
		else
		{
			if (data[left] < data[index])
			{
				int temp = data[left];
				data[left] = data[index];
				data[index] = temp;
				shiftDown(left);
			}
		}
	}
}

int main()
{
	return 0;
}