#include"libraries.h"
class validate {
public:
	bool valid_cinic(string num) {
		int a = 0, b = 0;
		if (num.length() == 15) {
			for (int i = 0; i < num.length(); i++) {
				if (isdigit(num[i]) == false) {
					a = a + i;
				}
				if (num[i] == '-') {
					b = b + i;
				}
			}
			if (a == 18 && b == 18) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	bool valid_date(string num) {
		int a = 0, b = 0;
		string m = "", d = "";
		if (num.length() == 10) {
			for (int i = 0; i < num.length(); i++) {
				if (isdigit(num[i]) == false) {
					a = a + i;
				}
				if (num[i] == '/') {
					b = b + i;
				}
			}
			m += num[3];
			m += num[4];
			d += num[0];
			d += num[1];
			int dd = 0;
			int mm = 0;
			stringstream con(m);
			con >> mm;
			stringstream conn(d);
			conn >> dd;
			if (a == 7 && b == 7) {
				if (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12) {
					if (dd >= 1 && dd <= 31) {
						return true;
					}
					else {
						return false;
					}
				}
				else if (mm == 2 && dd >= 1 && dd <= 28) {
					return true;
				}
				else if (mm == 4 || mm == 6 || mm == 9 || mm == 11) {
					if (dd >= 1 && dd <= 30) {
						return true;
					}
					else {
						return false;
					}
				}
				else {
					return false;
				}
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	bool Valid_email(string email)
	{
		if (email.length() > 10) {
			int a = email.length() - 10;
			if (email[a] == '@' && email[a + 1] == 'g' && email[a + 2] == 'm' && email[a + 3] == 'a' && email[a + 4] == 'i' && email[a + 5] == 'l' && email[a + 6] == '.' && email[a + 7] == 'c' && email[a + 8] == 'o' && email[a + 9] == 'm') {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	bool valid_contect(string con) {
		int a = 0, b = 0;
		if (con.length() == 12) {
			for (int i = 0; i < con.length(); i++) {
				if (isdigit(con[i]) == false) {
					a = i;
				}
				if (con[i] == '-') {
					b = i;
				}
			}
			if (a == 4 && b == 4) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
};
