#include <iostream>

int main(){
    const int startingPoint{0};
    const int HourMax{23};
    const int MinuteMax{59};

    const int startMorning{5};
    const int noon{12};
    const int startEvening{18};

    const int one {1};
    const int five{5};
    const int ten {10};

    int hour;
    int minute;

    std::cin >> hour >> minute;

    if (hour > HourMax || hour < startingPoint || minute > MinuteMax || minute < startingPoint)
    {
        std::cout << "введены недопустимые данные";
        return 0;
    }

    if (hour == startingPoint && minute == startingPoint)
    {
        std::cout << "полночь";
        return 0;
    }

    if (hour == noon && minute == startingPoint)
    {
        std::cout << "полдень";
        return 0;
    }

    int clock = hour;

    if (hour > noon)
    {
        clock = hour - noon;
    }

    std::cout << clock;

    if (clock == one)
    {
        std::cout << " час";
    }
    else if (clock > one && clock < five)
    {
        std::cout << " часа";
    }
    else
    {
        std::cout << " часов";
    }

    if (minute != startingPoint)
    {
        std::cout << " " << minute;

        if (minute % ten == one)
        {
            std::cout << " минута";
        }
        else  if (minute % ten > one && minute % ten < five )
        {
            std::cout<< " минуты";
        }
        else
        {
            std::cout<< " минут";
        }
    }

    if (hour >= startMorning && hour < noon)
    {
        std::cout<< " утра";
    }
    else if (hour > noon && hour < startEvening)
    {
        std::cout<< " дня";
    }
    else if (hour >= startEvening && hour <= HourMax)
    {
        std::cout<< " вечера";
    }
    else
    {
        std::cout<< " ночи";
    }

    return 0;





}
