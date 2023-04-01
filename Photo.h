
#ifndef PHOTO_H
#define PHOTO_H

#include "Date.h"

using namespace std;

class Photo {

	friend ostream& operator<<(ostream&, const Photo&);

	public:
		//constructor
		Photo(const string&, const string&, const Date&, const string&);
		Photo(const Photo&);

		//getters
		string getCategory() const;
		Date getDate() const;

		//other
		bool equals(string);
		void print ( ostream &) const ;
		void display ( ostream &) const ;


	private:
		//variables
		string title;
    string content;
		string category;
    Date date;
};
#endif
