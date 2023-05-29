#include <iostream>
#include <cstring>
using namespace std;

class FDAccount {
private:
    char account[30]{};
    char acname[30]{};
    float balance;
    int due;
    float rate;

public:
    FDAccount(char* _acc, char* _acn, float _bal, int _due, float _rate);
    void withdrawl(float amount);
    void deposit(float amount);
    void bal_show();
    void info_show();
};

FDAccount::FDAccount(char *_acc, char *_acn, float _bal, int _due, float _rate) {
    strcpy(account, _acc);
    strcpy(acname, _acn);
    balance = _bal;
    due = _due;
    rate = _rate;
}

void FDAccount::withdrawl(float amount) {
    balance -= amount;
}

void FDAccount::deposit(float amount) {
    balance += amount;
}

void FDAccount::bal_show() {
    cout << "账号: " << acname
         << " (" << account << ")" << endl;
    cout << "余额: " << balance << endl;
}

void FDAccount::info_show() {
    cout << "账号: " << acname
         << " (" << account << ")" << endl;
    cout << "余额: " << balance << endl;
    cout << "期限: " << due << "月" << endl;
    cout << "利率: " << rate * 100 << "%" << endl;
    cout << "利息: " << balance * rate << endl;
}

char help_text[] = "1. 存款\n"
                   "2. 取款\n"
                   "3. 余额\n"
                   "4. 信息\n"
                   "5. 退出\n";

int main() {
    char acc[30], acname[30];
    float balance, rate, amount;
    int due;
    cout << "账号 账户名 余额 期限 利率%" << endl;
    cin >> acc >> acname >> balance >> due >> rate;
    FDAccount account = FDAccount(acc, acname, balance, due, rate / 100);

    char op = 0;
    while (op != '5') {
        cout << help_text;
        cout << "操作: ";
        cin >> op;
        switch (op) {
            case '1':
                cout << "金额: ";
                cin >> amount;
                account.deposit(amount);
                break;

            case '2':
                cout << "金额: ";
                cin >> amount;
                account.withdrawl(amount);
                break;

            case '3':
                account.bal_show();
                break;

            case '4':
                account.info_show();
                break;

            case '5':
                continue;

            default:
                cout << "未知操作！请重新输入" << endl;
        }
    }
}
