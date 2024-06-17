#include <iostream>
#include <deque>
using namespace std;
int main() {
	deque<int> numbers;
	int command, value;
	while (true) {
		cin >> command;
		//±¸Çö
		switch (command) {
		case 1:
			cin >> value;
			numbers.push_front(value);
			break;
		case 2:
			cin >> value;
			numbers.push_back(value);
			break;
		case 3:
			for (int n : numbers) {
				cout << n << " ";
			}
			cout << endl;
			break;
		default:
			exit(0);
		}
	}
	return 0;
}