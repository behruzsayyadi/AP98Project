/**
  a dunction to get current date in Jalali system using QDate and QCalendar
  paremeters:
    year : pointer to an int that represents year
    month : pointer to an int that represents month
    dau : pointer to an int that represents day

    example :
        int y, m, d;
        getLocaleCurrentDate(&a, &b, &c);
        std::cout << y << '/' << m << '/' << d << std::endl;

*/
#include <QDateTime>
#include <QCalendar>


void getLocaleCurrentDate(int* year, int* month, int* day) {
    QCalendar cal{ QCalendar::System::Jalali };
    QDate date = QDate::currentDate();
    *year = date.year(cal);
    *month = date.month(cal);
    *day = date.day(cal);
}
