#pragma once
#include "Student.h"
#define MAX_QUEUE_SIZE 100

class CircularQueue {
protected:
	int front;
	int rear;
	Student data[MAX_QUEUE_SIZE];
public:
	CircularQueue();
	bool isFull();
	bool isEmpty();
	void enqueue(Student& n);
	Student dequeue();
	Student peek();
};
