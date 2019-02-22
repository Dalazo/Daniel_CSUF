


#include "person.h"
#include <string>

Person::Person()
{

}

float Person::totalPay()
{
 return hoursWorked * payRate   
}
void Person::setHoursWorked(float hours)
{

hoursWorked = hours;

}
    
void Person::setFirstName(string fName)
{

firstName = fName;

}    
void Person::setLastName(string lName)
{

lastName = lName;

}    

void Person::setPayRate(float payrate)
{

payRate = payrate;


}

std::string Person::getFirstName()
{
return firstName;
}

std::string Person::getLastName()
{

return lastName;

}

float Person::getPayRate()
{

return payRate;

}

float Person::getHoursWorked()
{

return hoursWorked;

}

std::string Person::fullName()
{


return firstName + " " + lastName;

}

   
