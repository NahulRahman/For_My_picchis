#include<bits/stdc++.h>
using namespace std;

class ComplexNumber {
public:
    double real;
    double imaginary;

    ComplexNumber(double r = 0, double i = 0) : real(r), imaginary(i) {}

    void print() const {
        if (imaginary >= 0)
            cout << real << " + " << imaginary << "i" << endl;
        else
            cout << real << " - " << -imaginary << "i" << endl;
    }
};

ComplexNumber parseComplexNumber(const string& input) {
    enum State { START, REAL_PART, SIGN, IMAGINARY_PART, END };
    State state = START;

    double real = 0;
    double imaginary = 0;
    string realPart, imaginaryPart;
    bool imaginarySign = false;  // true if negative

    for (int i = 0; i < input.length(); ++i) {
        char ch = input[i];
        switch (state) {
            case START:
                if (isdigit(ch) || ch == '+' || ch == '-') {
                    realPart += ch;
                    state = REAL_PART;
                } else {
                    throw invalid_argument("Invalid start of complex number");
                }
                break;
            case REAL_PART:
                if (isdigit(ch) || ch == '.') {
                    realPart += ch;
                } else if (ch == '+' || ch == '-') {
                    state = SIGN;
                    imaginarySign = (ch == '-');
                } else if (ch == 'i') {
                    imaginaryPart = "1";
                    state = END;
                } else {
                    throw invalid_argument("Invalid character in real part");
                }
                break;
            case SIGN:
                if (isdigit(ch) || ch == '.') {
                    imaginaryPart += ch;
                    state = IMAGINARY_PART;
                } else if (ch == 'i') {
                    imaginaryPart = "1";
                    state = END;
                } else {
                    throw invalid_argument("Invalid character after sign");
                }
                break;
            case IMAGINARY_PART:
                if (isdigit(ch) || ch == '.') {
                    imaginaryPart += ch;
                } else if (ch == 'i') {
                    state = END;
                } else {
                    throw invalid_argument("Invalid character in imaginary part");
                }
                break;
            case END:
                throw ("Invalid character after imaginary part");
        }
    }

    // Final parsing of the parts
    if (!realPart.empty()) {
        real = stod(realPart);
    }
    if (!imaginaryPart.empty()) {
        imaginary = stod(imaginaryPart);
        if (imaginarySign) {
            imaginary = -imaginary;
        }
    }

    return ComplexNumber(real, imaginary);
}

int main() {
    string input;

    cout << "Enter a complex number: ";
    getline(cin, input);

    try {
        ComplexNumber cn = parseComplexNumber(input);
        cn.print();
    } catch (const invalid_argument& e) {
        cerr << e.what() << endl;
    }

    return 0;
}