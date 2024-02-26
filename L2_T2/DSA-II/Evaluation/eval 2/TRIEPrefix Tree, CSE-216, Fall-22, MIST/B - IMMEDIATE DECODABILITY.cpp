/*
An encoding of a set of symbols is said to be immediately decodable if no code for one symbol is the prefix of a code for another symbol. We will assume for this problem that all codes are in binary, that no two codes within a set of codes are the same, that each code has at least one bit and no more than ten bits, and that each set has at least two codes and no more than eight.

Examples: Assume an alphabet that has symbols {A, B, C, D}

The following code is immediately decodable:
A:01 B:10 C:0010 D:0000

but this one is not:
A:01 B:10 C:010 D:0000 (Note that A is a prefix of C)
Input
Write a program that accepts as input a series of groups of records from standard input. Each record in a group contains a collection of zeroes and ones representing a binary code for a different symbol. Each group is followed by a single separator record containing a single 9; the separator records are not part of the group. Each group is independent of other groups; the codes in one group are not related to codes in any other group (that is, each group is to be processed independently).
Output
For each group, your program should determine whether the codes in that group are immediately decodable, and should print a single output line giving the group number and stating whether the group is, or is not, immediately decodable.
Sample
Inputcopy	Outputcopy
01
10
0010
0000
9
01
10
010
0000
9
Set 1 is immediately decodable
Set 2 is not immediately decodable
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int setNumber = 1;
    while (true) {
        vector<string> codes;
        string code;

        while (cin >> code) {
            if (code == "9") {
                break;
            }
            codes.push_back(code);
        }

        if (codes.empty()) {
            break;
        }

        bool decodable = true;

        for (int i = 0; i < codes.size() - 1; i++) {
            for (int j = i + 1; j < codes.size(); j++) {
                if (codes[i] == codes[j].substr(0, codes[i].length()) || codes[j] == codes[i].substr(0, codes[j].length())) {
                    decodable = false;
                    break;
                }
            }
            if (!decodable) {
                break;
            }
        }

        cout << "Set " << setNumber << " is " << (decodable ? "immediately decodable" : "not immediately decodable") << endl;
        setNumber++;
    }

    return 0;
}
