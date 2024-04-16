#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>

using namespace std;

class PermanentWorker {
	char name[100];
	int salary;
public:
	PermanentWorker(const char* name, int money) {
		strcpy(this->name, name);
		this->salary = money;
	}
	int GetPay() {
		return this->salary;
	}
	void ShowSalaryInfo() const {
		cout << "Name: " << this->name << endl;
		cout << "Salary: " << this->salary << endl;
	}
};

class EmployeeHandler {
	PermanentWorker* empList[50];
	int empNum;
public:
	EmployeeHandler() : empNum(0) {};
	void AddEmployee(PermanentWorker* emp) {	
		empList[empNum] = emp;
		this->empNum++;
	}
	void ShowAllSalaryInfo() const {
		for (int i = 0; i < empNum; i++) {
			empList[i]->ShowSalaryInfo();
			cout << endl;
		}
	}
	void ShowTotalSalary() const {
		int result = 0;
		for (int i = 0; i < empNum; i++) {
			result += empList[i]->GetPay();
		}
		cout << "Total Salary: " << result;
	}
	~EmployeeHandler() {
		for (int i = 0; i < empNum; i++) {
			delete[] empList[i];
		}
	}
};

int main() {
	EmployeeHandler handler; //�޿� ������ �������� ����� �ڵ鷯 ��ü ����
	//���� ���
	handler.AddEmployee(new PermanentWorker("Kim", 200));
	handler.AddEmployee(new PermanentWorker("Lee", 350));
	handler.AddEmployee(new PermanentWorker("choi", 400));
	//�̹� �޿� �����ؾ��� �޿� ����
	handler.ShowAllSalaryInfo();
	//�̹� �޿� �����ؾ��� �� �޿�
	handler.ShowTotalSalary();
	return 0;
}