#include <iostream>
namespace {
const int kStartingPoint{0};
const int kHourMax{23};
const int kMinuteMax{59};

const int kStartMorning{5};
const int kNoon{12};
const int kStartEvening{18};

const int kEndwithOne{1};
const int kEndWithFive{5};
const int kDelitelTen{10};
}  // namespace
int main() {
    int hour;
    int minute;
    std::cout << "Введите часы и минуты: ";
    std::cin >> hour >> minute;

    if (hour > kHourMax || hour < kStartingPoint || minute > kMinuteMax || minute < kStartingPoint) {
        std::cout << "введены недопустимые данные";
        return 0;
    }

    if (hour == kStartingPoint && minute == kStartingPoint) {
        std::cout << "полночь";
        return 0;
    }

    if (hour == kNoon && minute == kStartingPoint) {
        std::cout << "полдень";
        return 0;
    }

    int clock = hour;

    if (hour > kNoon) {
        clock = hour - kNoon;
    }

    std::cout << clock;

    if (clock == kEndwithOne) {
        std::cout << " час";
    } else if (clock > kEndwithOne && clock < kEndWithFive) {
        std::cout << " часа";
    } else {
        std::cout << " часов";
    }

    if (minute != kStartingPoint) {
        std::cout << " " << minute;

        if (minute % kDelitelTen == kEndwithOne) {
            std::cout << " минута";
        } else if (minute % kDelitelTen > kEndwithOne && minute % kDelitelTen < kEndWithFive) {
            std::cout << " минуты";
        } else {
            std::cout << " минут";
        }
    }

    if (hour >= kStartMorning && hour < kNoon) {
        std::cout << " утра";
    } else if (hour >= kNoon && hour < kStartEvening) {
        std::cout << " дня";
    } else if (hour >= kStartEvening && hour <= kHourMax) {
        std::cout << " вечера";
    } else {
        std::cout << " ночи";
    }
    if (minute == kStartingPoint) {
        std::cout << " ровно";
    }
    return 0;
}
