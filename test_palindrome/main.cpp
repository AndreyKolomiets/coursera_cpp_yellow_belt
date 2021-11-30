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

bool IsPalindrom(const string& s) {
  // Вы можете вставлять сюда различные реализации функции,
  // чтобы проверить, что ваши тесты пропускают корректный код
  // и ловят некорректный
	int n = s.size();
	for (int i =0; i<n/2; i++) {
		//cout << s[i] << " " << s[n-i-1] << endl;
		if (s[i] != s[n-i-1]) {
			return false;
		}
	}
	return true;
}

void TestEmpty() {
	Assert(IsPalindrom(""), "Empty is palindrome");
}

void TestOneSymbol() {
	Assert(IsPalindrom("s"), "One symbol is palindrome");
}

void TestMultiSymbolIsPalindrome() {
	Assert(IsPalindrom("aba"), "aba");
	Assert(IsPalindrom("madam"), "madam");
	Assert(IsPalindrom("wasitacaroracatisaw"), "wasitacaroracatisaw");
	Assert(IsPalindrom("madam madam"), "madam madam");
	Assert(IsPalindrom("maddam"), "maddam");
	Assert(IsPalindrom("ma d am"), "ma d am");
	Assert(IsPalindrom(" "), "single char");
		Assert(IsPalindrom("&"), "single char");

		Assert(IsPalindrom("   "), "only space in string");
		Assert(IsPalindrom("# ## #"), "non letters string");
		Assert(IsPalindrom("   m   "), "any string");
		Assert(IsPalindrom("abcd !!_ ! _!! dcba"), "stranger palindrom");

		Assert(IsPalindrom("  "), "two spaces");
		Assert(IsPalindrom("a b c d d c b a"), "");
		Assert(IsPalindrom("aa"), "two symbols");
	//Assert(IsPalindrom("мадам"), "мадам");
}

void TestNotPalindrome() {
	Assert(!IsPalindrom("madamb"), "madamb");
	Assert(!IsPalindrom("bmadam"), "bmadam");
	Assert(!IsPalindrom("madbidam"), "madbidam");
	Assert(!IsPalindrom("Amama"), "Amama");
	Assert(!IsPalindrom(" madam"), " madam");
}

int main() {
  TestRunner runner;
  // добавьте сюда свои тесты
  runner.RunTest(TestEmpty, "TestEmpty");
  runner.RunTest(TestOneSymbol, "TestOneSymbol");
  runner.RunTest(TestMultiSymbolIsPalindrome, "TestMultiSymbolIsPalindrome");
  runner.RunTest(TestNotPalindrome, "TestNotPalindrome");
  return 0;
}
