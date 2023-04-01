#include "Criteria.h"


ostream& operator<<(ostream& os, const Criteria& t){
	t.print(os);
	return os;
}

Criteria::Criteria(){}
bool Criteria::matches(const Photo& p) const{
  return false;
}
void Criteria::print(ostream& os) const{}

Cat_Criteria::Cat_Criteria(string cat) : category(cat){}

bool Cat_Criteria::matches(const Photo& p) const{
  if(category==p.getCategory()) return true;

  return false;
}

void Cat_Criteria::print(ostream& os) const{
  os<<"Cat_Criteria: "<<category<<endl;
}




Date_Criteria::Date_Criteria(Date s, Date e) : start(s), end(e){}

bool Date_Criteria::matches(const Photo& p) const{
  if (start.getYear() < p.getDate().getYear() || end.getYear() > p.getDate().getYear()){
    return true;
  }
  else if (start.getYear() == p.getDate().getYear()){
    if (start.getMonth() < p.getDate().getMonth()){
      return true;
    }
    else if (start.getMonth() == p.getDate().getMonth()){
      if (start.getDay() <= p.getDate().getDay()){
        return true;
      }
    }
  }
  else if(end.getYear() == p.getDate().getYear()){
    if (end.getMonth() > p.getDate().getMonth()){
      return true;
    }
    else if (end.getMonth() == p.getDate().getMonth()){
      if (end.getDay() >= p.getDate().getDay()){
        return true;
      }
    }
  }
  return false;
}

void Date_Criteria::print(ostream& os) const{
  os<<"Date_Criteria: \nStart: ";
  start.print(os);
  os<<"\nEnd: ";
  end.print(os);
  os<<endl;
}




CandD_Criteria::CandD_Criteria(Date s, Date e, string c) : Cat_Criteria(c), Date_Criteria(s, e){}

bool CandD_Criteria::matches(const Photo& p) const{
  bool flag=false;
  if (start.getYear() < p.getDate().getYear() || end.getYear() > p.getDate().getYear()){
    flag= true;
  }
  else if (start.getYear() == p.getDate().getYear()){
    if (start.getMonth() < p.getDate().getMonth()){
      flag= true;
    }
    else if (start.getMonth() == p.getDate().getMonth()){
      if (start.getDay() <= p.getDate().getDay()){
        flag= true;
      }
    }
  }
  else if(end.getYear() == p.getDate().getYear()){
    if (end.getMonth() > p.getDate().getMonth()){
      flag= true;
    }
    else if (end.getMonth() == p.getDate().getMonth()){
      if (end.getDay() >= p.getDate().getDay()){
        flag= true;
      }
    }
  }
  if(category==p.getCategory() && flag==true){
    return true;
  }
  return false;
}

void CandD_Criteria::print(ostream& os) const{
  os<<"CandD_Criteria: \nStart: ";
  start.print(os);
  os<<"\nEnd: ";
  end.print(os);
  os<<"\nCategory: "<<category<<endl;
}
