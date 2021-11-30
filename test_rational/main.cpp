#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
       os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};

//int gcd(int a, int b) {
//	//	int a,b, r1, r2, new_r2;
//	//		cin >> a >> b;
//		while ((a>0) & (b>0)) {
//			if (a > b) {
//				a = a%b;
//			} else {
//				b = b % a;
//			}
//		}
//		return a+b;
//}

//class Rational {
//public:
//  // Вы можете вставлять сюда различные реализации,
//  // чтобы проверить, что ваши тесты пропускают корректный код
//  // и ловят некорректный
//
//  Rational() {
//	  this->numerator = 0;
//	  this->denominator = 1;
//  };
//  Rational(int numerator, int denominator) {
//          // Реализуйте конструктор
//      	if (denominator == 0) {
//      		throw invalid_argument("Invalid argument");
//      	}
//      	int g = gcd(abs(numerator), abs(denominator));
//      	if (((numerator < 0) && (denominator < 0)) || (((numerator > 0) && (denominator < 0)))) {
//      		numerator *= -1;
//      		denominator *= -1;
//      	} else if ((numerator == 0) && (denominator < 0)) {
//      		denominator *= -1;
//      	}
//      	this->numerator = numerator / g;
//      	this->denominator = denominator / g;
//      }
//
//  int Numerator() const {
//	  return numerator;
//  }
//
//  int Denominator() const {
//	  return denominator;
//  }
//private:
//  int numerator=0, denominator=0;
//};

void TestDefaultConstructor() {
	Rational r;
	AssertEqual(r.Denominator(), 1, "Default denominator equal 1");
	AssertEqual(r.Numerator(), 0, "Default numerator equal 0");
}

void TestGCD() {
	Rational r(3, 6);
	AssertEqual(r.Numerator(), 1, "3/6 -> num=1");
	AssertEqual(r.Denominator(), 2, "3/6 -> denom=2");
	Rational r1(3, 5);
	AssertEqual(r1.Numerator(), 3, "3/5 -> num=3");
		AssertEqual(r1.Denominator(), 5, "3/5 -> denom=5");
	Rational r2(4, 6);
	AssertEqual(r2.Numerator(), 2, "4/6 -> num=2");
		AssertEqual(r2.Denominator(), 3, "4/6 -> denom=3");
}

void TestNumNegative() {
	Rational r(-1, 5);
	AssertEqual(r.Numerator(), -1, "-1/5->num=-1");
	AssertEqual(r.Denominator(), 5, "-1/5 -> denom=5");

	Rational r1(-4, 6);
	AssertEqual(r1.Numerator(), -2, "-4/6 -> num=-2");
	AssertEqual(r1.Denominator(), 3, "-4/6 -> denom=3");
}

void TestDenomNegative() {
	Rational r(1, -5);
		AssertEqual(r.Numerator(), -1, "-1/5->num=-1");
		AssertEqual(r.Denominator(), 5, "-1/5 -> denom=5");

		Rational r1(4, -6);
		AssertEqual(r1.Numerator(), -2, "-4/6 -> num=-2");
		AssertEqual(r1.Denominator(), 3, "-4/6 -> denom=3");
}

void TestBothNegative() {
	Rational r(-2, -3);
	AssertEqual(r.Numerator(), 2, "-2/-3 -> 2/3");
	AssertEqual(r.Denominator(), 3, "-2/-3 -> 2/3");
	Rational r1(-4, -6);
	AssertEqual(r1.Numerator(), 2, "-4/-6 -> 2/3");
	AssertEqual(r1.Denominator(), 3, "-4/-6 -> 2/3");
}

void TestBothPositive() {
	Rational r(2, 3);
	AssertEqual(r.Numerator(), 2, "2/3 positive");
	AssertEqual(r.Denominator(), 3, "2/3 positive");
}

void TestZeroNumerator() {
	Rational r(0, 5);
	AssertEqual(r.Numerator(), 0, "0/5 -> 0/1");
	AssertEqual(r.Denominator(), 1, "0/5 -> 0/1");
}

int main() {
  TestRunner runner;
  // добавьте сюда свои тесты
  runner.RunTest(TestDefaultConstructor, "TestDefaultConstructor");
  runner.RunTest(TestGCD, "TestGCD");
  runner.RunTest(TestBothPositive, "TestBothPositive");
  runner.RunTest(TestNumNegative, "TestNumNegative");
  runner.RunTest(TestDenomNegative, "TestDenomNegative");
  runner.RunTest(TestBothNegative, "TestBothNegative");
  runner.RunTest(TestZeroNumerator, "TestZeroNumerator");
  return 0;
}
