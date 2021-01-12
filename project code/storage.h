#include"libraries.h"
class account_storage {
public:
    string name;
    string father;
    string dob;
    string contect;
    string acc_num;
    string date;
    string trans;
    string atm_acc;
    string atm_date;
    string atm_pass;
    string tim;
    string history;
    string pasword;
    string cinic;
    string email;
    string type;
    double price;
    account_storage* next;
};
class admin_account_pass {
public:
    string username = "amirghafoor";
    string pass = "12345678";
    string admin_id = "12345-1234567-9";
    int data = 0;
    int user_data = 0;
    int user_data_ATM = 0;
};