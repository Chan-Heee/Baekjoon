#include "MeetingSimulator.h"
#include <iostream>
#include <string>

using namespace std;



void MeetingSimulator::InsertStudent(int arrivalTime) {

	int i = rand() % 2;
	string gen = (i == 0) ? "��" : "��";
	Student a(arrivalTime, arrivalTime, gen);
	cout << gen << "�л� " << a.id << " �湮" << endl;
	if (gen == "��")
		boy.push(a);
	else
		girl.push(a);
}

void MeetingSimulator::readSimulationParameters() {
	cout << "�ùķ��̼� �� �ִ� �ο� (��: 100[��]) = ";
	cin >> nSimulation;
	cout << "�����ð��� ����ϴ� �л� �� (��: 0.5 [�л�/���� �ð�])";
	cin >> probArrival;
	cout << "====================================================" << endl;
}

void MeetingSimulator::run() {
	int clock = 0;
	int count_Student = 0;
	int index = 0;
	while (count_Student < nSimulation) {
		clock++;
		cout << "����ð�= " << clock << endl;

		if (IsNewStudent()) {
		
			InsertStudent(clock);
			count_Student++;
		}
		if (boy.empty() || girl.empty()) {
			cout << "���� ����ڰ� �����ϴ�. ��ٷ��ֽʽÿ�." << endl;
		}
		else {
			
			
			boysWaitTime = boysWaitTime + clock - boy.front().tArrival;
			girlsWaitTime = girlsWaitTime + clock - girl.front().tArrival;

			pair.boyNum = boy.front().id;
			pair.girlNum = girl.front().id;

			arr[index] = pair;

		
			index++;
			nPair++;
			
			boy.pop();
			girl.pop();
			cout << "��Ī ����!" << endl;
		
		}
	}
}

void MeetingSimulator::printStat() {
	cout << "==================================================" << endl;
	cout << "     ��ü ���� �ּ� Ƚ��     = " << nPair<< endl;
	cout << "       ���� �ּ��� ������ Ŀ�� ���� ��ȣ (���ڹ�ȣ, ���ڹ�ȣ)     = ";
	for(int i=0; i<nPair; i++){
			cout << "( " << arr[i].boyNum << ", " << arr[i].girlNum << " )" << ", ";
	}
	cout << endl;
	cout << "     ���� ���񽺰� ��� ���ð�     = " << (double)boysWaitTime / nPair << endl;
	cout << "     ���� ���񽺰� ��� ���ð�     = " << (double)girlsWaitTime / nPair << endl;
}