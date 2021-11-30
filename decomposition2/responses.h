#pragma once

#include <string>
#include <vector>
#include <map>
using namespace std;

struct BusesForStopResponse {
  // Наполните полями эту структуру
	string stop;
	vector<string> buses_for_stop;
};

struct StopsForBusResponse {
  // Наполните полями эту структуру
	string bus;
	vector<string> stops;
	map<string, vector<string> > stops_to_buses;
};

struct AllBusesResponse {
  // Наполните полями эту структуру
	map<string, vector<string> > buses_to_stops;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r);

ostream& operator << (ostream& os, const StopsForBusResponse& r);

ostream& operator << (ostream& os, const AllBusesResponse& r);
