#include <bits/stdc++.h>
using namespace std;
#include <fstream>

long long getSize(const string& filename) {
    ifstream in(filename, ios::binary | ios::ate);
    return in.tellg();
}
int main() {
    int t = 0;
    while (true) {
        cout << "test：" << t++ << endl;

        system("data.exe > data.in");
        system("std.exe < data.in > std.out");
        system("solve.exe < data.in > solve.out");

        long long s1 = getSize("std.out");
        long long s2 = getSize("solve.out");

        if (s1 != s2) {
            cout << "WA (length diff)\n";
            break;
        }

        cout << "AC\n";
    }
}