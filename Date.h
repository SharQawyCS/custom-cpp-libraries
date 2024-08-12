#pragma warning(disable : 4996)
#pragma once

#include <iostream>
#include <string>
#include "String.h"

using namespace std;

class Date
{

private:
  short _Day = 1;
  short _Month = 1;
  short _Year = 1900;

public:
  Date()
  {
    time_t t = time(0);
    tm *now = localtime(&t);
    _Day = now->tm_mday;
    _Month = now->tm_mon + 1;
    _Year = now->tm_year + 1900;
  }

  Date(string sDate)
  {

    vector<string> vDate;
    vDate = String::Split(sDate, "/");

    _Day = stoi(vDate[0]);
    _Month = stoi(vDate[1]);
    _Year = stoi(vDate[2]);
  }

  Date(short _Day, short _Month, short _Year)
  {

    _Day = _Day;
    _Month = _Month;
    _Year = _Year;
  }

  Date(short DateOrderInYear, short _Year)
  {
    // This will construct a date by date order in year
    Date Date1 = GetDateFromDayOrderInYear(DateOrderInYear, _Year);
    _Day = Date1._Day;
    _Month = Date1._Month;
    _Year = Date1._Year;
  }

  void SetDay(short _Day)
  {
    _Day = _Day;
  }

  short GetDay()
  {
    return _Day;
  }

  void SetMonth(short _Month)
  {
    _Month = _Month;
  }

  short GetMonth()
  {
    return _Month;
  }

  void SetYear(short _Year)
  {
    _Year = _Year;
  }

  short GetYear()
  {
    return _Year;
  }

  void Print()
  {
    cout << DateToString() << endl;
  }

  static Date GetSystemDate()
  {
    // system date
    time_t t = time(0);
    tm *now = localtime(&t);

    short _Day, _Month, _Year;

    _Year = now->tm_year + 1900;
    _Month = now->tm_mon + 1;
    _Day = now->tm_mday;

    return Date(_Day, _Month, _Year);
  }

  static bool IsValidDate(Date Date)
  {

    if (Date._Day < 1 || Date._Day > 31)
      return false;

    if (Date._Month < 1 || Date._Month > 12)
      return false;

    if (Date._Month == 2)
    {
      if (isLeapYear(Date._Year))
      {
        if (Date._Day > 29)
          return false;
      }
      else
      {
        if (Date._Day > 28)
          return false;
      }
    }

    short DaysInMonth = NumberOfDaysInAMonth(Date._Month, Date._Year);

    if (Date._Day > DaysInMonth)
      return false;

    return true;
  }

  bool IsValid()
  {
    return IsValidDate(*this);
  }

  static string DateToString(Date Date)
  {
    return to_string(Date._Day) + "/" + to_string(Date._Month) + "/" + to_string(Date._Year);
  }

  string DateToString()
  {
    return DateToString(*this);
  }

  static bool isLeapYear(short _Year)
  {

    // if year is divisible by 4 AND not divisible by 100
    // OR if year is divisible by 400
    // then it is a leap year
    return (_Year % 4 == 0 && _Year % 100 != 0) || (_Year % 400 == 0);
  }

  bool isLeapYear()
  {
    return isLeapYear(_Year);
  }

  static short NumberOfDaysInAYear(short _Year)
  {
    return isLeapYear(_Year) ? 365 : 364;
  }

  short NumberOfDaysInAYear()
  {
    return NumberOfDaysInAYear(_Year);
  }

  static short NumberOfHoursInAYear(short _Year)
  {
    return NumberOfDaysInAYear(_Year) * 24;
  }

  short NumberOfHoursInAYear()
  {
    return NumberOfHoursInAYear(_Year);
  }

  static int NumberOfMinutesInAYear(short _Year)
  {
    return NumberOfHoursInAYear(_Year) * 60;
  }

  int NumberOfMinutesInAYear()
  {
    return NumberOfMinutesInAYear(_Year);
  }

  static int NumberOfSecondsInAYear(short _Year)
  {
    return NumberOfMinutesInAYear(_Year) * 60;
  }

  int NumberOfSecondsInAYear()
  {
    return NumberOfSecondsInAYear();
  }

  static short NumberOfDaysInAMonth(short _Month, short _Year)
  {

    if (_Month < 1 || _Month > 12)
      return 0;

    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return (_Month == 2) ? (isLeapYear(_Year) ? 29 : 28) : days[_Month - 1];
  }

  short NumberOfDaysInAMonth()
  {
    return NumberOfDaysInAMonth(_Month, _Year);
  }

  static short NumberOfHoursInAMonth(short _Month, short _Year)
  {
    return NumberOfDaysInAMonth(_Month, _Year) * 24;
  }

  short NumberOfHoursInAMonth()
  {
    return NumberOfDaysInAMonth(_Month, _Year) * 24;
  }

  static int NumberOfMinutesInAMonth(short _Month, short _Year)
  {
    return NumberOfHoursInAMonth(_Month, _Year) * 60;
  }

  int NumberOfMinutesInAMonth()
  {
    return NumberOfHoursInAMonth(_Month, _Year) * 60;
  }

  static int NumberOfSecondsInAMonth(short _Month, short _Year)
  {
    return NumberOfMinutesInAMonth(_Month, _Year) * 60;
  }

  int NumberOfSecondsInAMonth()
  {
    return NumberOfMinutesInAMonth(_Month, _Year) * 60;
  }

  static short DayOfWeekOrder(short _Day, short _Month, short _Year)
  {
    short a, y, m;
    a = (14 - _Month) / 12;
    y = _Year - a;
    m = _Month + (12 * a) - 2;
    // Gregorian:
    // 0:sun, 1:Mon, 2:Tue...etc
    return (_Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
  }

  short DayOfWeekOrder()
  {
    return DayOfWeekOrder(_Day, _Month, _Year);
  }

  static string DayShortName(short DayOfWeekOrder)
  {
    string arrDayNames[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

    return arrDayNames[DayOfWeekOrder];
  }

  static string DayShortName(short _Day, short _Month, short _Year)
  {

    string arrDayNames[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

    return arrDayNames[DayOfWeekOrder(_Day, _Month, _Year)];
  }

  string DayShortName()
  {

    string arrDayNames[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

    return arrDayNames[DayOfWeekOrder(_Day, _Month, _Year)];
  }

  static string MonthShortName(short MonthNumber)
  {
    string Months[12] = {"Jan", "Feb", "Mar",
                         "Apr", "May", "Jun",
                         "Jul", "Aug", "Sep",
                         "Oct", "Nov", "Dec"};

    return (Months[MonthNumber - 1]);
  }

  string MonthShortName()
  {

    return MonthShortName(_Month);
  }

  static void PrintMonthCalendar(short _Month, short _Year)
  {
    int NumberOfDays;

    // Index of the day from 0 to 6
    int current = DayOfWeekOrder(1, _Month, _Year);

    NumberOfDays = NumberOfDaysInAMonth(_Month, _Year);

    // Print the current month name
    printf("\n  _______________%s_______________\n\n",
           MonthShortName(_Month).c_str());

    // Print the columns
    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    // Print appropriate spaces
    int i;
    for (i = 0; i < current; i++)
      printf("     ");

    for (int j = 1; j <= NumberOfDays; j++)
    {
      printf("%5d", j);

      if (++i == 7)
      {
        i = 0;
        printf("\n");
      }
    }

    printf("\n  _________________________________\n");
  }

  void PrintMonthCalendar()
  {
    PrintMonthCalendar(_Month, _Year);
  }

  static void PrintYearCalendar(int _Year)
  {
    printf("\n  _________________________________\n\n");
    printf("           Calendar - %d\n", _Year);
    printf("  _________________________________\n");

    for (int i = 1; i <= 12; i++)
    {
      PrintMonthCalendar(i, _Year);
    }

    return;
  }

  void PrintYearCalendar()
  {
    printf("\n  _________________________________\n\n");
    printf("           Calendar - %d\n", _Year);
    printf("  _________________________________\n");

    for (int i = 1; i <= 12; i++)
    {
      PrintMonthCalendar(i, _Year);
    }

    return;
  }

  static short DaysFromTheBeginingOfTheYear(short _Day, short _Month, short _Year)
  {

    short TotalDays = 0;

    for (int i = 1; i <= _Month - 1; i++)
    {
      TotalDays += NumberOfDaysInAMonth(i, _Year);
    }

    TotalDays += _Day;

    return TotalDays;
  }

  short DaysFromTheBeginingOfTheYear()
  {

    short TotalDays = 0;

    for (int i = 1; i <= _Month - 1; i++)
    {
      TotalDays += NumberOfDaysInAMonth(i, _Year);
    }

    TotalDays += _Day;

    return TotalDays;
  }

  static Date GetDateFromDayOrderInYear(short DateOrderInYear, short _Year)
  {

    Date Date;
    short RemainingDays = DateOrderInYear;
    short MonthDays = 0;

    Date._Year = _Year;
    Date._Month = 1;

    while (true)
    {
      MonthDays = NumberOfDaysInAMonth(Date._Month, _Year);

      if (RemainingDays > MonthDays)
      {
        RemainingDays -= MonthDays;
        Date._Month++;
      }
      else
      {
        Date._Day = RemainingDays;
        break;
      }
    }

    return Date;
  }

  void AddDays(short Days)
  {

    short RemainingDays = Days + DaysFromTheBeginingOfTheYear(_Day, _Month, _Year);
    short MonthDays = 0;

    _Month = 1;

    while (true)
    {
      MonthDays = NumberOfDaysInAMonth(_Month, _Year);

      if (RemainingDays > MonthDays)
      {
        RemainingDays -= MonthDays;
        _Month++;

        if (_Month > 12)
        {
          _Month = 1;
          _Year++;
        }
      }
      else
      {
        _Day = RemainingDays;
        break;
      }
    }
  }

  static bool IsDate1BeforeDate2(Date Date1, Date Date2)
  {
    return (Date1._Year < Date2._Year) ? true : ((Date1._Year == Date2._Year) ? (Date1._Month < Date2._Month ? true : (Date1._Month == Date2._Month ? Date1._Day < Date2._Day : false)) : false);
  }

  bool IsDateBeforeDate2(Date Date2)
  {
    // note: *this sends the current object :-)
    return IsDate1BeforeDate2(*this, Date2);
  }

  static bool IsDate1EqualDate2(Date Date1, Date Date2)
  {
    return (Date1._Year == Date2._Year) ? ((Date1._Month == Date2._Month) ? ((Date1._Day == Date2._Day) ? true : false) : false) : false;
  }

  bool IsDateEqualDate2(Date Date2)
  {
    return IsDate1EqualDate2(*this, Date2);
  }

  static bool IsLastDayInMonth(Date Date)
  {

    return (Date._Day == NumberOfDaysInAMonth(Date._Month, Date._Year));
  }

  bool IsLastDayInMonth()
  {

    return IsLastDayInMonth(*this);
  }

  static bool IsLastMonthInYear(short _Month)
  {
    return (_Month == 12);
  }

  static Date AddOneDay(Date Date)
  {
    if (IsLastDayInMonth(Date))
    {
      if (IsLastMonthInYear(Date._Month))
      {
        Date._Month = 1;
        Date._Day = 1;
        Date._Year++;
      }
      else
      {
        Date._Day = 1;
        Date._Month++;
      }
    }
    else
    {
      Date._Day++;
    }

    return Date;
  }

  void AddOneDay()

  {
    *this = AddOneDay(*this);
  }

  static void SwapDates(Date &Date1, Date &Date2)
  {

    Date TempDate;
    TempDate = Date1;
    Date1 = Date2;
    Date2 = TempDate;
  }

  static int GetDifferenceInDays(Date Date1, Date Date2, bool IncludeEndDay = false)
  {
    // this will take care of negative diff
    int Days = 0;
    short SawpFlagValue = 1;

    if (!IsDate1BeforeDate2(Date1, Date2))
    {
      // Swap Dates
      SwapDates(Date1, Date2);
      SawpFlagValue = -1;
    }

    while (IsDate1BeforeDate2(Date1, Date2))
    {
      Days++;
      Date1 = AddOneDay(Date1);
    }

    return IncludeEndDay ? ++Days * SawpFlagValue : Days * SawpFlagValue;
  }

  int GetDifferenceInDays(Date Date2, bool IncludeEndDay = false)
  {
    return GetDifferenceInDays(*this, Date2, IncludeEndDay);
  }

  static short CalculateMyAgeInDays(Date DateOfBirth)
  {
    return GetDifferenceInDays(DateOfBirth, Date::GetSystemDate(), true);
  }
  // above no need to have nonstatic function for the object because it does not depend on any data from it.

  static Date IncreaseDateByOneWeek(Date &Date)
  {

    for (int i = 1; i <= 7; i++)
    {
      Date = AddOneDay(Date);
    }

    return Date;
  }

  void IncreaseDateByOneWeek()
  {
    IncreaseDateByOneWeek(*this);
  }

  Date IncreaseDateByXWeeks(short Weeks, Date &Date)
  {

    for (short i = 1; i <= Weeks; i++)
    {
      Date = IncreaseDateByOneWeek(Date);
    }
    return Date;
  }

  void IncreaseDateByXWeeks(short Weeks)
  {
    IncreaseDateByXWeeks(Weeks, *this);
  }

  Date IncreaseDateByOneMonth(Date &Date)
  {

    if (Date._Month == 12)
    {
      Date._Month = 1;
      Date._Year++;
    }
    else
    {
      Date._Month++;
    }

    // last check day in date should not exceed max days in the current month
    //  example if date is 31/1/2022 increasing one month should not be 31/2/2022, it should
    //  be 28/2/2022
    short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date._Month, Date._Year);
    if (Date._Day > NumberOfDaysInCurrentMonth)
    {
      Date._Day = NumberOfDaysInCurrentMonth;
    }

    return Date;
  }

  void IncreaseDateByOneMonth()
  {

    IncreaseDateByOneMonth(*this);
  }

  Date IncreaseDateByXDays(short Days, Date &Date)
  {

    for (short i = 1; i <= Days; i++)
    {
      Date = AddOneDay(Date);
    }
    return Date;
  }

  void IncreaseDateByXDays(short Days)
  {

    IncreaseDateByXDays(Days, *this);
  }

  Date IncreaseDateByXMonths(short Months, Date &Date)
  {

    for (short i = 1; i <= Months; i++)
    {
      Date = IncreaseDateByOneMonth(Date);
    }
    return Date;
  }

  void IncreaseDateByXMonths(short Months)
  {
    IncreaseDateByXMonths(Months, *this);
  }

  static Date IncreaseDateByOneYear(Date &Date)
  {
    Date._Year++;
    return Date;
  }

  void IncreaseDateByOneYear()
  {
    IncreaseDateByOneYear(*this);
  }

  Date IncreaseDateByXYears(short Years, Date &Date)
  {
    Date._Year += Years;
    return Date;
  }

  void IncreaseDateByXYears(short Years)
  {
    IncreaseDateByXYears(Years);
  }

  Date IncreaseDateByOneDecade(Date &Date)
  {
    // Period of 10 years
    Date._Year += 10;
    return Date;
  }

  void IncreaseDateByOneDecade()
  {
    IncreaseDateByOneDecade(*this);
  }

  Date IncreaseDateByXDecades(short Decade, Date &Date)
  {
    Date._Year += Decade * 10;
    return Date;
  }

  void IncreaseDateByXDecades(short Decade)
  {
    IncreaseDateByXDecades(Decade, *this);
  }

  Date IncreaseDateByOneCentury(Date &Date)
  {
    // Period of 100 years
    Date._Year += 100;
    return Date;
  }

  void IncreaseDateByOneCentury()
  {
    IncreaseDateByOneCentury(*this);
  }

  Date IncreaseDateByOneMillennium(Date &Date)
  {
    // Period of 1000 years
    Date._Year += 1000;
    return Date;
  }

  Date IncreaseDateByOneMillennium()
  {
    IncreaseDateByOneMillennium(*this);
  }

  static Date DecreaseDateByOneDay(Date Date)
  {
    if (Date._Day == 1)
    {
      if (Date._Month == 1)
      {
        Date._Month = 12;
        Date._Day = 31;
        Date._Year--;
      }
      else
      {

        Date._Month--;
        Date._Day = NumberOfDaysInAMonth(Date._Month, Date._Year);
      }
    }
    else
    {
      Date._Day--;
    }

    return Date;
  }

  void DecreaseDateByOneDay()
  {
    DecreaseDateByOneDay(*this);
  }

  static Date DecreaseDateByOneWeek(Date &Date)
  {

    for (int i = 1; i <= 7; i++)
    {
      Date = DecreaseDateByOneDay(Date);
    }

    return Date;
  }

  void DecreaseDateByOneWeek()
  {
    DecreaseDateByOneWeek(*this);
  }

  static Date DecreaseDateByXWeeks(short Weeks, Date &Date)
  {

    for (short i = 1; i <= Weeks; i++)
    {
      Date = DecreaseDateByOneWeek(Date);
    }
    return Date;
  }

  void DecreaseDateByXWeeks(short Weeks)
  {
    DecreaseDateByXWeeks(Weeks, *this);
  }

  static Date DecreaseDateByOneMonth(Date &Date)
  {

    if (Date._Month == 1)
    {
      Date._Month = 12;
      Date._Year--;
    }
    else
      Date._Month--;

    // last check day in date should not exceed max days in the current month
    //  example if date is 31/3/2022 decreasing one month should not be 31/2/2022, it should
    //  be 28/2/2022
    short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date._Month, Date._Year);
    if (Date._Day > NumberOfDaysInCurrentMonth)
    {
      Date._Day = NumberOfDaysInCurrentMonth;
    }

    return Date;
  }

  void DecreaseDateByOneMonth()
  {
    DecreaseDateByOneMonth(*this);
  }

  static Date DecreaseDateByXDays(short Days, Date &Date)
  {

    for (short i = 1; i <= Days; i++)
    {
      Date = DecreaseDateByOneDay(Date);
    }
    return Date;
  }

  void DecreaseDateByXDays(short Days)
  {
    DecreaseDateByXDays(Days, *this);
  }

  static Date DecreaseDateByXMonths(short Months, Date &Date)
  {

    for (short i = 1; i <= Months; i++)
    {
      Date = DecreaseDateByOneMonth(Date);
    }
    return Date;
  }

  void DecreaseDateByXMonths(short Months)
  {
    DecreaseDateByXMonths(Months, *this);
  }

  static Date DecreaseDateByOneYear(Date &Date)
  {

    Date._Year--;
    return Date;
  }

  void DecreaseDateByOneYear()
  {
    DecreaseDateByOneYear(*this);
  }

  static Date DecreaseDateByXYears(short Years, Date &Date)
  {

    Date._Year -= Years;
    return Date;
  }

  void DecreaseDateByXYears(short Years)
  {
    DecreaseDateByXYears(Years, *this);
  }

  static Date DecreaseDateByOneDecade(Date &Date)
  {
    // Period of 10 years
    Date._Year -= 10;
    return Date;
  }

  void DecreaseDateByOneDecade()
  {
    DecreaseDateByOneDecade(*this);
  }

  static Date DecreaseDateByXDecades(short Decades, Date &Date)
  {

    Date._Year -= Decades * 10;
    return Date;
  }

  void DecreaseDateByXDecades(short Decades)
  {
    DecreaseDateByXDecades(Decades, *this);
  }

  static Date DecreaseDateByOneCentury(Date &Date)
  {
    // Period of 100 years
    Date._Year -= 100;
    return Date;
  }

  void DecreaseDateByOneCentury()
  {
    DecreaseDateByOneCentury(*this);
  }

  static Date DecreaseDateByOneMillennium(Date &Date)
  {
    // Period of 1000 years
    Date._Year -= 1000;
    return Date;
  }

  void DecreaseDateByOneMillennium()
  {
    DecreaseDateByOneMillennium(*this);
  }

  static short IsEndOfWeek(Date Date)
  {
    return DayOfWeekOrder(Date._Day, Date._Month, Date._Year) == 6;
  }

  short IsEndOfWeek()
  {
    return IsEndOfWeek(*this);
  }

  static bool IsWeekEnd(Date Date)
  {
    // Weekends are Fri and Sat
    short DayIndex = DayOfWeekOrder(Date._Day, Date._Month, Date._Year);
    return (DayIndex == 5 || DayIndex == 6);
  }

  bool IsWeekEnd()
  {
    return IsWeekEnd(*this);
  }

  static bool IsBusinessDay(Date Date)
  {
    // Weekends are Sun,Mon,Tue,Wed and Thur

    /*
   short DayIndex = DayOfWeekOrder(Date._Day, Date._Month, Date._Year);
   return  (DayIndex >= 5 && DayIndex <= 4);
    */

    // shorter method is to invert the IsWeekEnd: this will save updating code.
    return !IsWeekEnd(Date);
  }

  bool IsBusinessDay()
  {
    return IsBusinessDay(*this);
  }

  static short DaysUntilTheEndOfWeek(Date Date)
  {
    return 6 - DayOfWeekOrder(Date._Day, Date._Month, Date._Year);
  }

  short DaysUntilTheEndOfWeek()
  {
    return DaysUntilTheEndOfWeek(*this);
  }

  static short DaysUntilTheEndOfMonth(Date Date1)
  {

    Date EndOfMontDate;
    EndOfMontDate._Day = NumberOfDaysInAMonth(Date1._Month, Date1._Year);
    EndOfMontDate._Month = Date1._Month;
    EndOfMontDate._Year = Date1._Year;

    return GetDifferenceInDays(Date1, EndOfMontDate, true);
  }

  short DaysUntilTheEndOfMonth()
  {
    return DaysUntilTheEndOfMonth(*this);
  }

  static short DaysUntilTheEndOfYear(Date Date1)
  {

    Date EndOfYearDate;
    EndOfYearDate._Day = 31;
    EndOfYearDate._Month = 12;
    EndOfYearDate._Year = Date1._Year;

    return GetDifferenceInDays(Date1, EndOfYearDate, true);
  }

  short DaysUntilTheEndOfYear()
  {
    return DaysUntilTheEndOfYear(*this);
  }

  // i added this method to calculate business days between 2 days
  static short CalculateBusinessDays(Date DateFrom, Date DateTo)
  {

    short Days = 0;
    while (IsDate1BeforeDate2(DateFrom, DateTo))
    {
      if (IsBusinessDay(DateFrom))
        Days++;

      DateFrom = AddOneDay(DateFrom);
    }

    return Days;
  }

  static short CalculateVacationDays(Date DateFrom, Date DateTo)
  {
    /*short Days = 0;
    while (IsDate1BeforeDate2(DateFrom, DateTo))
    {
      if (IsBusinessDay(DateFrom))
        Days++;

      DateFrom = AddOneDay(DateFrom);
    }*/

    return CalculateBusinessDays(DateFrom, DateTo);
  }
  // above method is eough , no need to have method for the object

  static Date CalculateVacationReturnDate(Date DateFrom, short VacationDays)
  {

    short WeekEndCounter = 0;

    for (short i = 1; i <= VacationDays; i++)
    {

      if (IsWeekEnd(DateFrom))
        WeekEndCounter++;

      DateFrom = AddOneDay(DateFrom);
    }
    // to add weekends
    for (short i = 1; i <= WeekEndCounter; i++)
      DateFrom = AddOneDay(DateFrom);

    return DateFrom;
  }

  static bool IsDate1AfterDate2(Date Date1, Date Date2)
  {
    return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
  }

  bool IsDateAfterDate2(Date Date2)
  {
    return IsDate1AfterDate2(*this, Date2);
  }

  enum enDateCompare
  {
    Before = -1,
    Equal = 0,
    After = 1
  };

  static enDateCompare CompareDates(Date Date1, Date Date2)
  {
    if (IsDate1BeforeDate2(Date1, Date2))
      return enDateCompare::Before;

    if (IsDate1EqualDate2(Date1, Date2))
      return enDateCompare::Equal;

    /* if (IsDate1AfterDate2(Date1,Date2))
       return enDateCompare::After;*/

    // this is faster
    return enDateCompare::After;
  }

  enDateCompare CompareDates(Date Date2)
  {
    return CompareDates(*this, Date2);
  }
};
