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
		cout << "Error: 큐가 가득 참";
	else {
		rear = (rear + 1) % MAX_QUEUE_SIZE;
		data[rear];
	}
}

Student CircularQueue::dequeue() {
	if (isEmpty())
		cout << "Error: 큐가 비어있음";
	else {
		front = (front + 1) % MAX_QUEUE_SIZE;
		return data[front];
	}
}

Student CircularQueue::peek() {
	if (isEmpty())
		cout << "Error: 큐가 비어있음";
	else {
		return data[(front + 1) % MAX_QUEUE_SIZE];
	}

}
