#include <iostream>
#include <string.h>
#include <cstring>
#include <math.h>

using namespace std;

class DayOfYear {
public:
			DayOfYear(int year, int month, int day ,int dayofweak);
	int		getDay(int year, int month, int day);
private:
	int Year;
	int Month;
	int Day;

	int DayOfWeak;
	
	int MonthDays[13] = { 0,31,31,31,31,31,31,30,30,30,30,30,29 };

	int		checkDirection(int year, int month, int day);
	bool	checkLeapYear(int year);

	int	getDaysBetweenMonths(int start_m, int end_m,int year);
	int	getDaysBetweenYears(int start_m, int end_m);
	int	getDayRes(int res);
};

DayOfYear::DayOfYear(int year, int month, int day, int dayofweak) {
	this->Year = year;
	this->Month = month;
	this->Day = day;
	this->DayOfWeak = dayofweak;
}

int DayOfYear::checkDirection(int year, int month, int day) {
	// 1 for forward  direction 
	// 0 for current  point
	//-1 for backward direction
	if (this->Year <= year) {
		if (this->Month <= month) {
			if (this->Day < day) {
				return -1;
			}
			else if (this->Day == day) {
				return 0;
			}
			else {
				return 1;
			}
		}
		else {
			return 1;
		}
	}
	else {
		return 1;
	}
}

bool DayOfYear::checkLeapYear(int year) {
	int a = 0;
	int b = 1309;
	for (int i = 1309; i <= (year + 5); i += 4) {
		b+=4;
		a++;
		if (a % 8 == 0)
			b++;
		if (b == year) {
			return true;
		}
	}
	return false;
}

int DayOfYear::getDaysBetweenMonths(int start_m, int end_m, int year) {
	int sum = 0;
	for (int m = start_m; m <= end_m; m++) {
		sum += MonthDays[m];
		if (m == 12 && checkLeapYear(year)) {
			sum++;
		}
	}
	return sum;
}

int DayOfYear::getDaysBetweenYears(int start_m, int end_m) {
	int sum = 0;
	for (int y = start_m; y < end_m; y++) {
		if (checkLeapYear(y))
			sum += 366;
		else
			sum += 365;
	}
	return sum;
}

int DayOfYear::getDayRes(int res) {
	if (res == 0 || res == -7 || res == 7) {
		return 0;
	}
	else if (res == 1 || res == -6 || res == 8) {
		return 1;
	}
	else if (res == 2 || res == -5 || res == 9) {
		return 2;
	}
	else if (res == 3 || res == -4 || res == 10) {
		return 3;
	}
	else if (res == 4 || res == -3 || res == 11) {
		return 4;
	}
	else if (res == 5 || res == -2 || res == 12) {
		return 5;
	}
	else if (res == 6 || res == -1 || res == 13) {
		return 6;
	}
}

int DayOfYear::getDay(int year, int month, int day) {
	int check = checkDirection(year, month, day);
	int res = 0;
	if (check == 0) {
		//curent point
		return this->DayOfWeak;
	}
	else if (check == 1) {
		//forward direction
		int sum_d = 0;
		if (year == this->Year) {
			if (month == this->Month) {
				sum_d += this->Day - day;
			}
			else {
				sum_d += MonthDays[month] - day;
				sum_d += getDaysBetweenMonths((month + 1), (this->Month-1), year);
				sum_d += this->Day;
			}
		}
		else {
			sum_d += MonthDays[month] - day;
			sum_d += getDaysBetweenMonths((month + 1), 12, year);
			sum_d += getDaysBetweenYears((year + 1), this->Year);
			sum_d += this->Day;
			sum_d += getDaysBetweenMonths(1, (this->Month - 1), year);
		}
		res = this->DayOfWeak - (sum_d % 7);
	}
	else if (check == -1) {
		//backward direction
		int sum_d = 0;
		if (year == this->Year) {
			if (month == this->Month) {
				sum_d += day - this->Day;
			}
			else {
				sum_d += MonthDays[this->Month] - this->Day;
				sum_d += getDaysBetweenMonths((this->Month + 1), (month - 1), year);
				sum_d += day;
			}
		}
		else {
			sum_d += MonthDays[this->Month] - this->Day;
			sum_d += getDaysBetweenMonths((this->Month + 1), 12, this->Year);
			sum_d += getDaysBetweenYears((this->Year+1),year);
			sum_d += getDaysBetweenMonths(1, (month-1), year);
			sum_d += day;
		}
		res = (this->DayOfWeak) + (sum_d % 7);
	}

	return getDayRes(res);
}

int main()
{
	bool isLeap=false;
	DayOfYear doy = DayOfYear(1395, 9, 1, 2);
	cout<<doy.getDay(1397,10,4)<<endl;
	system("Pause");
	return 0;
}

