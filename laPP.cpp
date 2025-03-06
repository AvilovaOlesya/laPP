// laPP.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;
class Date {
private:
    int day;
    int month;
    int year;
public:
    Date() : day(1), month(1), year(2000) {
        cout << "Конструктор по умолчанию вызван: " << toString() << endl;
    }
    Date(int d, int m, int y) : day(d), month(m), year(y) {
        cout << "Конструктор с параметрами вызван: " << toString() << endl;
    }
    ~Date() {
        cout << "Деструктор вызван для уничтожения объекта : " << endl;
    }
    bool isDayEqualsToMonth() const {
        return day == month;
    }
    void increaseMonth() {
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }
    string toString() const {
        ostringstream oss;
        oss << setfill('0') << setw(2) << day << "/"
            << setfill('0') << setw(2) << month << "/"
            << year;
        return oss.str();
    }
};
int main() {
    setlocale(LC_ALL, "RUS");
    Date date1(14, 4, 2024);
    Date date2(1, 1, 2021);
    Date date3(11, 11, 2011);
    cout << "Дата " << date1.toString()
        << (date1.isDayEqualsToMonth() ? " совпадает " : " не совпадает")
        << " с номером месяца." << endl;
    cout << "Дата " << date2.toString()
        << (date2.isDayEqualsToMonth() ? " совпадает " : " не совпадает")
        << " с номером месяца." << endl;
    cout << "Дата " << date3.toString()
        << (date3.isDayEqualsToMonth() ? " совпадает " : " не совпадает")
        << " с номером месяца." << endl;
    cout << "Увеличиваем дату на один месяц:" << endl;
    date1.increaseMonth();
    cout << "Новая дата: " << date1.toString() << endl;
    date2.increaseMonth();
    cout << "Новая дата: " << date2.toString() << endl;
    date3.increaseMonth();
    cout << "Новая дата: " << date3.toString() << endl;
    return 0;
}
