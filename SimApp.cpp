
/*simApp.cpp
* Description: This program is used to implement an event-driven simulation application for bank.
* This program display trace of the event occured and summary of computed statistics such as
* (total number of customer processed and average amount of time spent waiting).


* Created on: April 26, 2020
* Modified by:Sarajuddin Kazimi
*/

#include "Queue.h"
#include "Event.h"
#include "PriorityQueue.h"
#include "EmptyDataCollectionException.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


//Desc: This function creates and add arrival event to event queue and Returns
//      the number of arrivals
//Pre: The inputs are space separated integers numbers and two numbers per line
int getArrivalEvents(PriorityQueue <Event>& anArrival){
	int arrivalTime = 0;
	int length = 0;
	//read the inputs
	while( cin>>arrivalTime>>length){
		Event anEvent = Event(arrival, arrivalTime, length);
		anArrival.enqueue(anEvent);
	}
	return anArrival.getLength();
}


//Desc:This function process an arrival Event
//Post: This event is removed from Event PriorityQueue
void processArrival(bool &tellerAvailable,PriorityQueue <Event>& anEvent, Queue <Event>& bankline){
	//get transaction and current time of event and dequeue from eventPriorityQueue

	Event currentEvent = anEvent. peek();
	int currentTime = currentEvent.getTime();
	int transactionTime = currentEvent.getLength();
	anEvent.dequeue();

	cout<<"Processing an arrival event at time:"<<right<<setw(5)<<currentTime<<endl;
	//if no one in the line and teller is available customer is served else sent to waiting line.
	if(bankline.isEmpty() && tellerAvailable){
		int departTime = currentTime + transactionTime;
		Event departEvent = Event(departure, departTime,0);
		anEvent.enqueue(departEvent);
		tellerAvailable = false;
	}else{
		bankline.enqueue(currentEvent);
	}
}

//Desc:This function process a departure Event and return the waiting time of the customers in line.
//Post: This event is removed from Event PriorityQueue
int processDeparture(bool &tellerAvailable,PriorityQueue <Event>& anEvent, Queue <Event>& bankline){

	Event currentEvent = anEvent. peek();
	int currentTime = currentEvent.getTime();
	int waitingTime = 0;
	anEvent.dequeue();
	cout<<"Processing a departure event at time:"<<right<<setw(4)<<currentTime<<endl;

	if(!bankline.isEmpty()){
		Event customer = bankline.peek();
		//calculate the waiting time
		waitingTime = currentTime-customer.getTime();
		bankline.dequeue();
		int departTime = currentTime + customer.getLength();
		Event departEvent = Event(departure, departTime,0);
		anEvent.enqueue(departEvent);
	}else{
		tellerAvailable = true;
	}
	return waitingTime;
}



int main () {
	//bank line
	Queue <Event> bankline = Queue<Event>();

	//Event Queue
	PriorityQueue <Event> eventPriorityQueue = PriorityQueue<Event>();

	bool tellerAvailable =true;
	int numOfCustomer = 0;
	int waitingTime = 0;
	double averageWaitTime = 0;

	//get, create and add arrival to eventPriorityQueue and return the
	numOfCustomer = getArrivalEvents(eventPriorityQueue);
	cout<<"Simulation Begins"<<endl;

	//event loop
	while(!eventPriorityQueue.isEmpty()){
		//get the newEvent
		Event newEvent = eventPriorityQueue.peek();
		//if arrival process arrival
		if(newEvent.getType()==arrival){
				processArrival(tellerAvailable,eventPriorityQueue,bankline);
		//if depature process departure and get the waiting time
		}else{
			waitingTime +=	processDeparture(tellerAvailable,eventPriorityQueue,bankline);
		}

	}
	//if numOfCustomer is not zero.
	if(numOfCustomer!=0)
		averageWaitTime = double(waitingTime)/double(numOfCustomer);

	//statistics output.
	cout<<"Simulation Ends\n\n"<<"Final Statistics:  "<<endl;
	cout<<"    Total number of people processed:  "<<numOfCustomer<<endl;
	cout<<"    Average amount of time spent waiting: "<<averageWaitTime<<endl;

	return 0;
} // main
