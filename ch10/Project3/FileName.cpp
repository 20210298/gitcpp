#include <iostream>
#include <string>

using namespace std;

class MathFunc {
private:
	string type;
	double param;
public:
	// ������
	MathFunc(const string& type, double param = 1)
		: type(type), param(param) {}
	// () ������ �����ε� ����

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
	MathFunc square("square"); //����
	MathFunc recip("reciprocal"); //����
	MathFunc multi("multiply", 5); //��� n�� ����
	cout << "Square of 3: " << square(3) << endl;
	cout << "Reciprocal of 4: " << recip(4) << endl;
	cout << "Multiply 6 by 5: " << multi(6) << endl;
	return 0;
}