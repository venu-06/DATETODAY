#include <stdio.h>

int isLeapYear(int y) {
    return ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0));
}

int getYearCode(int y) {
    if ((y >= 1500 && y <= 1599) || (y >= 1900 && y <= 1999) || (y >= 2300 && y <= 2399)) return 0;
    if ((y >= 1600 && y <= 1699) || (y >= 2000 && y <= 2099) || (y >= 2400 && y <= 2499)) return 6;
    if ((y >= 1700 && y <= 1799) || (y >= 2100 && y <= 2199)) return 4;
    if ((y >= 1800 && y <= 1899) || (y >= 2200 && y <= 2299)) return 2;
    return 0;
}

int getMonthCode(int m) {
    int codes[] = {0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5};
    return codes[m - 1];
}

void printDay(int d) {
     const char* days[] = {"SUNDAY","MONDAY","TUESDAY","WEDNESDAY","THURSDAY","FRIDAY","SATURDAY"};
     printf("%s\n", days[d]);
}

int main(){
     int d, m, y;
     printf("Enter Date (1-31): ");
     scanf("%d", &d);

     do{
         printf("Enter Month (1-12): ");
         scanf("%d", &m);
     } while (m < 1 || m > 12);

     do{
         printf("Enter Year (1500 - 2500): ");
         scanf("%d", &y);
     } while (y < 1500 || y > 2500);

    // int maxDays[12];
    // maxDays[0] for January, maxDays[1] for Feb and so on...
    int maxDays[] = {31, 28 + isLeapYear(y), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    while (d < 1 || d > maxDays[m-1]) {
         printf("Invalid date for given month. Re-enter day (1-%d): ", maxDays[m-1]);
         scanf("%d", &d);
    } 

    int last2 = y%100;
    int yearPart = last2 + (last2/4);
    int total = d + getMonthCode(m) + getYearCode(y) + yearPart; // getYearCode, getMonthCode and yearCode have logic
    if (isLeapYear(y) && (m==1 || m==2)) total -= 1;

    int dayIndex = total%7;

    printDay(dayIndex);

    return 0;
}
