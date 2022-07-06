#include <iostream>	
#include <queue>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	queue<int> que;


	for (int i = 1; i <= N; i++) {
		que.push(i);
	}
	cout << "<";
	int tmp;

	while (que.size()> 1) {
		for(int i=0; i<K-1; i++) {
			tmp = que.front();
			que.push(tmp);
			que.pop();
		}
		tmp = que.front();
		cout << tmp << ", ";
		que.pop();
	}
	cout << que.front();
	que.pop();
	cout << ">";

	return 0;
}