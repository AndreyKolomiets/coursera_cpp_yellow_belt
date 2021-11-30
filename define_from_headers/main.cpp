/*
 * main.cpp
 *
 *  Created on: 30 нояб. 2021 г.
 *      Author: ak
 */

#include "sum_reverse_sort.h"
#include <sstream>
#include <algorithm>

using namespace std;

int Sum(int x, int y) {
	return x+y;
}

string Reverse(string s) {
	ostringstream ss;
	for (int i=s.size()-1; i>=0; i--) {
		ss << s[i];
	}
	return ss.str();
}

void Sort(vector<int>& nums) {
	sort(begin(nums), end(nums));
}


