#include "MeetingSimulator.h"
#include <iostream>
#include <string>

using namespace std;



void MeetingSimulator::InsertStudent(int arrivalTime) {

	int i = rand() % 2;
	string gen = (i == 0) ? "남" : "여";
	Student a(arrivalTime, arrivalTime, gen);
	cout << gen << "학생 " << a.id << " 방문" << endl;
	if (gen == "남")
		boy.push(a);
	else
		girl.push(a);
}

void MeetingSimulator::readSimulationParameters() {
	cout << "시뮬레이션 할 최대 인원 (예: 100[명]) = ";
	cin >> nSimulation;
	cout << "단위시간에 등록하는 학생 수 (예: 0.5 [학생/단위 시간])";
	cin >> probArrival;
	cout << "====================================================" << endl;
}

void MeetingSimulator::run() {
	int clock = 0;
	int count_Student = 0;
	int index = 0;
	while (count_Student < nSimulation) {
		clock++;
		cout << "현재시각= " << clock << endl;

		if (IsNewStudent()) {
		
			InsertStudent(clock);
			count_Student++;
		}
		if (boy.empty() || girl.empty()) {
			cout << "아직 대상자가 없습니다. 기다려주십시오." << endl;
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
			cout << "매칭 성공!" << endl;
		
		}
	}
}

void MeetingSimulator::printStat() {
	cout << "==================================================" << endl;
	cout << "     전체 미팅 주선 횟수     = " << nPair<< endl;
	cout << "       미팅 주선에 성공한 커플 쌍의 번호 (남자번호, 여자번호)     = ";
	for(int i=0; i<nPair; i++){
			cout << "( " << arr[i].boyNum << ", " << arr[i].girlNum << " )" << ", ";
	}
	cout << endl;
	cout << "     남자 서비스고객 평균 대기시간     = " << (double)boysWaitTime / nPair << endl;
	cout << "     여자 서비스고객 평균 대기시간     = " << (double)girlsWaitTime / nPair << endl;
}