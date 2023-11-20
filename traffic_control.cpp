#include <bits/stdc++.h>
#include <thread>
using namespace std;

void sleepSeconds(int seconds) {
    this_thread::sleep_for(chrono::seconds(seconds));
}

int main() {
    start:
    for (int i = 6; i >= 0; i--) {
        system("cls");
        cout << " ---------" << endl;
        cout << " | Stop! |" << endl;
        cout << " ---------" << endl;
        cout << "     " << i;

        if (i == 1) {
            system("cls");
            cout << " --------------" << endl;
            cout << " | Get Ready! |" << endl;
            cout << " --------------" << endl;
            i--;
        }

        sleepSeconds(1);
    }

    for (int i = 6; i >= 0; i--) {
        system("cls");
        cout << " -------" << endl;
        cout << " | Go! |" << endl;
        cout << " -------" << endl;
        cout << "    " << i;

        sleepSeconds(1);
    }

    goto start;

    return 0;
}
