#include <iostream>

class Squad
{
	int archers, spearman, horse, result;
public:
	Squad(int archers, int spearman, int horse) {
		this->archers = archers;
		this->spearman = spearman;
		this->horse = horse;
	}
	friend std::ostream& operator<<(std::ostream& out, const Squad& obj);
	friend std::istream& operator>>(std::ostream&, Squad& obj);
	friend Squad operator+ (const Squad& left, const Squad& right) {
		Squad result(left.archers + right.archers,left.spearman + right.spearman, left.horse + right.horse);
		return result;
	}
	friend Squad operator-(const Squad& left, const Squad& right) {
		Squad result(left.archers - right.archers, left.spearman - right.spearman, left.horse - right.horse);
		return result;
	}
	friend bool operator<(const Squad& left, const Squad& right) {
		if (((left.archers + left.spearman + left.horse) < (right.archers + right.spearman + right.horse))) return true;
		else return false;
	}
	friend bool operator>(const Squad& left, const Squad& right) {
		if (((left.archers + left.spearman + left.horse) > (right.archers + right.spearman + right.horse))) return true;
		else return false;
	}
	
};

int main() {
	system("chcp 1251");
}
