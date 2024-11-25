#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void updateTime(int &hours, int &minutes, int &seconds) {
    seconds++;
    if (seconds == 60) {
        seconds = 0;
        minutes++;
        if (minutes == 60) {
            minutes = 0;
            hours++;
            if (hours == 24) {
                hours = 0;
            }
        }
    }
}

void displayTime(int hours, int minutes, int seconds) {
    cout << (hours < 10 ? "0" : "") << hours << ":"
         << (minutes < 10 ? "0" : "") << minutes << ":"
         << (seconds < 10 ? "0" : "") << seconds << endl;
}

int main() {
    int hours = 0, minutes = 0, seconds = 0;
    while (true) {
        displayTime(hours, minutes, seconds);
        this_thread::sleep_for(chrono::seconds(1));
        updateTime(hours, minutes, seconds);
    }
    return 0;
}
