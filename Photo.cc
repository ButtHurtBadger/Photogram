#include "Photo.h"



Photo::Photo(const string& t, const string& ca, const Date& d, const string& c){
    title=t;
    category=ca;
    date=d;
    content=c;
}
Photo::Photo(const Photo& p){
  title=p.title;
  category=p.category;
  content=p.content;
  date=p.date;
}

string Photo::getCategory() const{
  return category;
}

Date Photo::getDate() const{
  return date;
}

bool Photo::equals(string t){
    if (title.compare(t) == 0){ return true;}
    else{ return false;}
}

void Photo::print(ostream& os) const{
    os<<"Title: "<<title<<"\n";
    date.print(os);
    os<<endl;
}

void Photo::display(ostream& os) const{
    os<<"title: "<<title<<"\n";
    os<<"date: ";
    date.print(os);
    os<<"\n"<<content<<endl;
}

ostream& operator<<(ostream& os, const Photo& t){
	t.print(os);
	return os;
}
