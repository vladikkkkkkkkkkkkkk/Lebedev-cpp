#include <iostream>
#include <string>

class DateTime {
private:
    int day;
    int month;
    int year;

public:
    DateTime(int d, int m, int y) : day(d), month(m), year(y) {}

    bool isLeapYear(int year) {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
            return true;
        }
        else {
            return false;
        }
    }

    bool isValidDate() {
        if (year < 1) {
            return false;
        }
        if (month < 1 || month > 12) {
            return false;
        }
        if (day < 1 || day > 31) {
            return false;
        }
        if (month == 4 || month == 6 || month == 9 || month == 11) {
            if (day > 30) {
                return false;
            }
        }
        if (month == 2) {
            if (isLeapYear(year)) {
                if (day > 29) {
                    return false;
                }
            }
            else {
                if (day > 28) {
                    return false;
                }
            }
        }
        return true;
    }

    void inputDate() {
        std::cout << "Enter day: ";
        std::cin >> day;

        std::cout << "Enter month: ";
        std::cin >> month;

        std::cout << "Enter year: ";
        std::cin >> year;

        while (!isValidDate()) {
            std::cout << "Invalid date. Please enter a valid date." << std::endl;

            std::cout << "Enter day: ";
            std::cin >> day;

            std::cout << "Enter month: ";
            std::cin >> month;

            std::cout << "Enter year: ";
            std::cin >> year;
        }
    }

    void printDate() {
        std::cout << day << "." << month << "." << year << std::endl;
    }

    int calculateDifference(DateTime& other) {
        // Calculation of the difference in days between two dates
        // Implementation omitted for brevity
        return 0;
    }

    int calculateDayOfWeek() {
        // Calculation of the day of the week for the specified date
        // Implementation omitted for brevity
        return 0;
    }
};

int main() {
    DateTime dt(1, 1, 2021);
    dt.inputDate();
    dt.printDate();

    return 0;
}