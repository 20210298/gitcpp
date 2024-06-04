#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
	vector<int> numbers = { 10, 21, 4, 45, 66, 93, 30 };
	vector<int> evens; //짝수 값만 저장
	//구현 1: 짝수 값만 evens 에 저장
	for (auto a : numbers) {
		if (a % 2 == 0) {
			evens.push_back(a);
		}
	}
	//구현 2: 오름차순 정렬
	sort(evens.begin(), evens.end());
	//구현 3: evens 출력
	for (auto b : evens) {
		cout << b << " ";
	}
	return 0;
}

//bubble sort를 구현