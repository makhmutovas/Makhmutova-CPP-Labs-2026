#include <iostream>

namespace {
    const int kLowBoundHour{0};
    const int kHighBoundHour{23};

    const int kLowBoundMinute{0};
    const int kHighBoundMinute{59};

    const int kNoonHour{12};

    const int kNightBeginHour{0};
    const int kMorningBeginHour{5};
    const int kNoonBeginHour{12};
    const int kEveningBeginHour{18};

    const int kSingularBoundHour{1};
    const int kPluralBoundHour{5};
    const int kUpperPluralBoundHour{12};

    const int kSingularBoundMinute{1};
    const int kPluralBoundMinute{5};

    const int kRemainderDivisor{10};

    const int kExceptionBeginMinute{11};
    const int kExceptionEndMinute{20};
}  // namespace

int main() {
    int hour{};
    int minute{};
    std::cout << "Введите часы и минуты: ";
    std::cin >> hour >> minute;

    if (hour > kHighBoundHour || hour < kLowBoundHour || minute > kHighBoundMinute || minute < kLowBoundMinute) {
        std::cout << "введены недопустимые данные\n";
        return 1;
    }

    if (hour == kNightBeginHour && minute == kLowBoundMinute) {
        std::cout << "полночь\n";
        return 0;
    }

    if (hour == kNoonBeginHour && minute == kLowBoundMinute) {
        std::cout << "полдень\n";
        return 0;
    }

    int clock {hour};

    if (hour > kNoonHour) {
        clock = hour - kNoonHour;
    }

    std::cout << clock;

    if (clock == kSingularBoundHour) {
        std::cout << " час";
    } else if (clock > kSingularBoundHour && clock < kPluralBoundHour) {
        std::cout << " часа";
    } else if (clock >= kPluralBoundHour && clock <= kUpperPluralBoundHour || clock == kLowBoundHour ) {
        std::cout << " часов";
    }

    if (minute != kLowBoundMinute) {
        std::cout << " " << minute;

        if (minute % kRemainderDivisor == kSingularBoundMinute && minute != kExceptionBeginMinute) {
            std::cout << " минута";
        } else if ((minute % kRemainderDivisor > kSingularBoundMinute && minute % kRemainderDivisor < kPluralBoundMinute) && !(minute >= kExceptionBeginMinute && minute < kExceptionEndMinute)) {
            std::cout << " минуты";
        } else if ( minute % kRemainderDivisor >= kPluralBoundMinute || minute % kRemainderDivisor == kLowBoundMinute || (minute >= kExceptionBeginMinute  && minute <= kExceptionEndMinute)) {
            std::cout << " минут";
        }
    }

    if (hour >= kMorningBeginHour && hour < kNoonBeginHour) {
        std::cout << " утра";
    } else if (hour >= kNoonBeginHour && hour < kEveningBeginHour) {
        std::cout << " дня";
    } else if (hour >= kEveningBeginHour && hour <= kHighBoundHour) {
        std::cout << " вечера";
    } else if (hour >= kNightBeginHour && hour < kMorningBeginHour) {
        std::cout << " ночи";
    }

    if (minute == kLowBoundMinute) {
        std::cout << " ровно";
    }

    std::cout << std::endl;
    return 0;
}
