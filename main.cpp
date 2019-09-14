#include <iostream>
#include <functional>

#include <windows.h>
#include <odbcinst.h>

void dsn_handler() {
    using namespace std;
    HWND hwndParent = nullptr;
    WORD fRequest;
    string lpszDriver;
    string lpszAttributes;

    function<void(void)> parse_lpszAttr = [&]() {
        if (cin.peek()) cin.ignore();
        string str;
        vector<string> args = {
                "DSN=",
                "UID=",
                "PWD=",
                "DATABASE="
        };
        for (auto &s: args) {
            cout << s;
            getline(cin, str);
            if (str.length()) {
                s += str + '\0';
                lpszAttributes += s;
            }
        }
        lpszAttributes += '\0';
    };

    WORD reqs[] = {
            ODBC_ADD_DSN,
            ODBC_CONFIG_DSN,
            ODBC_REMOVE_DSN
    };

    while (true) {
        cout << "1. Добавить новый источник данных\n"
             << "2. Изменить существующий источник данных\n"
             << "3. Удалить источник данных\n"
             << "0. Выход\n";
        int ans;
        cin >> ans;
        if (0 == ans) return;
        fRequest = reqs[ans - 1];
        parse_lpszAttr();
        cout << lpszAttributes.length() << '\n';
        for (char &ch: lpszAttributes) {
            if (ch == '\0') cout << "\\0";
            else cout << ch;
        }
        cout << '\n';

    }
}

int main() {
    setlocale(LC_ALL, "");
    dsn_handler();
    return 0;
}