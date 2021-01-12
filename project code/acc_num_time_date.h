#include"libraries.h"
class date_time {
public:
    string current_date() {
        SYSTEMTIME time;
        GetLocalTime(&time);
        string d = "", m = "", y = "";
        string dat = "";
        int a = time.wDay;
        int b = time.wMonth;
        int c = time.wYear;
        stringstream s;
        s << a;
        s >> d;
        stringstream s1;
        s1 << b;
        s1 >> m;
        stringstream s2;
        s2 << c;
        s2 >> y;
        dat += d + "/" + m + "/" + y;
        return dat;
    }
    string current_time() {
        SYSTEMTIME time;
        GetLocalTime(&time);
        string s = "", m = "", h = "";
        string dat = "";
        int a = time.wSecond;
        int b = time.wMinute;
        int c = time.wHour;
        stringstream s0;
        s0 << a;
        s0 >> s;
        stringstream s1;
        s1 << b;
        s1 >> m;
        stringstream s2;
        s2 << c;
        s2 >> h;
        dat += h + ":" + m + ":" + s;
        return dat;
    }
    string auto_account_number()
    {
        static int n = 100;
        ++n;
        string code = "PK95022710";
        ostringstream con;
        con << n;
        string account = code + con.str();
        return account;
    }
    string auto_atm_account_number()
    {
        static int n = 10;
        ++n;
        string code = "95024710";
        ostringstream con;
        con << n;
        string account = code + con.str();
        return account;
    }
};
