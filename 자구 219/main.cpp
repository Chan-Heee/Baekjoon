#include "MeetingSimulator.h"
#include <ctime>

int main() {
	srand((unsigned)time(NULL));
	MeetingSimulator sim;
	sim.readSimulationParameters();
	sim.run();
	sim.printStat();
}