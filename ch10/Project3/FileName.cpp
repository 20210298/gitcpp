#include <iostream>
#include <string>

using namespace std;

class MathFunc {
private:
	string type;
	double param;
public:
	// 생성자
	MathFunc(const string& type, double param = 1)
		: type(type), param(param) {}
	// () 연산자 오버로딩 구현

	double operator() (const double& n) const
	{
		if (this->type == "square") {
			return n * n;
		}
		else if (this->type == "reciprocal") {
			return 1 / n;
		}
		else if (this->type == "multiplay") {
			return this->param * n;
		}
	}

};

int main() {
	MathFunc square("square"); //제곱
	MathFunc recip("reciprocal"); //역수
	MathFunc multi("multiply", 5); //상수 n을 곱셈
	cout << "Square of 3: " << square(3) << endl;
	cout << "Reciprocal of 4: " << recip(4) << endl;
	cout << "Multiply 6 by 5: " << multi(6) << endl;
	return 0;
}