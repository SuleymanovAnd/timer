#include <iostream>
#include <iomanip>
#include <Windows.h>
using namespace std;

bool overflow ( ){

    if (! std::cin){
        std::cout <<"Input error.Enter again: ";
        std::cin.clear();
        std::cin.ignore(1000, '\n');

        return true;
    } else {return false;}
}

int main() {
    time_t t = time (nullptr);
    std::tm timer = *std::localtime (&t);
    cout << "Enter timer values";
    cin >> get_time (&timer,"%M:%S");
    while (overflow ()){cin >> get_time (&timer,"%M:%S");}

    std::tm nowTime = *std::localtime (&t);
    time_t timeOffset = (timer.tm_min*60 + timer.tm_sec);
    time_t EndTime = time (nullptr) + timeOffset;


    for (int i = (int) timeOffset ; ; i--) {
        time_t temp = time (nullptr);
        if(temp - EndTime == 0) {cout << "DING! DING! DING!\n";Sleep(2000);break;}
        int min =  ((int) timeOffset -i) /60;
        int sec = ((int) timeOffset-i)%60;
        cout << min << ":" << sec;
        Sleep(900);
        system("cls");
    }
}
