#ifndef __NAME_CARD_H__
#define __NAME_CARD_H__
namespace COMP_POS {
	enum { CLERK, SENIOR, ASSIST, MANAGER };
	void ShowPositionInfo(int pos);
}
class NameCard {
private:
	char* name;
	char* company;
	char* phone;
	int position;
public:
	NameCard(const char* name, const char* company, const char* phone, int pos);
	void ShowNameCardInfo();
	~NameCard();
	NameCard(NameCard& copy);
};
#endif