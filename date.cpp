#include <iostream>
#include <ctime>
#include <unistd.h> // For sleep() function

using namespace std;

void showDateTime() {
    time_t now = time(0);
    tm *ltm = localtime(&now);

    string days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    cout << "\nCurrent Date and Time:" << endl;
    cout << "-----------------------" << endl;
    cout << "Day: " << days[ltm->tm_wday] << endl;
    cout << "Date: " << 1900 + ltm->tm_year << "-"
         << 1 + ltm->tm_mon << "-"
         << ltm->tm_mday << endl;
    cout << "Time: " << ltm->tm_hour << ":"
         << ltm->tm_min << ":"
         << ltm->tm_sec << endl << endl;

    // Sleep for 4 seconds
    sleep(4); // Sleep function takes seconds as argument
}

int main() {
    showDateTime();
    return 0;
}

