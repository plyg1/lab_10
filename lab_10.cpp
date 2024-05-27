#include <iostream>
#include <cmath>
#include <Windows.h>

using namespace std;

// Структура для завдання 1
struct TPoint {
    double x, y;
};

double Leng(TPoint A, TPoint B);

// Структура для завдання 2
struct Circle {
    double R;
    double L, S;
};

void calcCircle(Circle& c);

bool isSecondQuadrant(double x, double y);

// Функція для завдання 1
double Leng(TPoint A, TPoint B) {
    return sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2));
}

// Функція для завдання 2
void calcCircle(Circle& c) {
    const double PI = 3.14;
    c.L = 2 * PI * c.R;
    c.S = PI * c.R * c.R;
}

bool isSecondQuadrant(double x, double y) {
    return (x < 0 && y > 0);
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int choice;
    do {
        cout << "Введіть номер завдання (1, 2 або 0 для виходу): ";
        cin >> choice;

        switch (choice) {
        case 1: {
            TPoint A, B, C, D;
            cout << "Введіть координати точок A, B, C, D:\n";
            cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;

            double AB = Leng(A, B);
            double AC = Leng(A, C);
            double AD = Leng(A, D);

            cout << "Довжина відрізка AB: " << AB << endl;
            cout << "Довжина відрізка AC: " << AC << endl;
            cout << "Довжина відрізка AD: " << AD << endl;
            break;
        }
        case 2: {
            Circle c;
            double x, y;
            cout << "Введіть радіус кола: ";
            cin >> c.R;
            calcCircle(c);
            cout << "Довжина кола: " << c.L << endl;
            cout << "Площа круга: " << c.S << endl;

            cout << "Введіть координати точки (x, y): ";
            cin >> x >> y;
            if (isSecondQuadrant(x, y))
                cout << "Точка (" << x << ", " << y << ") лежить у другій координатній чверті" << endl;
            else
                cout << "Точка (" << x << ", " << y << ") не лежить у другій координатній чверті" << endl;
            break;
        }
        case 0:
            cout << "Вихід з програми..." << endl;
            break;
        default:
            cout << "Невірний номер завдання!" << endl;
        }
    } while (choice != 0);

    return 0;
}
