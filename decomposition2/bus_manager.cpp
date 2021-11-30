#include "bus_manager.h"
#include "responses.h"

#include <string>
#include <vector>


  void BusManager::AddBus(const string& bus, const vector<string>& stops) {
    // Реализуйте этот метод
	  for (const string& stop : stops) {
		  buses_to_stops[bus].push_back(stop);
	          stops_to_buses[stop].push_back(bus);
	        }
  }

  BusesForStopResponse BusManager::GetBusesForStop(const string& stop) const {
    // Реализуйте этот метод
	  BusesForStopResponse r;
	  r.stop = stop;
	  if (stops_to_buses.count(stop) == 1) {
		  r.buses_for_stop = stops_to_buses.at(stop);
          //cout << "Added buses to response" << endl;
	  }
	  return r;
  }

  StopsForBusResponse BusManager::GetStopsForBus(const string& bus) const {
    // Реализуйте этот метод
	  StopsForBusResponse r;
	  r.bus = bus;
	  r.stops_to_buses = stops_to_buses;
	  if (buses_to_stops.count(bus) == 1) {
		  r.stops = buses_to_stops.at(bus);
	  }
	  return r;
  }

  AllBusesResponse BusManager::GetAllBuses() const {
    // Реализуйте этот метод
	  AllBusesResponse r;
	  r.buses_to_stops = buses_to_stops;
	  return r;
  }
