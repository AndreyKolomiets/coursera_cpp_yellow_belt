#include <iostream>
#include <vector>
#include <map>
#include <utility>

using namespace std;

template <typename T, typename Key>
map<Key, T> operator * (const map<Key, T>& l, const map<Key, T>& r);

template <typename T>
T Sqr(T x);
template <typename T>
vector<T> operator * (const vector<T>& l, const vector<T>& r);

template <typename T1, typename T2>
pair<T1, T2> operator *(const pair<T1, T2>& l, const pair<T1, T2>& r);

template <typename T1, typename T2>
pair<T1, T2> operator *(const pair<T1, T2>& l, const pair<T1, T2>& r) {
	return make_pair(l.first*r.first, l.second*r.second);
}

template <typename T>
vector<T> operator * (const vector<T>& l, const vector<T>& r) {
	vector<T> out(l.size());
	for (size_t i=0; i< l.size(); i++) {
		out[i] = l[i] * r[i];
	}
	return out;
}

template <typename T, typename Key>
map<Key, T> operator * (const map<Key, T>& l, const map<Key, T>& r) {
	map<Key, T> out;
	for (auto [key, value]: l) {
		out[key] = value * value;
	}
	return out;
}



template <typename T>
T Sqr(T x) {
	return x*x;
}



int main() {
	vector<int> v = {1,2,3};
	auto v2 = Sqr(v);
	for (auto v_i: v2) {
		cout << v_i << " ";
	}
	cout << endl;
	map<int, int> m;
	m[1] = 2;
	m[3] = 4;
	auto m2 = Sqr(m);
	for (auto [key, value]: m2) {
		cout << key << "," << value << ";";
	}
	cout << endl;

	map<int, pair<int, int> > mp;
	mp[1] = {2, 3};
	mp[4] = {5, 6};
	auto mp2 = Sqr(mp);
	for (auto [key, value]: mp2) {
		cout << key << ":" << value.first << ", " << value.second << "; ";
	}
	cout << endl;

	vector<pair<int, int> > vp = {{1,2}, {3,4}};
	auto vp2 = Sqr(vp);
	for (pair<int, int> p: vp2) {
		cout << p.first << " " << p.second << "; ";
	}
	cout << endl;
	return 0;
}
