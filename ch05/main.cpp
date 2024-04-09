#include <iostream>
#include "NameCard.h"

using namespace std;

int main() {
	NameCard clerk1("Choi", "KIT", "010-0000-0000", COMP_POS::CLERK);
	NameCard senior1("Hong", "Saemsung", "010-1111-2222", COMP_POS::SENIOR);
	NameCard Assist1("Lee", "Gogle", "010-3332-4444", COMP_POS::ASSIST);
	clerk1.ShowNameCardInfo();
	senior1.ShowNameCardInfo();
	Assist1.ShowNameCardInfo();

	cout << "--------บนป็--------" << endl;
	NameCard copy1 = clerk1;
	NameCard copy2 = senior1;
	copy1.ShowNameCardInfo();
	copy2.ShowNameCardInfo();

	return 0;
}