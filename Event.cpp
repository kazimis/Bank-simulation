/*Event.cpp
 * Class Description: This class represents a simulation event which handles arrival and departure time.
 * Class invariant: The time are integer numbers
 *
 * Author: Sarajuddin Kazimi
 * Date: April 23, 2020
 */
#include "Event.h"

//Description: default Constructor. set time and length to zero and no action for type.
Event::Event():time(0),length(0){

}
// Parameterized Constructor
// Description: Create event with the given given type, time and length.
//Pre: aLength and aType are integers and aType is type EventType.
Event::Event(EventType aType, int aTime, int aLength):type(aType),time(aTime),length(aLength){

}//Event()

//getters and setters
// Description: Returns Event time.
int Event::getTime()const{
  return time;
}


//Description: Returns Event transaction time
int Event::getLength()const{
  return length;
}


//Description: Returns Event type.
EventType Event::getType()const{
  return type;
}


//Description: Sets Event Time
void Event::setTime(const int aTime){
  time = aTime;
}


//Description: Sets Event transaction time
void Event::setLength(const int aLength){
  length = aLength;
}


//Description: Sets Event type
void Event::setType(const EventType aType){
  type = aType;
}

//comparators
// Description: Compares "this" Event object with "r" Event object.
      //              Returns true if the time of "this" Event < time of "r" event and false otherwise
bool Event::operator<(const Event &r) const{
  if (this->time < r.getTime() )
    return true;
  else
    return false;
}


// Description: Compares "this" Event object with "r" Event object.
//              Returns true if the time of "this" Event > time of "r" event and false otherwise
bool Event::operator>(const Event &r) const {
  if(this->time > r.getTime())
    return true;
  else
    return false;
}


// Description: Compares "this" Event object with "r" Event object.
//              Returns true if the time of "this" Event <= time of "r" event and false otherwise
bool Event::operator<=(const Event &r) const {
  if(this->time <= r.getTime())
    return true;
  else
    return false;
}


// Description: Compares "this" Event object with "r" Event object.
//              Returns true if the time of "this" Event >= time of "r" event and false otherwise
bool Event::operator>=(const Event &r) const {
  if(this->time >= r.getTime())
    return true;
  else
    return false;
}


//Description: Overloader operator << to print the anEvent.
ostream & operator<<(ostream & os, const Event & anEvent) {
  //freind function to class. We can get data directly.
  os << "Event Type is "<<anEvent.type << " Time is "<< anEvent.time<<" Length is "<<anEvent.length<<endl;
  return os;
}
