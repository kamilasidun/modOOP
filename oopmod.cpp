#include <iostream>
#include <vector>
using namespace std;

class Hyperplane {
protected:
    double a0, a1, a2, a3, a4;

public:
    Hyperplane(double a0 = 0, double a1 = 0, double a2 = 0, double a3 = 0, double a4 = 0)
        : a0(a0), a1(a1), a2(a2), a3(a3), a4(a4) {}

    //встановлення коефіцієнтів
    void setCoefficients(double _a0, double _a1, double _a2, double _a3, double _a4) {
    a0 = _a0;
    a1 = _a1;
    a2 = _a2;
    a3 = _a3;
    a4 = _a4;
}

    //виведення коефіцієнтів
    void printCoefficients() const {
        cout << "Коефіцієнти рівняння гіперплощини: "
             << "a0 = " << a0 << ", a1 = " << a1 << ", a2 = " << a2 << ", a3 = " << a3 << ", a4 = " << a4 << endl;
    }

    //перевірка, чи належить точка X = (x1, x2, x3, x4) гіперплощині
    bool isPointOnHyperplane(double x1, double x2, double x3, double x4) const {
        double result = a4 * x4 + a3 * x3 + a2 * x2 + a1 * x1 + a0;
        return result == 0;
    }
};

//Похідний клас
class Line : public Hyperplane {
public:
    // Конструктор для класу Line, який приймає лише три коефіцієнти
    Line(double a0 = 0, double a1 = 0, double a2 = 0)
        : Hyperplane(a0, a1, a2, 0, 0) {} //два нулі потрібні для ініціалізації параметрів a3 і a4 базового класу Hyperplane

    // Перевизначаємо функцію виведення для класу Line
    void printCoefficients() const override {
        cout << "Коефіцієнти рівняння прямої: "
             << "a0 = " << a0 << ", a1 = " << a1 << ", a2 = " << a2 << endl;
    }

    // Метод для перевірки, чи належить точка (x, y) прямій
    bool isPointOnLine(double x, double y) const {
        double result = a1 * x + a2 * y + a0;
        return result == 0;
    }
};

int main() {
    // Створюємо об'єкт класу Hyperplane
    Hyperplane hyperplane;
    hyperplane.setCoefficients(1, -2, 3, 4, -5);
    hyperplane.printCoefficients();

    // Перевірка, чи належить точка гіперплощині
    if (hyperplane.isPointOnHyperplane(1, 2, 3, -4)) {
        cout << "Точка належить гіперплощині." << endl;
    } else {
        cout << "Точка не належить гіперплощині." << endl;
    }

    // Створюємо об'єкт класу Line
    Line line;
    line.setCoefficients(1, -1, 2);
    line.printCoefficients();

    // Перевірка, чи належить точка прямій
    if (line.isPointOnLine(1, 0.5)) {
        cout << "Точка належить прямій." << endl;
    } else {
        cout << "Точка не належить прямій." << endl;
    }

    return 0;
}
