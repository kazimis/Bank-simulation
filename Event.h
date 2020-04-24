/*Event.h
 * Class Description: This class represents a simulation event which handles arrival and departure time.
 * Class invariant: The time are integer numbers


 * Author: Sarajuddin Kazimi
 * Date: April 23, 2020
 */
#pragma once
#include<string>
#include <iostream>
using namespace std;

typedef enum etype { arrival, departure } EventType;

class Event {
  private:
    EventType type;//type of event
    int time;//Time when the event occurs
    int length;//transaction time

  public:

    //Description: default Constructor. set time and length to zero and no action for type.
    Event();

    // Parameterized Constructor
    // Description: Create event with the given given type, time and length.
    //Pre: aLength and aType are integers and aType is type EventType.
    Event(EventType aType, int aTime, int aLength);

    //getters and setters

    // Description: Returns Event time.
    int getTime()const;

    //Description: Returns Event transaction time
    int getLength()const;

    //Description: Returns Event type.
    EventType getType()const;

    //Description: Sets Event Time
    void setTime(const int aTime);

    //Description: Sets Event transaction time
    void setLength(const int aLength);

    //Description: Sets Event type
    void setType(const EventType aType);

    //comparators

    // Description: Compares "this" Event object with "r" Event object.
    //              Returns true if the time of "this" Event < time of "r" event and false otherwise
    bool operator<(const Event &r) const;

    // Description: Compares "this" Event object with "r" Event object.
    //              Returns true if the time of "this" Event > time of "r" event and false otherwise
    bool operator>(const Event &r) const;

    // Description: Compares "this" Event object with "r" Event object.
    //              Returns true if the time of "this" Event <= time of "r" event and false otherwise
    bool operator<=(const Event &r) const;

    // Description: Compares "this" Event object with "r" Event object.
    //              Returns true if the time of "this" Event >= time of "r" event and false otherwise
    bool operator>=(const Event &r) const;


    // Description: Prints the content of "this".
    friend ostream & operator<<(ostream & os, const Event & anEvent);



};
