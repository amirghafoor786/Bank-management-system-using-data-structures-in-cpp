#include"libraries.h"
#include"design.h"
#include"employee_user_account.h"
#include"validation.h"
string name, father, dob, contect, acc_num, pasword, cinic, choice, email, admin_user, admin_pass;
validate v;
admin_account_pass k;
desgin_manu a;
employee put;
create c;
// admin username and password is hardcored as given below
// admin username= amirghafoor
// admin password= 12345678
// you cannot change admin password with login using this password.
//thank you
double total_amount = 0;
void recover_account_atm() {
	while (true)
	{
		system("cls");
		a.recover_account_logo();
		cout << "\n\t\t\t\t   Enter your choice: ";
		cin >> choice;
		if (choice == "1") {
			system("cls");
			a.recover_account_logo();
			cout << "\t\t\t\t   Enter ATM account number :: ";
			cin >> cinic;
			if (c.check_account(cinic)==true && c.atm_check_account(cinic)==true && cinic.length()==10) {
				system("cls");
				a.recover_account_logo();
				string pass;
				char ch;
				int count = 0;
				cout << "\n\t\t\t\t   Enter ATM account new password : ";
				while (true) {
					ch = _getch();
					if (ch == 13) {
						break;
					}
					else if (ch == '\b') {
						if (pass.length() > 0) {
							pass.pop_back();
							count--;
							system("cls");
							a.recover_account_logo();
							cout << "\n\t\t\t\t   Enter ATM account new password : ";
							for (int i = 0; i < count; i++) {
								cout << "*";
							}
						}
					}
					else {
						count++;
						pass.push_back(ch);
						system("cls");
						a.recover_account_logo();
						cout << "\n\t\t\t\t   Enter ATM account new password : ";
						for (int i = 0; i < count; i++) {
							cout << "*";
						}
					}
				}
				if (pass.length() == 4) {
					if (c.atm_account_pass_change(cinic, pass) == true) {
						cout << "\n\t\t\t\t   ATM account is recover successfuly\n";
						cout << "\n\t\t\t\t   ";
						system("pause");
					}
				}
				else {
					cout << "\n\t\t\t\t   Please 4 digits Pincode of ATM account\n";
					cout << "\n\t\t\t\t   ";
					system("pause");
				}
			}
			else {
				if (cinic.length()!=10) {
					cout << "\n\t\t\t\t   Please enter correct 10 digits ATM account\n";
				}
				else {
					cout << "\t\t\t\t   This ATM account not found\n";
				}
				cout << "\n\t\t\t\t   ";
				system("pause");
			}
		}
		else if (choice == "0") {
			break;
		}
		else {
			system("color 0c");
			cout << "\n\t\t\t\t   Please enter correct choice (0 or 1)\n";
			cout << "\n\t\t\t\t   ";
			system("pause");
		}
	}
}
void withdraw_money(string type1, string type2) {
	while (true)
	{
		system("cls");
		a.withdraw_money_account_logo();
		cout << "\n\t\t\t\t   Enter your choice: ";
		cin >> choice;
		if (choice == "1") {
			system("cls");
			a.withdraw_money_account_logo();
			cout << "\t\t\t\t   Enter user account number : ";
			cin >> cinic;
			if (c.check_account(cinic) && cinic.length() == 13) {
				system("cls");
				a.withdraw_money_account_logo();
				cout << "\n\t\t\t\t   Account details is: \n";
				c.check_balance(cinic, type1);
				cout << "\n\t\t\t\t  *  Press (1) for deposit             *";
				cout << "\n\t\t\t\t  **************************************\n";
				cout << "\n\t\t\t\t   Enter your choice: ";
				cin >> choice;
				if (choice == "1") {
					int pric;
					system("cls");
					a.withdraw_money_account_logo();
					cout << "\n\t\t\t\t   Account details is: \n";
					c.check_balance(cinic, type1);
					cout << "\n\t\t\t\t   Enter amount you want to withdraw : ";
					cin >> pric;
					if (c.withdraw_balance(cinic, pric, type2) == true) {
						total_amount = total_amount - pric;
						cout << "\n\t\t\t\t   ";
						system("pause");
					}
					else {
						cout << "\n\t\t\t\t   Withdrawal is failed due to low current amount : ";
						cout << "\n\t\t\t\t   ";
						system("pause");
					}
				}
			}
			else {
				if (cinic.length() != 13) {
					cout << "\n\t\t\t\t   Please enter correct 13 digits account number \n";
				}
				else {
					cout << "\t\t\t\t   This User account not found\n";
				}
				cout << "\n\t\t\t\t   ";
				system("pause");
			}
		}
		else if (choice == "0") {
			break;
		}
		else {
			system("color 0c");
			cout << "\n\t\t\t\t   Please enter correct choice (0 or 1)\n";
			cout << "\n\t\t\t\t   ";
			system("pause");
		}

	}
}
void check_balance(string type) {
	while (true)
	{
		system("cls");
		a.check_balance_account_logo();
		cout << "\n\t\t\t\t   Enter your choice: ";
		cin >> choice;
		if (choice == "1") {
			system("cls");
			a.check_balance_account_logo();
			cout << "\t\t\t\t   Enter user account number : ";
			cin >> cinic;
			if (c.check_account(cinic) && cinic.length() == 13) {
				system("cls");
				a.check_balance_account_logo();
				cout << "\n\t\t\t\t   Account details is: \n";
				c.check_balance(cinic, type);
				cout << "\n\t\t\t\t   ";
				system("pause");
			}
			else {
				if (cinic.length() != 13) {
					cout << "\n\t\t\t\t   Please enter correct 13 digits account number \n";
				}
				else {
					cout << "\t\t\t\t   This User account not found\n";
				}
				cout << "\n\t\t\t\t   ";
				system("pause");
			}
		}
		else if (choice == "0") {
			break;
		}
		else {
			system("color 0c");
			cout << "\n\t\t\t\t   Please enter correct choice (0 or 1)\n";
			cout << "\n\t\t\t\t   ";
			system("pause");
		}
	}
}
void atm_user(string log) {
	string login = log;
	while (true)
	{
		system("cls");
		a.user_atm__account_logo();
		cin >> choice;
		if (choice == "1") {
			while (true)
			{
				string acc2;
				system("cls");
				a.send_money_account_logo();
				cout << "\n\t\t\t\t   Enter your choice: ";
				cin >> choice;
				if (choice == "1") {
					system("cls");
					a.send_money_account_logo();
						cout << "\n\t\t\t\t   Enter Receiver ATM account Number : ";
						cin >> acc2;
						if (c.atm_check_account(acc2)==true && acc2.length() == 10 && login != acc2) {
							system("cls");
							a.send_money_account_logo();
							c.show_templet(login, acc2, "ATM");
							cout << "\n\t\t\t\t   Enter your choice: ";
							cin >> choice;
							if (choice == "1") {
								double mony;
								system("cls");
								a.send_money_account_logo();
								c.show_templet(login, acc2, "ATM");
								cout << "\n\t\t\t\t   Enter amount you want to transfer : ";
								cin >> mony;
								if (c.transfer_from_account(login, mony) == true && c.transfer_to_account(acc2, mony) == true) {
									system("cls");
									a.send_money_account_logo();
									cout << "\n\t\t\t\t   Amount transfer successfully\n";
									c.transection_record(login, acc2, mony, "ATM Transection", "ATM Received", "ATM");
									cout << "\n\t\t\t\t   ";
									system("pause");
								}
								else {
									cout << "\n\t\t\t\t   Current balance is low then transection amount\n";
									cout << "\n\t\t\t\t   ";
									system("pause");
								}

							}
							else {
								cout << "\n\t\t\t\t   Transection Canlced\n";
								cout << "\n\t\t\t\t   ";
								system("pause");
							}
						}
						else {
							if (acc2.length() != 10) {
								cout << "\n\t\t\t\t   Please enter 10 digits ATM account number \n";
							}
							else if (login == acc2)
							{
								cout << "\n\t\t\t\t   Please Use different ATM account number for transection\n";
							}
							else {
								cout << "\t\t\t\t   This ATM account user not found\n";
							}
							cout << "\n\t\t\t\t   ";
							system("pause");
						}
				}
				else if (choice == "0") {
					break;
				}
				else {
					system("color 0c");
					cout << "\n\t\t\t\t   Please enter correct choice (0 or 1)\n";
					cout << "\n\t\t\t\t   ";
					system("pause");
				}
			}
		}
		else if (choice == "2") {
				system("cls");
				a.atm_check_balance_account_logo();
				cout << "\n\t\t\t\t   Account details is: \n";
				c.check_balance(login, "ATM");
				cout << "\n\t\t\t\t   ";
				system("pause");		
		}
		else if (choice == "3") {
				system("cls");
				a.withdraw_money_account_logo();
				cout << "\n\t\t\t\t   Account details is: \n";
				c.check_balance(login, "ATM");
				cout << "\n\t\t\t\t  *  Press (1) for Withdraw            *";
				cout << "\n\t\t\t\t  **************************************\n";
				cout << "\n\t\t\t\t   Enter your choice: ";
				cin >> choice;
				if (choice == "1") {
						int pric;
						system("cls");
						a.withdraw_money_account_logo();
						cout << "\n\t\t\t\t   Account details is: \n";
						c.check_balance(login, "ATM");
						cout << "\n\t\t\t\t   Enter amount you want to withdraw : ";
						cin >> pric;
						if (c.withdraw_balance(login, pric, "ATM Withdraw") == true) {
							total_amount = total_amount - pric;
							cout << "\n\t\t\t\t   ";
							system("pause");
						}
						else {
							cout << "\n\t\t\t\t   Withdrawal is failed due to low current amount : ";
							cout << "\n\t\t\t\t   ";
							system("pause");
						}

				}
				else {
					cout << "\n\t\t\t\t   Withdrawal cancled ";
					cout << "\n\t\t\t\t   ";
					system("pause");
				}
		}
		else if (choice == "4") {
		system("cls");
		a.recover_account_logo();
		cout << "\t\t\t\t   Enter ATM account number :: ";
		cin >> cinic;
		
		if (cinic.length() == 10) {
			if (cinic == log) {
				system("cls");
				a.recover_account_logo();
				string pass;
				char ch;
				int count = 0;
				cout << "\n\t\t\t\t   Enter ATM account new password : ";
				while (true) {
					ch = _getch();
					if (ch == 13) {
						break;
					}
					else if (ch == '\b') {
						if (pass.length() > 0) {
							pass.pop_back();
							count--;
							system("cls");
							a.recover_account_logo();
							cout << "\n\t\t\t\t   Enter ATM account new password : ";
							for (int i = 0; i < count; i++) {
								cout << "*";
							}
						}
					}
					else {
						count++;
						pass.push_back(ch);
						system("cls");
						a.recover_account_logo();
						cout << "\n\t\t\t\t   Enter ATM account new password : ";
						for (int i = 0; i < count; i++) {
							cout << "*";
						}
					}
				}
				if (pass.length() == 4) {
					if (c.atm_account_pass_change(cinic, pass) == true) {
						cout << "\n\t\t\t\t   ATM account is recover successfuly\n";
						cout << "\n\t\t\t\t   ";
						system("pause");
					}
				}
				else {
					cout << "\n\t\t\t\t   Please 4 digits Pincode of ATM account\n";
					cout << "\n\t\t\t\t   ";
					system("pause");
				}
			}
			else {
				cout << "\n\t\t\t\t   Please enter ATM account in which you login\n";
				cout << "\n\t\t\t\t   ";
				system("pause");
			}
		}
		else {
			if (cinic.length() != 10) {
				cout << "\n\t\t\t\t   Please enter correct 10 digits ATM account\n";
			}
			else {
				cout << "\t\t\t\t   This ATM account not found\n";
			}
			cout << "\n\t\t\t\t   ";
			system("pause");
			}
		}
		else if (choice == "0") {
			break;
		}
		else {
			system("color 0c");
			cout << "\n\t\t\t\t\t   Please enter correct choice\n";
			cout << "\n\t\t\t\t\t  ";
			system("pause");
		}
	}
}
void accounts_history() {
	string acc1;
	while (true)
	{
		system("cls");
		a.account_histroy();
		cout << "\n\t\t\t\t   Enter your choice: ";
		cin >> choice;
		if (choice == "1") {
			system("cls");
			a.account_histroy();
			cout << "\n\t\t\t\t   Enter account Number : ";
			cin >> acc1;
			if (c.check_account(acc1) && acc1.length() == 13) {
				system("cls");
				a.account_histroy();
				cout << "\n\t\t\t\t   Account history is\n";
				if (c.show_history(acc1) == true) {
					cout << "\n\t\t\t\t   ";
					system("pause");
				}
				else {
					cout << "\n\t\t\t\t   This account has no history still\n";
					cout << "\n\t\t\t\t   ";
					system("pause");
				}

			}
			else {
				if (acc1.length() != 13) {
					cout << "\n\t\t\t\t   Please enter 13 digits account number \n";
				}
				else {
					cout << "\t\t\t\t   This User account not found\n";
				}
				cout << "\n\t\t\t\t   ";
				system("pause");
			}
		}
		else if (choice == "0") {
			break;
		}
		else {
			system("color 0c");
			cout << "\n\t\t\t\t   Please enter correct choice (0 or 1)\n";
			cout << "\n\t\t\t\t   ";
			system("pause");
		}
	}
}
void send_money(string type, string type2, string type3) {
	while (true)
	{
		string acc1, acc2;
		system("cls");
		a.send_money_account_logo();
		cout << "\n\t\t\t\t   Enter your choice: ";
		cin >> choice;
		if (choice == "1") {
			system("cls");
			a.send_money_account_logo();
			cout << "\n\t\t\t\t   Enter Sender account Number : ";
			cin >> acc1;
			if (c.check_account(acc1) == true && acc1.length() == 13) {
				cout << "\n\t\t\t\t   Enter Receiver account Number : ";
				cin >> acc2;
				if (c.check_account(acc2) == true && acc2.length() == 13 && acc1 != acc2) {
					system("cls");
					a.send_money_account_logo();
					c.show_templet(acc1, acc2, type3);
					cout << "\n\t\t\t\t   Enter your choice: ";
					cin >> choice;
					if (choice == "1") {
						double mony;
						system("cls");
						a.send_money_account_logo();
						c.show_templet(acc1, acc2, type3);
						cout << "\n\t\t\t\t   Enter amount you want to transfer : ";
						cin >> mony;
						if (c.transfer_from_account(acc1, mony) == true && c.transfer_to_account(acc2, mony) == true) {
							system("cls");
							a.send_money_account_logo();
							cout << "\n\t\t\t\t   Amount transfer successfully\n";
							c.transection_record(acc1, acc2, mony, type,type2,type3 );
							cout << "\n\t\t\t\t   ";
							system("pause");
						}
						else {
							cout << "\n\t\t\t\t   Current balance is low then transection amount\n";
							cout << "\n\t\t\t\t   ";
							system("pause");
						}

					}
				}
				else {
					if (acc2.length() != 13) {
						cout << "\n\t\t\t\t   Please enter 13 digits account number \n";
					}
					else if (acc1 == acc2)
					{
						cout << "\n\t\t\t\t   Please Enter different account number\n";
					}
					else {
						cout << "\t\t\t\t   This User account not found\n";
					}
					cout << "\n\t\t\t\t   ";
					system("pause");
				}
			}
			else {
				if (acc1.length() != 13) {
					cout << "\n\t\t\t\t   Please enter 13 digits account number \n";
				}
				else {
					cout << "\t\t\t\t   This User account not found\n";
				}
				cout << "\n\t\t\t\t   ";
				system("pause");
			}
		}
		else if (choice == "0") {
			break;
		}
		else {
			system("color 0c");
			cout << "\n\t\t\t\t   Please enter correct choice (0 or 1)\n";
			cout << "\n\t\t\t\t   ";
			system("pause");
		}
	}
}
void search_u() {
	while (true) {
		system("cls");
		a.search_account_logo();
		cout << "\n\t\t\t\t   Enter your choice: ";
		cin >> choice;
		if (choice == "1") {
			system("cls");
			a.search_account_logo();
			cout << "\t\t\t\t   Enter id card OR account number : ";
			cin >> cinic;
			if (cinic[0] == '3') {
				if (c.check_account(cinic) && v.valid_cinic(cinic) == true) {
					system("cls");
					a.search_account_logo();
					cout << "\t\t\t\t  Account data is :: \n";
					c.search_user(cinic);
					cout << "\n\t\t\t\t   ";
					system("pause");
				}
				else {
					if (v.valid_cinic(cinic) == false) {
						cout << "\n\t\t\t\t   Enter correct CNIC format(xxxxx-xxxxxxx-x)\n";
					}
					else {
						cout << "\t\t\t\t   This User account not found\n";
					}
					cout << "\n\t\t\t\t   ";
					system("pause");
				}
			}
			else if (cinic[0] == 'P' || cinic[0] == 'p' || cinic[1] == 'K' || cinic[1] == 'k') {
				if (c.check_account(cinic) && cinic.length() == 13) {
					system("cls");
					a.search_account_logo();
					cout << "\t\t\t\t  Account data is :: \n";
					c.search_user(cinic);
					cout << "\n\t\t\t\t   ";
					system("pause");
				}
				else {
					if (cinic.length() != 13) {
						cout << "\n\t\t\t\t   Please Enter correct 13 digits account number\n";
					}
					else {
						cout << "\t\t\t\t   This User account not found\n";
					}
					cout << "\n\t\t\t\t   ";
					system("pause");
				}
			}
			else {
				cout << "\n\t\t\t\t   Please Enter proper account number OR CNIC number\n";
				cout << "\n\t\t\t\t   ";
				system("pause");
			}
		}
		else if (choice == "0") {
			break;
		}
		else {
			system("color 0c");
			cout << "\n\t\t\t\t   Please enter correct choice (0 or 1)\n";
			cout << "\n\t\t\t\t   ";
			system("pause");
		}
	}
}
void delete_user() {
	while (true)
	{
		system("cls");
		a.delete_account_logo();
		cout << "\n\t\t\t\t   Enter your choice: ";
		cin >> choice;
		if (choice == "1") {
			system("cls");
			a.delete_account_logo();
			cout << "\t\t\t\t   Enter id card OR account number : ";
			cin >> cinic;
			if (cinic[0] == '3') {
				if (c.check_account(cinic) && v.valid_cinic(cinic) == true) {
					system("cls");
					a.delete_account_logo();
					if (c.delete_account(cinic)) {
						cout << "\n\t\t\t\t   User account is deleted successfuly\n";
						cout << "\n\t\t\t\t   ";
						system("pause");
						--k.user_data;
						--k.user_data_ATM;
					}
					else {
						cout << "\n\t\t\t\t   User account is not delete\n";
						cout << "\n\t\t\t\t   ";
						system("pause");
					}
				}
				else {
					if (v.valid_cinic(cinic) == false) {
						cout << "\n\t\t\t\t   Enter correct CNIC format(xxxxx-xxxxxxx-x)\n";
					}
					else {
						cout << "\t\t\t\t   This User account not found\n";
					}
					cout << "\n\t\t\t\t   ";
					system("pause");
				}
			}
			else if (cinic[0] == 'P' || cinic[0] == 'p' || cinic[1] == 'K' || cinic[1] == 'k') {
				if (c.check_account(cinic) && cinic.length() == 13) {
					system("cls");
					a.delete_account_logo();
					if (c.delete_account(cinic)) {
						cout << "\n\t\t\t\t   User account is deleted successfuly\n";
						cout << "\n\t\t\t\t   ";
						system("pause");
						total_amount = total_amount - c.amount_delete(cinic);
						--k.user_data;
					}
					else {
						cout << "\n\t\t\t\t   User account is not delete\n";
						cout << "\n\t\t\t\t   ";
						system("pause");
					}
				}
				else {
					if (cinic.length() != 13) {
						cout << "\n\t\t\t\t   Please Enter correct 13 digits account number\n";
					}
					else {
						cout << "\t\t\t\t   This User account not found\n";
					}
					cout << "\n\t\t\t\t   ";
					system("pause");
				}
			}
			else {
				cout << "\n\t\t\t\t   Please Enter proper account number OR CNIC number\n";
				cout << "\n\t\t\t\t   ";
				system("pause");
			}
		}
		else if (choice == "0") {
			break;
		}
		else {
			system("color 0c");
			cout << "\n\t\t\t\t   Please enter correct choice (0 or 1)\n";
			cout << "\n\t\t\t\t   ";
			system("pause");
		}
	}
}
void atm_insertion(string cinc) {
	if (c.atm_check_account(cinc) == false)
	{
		system("cls");
		a.insert_account_logo();
		string pass;
		char ch;
		int count = 0;
		cout << "\t\t\t\t   Enter ATM account Pincode (4 digits): ";
		while (true) {
			ch = _getch();
			if (ch == 13) {
				break;
			}
			else if (ch == '\b') {
				if (pass.length() > 0) {
					pass.pop_back();
					count--;
					system("cls");
					a.insert_account_logo();
					cout << "\t\t\t\t   Enter ATM account Pincode (4 digits): ";
					for (int i = 0; i < count; i++) {
						cout << "*";
					}
				}
			}
			else {
				count++;
				pass.push_back(ch);
				system("cls");
				a.insert_account_logo();
				cout << "\t\t\t\t   Enter ATM account Pincode (4 digits): ";
				for (int i = 0; i < count; i++) {
					cout << "*";
				}
			}
		}
		if (pass.length() == 4) {
			if (c.atm_insert(cinc, pass) == true) {
				cout << "\n\t\t\t\t   ATM account is activated: ";
				cout << "\n\t\t\t\t   ATM account will be show next: ";
				cout << "\n\t\t\t\t   ";
				system("pause");
				system("cls");
				a.insert_account_logo();
				cout << "\n\t\t\t\t   Account data is: ";
				c.search_user(cinc);
				++k.user_data_ATM;
				cout << "\n\t\t\t\t   ";
				system("pause");
			}
		}
		else {
			cout << "\n\t\t\t\t   Please Enter only 4 digits Pincode";
			cout << "\n\t\t\t\t   ";
			system("pause");
		}
	}
	else if (c.atm_check_account(cinc) == true) {
		cout << "\n\t\t\t\t   ATM account is alreaady registered on this account number  \n";
		cout << "\n\t\t\t\t   ";
		system("pause");
	}
}
void entry() {
	cin.ignore();
	cout << "\t\t\t\t   Enter name: ";
	getline(cin, name);
	cout << "\t\t\t\t   Enter father name: ";
	getline(cin, father);
}
bool valid_entry() {
	int go = 0;
	while (true) {
		cout << "\t\t\t\t   Enter contect number format(03xx-xxxxxxx): ";
		getline(cin, contect);
		if (v.valid_contect(contect) == true) {
			go = go + 1;
			break;
		}
		else {
			cout << "\n\t\t\t\t   Enter correct contect number as given format\n\n";
		}
	}
	while (true) {
		cout << "\t\t\t\t   Enter email account (only gmail): ";
		getline(cin, email);
		if (v.Valid_email(email) == true) {
			go = go + 1;
			break;
		}
		else {
			cout << "\n\t\t\t\t   Please  enter valid email account\n\n";
		}
	}
	while (true) {
		cout << "\t\t\t\t   Enter date birth format(dd/mm/yyyy): ";
		getline(cin, dob);
		if (v.valid_date(dob) == true) {
			go = go + 1;
			break;
		}
		else {
			cout << "\n\t\t\t\t   Please  enter correct DateOfBirth as given format\n\n";
		}
	}
	if (go == 3) {
		return true;
	}
	else {
		return false;
	}
}
int main() {
	a.wellcome_slomo();
	system("pause");
	system("cls");
	a.load_bar();
	while (true)
	{
		system("cls");
		a.home_logo();
		cout << "\n\t\t\t\t\t     Enter your choice: ";
		cin >> choice;
		if (choice == "1") {
			system("cls");
			a.admin_account_login();
			cout << "\n\t\t\t\t\t  Enter admin username: ";
			cin >> admin_user;
			string pass;
			char ch;
			int count = 0;
			cout << "\n\t\t\t\t\t  Enter admin password: ";
			while (true) {
				ch = _getch();
				if (ch == 13) {
					break;
				}
				else if (ch == '\b') {
					if (pass.length() > 0) {
						pass.pop_back();
						count--;
						system("cls");
						a.admin_account_login();
						cout << "\n\t\t\t\t\t  Enter admin username: "<<admin_user;
						cout << "\n\n\t\t\t\t\t  Enter admin password: ";
						for (int i = 0; i < count; i++) {
							cout << "*";
						}
					}
				}
				else {
					count++;
					pass.push_back(ch);
					system("cls");
					a.admin_account_login();
					cout << "\n\t\t\t\t\t  Enter admin username: " << admin_user;
					cout << "\n\n\t\t\t\t\t  Enter admin password: ";
					for (int i = 0; i < count; i++) {
						cout << "*";
					}
				}
			}
			if (admin_user == k.username && pass == k.pass) {
				system("cls");
				a.log_in();
				while (true) {
					system("cls");
					a.admin_logo();
					cin >> choice;
					if (choice == "1") {
						while (true)
						{
							system("cls");
							a.employee_logo();
							cin >> choice;
							if (choice == "1") {
								while (true)
								{
									system("cls");
									a.insert_account_logo();
									cout << "\t\t\t\t   Enter your choice: ";
									cin >> choice;
									if (choice == "1") {
										system("cls");
										a.insert_account_logo();
										cout << "\n\t\t\t\tEnter id card format(xxxxx-xxxxxxx-x): ";
										cin >> cinic;
										string pass;
										char ch;
										int count = 0;
										cout << "\n\t\t\t\tEnter Employee account password: ";
										while (true) {
											ch = _getch();
											if (ch == 13) {
												break;
											}
											else if (ch == '\b') {
												if (pass.length() > 0) {
													pass.pop_back();
													count--;
													system("cls");
													a.insert_account_logo();
													cout << "\n\t\t\t\tEnter id card format(xxxxx-xxxxxxx-x): " << cinic;
													cout << "\n\n\t\t\t\t Enter Employee account password: ";
													for (int i = 0; i < count; i++) {
														cout << "*";
													}
												}
											}
											else {
												count++;
												pass.push_back(ch);
												system("cls");
												a.insert_account_logo();
												cout << "\n\t\t\t\tEnter id card format(xxxxx-xxxxxxx-x): " << cinic;
												cout << "\n\n\t\t\t\tEnter Employee account password  : ";
												for (int i = 0; i < count; i++) {
													cout << "*";
												}
											}
										}
										if (put.check_accounts(cinic) == false && (v.valid_cinic(cinic) == true && pass.length()>=8)) {
											system("cls");
											a.insert_account_logo();
											cout << "\t\t\t\t   New Employee account is opened\n";
											cout << "\t\t\t\t   Please Enter more Personal information\n";
											cout << "\n\t\t\t\t   ";
											system("pause");
											system("cls");
											a.insert_account_logo();
											entry();
											valid_entry();
											system("cls");
											a.insert_account_logo();
											if (put.insert(name, father, dob, contect, pass, cinic, email)) {
												cout << "\n\t\t\t\t   Account created successfully\n";
												put.search(cinic);
												cout << "\n\t\t\t\t   ";
												system("pause");
												++k.data;
											}
											else {
												cout << "\n\t\t\t\t   Data is not insert\n";
												cout << "\n\t\t\t\t   ";
												system("pause");

											}
										}
										else {
											if (v.valid_cinic(cinic) == false) {
												cout << "\n\t\t\t\tPlease enter correct CNIC number as given format \n";
											}
											else if (pass.length() != 8) {
												cout << "\n\t\t\t\tPassword length is greater then 7 is required";
											}
											else {
												cout << "\n\t\t\t\tAccount is already created on this CNIC \n";
											}
											cout << "\n\t\t\t\t";
											system("pause");
										}
									}
									else if (choice == "0") {
										break;
									}
									else {
										system("color 0c");
										cout << "\n\t\t\t\t   Please enter correct choice (0 or 1)\n";
										cout << "\n\t\t\t\t   ";
										system("pause");
									}
								}

							}
							else if (choice == "2") {
								while (true) {
									system("cls");
									a.search_account_logo();
									cout << "\n\t\t\t\t   Enter your choice: ";
									cin >> choice;
									if (choice == "1") {
										system("cls");
										a.search_account_logo();
										cout << "\t\t\t\t   Enter id card format(xxxxx-xxxxxxx-x): ";
										cin >> cinic;
										if (put.check_accounts(cinic) && v.valid_cinic(cinic) == true) {
											system("cls");
											a.search_account_logo();
											cout << "\t\t\t\t  Employee data is :: \n\n";
											put.search(cinic);
											cout << "\n\n\t\t\t\t   ";
											system("pause");
										}
										else {
											if (v.valid_cinic(cinic) == false) {
												cout << "\n\t\t\t\t   Please enter correct CNIC format as given \n";
											}
											else {
												cout << "\t\t\t\t   This Employee account not found\n";
											}
											cout << "\n\t\t\t\t   ";
											system("pause");
										}
									}
									else if (choice == "0") {
										break;
									}
									else {
										system("color 0c");
										cout << "\n\t\t\t\t   Please enter correct choice (0 or 1)\n";
										cout << "\n\t\t\t\t   ";
										system("pause");
									}
								}

							}
							else if (choice == "3") {
								while (true)
								{
									system("cls");
									a.update_account_logo();
									cout << "\n\t\t\t\t   Enter your choice: ";
									cin >> choice;
									if (choice == "1") {
										system("cls");
										a.update_account_logo();
										cout << "\t\t\t\t   Enter id card format(xxxxx-xxxxxxx-x): ";
										cin >> cinic;
										if (put.check_accounts(cinic) && v.valid_cinic(cinic) == true) {
											system("cls");
											a.update_account_logo();
											entry();
											valid_entry();
											if (put.user_update(name, father, dob, contect, email, cinic)) {
												cout << "\n\t\t\t\t   Employee account is update successfuly\n";
												cout << "\n\t\t\t\t   ";
												system("pause");
											}
											else {
												cout << "\n\t\t\t\t   Employee account is not update\n";
												cout << "\n\t\t\t\t   ";
												system("pause");
											}
										}
										else {
											if (v.valid_cinic(cinic) == false) {
												cout << "\n\t\t\t\t   Please enter correct CNIC format as given \n";
											}
											else {
												cout << "\t\t\t\t   This Employee account not found\n";
											}
											cout << "\n\t\t\t\t   ";
											system("pause");
										}
									}
									else if (choice == "0") {
										break;
									}
									else {
										system("color 0c");
										cout << "\n\t\t\t\t   Please enter correct choice (0 or 1)\n";
										cout << "\n\t\t\t\t   ";
										system("pause");
									}
								}
							}
							else if (choice == "4") {
								while (true)
								{
									system("cls");
									a.delete_account_logo();
									cout << "\n\t\t\t\t   Enter your choice: ";
									cin >> choice;
									if (choice == "1") {
										system("cls");
										a.delete_account_logo();
										cout << "\t\t\t\t   Enter id card format(xxxxx-xxxxxxx-x): ";
										cin >> cinic;
										if (put.check_accounts(cinic) && v.valid_cinic(cinic) == true) {
											system("cls");
											a.delete_account_logo();
											if (put.delete_account(cinic)) {
												cout << "\n\t\t\t\t   Employee account is deleted successfuly\n";
												cout << "\n\t\t\t\t   ";
												system("pause");
												--k.data;
											}
											else {
												cout << "\n\t\t\t\t   Employee account is not delete\n";
												cout << "\n\t\t\t\t   ";
												system("pause");
											}
										}
										else {
											if (v.valid_cinic(cinic) == false) {
												cout << "\n\t\t\t\t   Please enter correct CNIC format as given \n";
											}
											else {
												cout << "\t\t\t\t   This Employee account not found\n";
											}
											cout << "\n\t\t\t\t   ";
											system("pause");
										}
									}
									else if (choice == "0") {
										break;
									}
									else {
										system("color 0c");
										cout << "\n\t\t\t\t   Please enter correct choice (0 or 1)\n";
										cout << "\n\t\t\t\t   ";
										system("pause");
									}
								}
							}
							else if (choice == "5") {
								system("cls");
								a.total_account_logo();
								cout << "\n\n\t\t\t\t\t   Total Employee registered     : " << k.data << endl;
								cout << "\n\t\t\t\t\t   ";
								system("pause");
							}
							else if (choice == "6") {
								while (true)
								{
									system("cls");
									a.recover_account_logo();
									cout << "\n\t\t\t\t   Enter your choice: ";
									cin >> choice;
									if (choice == "1") {
										system("cls");
										a.recover_account_logo();
										cout << "\t\t\t\t   Enter id card format(xxxxx-xxxxxxx-x): ";
										cin >> cinic;
										if (put.check_accounts(cinic) && v.valid_cinic(cinic) == true) {
											system("cls");
											a.recover_account_logo();
											string pass;
											char ch;
											int count = 0;
											cout << "\t\t\t\t   Enter Employee account new password: ";
											while (true) {
												ch = _getch();
												if (ch == 13) {
													break;
												}
												else if (ch == '\b') {
													if (pass.length() > 0) {
														pass.pop_back();
														count--;
														system("cls");
														a.recover_account_logo();
														cout << "\t\t\t\t   Enter Employee account new password: ";
														for (int i = 0; i < count; i++) {
															cout << "*";
														}
													}
												}
												else {
													count++;
													pass.push_back(ch);
													system("cls");
													a.recover_account_logo();
													cout << "\t\t\t\t   Enter Employee account new password: ";
													for (int i = 0; i < count; i++) {
														cout << "*";
													}
												}
											}
											if (put.password_change(cinic, pass)==true && pass.length()>=8) {
												cout << "\n\t\t\t\t   Employee account is recover successfuly\n";
												cout << "\n\t\t\t\t   ";
												system("pause");
											}
											else {
												cout << "\n\t\t\t\t   Password digits must be equal or greater then 8\n";
												cout << "\n\t\t\t\t   ";
												system("pause");
											}
										}
										else {
											if (v.valid_cinic(cinic) == false) {
												cout << "\n\t\t\t\t   Please enter correct CNIC format as given \n";
											}
											else {
												cout << "\t\t\t\t   This Employee account not found\n";
											}
											cout << "\n\t\t\t\t   ";
											system("pause");
										}
									}
									else if (choice == "0") {
										break;
									}
									else {
										system("color 0c");
										cout << "\n\t\t\t\t   Please enter correct choice (0 or 1)\n";
										cout << "\n\t\t\t\t   ";
										system("pause");
									}
								}
							}
							else if (choice == "0") {
								break;
							}
							else {
								system("color 0c");
								cout << "\n\t\t\t\t\t   Please enter correct choice\n";
								cout << "\n\t\t\t\t\t  ";
								system("pause");
							}
						}
					}
					else if (choice == "2") {
					while (true)
					{
						system("cls");
						a.admin_access_account_user_logo();
						cin >> choice;
						if (choice == "1") {
							search_u();
						}
						else if (choice == "2") {
							delete_user();
						}
						else if (choice == "3") {
							system("cls");
							a.total_account_logo();
							cout << "\n\n\t\t\t\t     Total User accounts registered   : " << k.user_data << endl;
							cout << "\n\t\t\t\t     ";
							system("pause");
						}
						else if (choice == "4") {
							system("cls");
							a.all_account_list();
							if (c.show_list_user() == true) {
								cout << "\n\t\t\t\t     ";
								system("pause");
							}
							else {
								cout << "\n\n\t\t\t\t     No account registered still : " << endl;
								cout << "\n\t\t\t\t     ";
								system("pause");
							}
						}
						else if (choice == "5") {
							accounts_history();
						}
						else if (choice == "0") {
							break;
						}
						else {
							system("color 0c");
							cout << "\n\t\t\t\t\t   Please enter correct choice\n";
							cout << "\n\t\t\t\t\t  ";
							system("pause");
						}
					}
					}
					else if (choice == "3") {
					system("cls");
					a.total_bank_balance_logo();
					cout << "\n\n\t\t\t\t\t   Total Bank balance present : " << total_amount << endl;
					cout << "\n\t\t\t\t\t   ";
					system("pause");
					}
					else if (choice == "4") {
					while (true)
					{
						system("cls");
						a.recover_account_logo();
						cout << "\n\t\t\t\t   Enter your choice: ";
						cin >> choice;
						if (choice == "1") {
							system("cls");
							a.recover_account_logo();
							cout << "\t\t\t\t   Enter admin id card format(xxxxx-xxxxxxx-x): ";
							cin >> cinic;
							if (cinic==k.admin_id && v.valid_cinic(cinic) == true) {
								system("cls");
								a.recover_account_logo();
									string pass;
									char ch;
									int count = 0;
									cout << "\t\t\t\t   Enter admin account new password: ";
									while (true) {
										ch = _getch();
										if (ch == 13) {
											break;
										}
										else if (ch == '\b') {
											if (pass.length() > 0) {
												pass.pop_back();
												count--;
												system("cls");
												a.recover_account_logo();
												cout << "\t\t\t\t   Enter admin account new password: ";
												for (int i = 0; i < count; i++) {
													cout << "*";
												}
											}
										}
										else {
											count++;
											pass.push_back(ch);
											system("cls");
											a.recover_account_logo();
											cout << "\t\t\t\t   Enter admin account new password: ";
											for (int i = 0; i < count; i++) {
												cout << "*";
											}
										}
									}
									if (pass.length() >= 8) {
										k.pass = pasword;
										cout << "\n\t\t\t\t   Admin account password is change successfuly\n";
									}
									else {
										cout << "\n\t\t\t\t   Password length is greater then 7 is required\n\n";

									}
								cout << "\n\t\t\t\t   ";
								system("pause");
							}
							else {
								if (v.valid_cinic(cinic) == false) {
									cout << "\n\t\t\t\t   Please enter correct CNIC format as given \n";
								}
								else {
									cout << "\t\t\t\t   Invalid admin account cinic number\n";
								}
								cout << "\n\t\t\t\t   ";
								system("pause");
							}
						}
						else if (choice == "0") {
							break;
						}
						else {
							system("color 0c");
							cout << "\n\t\t\t\t   Please enter correct choice (0 or 1)\n";
							cout << "\n\t\t\t\t   ";
							system("pause");
						}
					}

					}
					else if (choice == "0") {
						break;
					}
					else {
						system("color 0c");
						cout << "\n\t\t\t\t\t      Please enter correct choice\n";
						cout << "\n\t\t\t\t\t  ";
						system("pause");
					}
				}
				system("cls");
				a.log_out();
			}
			else {
				system("color 0c");
				cout << "\n\t\t\t\t\t  Invalid Username or password\n";
				cout << "\n\t\t\t\t\t  ";
				system("pause");
			}
		}
        else if (choice == "2") {
			system("cls");
			a.employee_account_login();
			cout << "\t\t\t\t   Enter id card format(xxxxx-xxxxxxx-x): ";
			cin >> cinic;
			string log=cinic;
			string pass;
			char ch;
			int count = 0;
			cout << "\n\t\t\t\t   Enter Employee account password: ";
			while (true) {
				ch = _getch();
				if (ch == 13) {
					break;
				}
				else if (ch == '\b') {
					if (pass.length() > 0) {
						pass.pop_back();
						count--;
						system("cls");
						a.employee_account_login();
						cout << "\n\t\t\t\t   Enter id card format(xxxxx-xxxxxxx-x): " << cinic;
						cout << "\n\t\t\t\t   Enter Employee account password: ";
						for (int i = 0; i < count; i++) {
							cout << "*";
						}
					}
				}
				else {
					count++;
					pass.push_back(ch);
					system("cls");
					a.employee_account_login();
					cout << "\n\t\t\t\t   Enter id card format(xxxxx-xxxxxxx-x): " << cinic;
					cout << "\n\t\t\t\t   Enter Employee account password: ";
					for (int i = 0; i < count; i++) {
						cout << "*";
					}
				}
			}
			if (put.check_accounts(cinic) == true && v.valid_cinic(cinic) == true && put.check_account_pass(pass)==true) {
			//if (cinic == "1" && pasword=="1") {
				system("cls");
				a.log_in();
				while (true) {
					system("cls");
					a.employee_home_logo();
					cin >> choice;
					if (choice == "1") {
						while (true)
						{
							system("cls");
							a.account_user_logo();
							cin >> choice;
							if (choice == "1") {
								while (true) {
									system("cls");
									a.insert_account_logo();
									cout << "\n\t\t\t\t   Enter your choice: ";
									cin >> choice;
									if (choice == "1") {
										system("cls");
										a.insert_account_logo();
										while (true) {
											cout << "\t\t\t\t   Enter Id card format(xxxxx-xxxxxxx-x): ";
											cin >> cinic;
											if (v.valid_cinic(cinic) == true) {
												break;
											}
											else {
												cout << "\n\t\t\t\t   Please enter correct CNIC format as given \n";
											}
										}
										if (c.check_account(cinic)==false && put.check_accounts(cinic)==false) {
											cout << "\n\t\t\t\t   Account is open on this cinic please enter more detail \n";
											cout << "\n\t\t\t\t   ";
											system("pause");
											system("cls");
											a.insert_account_logo();
											entry();
											valid_entry();
											string em = "u";
											if (c.insert(name, father, dob, contect, cinic, email) == true) {
												system("cls");
												a.insert_account_logo();
												cout << "\n\t\t\t\t   Account is created successfully \n";
												++k.user_data;
												c.search_user(cinic);
												cout << "\n\t\t\t\t   ";
												system("pause");
										
											}
											else {
												cout << "\n\t\t\t\t   Account is not create due to some issue\n";
												cout << "\n\t\t\t\t   ";
												system("pause");
											}
										}
										else if (put.check_accounts(cinic)==true && c.check_account(cinic)==false) {
											string f;
											cout << "\n\t\t\t\t   This CNIC is registered in Bank as Employee \n";
											cout << "\n\t\t\t\t   For open account on this CNIC press (1) :: ";
											cin >> f;
											if (f == "1") {
												cout << "\n\t\t\t\t   Account is opened on this CNIC \n";
												cout << "\n\t\t\t\t   Information of this CNIC is auto get from employee record \n";
												put.registered_balance_account_of_employee(cinic);
												cout << "\n\t\t\t\t   ";
												system("pause");
												if (c.insert(put.u_name(), put.father_name(), put.d_o_b(), put.contect_u(), put.cnc_u(), put.mail_u()) == true) {
													system("cls");
													a.insert_account_logo();
													cout << "\n\t\t\t\t   Account is created successfully \n";
													++k.user_data;
													c.search_user(cinic);
													cout << "\n\t\t\t\t   ";
													system("pause");
												}
												else {
													cout << "\n\t\t\t\t   Account is not create due to some issue\n";
													cout << "\n\t\t\t\t   ";
													system("pause");
												}
											}
										}
										else {
											cout << "\n\t\t\t\t   Account is already open on this cinic\n";
											cout << "\n\t\t\t\t   ";
											system("pause");
										}
										
									}
									else if (choice == "0") {
										break;
									}
									else {
										system("color 0c");
										cout << "\n\t\t\t\t   Please enter correct choice (0 or 1)\n";
										cout << "\n\t\t\t\t   ";
										system("pause");
									}
								}
							}
							else if (choice == "2") {
								search_u();
							}
							else if (choice == "3") {
								while (true)
								{
									system("cls");
									a.update_account_logo();
									cout << "\n\t\t\t\t   Enter your choice: ";
									cin >> choice;
									if (choice == "1") {
										system("cls");
										a.update_account_logo();
										cout << "\t\t\t\t   Enter id card OR account number : ";
										cin >> cinic;
										if (cinic[0] == '3') {
											if (c.check_account(cinic) && v.valid_cinic(cinic) == true) {
												system("cls");
												a.update_account_logo();
												cout << "\t\t\t\t   Please Enter User details below\n\n";
												entry();
												valid_entry();
												if (c.user_update(name, father, dob, contect, email, cinic)) {
													cout << "\n\t\t\t\t   User account is update successfuly\n";
													cout << "\n\t\t\t\t   ";
													system("pause");
												}
												else {
													cout << "\n\t\t\t\t   User account is not update\n";
													cout << "\n\t\t\t\t   ";
													system("pause");
												}
											}
											else {
												if (v.valid_cinic(cinic) == false) {
													cout << "\n\t\t\t\t   Enter correct CNIC format(xxxxx-xxxxxxx-x)\n";
												}
												else {
													cout << "\t\t\t\t   This User account not found\n";
												}
												cout << "\n\t\t\t\t   ";
												system("pause");
											}
										}
										else if (cinic[0] == 'P' || cinic[0] == 'p' || cinic[1] == 'K' || cinic[1] == 'k') {
											if (c.check_account(cinic) && cinic.length() == 13) {
												system("cls");
												system("cls");
												a.update_account_logo();
												cout << "\t\t\t\t   Please Enter User details below\n\n";
												entry();
												valid_entry();
												if (c.user_update(name, father, dob, contect, email, cinic)) {
													cout << "\n\t\t\t\t   User account is update successfuly\n";
													cout << "\n\t\t\t\t   ";
													system("pause");
												}
												else {
													cout << "\n\t\t\t\t   User account is not update\n";
													cout << "\n\t\t\t\t   ";
													system("pause");
												}
											}
											else {
												if (cinic.length() != 13) {
													cout << "\n\t\t\t\t   Please Enter correct 13 digits account number\n";
												}
												else {
													cout << "\t\t\t\t   This User account not found\n";
												}
												cout << "\n\t\t\t\t   ";
												system("pause");
											}
										}
										else {
											cout << "\n\t\t\t\t   Please Enter proper account number OR CNIC number\n";
											cout << "\n\t\t\t\t   ";
											system("pause");
										}
									}
									else if (choice == "0") {
										break;
									}
									else {
										system("color 0c");
										cout << "\n\t\t\t\t   Please enter correct choice (0 or 1)\n";
										cout << "\n\t\t\t\t   ";
										system("pause");
									}
								}
							}else if(choice=="4"){
								delete_user();
							}
							else if (choice == "5") {
							  system("cls");
							  a.total_account_logo();
							  cout << "\n\n\t\t\t\t     Total User accounts registered   : " << k.user_data << endl;
							  cout << "\n\t\t\t\t     ";
							  system("pause");
							}
							else if (choice == "6") {
							system("cls");
							a.all_account_list();
							if (c.show_list_user() == true) {
								cout << "\n\t\t\t\t     ";
								system("pause");
							}
							else {
								cout << "\n\n\t\t\t\t     No account registered still : " << endl;
								cout << "\n\t\t\t\t     ";
								system("pause");
							}
							}
							else if (choice == "7") {
							      accounts_history();
							}
							else if (choice == "0") {
							  break;
							}
							else {
							  system("color 0c");
							  cout << "\n\t\t\t\t\t   Please enter correct choice\n";
							  cout << "\n\t\t\t\t\t  ";
							  system("pause");
							}
						}
						
					}
					else if (choice == "2") {
					    while (true)
					    {
						  system("cls");
						  a.money_account_logo();
						  cin >> choice;
						  if (choice == "1") {
							  send_money("Bank Transection", " Bank Received", "emp");
						  }
						  else if (choice == "2") {
							  while (true) {
								  system("cls");
								  a.deposit_money_account_logo();
								  cout << "\n\t\t\t\t   Enter your choice: ";
								  cin >> choice;
								  if (choice == "1") {
									  system("cls");
									  string cn;
									  double pric;
									  a.deposit_money_account_logo();
									  cout << "\t\t\t\t   Enter user account number : ";
									  cin >> cn;
									  if (c.check_account(cn) && cn.length()==13) {
										  system("cls");
										  a.deposit_money_account_logo();
										  cout << "\n\t\t\t\t   Account details is: \n";
										  c.deposit_balance_title(cn);
										  cout << "\n\t\t\t\t   Enter your choice: ";
										  cin >> choice;
										  if (choice == "1") {
											  system("cls");
											  a.deposit_money_account_logo();
											  c.deposit_balance_title(cn);
											  cout << "\n\t\t\t\t   Enter amount you want to deposit : ";
											  cin >> pric;
											  if (pric > 0) {
												  c.deposit_balance(cn, pric);
												  total_amount = total_amount + pric;
												  cout << "\n\t\t\t\t   ";
												  system("pause");
											  }
											  else {
												  cout << "\n\t\t\t\t   Amount is not deposit due to invalid amount : ";
												  cout << "\n\t\t\t\t   ";
												  system("pause");
											  }
										  }
									  }
									  else {
										  if (cn.length() !=13) {
											  cout << "\n\t\t\t\t   Please enter correct 13 digits account number \n";
										  }
										  else {
											  cout << "\t\t\t\t   This User account not found\n";
										  }
										  cout << "\n\t\t\t\t   ";
										  system("pause");
									  }
								  }
								  else if (choice == "0") {
									  break;
								  }
								  else {
									  system("color 0c");
									  cout << "\n\t\t\t\t   Please enter correct choice (0 or 1)\n";
									  cout << "\n\t\t\t\t   ";
									  system("pause");
								  }
							  }

						  }
						  else if (choice == "3") {
							  check_balance("emp");
						  }
						  else if (choice == "4") {
							  withdraw_money("emp", "Bank Withdraw");
						  }
						  else if (choice == "0") {
							  break;
						  }
						  else {
							  system("color 0c");
							  cout << "\n\t\t\t\t\t   Please enter correct choice\n";
							  cout << "\n\t\t\t\t\t  ";
							  system("pause");
						  }

					    }
					
					}
					else if (choice == "3") {
					    while (true)
					    {
							system("cls");
							a.atm_account_logo();
							cin >> choice;
							if (choice == "1") {
								while (true) {
									system("cls");
									a.insert_account_logo();
									cout << "\n\t\t\t\t   Enter your choice: ";
									cin >> choice;
									if (choice == "1") {
										system("cls");
										a.insert_account_logo();
										cout << "\t\t\t\t   Enter id card OR Bank account number : ";
										cin >> cinic;
										if (cinic[0] == '3') {
											if (c.check_account(cinic) == true && v.valid_cinic(cinic) == true)
											{
												atm_insertion(cinic);
											}
											else {
												if (v.valid_cinic(cinic) == false) {
													cout << "\n\t\t\t\t   Enter correct CNIC format(xxxxx-xxxxxxx-x)\n";
												}
												else {
													cout << "\n\t\t\t\t   No account is registered on this CNIC number  \n";
												}
												cout << "\n\t\t\t\t   ";
												system("pause");
											}
										}
										else if (cinic[0] == 'p' || cinic[0] == 'P' || cinic[1] == 'k' || cinic[1] == 'K') {
											if (c.check_account(cinic) == true && cinic.length()==13)
											{
												atm_insertion(cinic);
											}
											else {
												if (cinic.length()!=13) {
													cout << "\n\t\t\t\t   Enter correct 13 digits bank account number \n";
												}
												else {
													cout << "\n\t\t\t\t   No account is registered on this account number  \n";
												}
												cout << "\n\t\t\t\t   ";
												system("pause");
											}
										}
										else 
										{
											cout << "\n\t\t\t\t   Please Enter proper account number OR CNIC number\n";
											cout << "\n\t\t\t\t   ";
											system("pause");
										}
									    
									}
									else if (choice == "0") {
										break;
									}
									else {
										system("color 0c");
										cout << "\n\t\t\t\t   Please enter correct choice (0 or 1)\n";
										cout << "\n\t\t\t\t   ";
										system("pause");
									}
								}
							}
							else if (choice == "2") {
							while (true) {
								system("cls");
								a.search_account_logo();
								cout << "\n\t\t\t\t   Enter your choice: ";
								cin >> choice;
								if (choice == "1") {
									system("cls");
									a.search_account_logo();
									cout << "\t\t\t\t   Enter id card OR ATM account number : ";
									cin >> cinic;
									if (cinic[0] == '3') {
										if (c.check_account(cinic)==true && v.valid_cinic(cinic) == true && c.atm_check_account(cinic)==true) {
											system("cls");
											a.search_account_logo();
											cout << "\t\t\t\t  Account data is :: \n";
											c.search_user(cinic);
											cout << "\n\t\t\t\t   ";
											system("pause");
										}
										else {
											if (v.valid_cinic(cinic) == false) {
												cout << "\n\t\t\t\t   Enter correct CNIC format(xxxxx-xxxxxxx-x)\n";
											}
											else if (c.check_account(cinic)==false) {
												cout << "\t\t\t\t   This User account not found in bank record\n";
											}
											else {
												cout << "\t\t\t\t   ATM account is not activate on this CNIC number\n";
											}
											cout << "\n\t\t\t\t   ";
											system("pause");
										}
									}
									else if (cinic[0] == '9' || cinic[1] == '5') {
										if (c.check_account(cinic)==true && cinic.length() == 10 && c.atm_check_account(cinic) == true) {
											system("cls");
											a.search_account_logo();
											cout << "\t\t\t\t  Account data is :: \n";
											c.search_user(cinic);
											cout << "\n\t\t\t\t   ";
											system("pause");
										}
										else {
											if (cinic.length() != 10) {
												cout << "\n\t\t\t\t   Please Enter correct 10 digits ATM account number\n";
											}
											else if (c.check_account(cinic) == false) {
												cout << "\t\t\t\t   This User account not found in bank record\n";
											}
											else {
												cout << "\t\t\t\t   ATM account is not activate on this account number\n";
											}
											cout << "\n\t\t\t\t   ";
											system("pause");
										}
									}
									else {
										cout << "\n\t\t\t\t   Please Enter proper account number OR CNIC number\n";
										cout << "\n\t\t\t\t   ";
										system("pause");
									}
								}
								else if (choice == "0") {
									break;
								}
								else {
									system("color 0c");
									cout << "\n\t\t\t\t   Please enter correct choice (0 or 1)\n";
									cout << "\n\t\t\t\t   ";
									system("pause");
								}
							}

							}
							else if (choice == "3") {
							while (true)
							{
								system("cls");
								a.delete_account_logo();
								cout << "\n\t\t\t\t   Enter your choice: ";
								cin >> choice;
								if (choice == "1") {
									system("cls");
									a.delete_account_logo();
									cout << "\t\t\t\t   Enter id card OR ATM account number : ";
									cin >> cinic;
									if (cinic[0] == '3') {
										if (c.atm_check_account(cinic)==true && c.check_account(cinic)==true && v.valid_cinic(cinic) == true) {
											system("cls");
											a.delete_account_logo();
											if (c.atm_account_delete(cinic)) {
												cout << "\n\t\t\t\t   User ATM account is deleted successfuly\n";
												cout << "\n\t\t\t\t   ";
												system("pause");
												--k.user_data_ATM;
											}
											else {
												cout << "\n\t\t\t\t   User account is not delete\n";
												cout << "\n\t\t\t\t   ";
												system("pause");
											}
										}
										else {
											if (v.valid_cinic(cinic) == false) {
												cout << "\n\t\t\t\t   Enter correct CNIC format(xxxxx-xxxxxxx-x)\n";
											}
											else {
												cout << "\t\t\t\t   This User account not found\n";
											}
											cout << "\n\t\t\t\t   ";
											system("pause");
										}
									}
									else if (cinic[0] == '9' || cinic[1] == '5') {
										if (c.check_account(cinic)==true && cinic.length() == 10 && c.atm_check_account(cinic)==true) {
											system("cls");
											a.delete_account_logo();
											if (c.atm_account_delete(cinic)) {
												cout << "\n\t\t\t\t   User account is deleted successfuly\n";
												cout << "\n\t\t\t\t   ";
												system("pause");
												--k.user_data_ATM;
											}
											else {
												cout << "\n\t\t\t\t   User account is not delete\n";
												cout << "\n\t\t\t\t   ";
												system("pause");
											}
										}
										else {
											if (cinic.length() != 10) {
												cout << "\n\t\t\t\t   Please Enter correct 10 digits ATM account number\n";
											}
											else {
												cout << "\t\t\t\t   This User account not found\n";
											}
											cout << "\n\t\t\t\t   ";
											system("pause");
										}
									}
									else {
										cout << "\n\t\t\t\t   Please Enter proper account number OR CNIC number\n";
										cout << "\n\t\t\t\t   ";
										system("pause");
									}
								}
								else if (choice == "0") {
									break;
								}
								else {
									system("color 0c");
									cout << "\n\t\t\t\t   Please enter correct choice (0 or 1)\n";
									cout << "\n\t\t\t\t   ";
									system("pause");
								}
							  }
							}
							else if (choice == "4") {
							   system("cls");
							   a.total_account_logo();
							   cout << "\n\n\t\t\t\t     Total ATM accounts registered   : " << k.user_data_ATM << endl;
							   cout << "\n\t\t\t\t     ";
							   system("pause");
							}
							else if (choice == "5") {
							   recover_account_atm();
							}
							else if (choice == "0") {
								break;
							}
							else {
								system("color 0c");
								cout << "\n\t\t\t\t\t   Please enter correct choice\n";
								cout << "\n\t\t\t\t\t  ";
								system("pause");
							}
					    }

					}
					else if (choice == "4") {
					  system("cls");
					  a.total_bank_balance_logo();
					  cout << "\n\n\t\t\t\t\t   Total Bank balance present : " <<total_amount << endl;
					  cout << "\n\t\t\t\t\t   ";
					  system("pause");
					}
					else if (choice == "5") {
					while (true)
					{
						system("cls");
						a.recover_account_logo();
						cout << "\n\t\t\t\t   Enter your choice: ";
						cin >> choice;
						if (choice == "1") {
							system("cls");
							a.recover_account_logo();
							cout << "\t\t\t\t   Enter id card format(xxxxx-xxxxxxx-x): ";
							cin >> cinic;
							if (put.check_accounts(cinic) && v.valid_cinic(cinic) == true) {
								if (cinic == log) {
									system("cls");
									a.recover_account_logo();
									string pass;
									char ch;
									int count = 0;
									cout << "\t\t\t\t   Enter Employee account new password: ";
									while (true) {
										ch = _getch();
										if (ch == 13) {
											break;
										}
										else if (ch == '\b') {
											if (pass.length() > 0) {
												pass.pop_back();
												count--;
												system("cls");
												a.recover_account_logo();
												cout << "\t\t\t\t   Enter Employee account new password: ";
												for (int i = 0; i < count; i++) {
													cout << "*";
												}
											}
										}
										else {
											count++;
											pass.push_back(ch);
											system("cls");
											a.recover_account_logo();
											cout << "\t\t\t\t   Enter Employee account new password: ";
											for (int i = 0; i < count; i++) {
												cout << "*";
											}
										}
									}
									if (put.password_change(cinic, pass) == true && pass.length() >= 8) {
										cout << "\n\t\t\t\t   Employee account is password chnage successfuly\n";
										cout << "\n\t\t\t\t   ";
										system("pause");
									}
									else {
										cout << "\n\t\t\t\t   Password digits must be equal or greater then 8\n";
										cout << "\n\t\t\t\t   ";
										system("pause");
									}
								}
								else {
									cout << "\n\t\t\t\t   Please enter CNIC number in which you login\n";
									cout << "\n\t\t\t\t   ";
									system("pause");
								}
							}
							else {
								if (v.valid_cinic(cinic) == false) {
									cout << "\n\t\t\t\t   Please enter correct CNIC format as given \n";
								}
								else {
									cout << "\t\t\t\t   This Employee account not found\n";
								}
								cout << "\n\t\t\t\t   ";
								system("pause");
							}
						}
						else if (choice == "0") {
							break;
						}
						else {
							system("color 0c");
							cout << "\n\t\t\t\t   Please enter correct choice (0 or 1)\n";
							cout << "\n\t\t\t\t   ";
							system("pause");
						}
					}
					}
					else if (choice == "0") {
					    break;
					}
					else {
						system("color 0c");
						cout << "\n\t\t\t\t\t   Please enter correct choice\n";
						cout << "\n\t\t\t\t\t  ";
						system("pause");
					}
				}
				system("cls");
				a.log_out();
			}
			else {
				if (v.valid_cinic(cinic) == false) {
					cout << "\n\t\t\t\t   Please enter correct CNIC format as given \n";
				}
				else {
					system("color 0c");
					cout << "\n\t\t\t\t   Wrong employee id card number OR password\n";
				}
				cout << "\n\t\t\t\t\t  ";
				system("pause");
			}
		}
		else if (choice == "3") {
		system("cls");
		a.user_atm_account_login();
		cout << "\n\t\t\t\t   Enter CNIC OR ATM account number : ";
		cin >> cinic;
		string pass;
		char ch;
		int count = 0;
		cout << "\n\n\t\t\t\t   Enter ATM account Pincode : ";
		while (true) {
			ch = _getch();
			if (ch == 13) {
				break;
			}
			else if (ch == '\b') {
				if (pass.length() > 0) {
					pass.pop_back();
					count--;
					system("cls");
					a.user_atm_account_login();
					cout << "\n\t\t\t\t   Enter CNIC OR ATM account number : " << cinic;
					cout << "\n\n\t\t\t\t   Enter ATM account Pincode: ";
					for (int i = 0; i < count; i++) {
						cout << "*";
					}
				}
			}
			else {
				count++;
				pass.push_back(ch);
				system("cls");
				a.user_atm_account_login();
				cout << "\n\t\t\t\t   Enter CNIC OR ATM account number : " << cinic;
				cout << "\n\n\t\t\t\t   Enter ATM account Pincode: ";
				for (int i = 0; i < count; i++) {
					cout << "*";
				}
			}
		}
		if (cinic[0] == '3') {
			if (c.check_account(cinic)==true && v.valid_cinic(cinic) && pass.length()==4 && c.atm_check_account(cinic) == true && c.atm_check_account_pass(cinic, pass) == true) {
				system("cls");
				a.log_in();
				string aa=c.return_atm_account(cinic);
				atm_user(aa);
				system("cls");
				system("cls");
				a.log_out();
			}
			else {
				if (v.valid_cinic(cinic) == false) {
					cout << "\n\t\t\t\t   Enter correct CNIC format(xxxxx-xxxxxxx-x)\n";
				}
				else if (pass.length() != 4) {
					cout << "\n\t\t\t\t   Enter correct 4 digits Pincode\n";
				}
				else if (c.atm_check_account(cinic) == false) {
					cout << "\t\t\t\t   ATM account is not activate on this CNIC number\n";
				}
				else if (c.atm_check_account_pass(cinic, pass) == false) {
					system("color 0c");
					cout << "\n\t\t\t\t   Wrong User CNIC number OR Pincode\n";
				}
				else {
					cout << "\t\t\t\t   This User account not found in bank record\n";
				}
				cout << "\n\t\t\t\t\t  ";
				system("pause");
			}
		}
		else if (cinic[0] == '9' || cinic[1] == '5') {
			if (c.check_account(cinic) == true  && pass.length() == 4 && cinic.length()==10 && c.atm_check_account_pass(cinic, pass) == true) {
				system("cls");
				a.log_in();
				atm_user(cinic);
				system("cls");
				a.log_out();
			}
			else {
				if (cinic.length()!=10) {
					cout << "\n\t\t\t\t   Enter correct 10 digits ATM account number\n";
				}
				else if (pass.length() != 4) {
					cout << "\n\t\t\t\t   Enter correct 4 digits Pincode\n";
				}
				else if (c.atm_check_account(cinic) == false) {
					cout << "\t\t\t\t   ATM account is not activate on this CNIC number\n";
				}
				else if (c.atm_check_account_pass(cinic, pass) == false) {
					system("color 0c");
					cout << "\n\t\t\t\t   Wrong User CNIC number OR Pincode\n";
				}
				else {
					cout << "\t\t\t\t   This User account not found in bank record\n";
				}
				cout << "\n\t\t\t\t\t  ";
				system("pause");
			}
		}
		else {
			cout << "\n\t\t\t\t   Please Enter proper account number OR CNIC number\n";
			cout << "\n\t\t\t\t   ";
			system("pause");
		}
		}
		else {
			system("color 0c");
			cout << "\n\t\t\t\t\t   Please enter correct choice\n";
			cout << "\n\t\t\t\t\t  ";
			system("pause");
		}
	}
	system("pause");
}