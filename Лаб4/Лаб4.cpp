#include <cmath>
#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    double x, e1; int n;

    cout << "Введите x (из интервала (-1, 1)), N, E: ";
    cin >> x >> n >> e1;
    if (abs(x) >= 1.0 || n < 0 || e1 <= 0.0) {
        cerr << "Ошибка ввода\n";
        return 1;
    }

    double s = 0.0;
    double p = 1.0;
    for (int k = 1; k <= n; ++k) {
        p *= x;
        double a = -p / k;
        s += a;
    }

    double e2 = e1 / 10.0;
    const int LIM = 1000000000;

    double s1 = 0.0;
    int c1 = 0;
    p = 1.0;
    for (int k = 1; k <= LIM; ++k) {
        p *= x;
        double a = -p / k;
        if (abs(a) > e1) {
            s1 += a;
            ++c1;
        }
        else
            break;
    }

    double s2 = 0.0;
    int c2 = 0;
    p = 1.0;
    for (int k = 1; k <= LIM; ++k) {
        p *= x;
        double a = -p / k;
        if (abs(a) > e2) {
            s2 += a;
            ++c2;
        }
        else
            break;
    }

    cout << "\nСумма " << n << " слагаемых: " << s << '\n';
    cout << "При E1 = " << e1 << ": сумма = " << s << ", количество слагаемых = " << c1 << '\n';
    cout << "При E2 = " << e2 << ": сумма = " << s2 << ", количество слагаемых = " << c2 << '\n';

    if (x < 1.0) {
        double res = log(1.0 - x);
        cout << "\nТочное значение ln(1 - x): " << res << '\n';
        cout << "Разность для N слагаемых и точного значения: " << abs(res - s) << '\n';
        cout << "Погрешность для слагаемых больших E1 и точного значения: " << abs(res - s1) << '\n';
        cout << "Погрешность для слагаемых больших E2 и точного значения: " << abs(res - s2) << '\n';
    }

    return 0;
}
