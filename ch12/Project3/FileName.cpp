#include <iostream>

using namespace std;

// 사용자 정의 예외 클래스: 재귀 깊이 초과 예외
class StackOverflowError {
	//1. 구현
private:
	int depth;
public:
	StackOverflowError(int depth) :depth(depth) {}
	void ShowExceptionReason() const {
		cout <<"재귀 깊이 초과 : 함수 호출 스택이 너무 깊습니다";
	}
};
// 재귀 깊이를 제한하는 함수
void RecurFunc(int depth, int maxDepth) {
	//2. 구현
	cout << "재귀 깊이: " << depth << endl;	
	if (depth == maxDepth) {
		cout << "예외 발생: ";
		throw(StackOverflowError(depth));
	}
	RecurFunc(++depth, maxDepth);	
}

int main() {
	int maxDepth;
	cout << "최대 재귀 깊이를 입력하세요: ";
	cin >> maxDepth;
	//3. 구현
	try {
		RecurFunc(1, maxDepth);
	}
	catch (StackOverflowError&expn){
		expn.ShowExceptionReason();
	}
	return 0;
}