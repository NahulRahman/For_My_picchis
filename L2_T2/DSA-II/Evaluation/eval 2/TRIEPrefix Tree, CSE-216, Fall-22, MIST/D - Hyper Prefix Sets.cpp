#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool isPrefix(const string& s1, const string& s2) {
    return s1.size() <= s2.size() && s1 == s2.substr(0, s1.size());
}

int main() {
    int t;
    cin >> t;

    for (int test = 1; test <= t; test++) {
        int n;
        cin >> n;
        vector<string> binaryStrings(n);
        bool isConsistent = true;

        for (int i = 0; i < n; i++) {
            cin >> binaryStrings[i];
        }

        sort(binaryStrings.begin(), binaryStrings.end());

        for (int i = 0; i < n - 1; i++) {
            if (isPrefix(binaryStrings[i], binaryStrings[i + 1])) {
                isConsistent = false;
                break;
            }
        }

        cout << "Set " << test << " is " << (isConsistent ? "immediately decodable" : "not immediately decodable") << endl;
    }

    return 0;
}
