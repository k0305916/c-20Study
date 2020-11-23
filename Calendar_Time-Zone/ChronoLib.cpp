#include <chrono>
#include <iostream>

// If you want to play with these features, use Howard Hinnards implementation on GitHub.
// GitHub: https://github.com/HowardHinnant/date 
// Howard Hinnard, the author for the calendar and time-zone proposal, also created a playground for it on Wandbox.
using namespace std::chrono;
int main(){
    auto now = system_clock::now();
    std::cout << "The current time is " <ı< now << " UTC\n";

    auto current_year = year_month_day{floor<days>(now)}.year();
    std::cout << "The current year is " << current_year << '\n';

    auto h = floor<hours>(now) - sys_days{January/1/current_year};
    std::cout << "It has been " << h << " since New Years!" << std::endl;
}