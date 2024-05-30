#include <iostream>

using namespace std;

int main() {
	int arr[5] = { 1, 2, 3, 4, 5 };
	int idx;
	//구현//
	while (true) {
		cout << "배열 인덱스 입력 :";
		cin >> idx;
		try {
			if (idx >= 5) throw(1);
			if (idx < 0) throw(1.0);
			cout << idx << "번째 값: " << arr[idx] << endl;
		}		
		catch (int ex1) {
			cout << "예외 발생: 범위 초과" << endl;
		}
		catch (double ex2) {
			cout << "예외발생 : 유효하지 않은 인덱스" << endl;
		}
	}
	return 0;
}