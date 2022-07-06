#include "CircularQueue.h"
#include <iostream>

using namespace std;

CircularQueue::CircularQueue() {
	front = rear = 0;
}

bool CircularQueue::isFull() {
	return front == (rear + 1) % MAX_QUEUE_SIZE;
}

bool CircularQueue::isEmpty() {
	return front == rear;
}

void CircularQueue::enqueue(Student& n) {
	if (isFull())
		cout << "Error: ť�� ���� ��";
	else {
		rear = (rear + 1) % MAX_QUEUE_SIZE;
		data[rear];
	}
}

Student CircularQueue::dequeue() {
	if (isEmpty())
		cout << "Error: ť�� �������";
	else {
		front = (front + 1) % MAX_QUEUE_SIZE;
		return data[front];
	}
}

Student CircularQueue::peek() {
	if (isEmpty())
		cout << "Error: ť�� �������";
	else {
		return data[(front + 1) % MAX_QUEUE_SIZE];
	}

}
