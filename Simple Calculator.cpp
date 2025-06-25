#include <iostream>
using namespace std;

int main() {
    double a, b, result;
    int op;

    cout << "Enter first number: ";
    cin >> a;

    cout << "Enter second number: ";
    cin >> b;

    cout << "Choose operation:\n";
    cout << "1. Add\n2. Subtract\n3. Multiply\n4. Divide\n";
    cin >> op;

    switch (op) {
        case 1: result = a + b; break;
        case 2: result = a - b; break;
        case 3: result = a * b; break;
        case 4:
            if (b == 0) {
                cout << "Error: Division by zero!\n";
                return 1;
            }
            result = a / b;
            break;
        default:
            cout << "Invalid operation!\n";
            return 1;
    }

    cout << "Result: " << result << endl;
    return 0;
}
