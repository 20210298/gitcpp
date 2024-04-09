#define _CRT_SECURE_NO_WARNINGS
#include "NameCard.h"
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

NameCard::NameCard(const char* name, const char* company, const char* phone, int pos) : position(pos) {
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->company = new char[strlen(company) + 1];
	strcpy(this->company, company);
	this->phone = new char[strlen(phone) + 1];
	strcpy(this->phone, phone);
}

NameCard::NameCard(const NameCard& copy) : position(copy.position) {
	this->name = new char[strlen(copy.name) + 1];
	strcpy(this->name, copy.name);
	this->company = new char[strlen(copy.company) + 1];
	strcpy(this->company, copy.company);
	this->phone = new char[strlen(copy.phone) + 1];
	strcpy(this->phone, copy.phone);
}

void NameCard::ShowNameCardInfo() {
	cout << "이름 : " << this->name << endl;
	cout << "회사 : " << this->company << endl;
	cout << "연락처 : " << this->phone << endl;
	COMP_POS::ShowPositionInfo(this->position);
}

NameCard::~NameCard() {
	delete[] name;
	delete[] company;
	delete[] phone;
}

void COMP_POS::ShowPositionInfo(int pos) {
	switch (pos) {
	case CLERK:
		cout << "직급 : " << "사원" << endl;
		break;
	case SENIOR:
		cout << "직급 : " << "주임" << endl;
		break;
	case ASSIST:
		cout << "직급 : " << "대리" << endl;
		break;
	case MANAGER:
		cout << "직급 : " << "과장" << endl;
		break;
	}
}

