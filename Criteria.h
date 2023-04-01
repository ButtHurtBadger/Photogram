#ifndef CRITERIA_H
#define CRITERIA_H

#include "Photo.h"

using namespace std;

class Criteria{
  friend ostream& operator<<(ostream&, const Criteria&);
  public:
    Criteria();
    virtual bool matches(const Photo&) const = 0;
    virtual void print(ostream&) const = 0;
};


class Cat_Criteria : virtual public Criteria{
  public:
    Cat_Criteria(string cat="");

    virtual bool matches(const Photo&) const;
    virtual void print(ostream&) const;

  protected:
      string category;
};

class Date_Criteria : virtual public Criteria{
public:
  Date_Criteria(Date s, Date e);

  virtual bool matches(const Photo&) const;
  virtual void print(ostream&) const;

protected:
      Date start;
      Date end;
};

class CandD_Criteria : public Cat_Criteria, virtual public Date_Criteria{
public:
  CandD_Criteria(Date s, Date e, string c="");
  virtual bool matches(const Photo&) const;
  virtual void print(ostream&) const;
};



#endif
