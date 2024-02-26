
/*inputs:
1 MIST
1 MIT
1 CSE
1 CSE
1 CE
1 MISTCSE
1 ME
1 EECE
1 ABC
1 ABC
1 AB
*/

/*
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int EoW;
    Node* children[26];
    Node() {
        EoW = 0;
        for (int i = 0; i < 26; i++) {
            this->children[i] = NULL;
        }
    }
};

void trie_insert(Node* root, string s) {
    Node* current = root;
    for (char c : s) {
        int index = c - 'A'; // Assuming uppercase letters only
        if (!current->children[index]) {
            current->children[index] = new Node();
        }
        current = current->children[index];
    }
    current->EoW++;
}

int trie_search(Node* root, string s, int k = 0) {
    Node* current = root;
    for (char c : s) {
        int index = c - 'A'; // Assuming uppercase letters only
        if (!current->children[index]) {
            return 0; // Not found
        }
        current = current->children[index];
    }
    return current->EoW;
}

bool trie_delete(Node* root, string s, int idx = 0) {
    if (!root) return false;

    if (idx == s.length()) {
        if (root->EoW > 0) {
            root->EoW--;
            return true;
        }
        return false;
    }

    int index = s[idx] - 'A'; // Assuming uppercase letters only
    if (!root->children[index]) {
        return false; // Word not found
    }

    bool canDelete = trie_delete(root->children[index], s, idx + 1);

    if (canDelete && root->children[index]->EoW == 0) {
        delete root->children[index];
        root->children[index] = nullptr;
    }

    return canDelete;
}

void printTRIEUtil(Node* root, string s) {
    if (root->EoW > 0) {
        cout << s << " (" << root->EoW << ")" << endl;
    }
    for (int i = 0; i < 26; i++) {
        if (root->children[i]) {
            char c = i + 'A'; // Assuming uppercase letters only
            printTRIEUtil(root->children[i], s + c);
        }
    }
}

void printTRIE(Node* root, string s = "") {
    printTRIEUtil(root, s);
}

int main() {
    Node* root = new Node();

    while (1) {
        cout << "1. Insert    2. Search    3. Delete   4. Lexicographical Sorting  5. Display Strings  6. End"
             << endl
             << endl;
        int choice;
        string x;
        cin >> choice;
        if (choice == 1) {
            cout << "Insert String: ";
            cin >> x;
            trie_insert(root, x);
            cout << x << " is inserted in the trie" << endl;
        } else if (choice == 2) {
            cout << "Enter string to search: ";
            cin >> x;
            if (trie_search(root, x) > 0)
                cout << x << " FOUND " << endl;
            else
                cout << x << " NOT FOUND " << endl;
        } else if (choice == 3) {
            cout << "Enter string to delete: ";
            cin >> x;
            if (trie_delete(root, x))
                cout << x << " DELETED " << endl;
            else
                cout << x << " NOT FOUND " << endl;
        } else if (choice == 4) {
            printTRIE(root);
        } else if (choice == 5) {
            printTRIE(root);
        } else if (choice == 6) {
            break;
        } else {
            cout << "Invalid Choice" << endl;
            break;
        }
        cout << endl;
    }

    return 0;
}
*/


#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int EoW;
    Node* children[26];
    Node() {
        EoW = 0;
        for (int i = 0; i < 26; i++) {
            this->children[i] = NULL;
        }
    }
};

void trie_insert(Node* root, string s) {
    Node* current = root;
    for (char c : s) {
        int index = c - 'A'; // Assuming uppercase letters only
        if (!current->children[index]) {
            current->children[index] = new Node();
        }
        current = current->children[index];
    }
    current->EoW++;
}

int trie_search(Node* root, string s, int k = 0) {
    Node* current = root;
    for (char c : s) {
        int index = c - 'A'; // Assuming uppercase letters only
        if (!current->children[index]) {
            return 0; // Not found
        }
        current = current->children[index];
    }
    return current->EoW;
}

bool trie_delete(Node* root, string s, int idx = 0) {
    if (!root) return false;

    if (idx == s.length()) {
        if (root->EoW > 0) {
            root->EoW--;
            return true;
        }
        return false;
    }

    int index = s[idx] - 'A'; // Assuming uppercase letters only
    if (!root->children[index]) {
        return false; // Word not found
    }

    bool canDelete = trie_delete(root->children[index], s, idx + 1);

    if (canDelete && root->children[index]->EoW == 0) {
        delete root->children[index];
        root->children[index] = nullptr;
    }

    return canDelete;
}

void printTRIEUtil(Node* root, string s) {
    if (root->EoW > 0) {
        cout << s << " (" << root->EoW << ")" << endl;
    }
    for (int i = 0; i < 26; i++) {
        if (root->children[i]) {
            char c = i + 'A'; // Assuming uppercase letters only
            printTRIEUtil(root->children[i], s + c);
        }
    }
}

void printTRIE(Node* root, string s = "") {
    printTRIEUtil(root, s);
}

void printStringsZA(Node* root, string s = "") {
    if (root->EoW > 0) {
        cout << s << " (" << root->EoW << ")" << endl;
    }
    for (int i = 25; i >= 0; i--) {
        if (root->children[i]) {
            char c = i + 'A'; // Assuming uppercase letters only
            printStringsZA(root->children[i], s + c);
        }
    }
}

void printPrefixStrings(Node* root, string prefix, string s = "") {
    if (prefix.length() > 0 && s != prefix) return;

    if (root->EoW > 0) {
        cout << s << " (" << root->EoW << ")" << endl;
    }

    for (int i = 0; i < 26; i++) {
        if (root->children[i]) {
            char c = i + 'A'; // Assuming uppercase letters only
            printPrefixStrings(root->children[i], prefix, s + c);
        }
    }
}

void printDuplicateStrings(Node* root, string s = "") {
    if (root->EoW > 1) {
        cout << s << " (" << root->EoW << ")" << endl;
    }

    for (int i = 0; i < 26; i++) {
        if (root->children[i]) {
            char c = i + 'A'; // Assuming uppercase letters only
            printDuplicateStrings(root->children[i], s + c);
        }
    }
}

int main() {
    Node* root = new Node();

    while (1) {
        cout << "1. Insert    2. Search    3. Delete   4. Lexicographical Sorting  5. Display Strings (Z to A)"
             << "  6. Print Strings with Prefix  7. Print Duplicate Strings  8. End"
             << endl
             << endl;
        int choice;
        string x;
        cin >> choice;
        if (choice == 1) {
            cout << "Insert String: ";
            cin >> x;
            trie_insert(root, x);
            cout << x << " is inserted in the trie" << endl;
        } else if (choice == 2) {
            cout << "Enter string to search: ";
            cin >> x;
            if (trie_search(root, x) > 0)
                cout << x << " FOUND " << endl;
            else
                cout << x << " NOT FOUND " << endl;
        } else if (choice == 3) {
            cout << "Enter string to delete: ";
            cin >> x;
            if (trie_delete(root, x))
                cout << x << " DELETED " << endl;
            else
                cout << x << " NOT FOUND " << endl;
        } else if (choice == 4) {
            printTRIE(root);
        } else if (choice == 5) {
            printStringsZA(root);
        } else if (choice == 6) {
            cout << "Enter prefix: ";
            cin >> x;
            printPrefixStrings(root, x);
        } else if (choice == 7) {
            printDuplicateStrings(root);
        } else if (choice == 8) {
            break;
        } else {
            cout << "Invalid Choice" << endl;
            break;
        }
        cout << endl;
    }

    return 0;
}

