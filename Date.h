
#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
#include <iomanip>
#include "defs.h"

using namespace std;

class Date {
		//Override

		friend ostream& operator<<(ostream&, const Date&);

	public:
		//constructor
		Date();
		Date(int year, int month, int day);
		Date(const Date&);

		//setters
		void setDay( int);
		void setMonth(int);
		void setYear(int);
		void setDate(int, int, int);
		void setDate(Date&);

		//getters
		int getDay() const;
		int getMonth() const;
		int getYear() const;
		string getMonthName() const;

		//other
		void incDate();
		void addDays(int);
		bool lessThan(const Date& d) const;
		bool equals(const Date& d) const;
		void print(ostream&) const;

		bool operator<(const Date&) const;
		bool operator==(const Date&) const;
		bool operator<=(const Date&) const;


	private:
		//functions
		int getMaxDay() const;

		//variables
		int day;
		int month;
		int year;

};
#endif
