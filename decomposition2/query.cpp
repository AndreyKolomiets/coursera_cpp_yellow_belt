#include "query.h"
#include <iostream>
#include <string>
#include <vector>

istream& operator >> (istream& is, Query& q) {
  // Реализуйте эту функцию
	string operation_code;
	is >> operation_code;
	if (operation_code == "NEW_BUS") {
			q.type = QueryType::NewBus;
	      is >> q.bus;
	      int stop_count;
	      is >> stop_count;
	      vector<string>& stops = q.stops;
	      stops.resize(stop_count);
	      for (string& stop : stops) {
	        cin >> stop;
	      }

	    } else if (operation_code == "BUSES_FOR_STOP") {
	    	q.type = QueryType::BusesForStop;
	      is >> q.stop;

	    } else if (operation_code == "STOPS_FOR_BUS") {
	    	q.type = QueryType::StopsForBus;
	      is >> q.bus;


	    } else if (operation_code == "ALL_BUSES") {
	    	q.type = QueryType::AllBuses;

	    }
  return is;
}
