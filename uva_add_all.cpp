#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>

using namespace std;

class PriorityQueue
{
public:
	vector<int> data;
	void push(int);
	void pop();
	int top();
	bool empty();
	void clear();
	int size();
	void print();
private:
	void shiftDown(int);
	void shiftUp(int);

};

void PriorityQueue::print()
{
	for (int i=0; i<data.size(); i++)
	{
		cout << data[i];
		if (i<data.size()-1) cout << " ";
	}
	cout << endl;
}

int PriorityQueue::size()
{
	return data.size();
}

void PriorityQueue::clear()
{
	data.clear();
}
 
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
	data[0] = data.back();
	data.pop_back();

	shiftDown(0);
}

void PriorityQueue::shiftDown(int index)
{
	if (((index*2)+1) < data.size())
	{
		int left = (index*2)+1;
		int right = (index*2)+2;

		if (right < data.size())
		{
			if ((data[left] <= data[right]) && (data[left] <= data[index]))
			{
				int temp = data[left];
				data[left] = data[index];
				data[index] = temp;
				shiftDown(left);
			}
			else
			if ((data[right] <= data[left]) && (data[right] <= data[index]))
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
	PriorityQueue pq;
	int n=-1;

	while (n!=0)
	{
		scanf("%d", &n);

		if (n==0) break;

		pq.clear();

		int bil;
		for (int i=0; i<n; i++)
		{
			scanf("%d", &bil);
			pq.push(bil);
		}

		long long sum=0;
		int a,b;
		while (!pq.empty())
		{
			// printf("----------------\n");
			// pq.print();

			a=pq.top();
			pq.pop();
			// pq.print();

			if (!pq.empty())
			{
				b=pq.top();
				pq.pop();
				// pq.print();
			}
			else
				break;

			// printf("----------------\n");

			int temp = a+b;
			sum+=temp;
			pq.push(temp);

		}

		cout << sum << endl;
	}

	return 0;
}