#include <iostream>
namespace {
const int kStartingPoint{0};
const int kHourLimit{23};
const int kMinuteLimit{59};

const int kMorningBegin{5};
const int kNoon{12};
const int kEveningBegin{18};

const int kLowBound{1};
const int kMedBound{5};
const int kFindLast{10};
const int HighBound{20};
}

int main() {
    int hour{0};
    int minute{0};
    std::cout << "Введите часы и минуты: ";
    std::cin >> hour >> minute;

    if (hour > kHourLimit || hour < kStartingPoint || minute > kMinuteLimit || minute < kStartingPoint) {
        std::cout << "введены недопустимые данные";
        return 1;
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

    if (clock == kLowBound) {
        std::cout << " час";
    } else if (clock > kLowBound && clock < kMedBound) {
        std::cout << " часа";
    } else {
        std::cout << " часов";
    }

    if (minute != kStartingPoint) {
        std::cout << " " << minute;

        if (minute % kFindLast == kLowBound) {
            std::cout << " минута";
        } else if ((minute % kFindLast > kLowBound && minute % kFindLast < kMedBound) && !(minute > kFindLast && minute < HighBound)) {
            std::cout << " минуты";
        } else {
            std::cout << " минут";
        }
    }

    if (hour >= kMorningBegin && hour < kNoon) {
        std::cout << " утра";
    } else if (hour >= kNoon && hour < kEveningBegin) {
        std::cout << " дня";
    } else if (hour >= kEveningBegin && hour <= kHourLimit) {
        std::cout << " вечера";
    } else {
        std::cout << " ночи";
    }
    if (minute == kStartingPoint) {
        std::cout << " ровно";
    }
    std::cout<< std::endl;
    return 0;

}
