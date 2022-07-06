#pragma once

#include"MatchingNum.h"
# include "CircularQueue.h"
#include <ctime>
#include <cstdlib>
#include<queue>




class MeetingSimulator {
	int nSimulation;
	double probArrival;
	int boysWaitTime=0;
	int girlsWaitTime = 0;
	int nPair=0;
	queue<Student> boy;
	queue<Student> girl;
	MatchingNum arr[100];
	MatchingNum pair;
	double Random() { return (double)rand() / (double)RAND_MAX; }
	bool IsNewStudent() { return Random() < probArrival; }
	void InsertStudent(int arrivalTime);
public:
	void readSimulationParameters();
	void run();
	void printStat();
};