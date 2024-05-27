#include <iostream>
#include <cmath>
#include <Windows.h>

using namespace std;

// ��������� ��� �������� 1
struct TPoint {
    double x, y;
};

double Leng(TPoint A, TPoint B);

// ��������� ��� �������� 2
struct Circle {
    double R;
    double L, S;
};

void calcCircle(Circle& c);

bool isSecondQuadrant(double x, double y);

// ������� ��� �������� 1
double Leng(TPoint A, TPoint B) {
    return sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2));
}

// ������� ��� �������� 2
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
        cout << "������ ����� �������� (1, 2 ��� 0 ��� ������): ";
        cin >> choice;

        switch (choice) {
        case 1: {
            TPoint A, B, C, D;
            cout << "������ ���������� ����� A, B, C, D:\n";
            cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;

            double AB = Leng(A, B);
            double AC = Leng(A, C);
            double AD = Leng(A, D);

            cout << "������� ������ AB: " << AB << endl;
            cout << "������� ������ AC: " << AC << endl;
            cout << "������� ������ AD: " << AD << endl;
            break;
        }
        case 2: {
            Circle c;
            double x, y;
            cout << "������ ����� ����: ";
            cin >> c.R;
            calcCircle(c);
            cout << "������� ����: " << c.L << endl;
            cout << "����� �����: " << c.S << endl;

            cout << "������ ���������� ����� (x, y): ";
            cin >> x >> y;
            if (isSecondQuadrant(x, y))
                cout << "����� (" << x << ", " << y << ") ������ � ����� ����������� �����" << endl;
            else
                cout << "����� (" << x << ", " << y << ") �� ������ � ����� ����������� �����" << endl;
            break;
        }
        case 0:
            cout << "����� � ��������..." << endl;
            break;
        default:
            cout << "������� ����� ��������!" << endl;
        }
    } while (choice != 0);

    return 0;
}