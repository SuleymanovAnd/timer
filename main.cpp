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
    EndTime -= nowTime.tm_min*60 + nowTime.tm_sec;

    for (int i =0 ; ; i++) {
        time_t temp = time (nullptr);
        time_t zero = temp - (nowTime.tm_min*60 + nowTime.tm_sec);
        if(zero - EndTime == 0) {cout << "DING! DING! DING!\n";Sleep(1000);break;}
        time_t Offset = EndTime - (EndTime - zero);
        tm* Counter = std::localtime (&Offset);
        cout << put_time(Counter, "%M:%S");
        Sleep(500);
        system("cls");
    }
}
