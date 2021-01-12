#include"libraries.h"
#include"storage.h"
#include"acc_num_time_date.h"
string nam, fathr, db, cntct, cnc, emil;
class create {
private:
    account_storage* head, * tail;
    date_time tt;
    string deposit = "Deposit";
public:
    create() {
        head = NULL;
        tail = NULL;
    }
    bool insert(string name, string father, string dob, string contect, string cnic, string email) {
        account_storage* temp = new account_storage();
        account_storage* ptr = head;
        temp->name = name;
        temp->father = father;
        temp->dob = dob;
        temp->contect = contect;
        temp->email = email;
        temp->atm_acc = "null";
        temp->atm_date = "null";
        temp->date = tt.current_date();
        temp->acc_num = tt.auto_account_number();
        temp->price = 0;
        temp->cinic = cnic;
        temp->next = NULL;
        if (head == NULL) {
            head = temp;
            tail = temp;
            return true;
        }
        else {
            tail->next = temp;
            tail = temp;
            return true;
        }
        return false;
    }
    bool check_account(string cnic) {
        account_storage* temp = NULL;
        temp = head;
        while (temp != NULL) {
            if (temp->cinic == cnic || temp->acc_num==cnic || temp->atm_acc==cnic) {
                    return true;
                    break;
            }
            temp = temp->next;
        }
        return false;
    }
    string return_atm_account(string cnic) {
        account_storage* temp = NULL;
        string a;
        temp = head;
        while (temp != NULL) {
            if (temp->cinic == cnic) {
                a = temp->atm_acc;
                break;
            }
            temp = temp->next;
        }
        return a;
    }
    bool user_update(string name, string father, string dob, string contect, string email, string cnic) {
        account_storage* ptr = NULL;
        ptr = head;
        while (ptr != NULL) {
            if (ptr->cinic == cnic || ptr->acc_num == cnic) {
                ptr->name = name;
                ptr->father = father;
                ptr->dob = dob;
                ptr->contect = contect;
                ptr->email = email;
                return true;
                break;
            }
            ptr = ptr->next;
        }
        return false;
    }
    bool atm_insert(string acc, string pass ) {
        account_storage* ptr = head;
        while (ptr != NULL) {
            if (ptr->acc_num == acc || ptr->cinic == acc) {
                ptr->atm_acc = tt.auto_atm_account_number();
                ptr->atm_date = tt.current_date();
                ptr->atm_pass = pass;
                return true;
                break;
            }
            ptr = ptr->next;
        }
        return false;
    }
    bool atm_check_account(string acc) {
        account_storage* ptr = head;
        while (ptr != NULL) {
            if (ptr->cinic == acc || ptr->atm_acc==acc || ptr->acc_num==acc) {
                if (ptr->atm_acc != "null") {
                    return true;
                    break;
                }
            }
            ptr=ptr->next;
        }
        return false;
    }
    bool atm_check_account_pass(string acc,string pass) {
        account_storage* ptr = head;
        while (ptr != NULL) {
            if (ptr->cinic == acc || ptr->atm_acc == acc) {
                if (ptr->atm_pass==pass) {
                    return true;
                    break;
                }
            }
            ptr = ptr->next;
        }
        return false;
    }
    bool atm_account_delete(string acc) {
        account_storage* ptr = head;
        while (ptr != NULL) {
            if (ptr->cinic == acc || ptr->atm_acc == acc) {
                ptr->atm_acc = "null";
                ptr->atm_pass = "null";
                return true;
                break;
            }
            ptr = ptr->next;
        }
        return false;
    }
    bool atm_account_pass_change(string acc, string pass) {
        account_storage* ptr = head;
        while (ptr != NULL) {
            if (ptr->atm_acc == acc) {
                ptr->atm_pass = pass;
                return true;
                break;
            }
            ptr = ptr->next;
        }
        return false;
    }
    void check_balance(string cinc, string type) {
        account_storage* ptr = head;
        while (ptr != NULL) {
            if (ptr->cinic == cinc || ptr->acc_num == cinc || ptr->atm_acc==cinc) {
                cout << "\n\t\t\t\t  **************************************";
                cout << "\n\t\t\t\t  *            Account Detail          *";
                cout << "\n\t\t\t\t  **************************************";
                cout << "\n\t\t\t\t  *  Current Balance: " << ptr->price;
                cout << "\n\t\t\t\t  *  Account title  : " << ptr->name;
                if (type == "ATM") {
                  cout << "\n\t\t\t\t  *  ATM Account    : " << ptr->atm_acc;
                }
                cout << "\n\t\t\t\t  *  Bank Account   : " << ptr->acc_num;
                cout << "\n\t\t\t\t  **************************************\n";
                break;
            }
            ptr = ptr->next;
        }
    }
    bool show_list_user() {
        account_storage* ptr = head;
        int i = 1;
        if (head == NULL) {
            return false;
        }
        else {
            cout << "\n\t\t\t\t     All Accounts list is  : " << endl;
            while (ptr != NULL) {
                cout << "\n\t\t\t\t  **************************************";
                cout << "\n\t\t\t\t  *            Account " << i;
                cout << "\n\t\t\t\t  **************************************";
                cout << "\n\t\t\t\t  *  User name      : " << ptr->name;
                cout << "\n\t\t\t\t  *  CNIC number    : " << ptr->cinic;
                if (ptr->atm_acc != "null") {
                    cout << "\n\t\t\t\t  *  ATM Account    : " << ptr->atm_acc;
                }
                cout << "\n\t\t\t\t  *  Bank Account   : " << ptr->acc_num;
                cout << "\n\t\t\t\t  **************************************";
                i++;
                ptr = ptr->next;
            }
            return true;
        }
    }
    void deposit_balance_title(string cinc) {
        account_storage* ptr = head;
        while (ptr != NULL) {
            if (ptr->cinic == cinc || ptr->acc_num == cinc) {
                cout << "\n\t\t\t\t  **********************************************";
                cout << "\n\t\t\t\t  *               Account Detail               *";
                cout << "\n\t\t\t\t  **********************************************";
                cout << "\n\t\t\t\t  *  Account title  : " << ptr->name;
                cout << "\n\t\t\t\t  *  Account Number : " << ptr->acc_num;
                cout << "\n\t\t\t\t  **********************************************";
                cout << "\n\t\t\t\t  * Press (1) for deposit | Press (0) for back *";
                cout << "\n\t\t\t\t  **********************************************\n";
                break;
            }
            ptr = ptr->next;
        }
    }
    void deposit_balance(string cinc, double p) {
        account_storage* ptr = head;
        while (ptr != NULL) {
            if (ptr->cinic == cinc || ptr->acc_num == cinc) {
                ptr->price = ptr->price+p;
                cout << "\n\t\t\t\t   Amount (" << p << ") is deposit successfully\n";
                string fill;
                ostringstream con;
                con << p;
                string rup = con.str();
                string title = ptr->name;
                string account = ptr->acc_num;
                string date = tt.current_date();
                string tims = tt.current_time();
                fill += "\n\t\t\t\t  ****************************************\n\t\t\t\t  *               " + deposit + "                *\n\t\t\t\t  ****************************************";
                fill += "\n\t\t\t\t  *  Account title  : " + title;
                fill += "\n\t\t\t\t  *  Account number : " + account;
                fill += "\n\t\t\t\t  *  Amount deposit : " + rup;
                fill += "\n\t\t\t\t  *  Time           : " + tims;
                fill += "\n\t\t\t\t  *  Date           : " + date;
                fill += "\n\t\t\t\t  ****************************************";
                ptr->history += fill;
                break;
            }
            ptr = ptr->next;
        }
    }
    bool withdraw_balance(string cinc, double p,string withdraw) {
        account_storage* ptr = head;
         while (ptr != NULL) {
            if (ptr->cinic == cinc || ptr->acc_num == cinc || ptr->atm_acc==cinc) {
                if (ptr->price >= p) {
                    ptr->price = ptr->price - p;
                    cout << "\n\t\t\t\t   Amount (" << p << ") is withdraw successfully\n";
                    string fill,atm;
                    ostringstream con;
                    con << p;
                    string rup = con.str();
                    string title = ptr->name;
                    atm = ptr->atm_acc;
                    string account = ptr->acc_num;
                    string date = tt.current_date();
                    string tims = tt.current_time();
                    fill += "\n\t\t\t\t  ****************************************\n\t\t\t\t  *             " + withdraw + "               \n\t\t\t\t  ****************************************";
                    fill += "\n\t\t\t\t  *  Account title   : " + title;
                    if (withdraw == "ATM Withdraw") {
                    fill += "\n\t\t\t\t  *  Bank Account    : " + account;
                    fill += "\n\t\t\t\t  *  ATM Account     : " + atm;
                    }
                    else {
                    fill += "\n\t\t\t\t  *  Bank account    : " + account;
                    }
                    fill += "\n\t\t\t\t  *  Withdraw amount : " + rup;
                    fill += "\n\t\t\t\t  *  Time            : " + tims;
                    fill += "\n\t\t\t\t  *  Date            : " + date;
                    fill += "\n\t\t\t\t  ****************************************";
                    ptr->history += fill;
                    return true;
                }
                break;
            }
            ptr = ptr->next;
         }
         return false;
    }
    void search_user (string cinic) {
        account_storage* ptr = NULL;
        ptr = head;
        while (ptr != NULL) {
            if (ptr->cinic == cinic || ptr->acc_num == cinic || ptr->atm_acc==cinic) {
                    cout << "\n\t\t\t\t  ************************************************";
                    cout << "\n\t\t\t\t  *              Account Profile                 *";
                    cout << "\n\t\t\t\t  ************************************************";
                    cout << "\n\t\t\t\t  *   Name          : " << ptr->name;
                    cout << "\n\t\t\t\t  *   Father name   : " << ptr->father;
                    cout << "\n\t\t\t\t  *   Contect number: " << ptr->contect;
                    cout << "\n\t\t\t\t  *   Id card number: " << ptr->cinic;
                    cout << "\n\t\t\t\t  *   Email account : " << ptr->email;
                    cout << "\n\t\t\t\t  ************************************************";
                    cout << "\n\t\t\t\t  *   Account Title : " << ptr->name;
                    if (ptr->atm_acc != "null") {
                       cout << "\n\t\t\t\t  *   ATM Account   : " << ptr->atm_acc;
                    }
                    cout << "\n\t\t\t\t  *   Bank Account  : " << ptr->acc_num;
                    cout << "\n\t\t\t\t  ************************************************";
                    cout << "\n\t\t\t\t  *   Date Format(dd/mm/yyyy): ";
                    cout << "\n\t\t\t\t  *   Date of birth             : " << ptr->dob;
                    cout << "\n\t\t\t\t  *   Bank account register date: " << ptr->date;
                    if (ptr->atm_acc != "null") {
                        cout << "\n\t\t\t\t  *   ATM account register date : " << ptr->atm_date;
                    }
                    cout << "\n\t\t\t\t  ************************************************";
                    break;
                
            }
            ptr = ptr->next;
        }
    }
    bool delete_account(string cnc) {
        account_storage* ptr = NULL;
        account_storage* del = NULL;
        account_storage* dl = NULL;
        dl = head;
        ptr = head;
        string cnic = cnc;
        if (cnic[0] == 'P' && cnic[1] == 'K') {
            while (dl != NULL) {
                if (cnc == dl->acc_num) {
                    cnic = dl->cinic;
                    break;
                }
                dl = dl->next;
            }
        }
        if (head->cinic == cnic) {
            if (head->next == NULL) {
                head = NULL;
                tail = NULL;
                delete(ptr);
                return true;
            }
            else {
                head = ptr->next;
                delete(ptr);
                return true;
            }
        }
        else {
            while (ptr != NULL && ptr->cinic != cnic) {
                del = ptr;
                ptr = ptr->next;
            }
            if (tail->cinic == cnic) {
                tail = del;
                delete(ptr);
                tail->next = NULL;
                return true;
            }
            else {
                del->next = ptr->next;
                delete(ptr);
                return true;
            }
            return false;
        }
    }
    double amount_delete(string acc) {
        account_storage* temp = NULL;
        double p=0;
        temp = head;
        while (temp != NULL) {
            if (temp->acc_num == acc || temp->cinic == acc) {
                p = temp->price;
                break;
            }
            temp = temp->next;
        }
        return p;
    }
    bool transfer_from_account(string acc, double pric) {
        account_storage* temp = NULL;
        temp = head;
        while (temp != NULL) {
            if (temp->acc_num == acc || temp->atm_acc==acc) {
                if (temp->price >= pric) {
                    temp->price = temp->price - pric;
                    temp->trans = tt.current_date();
                    temp->tim = tt.current_time();
                    return true;
                    break;
                }
            }
            temp = temp->next;
        }
        return false;
    }
    bool transfer_to_account(string acc, double price) {
        account_storage* temp = NULL;
        temp = head;
        while (temp != NULL) {
            if (temp->acc_num == acc || temp->atm_acc==acc) {
                temp->price = temp->price + price;
                temp->trans = tt.current_date();
                temp->tim = tt.current_time();
                return true;
                break;
            }
            temp = temp->next;
        }
        return false;
    }
    void show_templet(string acc1, string acc2, string type) {
        account_storage* temp = NULL;
        temp = head;
        while (temp != NULL) {
            if (temp->acc_num == acc1 || temp->atm_acc==acc1) {
                cout << "\n\t\t\t\t  **********************************************";
                cout << "\n\t\t\t\t  *           Sender Account Detail            *";
                cout << "\n\t\t\t\t  **********************************************";
                cout << "\n\t\t\t\t  *  Account title  : " << temp->name;
                if (type == "ATM") {
                    cout << "\n\t\t\t\t  *  ATM Account    : " << temp->atm_acc;
                }
                cout << "\n\t\t\t\t  *  Bank Account   : " << temp->acc_num;
                cout << "\n\t\t\t\t  **********************************************";
                break;
            }
            temp = temp->next;
        }
        temp = head;
        while (temp != NULL) {
            if (temp->acc_num == acc2 || temp->atm_acc==acc2) {
                cout << "\n\t\t\t\t  **********************************************";
                cout << "\n\t\t\t\t  *           Receiver Account Detail          *";
                cout << "\n\t\t\t\t  **********************************************";
                cout << "\n\t\t\t\t  *  Account title  : " << temp->name;
                if (type == "ATM") {
                    cout << "\n\t\t\t\t  *  ATM Account    : " << temp->atm_acc;
                }
                cout << "\n\t\t\t\t  *  Account Number : " << temp->acc_num;
                cout << "\n\t\t\t\t  **********************************************";
                cout << "\n\t\t\t\t  * Press (1) for transfer | Press (0) for back*";
                cout << "\n\t\t\t\t  **********************************************\n";
                break;
            }
            temp = temp->next;
        }
    }
    void transection_record(string acc1, string acc2 ,double p, string sent,string received, string type) {
        account_storage* temp = NULL;
        account_storage* temp1 = NULL;
        account_storage* temp2 = NULL;
        account_storage* tmp = NULL;
        temp = head;
        tmp = head;
        double pp = p;
        while (temp != NULL) {
            if (temp->acc_num == acc1 || temp->atm_acc==acc1) {
                cout << "\n\t\t\t\t  ************************************************";
                cout << "\n\t\t\t\t  *              Transection history             *";
                cout << "\n\t\t\t\t  ************************************************";
                cout << "\n\t\t\t\t  *  Sender account title   : " << temp->name;
                if (type == "ATM") {
                cout << "\n\t\t\t\t  *  Sender ATM account     : " << temp->atm_acc;
                }
                cout << "\n\t\t\t\t  *  Sender Bank account    : " << temp->acc_num;
                temp1 = temp;
                break;
            }
            temp = temp->next;
        }
        while (tmp != NULL) {
            if (tmp->acc_num == acc2 || tmp->atm_acc==acc2) {
                cout << "\n\t\t\t\t  *  Receiver account title : " << tmp->name;
                if (type == "ATM") {
                cout << "\n\t\t\t\t  *  Receiver ATM  account  : " << tmp->atm_acc;
                }
                cout << "\n\t\t\t\t  *  Receiver Bank account  : " << tmp->acc_num;
                cout << "\n\t\t\t\t  *  Transection amount     : " << pp;
                cout << "\n\t\t\t\t  *  Date of transection    : " << tmp->trans;
                cout << "\n\t\t\t\t  *  Time of transection    : " << tmp->tim;
                cout << "\n\t\t\t\t  ************************************************\n";
                temp2 = tmp;
                break;
            }
            tmp = tmp->next;
        }
        string fill;
        string full;
        ostringstream con;
        con << pp;
        string rup = con.str();
        string title = temp2->name;
        string account = temp2->acc_num;
        string accc = temp2->atm_acc;
        string date = temp2->trans;
        string tims = temp2->tim;
        fill += "\n\t\t\t\t  ****************************************\n\t\t\t\t  *              " + sent + "            \n\t\t\t\t  ****************************************";
        fill += "\n\t\t\t\t  *  Receiver name  : " + title;
        if (sent == "ATM Transection") {
        fill += "\n\t\t\t\t  *  Bank account   : " + account;
        fill += "\n\t\t\t\t  *  ATM Account    : " + accc;
        }
        else {
        fill += "\n\t\t\t\t  *  Bank Account   : " + account;
        }
        fill += "\n\t\t\t\t  *  Time           : " + tims;
        fill += "\n\t\t\t\t  *  Date           : " + date;
        fill += "\n\t\t\t\t  *  Amount         : " + rup;
        fill += "\n\t\t\t\t  ****************************************";
        string ttle = temp1->name;
        string accunt = temp1->acc_num;
        string accnt = temp1->atm_acc;
        string dte = temp1->trans;
        string tms = temp1->tim;
        full += "\n\t\t\t\t  ****************************************\n\t\t\t\t  *              " + received + "              \n\t\t\t\t  ****************************************";
        full += "\n\t\t\t\t  *  Sender name    : " + ttle;
        if (received == "ATM Received") {
        full += "\n\t\t\t\t  *  Bank account   : " + accunt;
        full += "\n\t\t\t\t  *  ATM account    : " + accnt;
        }
        else {
        full += "\n\t\t\t\t  *  Bank account   : " + accunt;
        }
        full += "\n\t\t\t\t  *  Time           : " + tms;
        full += "\n\t\t\t\t  *  Date           : " + dte;
        full += "\n\t\t\t\t  *  Amount         : " + rup;
        full += "\n\t\t\t\t  ****************************************";
        temp2->history +=full;
        temp1->history +=fill;
    }
    bool show_history(string acc) {
         account_storage* temp = NULL;
         temp = head;
          while (temp != NULL) {
            if (temp->acc_num == acc) {
                if(temp->history==""){
                    return false;
                    break;
                }
                else {
                    cout << temp->history;
                    return true;
                    break;
                }
            }
            temp = temp->next;
          }
          return false;
    }
};
class employee {
    account_storage* head, * tail;
    date_time tt;
    create g;
public:
    employee() {
        head = NULL;
        tail = NULL;
    }
    void registered_balance_account_of_employee(string cinic) {
        account_storage* temp = NULL;
        temp = head;
        while (temp != NULL) {
            if (temp->cinic == cinic) {
                nam = temp->name;
                fathr = temp->father;
                db = temp->dob;
                cntct = temp->contect;
                cnc = temp->cinic;
                emil = temp->email;
                break;
            }
            temp = temp->next;
        }
    }
    string u_name() {
        return nam;
    }
    string father_name() {
        return fathr;
    }
    string d_o_b() {
        return db;
    }
    string contect_u() {
        return cntct;
    }
    string cnc_u() {
        return cnc;
    }
    string mail_u() {
        return emil;
    }
    bool insert(string name, string father, string dob, string contect, string pasword, string cnic, string email) {
        account_storage* temp = new account_storage();
        account_storage* ptr = head;
        temp->name = name;
        temp->father = father;
        temp->dob = dob;
        temp->contect = contect;
        temp->email = email;
        temp->pasword = pasword;
        temp->date = tt.current_date();
        temp->cinic = cnic;
        temp->next = NULL;
        if (head == NULL) {
            head = temp;
            tail = temp;
            return true;
        }
        else {
            tail->next = temp;
            tail = temp;
            return true;
        }
        return false;
    }
    bool user_update(string name, string father, string dob, string contect, string email, string cnic) {
        account_storage* ptr = NULL;
        ptr = head;
        while (ptr != NULL) {
            if (ptr->cinic == cnic) {
                ptr->name = name;
                ptr->father = father;
                ptr->dob = dob;
                ptr->contect = contect;
                ptr->email = email;
                return true;
            }
            ptr = ptr->next;
        }
        return false;
    }
    void search(string cinic) {
        account_storage* ptr = NULL;
        ptr = head;
        while (ptr != NULL) {
            if (ptr->cinic == cinic) {
                cout << "\n\t\t\t\t  ************************************************";
                cout << "\n\t\t\t\t  *         Employee Account Profile             *";
                cout << "\n\t\t\t\t  ************************************************";
                cout << "\n\t\t\t\t  *   Name          : " << ptr->name;
                cout << "\n\t\t\t\t  *   Father name   : " << ptr->father;
                cout << "\n\t\t\t\t  *   Contect number: " << ptr->contect;
                cout << "\n\t\t\t\t  *   Id card number: " << ptr->cinic;
                cout << "\n\t\t\t\t  *   Email account : " << ptr->email;
                cout << "\n\t\t\t\t  ************************************************";
                cout << "\n\t\t\t\t  *   Date Format(dd/mm/yyyy): ";
                cout << "\n\t\t\t\t  *   Date of birth :     " << ptr->dob;
                cout << "\n\t\t\t\t  *   Registeration date: " << ptr->date;
                cout << "\n\t\t\t\t  ************************************************\n";
                break;
            }
            ptr = ptr->next;
        }
    }
    bool delete_account(string cnic) {
        account_storage* ptr = NULL;
        account_storage* del = NULL;
        ptr = head;
        if (head->cinic == cnic) {
            if (head->next == NULL) {
                head = NULL;
                tail = NULL;
                delete(ptr);
                return true;
            }
            else {
                head = ptr->next;
                delete(ptr);
                return true;
            }
        }
        else {
            while (ptr != NULL && ptr->cinic != cnic) {
                del = ptr;
                ptr = ptr->next;
            }
            if (tail->cinic == cnic) {
                tail = del;
                delete(ptr);
                tail->next = NULL;
                return true;
            }
            else {
                del->next = ptr->next;
                delete(ptr);
                return true;
            }
            return false;
        }
    }
    bool password_change(string cinc, string nw) {
        account_storage* ptr = head;
        while (ptr != NULL) {
            if (ptr->cinic == cinc) {
                ptr->pasword = nw;
                return true;
            }
            ptr = ptr->next;
        }
        return false;
    }
    bool check_accounts(string cnic) {
        account_storage* temp = NULL;
        temp = head;
        while (temp != NULL) {
            if (temp->cinic == cnic) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
    bool check_account_pass(string pass) {
        account_storage* temp = NULL;
        temp = head;
        while (temp != NULL) {
            if (temp->pasword == pass) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
};
