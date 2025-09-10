#include <iostream>
#include <cmath>

using namespace std;

int solveQuartic(double a, double b, double c, double x[]) {
    if (a == 0 && b == 0 && c == 0) {
    return -1;
    }

    if (a == 0 && b == 0) {
    return 0;
    }

    if (a == 0) {
    double y = -c / b;
    if (y < 0) return 0;
    x[0] = sqrt(y);
    x[1] = -sqrt(y);
    return 2;
    }

    double delta = b * b - 4 * a * c;
    if (delta < 0) return 0;
    double y1 = (-b + sqrt(delta)) / (2 * a);
    double y2 = (-b - sqrt(delta)) / (2 * a);
    int count = 0;
    
    if (y1 >= 0) {
    x[count++] = sqrt(y1);
    x[count++] = -sqrt(y1);
    }

    if (y2 >= 0 && y2 != y1) {
    x[count++] = sqrt(y2);
    x[count++] = -sqrt(y2);
    }

    return count;
}
void randomTest(int numTests) {
    srand(time(NULL)); // khởi tạo seed theo thời gian
    for (int i = 0; i < numTests; i++) {
        // Sinh ngẫu nhiên a, b, c trong khoảng [-5, 5]
        double a = rand() % 11 - 5;
        double b = rand() % 11 - 5;
        double c = rand() % 11 - 5;

        double x[4];
        int n = solveQuartic(a, b, c, x);

        cout << "Test " << i+1 << ": a=" << a << ", b=" << b << ", c=" << c << endl;
        if (n == -1) {
            cout << "  => Infinite solutions\n";
        } else if (n == 0) {
            cout << "  => No solution\n";
        } else {
            cout << "  => " << n << " solution(s): ";
            for (int j = 0; j < n; j++) cout << x[j] << " ";
            cout << endl;
        }
        cout << "-----------------------\n";
    }
}

int main() {
    randomTest(10);
    return 0;
}