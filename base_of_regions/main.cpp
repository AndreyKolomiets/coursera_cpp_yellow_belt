#include <iostream>
#include <string>
#include <map>
#include <tuple>

using namespace std;

enum class Lang {
  DE, FR, IT
};

struct Region {
  string std_name;
  string parent_std_name;
  map<Lang, string> names;
  int64_t population;
};

tuple<string, string, map<Lang, string>, int64_t> GetRank(const Region& r) {
	return tie(r.std_name, r.parent_std_name, r.names, r.population);
}

bool operator < (const Region& lhs, const Region& rhs) {
	return GetRank(lhs) < GetRank(rhs);
}

int FindMaxRepetitionCount(const vector<Region>& regions){
	map<Region, int> counter;
	for (const Region& r: regions) {
		counter[r]++;
	}
	int max_count = -1;
	Region max_region;
	for (const auto& [key, value]: counter) {
		if (value > max_count) {
			max_count = value;
			max_region = key;
		}
	}
	return max_count;
}

int main() {
	vector<Region> vec1 = {
		      {
		          "Moscow",
		          "Russia",
		          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
		          89
		      }, {
		          "Russia",
		          "Eurasia",
		          {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
		          89
		      }, {
		          "Moscow",
		          "Russia",
		          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
		          89
		      }, {
		          "Moscow",
		          "Russia",
		          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
		          89
		      }, {
		          "Russia",
		          "Eurasia",
		          {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
		          89
		      },
		  }
	cout << FindMaxRepetitionCount(vec1) << endl;

	  cout << FindMaxRepetitionCount({
	      {
	          "Moscow",
	          "Russia",
	          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
	          89
	      }, {
	          "Russia",
	          "Eurasia",
	          {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
	          89
	      }, {
	          "Moscow",
	          "Russia",
	          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou deux"}, {Lang::IT, "Mosca"}},
	          89
	      }, {
	          "Moscow",
	          "Toulouse",
	          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
	          89
	      }, {
	          "Moscow",
	          "Russia",
	          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
	          31
	      },
	  }) << endl;
	return 0;
}
