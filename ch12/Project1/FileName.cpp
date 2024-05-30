#include <iostream>

using namespace std;

int main() {
	int arr[5] = { 1, 2, 3, 4, 5 };
	int chk[5] = { 0 };
	int cnt = 0;
	int idx;
	//구현//
	while (true) {
		cout << "배열 인덱스 입력 :";
		cin >> idx;
		try {
			if (idx >= 5) throw 1;
			if (idx < 0) throw 1.0;
			cout << idx << "번째 값: " << arr[idx] << endl;
			if (chk[idx] == 0) {				
				cnt++;
			}
			chk[idx]++;
			if (cnt == 5) throw '1';	// 예외처리 안하고 그냥 탈출시켜도 좋음
		}
		catch (int ex1) {
			cout << "예외 발생: 범위 초과" << endl;
		}
		catch (double ex2) {
			cout << "예외 발생: 유효하지 않은 인덱스" << endl;
		}
		catch (char ex3) {
			cout << "모든 인덱스의 값이 한 번 이상 출력되었습니다.";
			break;
		}
	}
	return 0;
}