#pragma once
#include <iostream>
#include <string>
#include "String.h"
#include "Date.h"

class InputValidate
{

public:
  static bool IsNumberBetween(short Number, short From, short To)
  {
    if (Number >= From && Number <= To)
      return true;
    else
      return false;
  }

  static bool IsNumberBetween(int Number, int From, int To)
  {
    if (Number >= From && Number <= To)
      return true;
    else
      return false;
  }

  static bool IsNumberBetween(float Number, float From, float To)
  {
    if (Number >= From && Number <= To)
      return true;
    else
      return false;
  }

  static bool IsNumberBetween(double Number, double From, double To)
  {
    if (Number >= From && Number <= To)
      return true;
    else
      return false;
  }

  static bool IsDateBetween(Date date, Date From, Date To)
  {
    // Date>=From && Date<=To
    if ((Date::IsDate1AfterDate2(date, From) || Date::IsDate1EqualDate2(date, From)) &&
        (Date::IsDate1BeforeDate2(date, To) || Date::IsDate1EqualDate2(date, To)))
    {
      return true;
    }

    // Date>=To && Date<=From
    if ((Date::IsDate1AfterDate2(date, To) || Date::IsDate1EqualDate2(date, To)) &&
        (Date::IsDate1BeforeDate2(date, From) || Date::IsDate1EqualDate2(date, From)))
    {
      return true;
    }

    return false;
  }

  static int ReadIntNumber(string ErrorMessage = "Invalid Number, Enter again\n")
  {
    int Number;
    while (!(cin >> Number))
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << ErrorMessage;
    }
    return Number;
  }

  static int ReadIntNumberBetween(int From, int To, string ErrorMessage = "Number is not within range, Enter again:\n")
  {
    int Number = ReadIntNumber();

    while (!IsNumberBetween(Number, From, To))
    {
      cout << ErrorMessage;
      Number = ReadIntNumber();
    }
    return Number;
  }

  static double ReadDblNumber(string ErrorMessage = "Invalid Number, Enter again\n")
  {
    double Number;
    while (!(cin >> Number))
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << ErrorMessage;
    }
    return Number;
  }

  static double ReadDblNumberBetween(double From, double To, string ErrorMessage = "Number is not within range, Enter again:\n")
  {
    double Number = ReadDblNumber();

    while (!IsNumberBetween(Number, From, To))
    {
      cout << ErrorMessage;
      Number = ReadDblNumber();
    }
    return Number;
  }

  static bool IsValideDate(Date Date)
  {
    return Date::IsValidDate(Date);
  }
};
