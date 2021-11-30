#include "phone_number.h"
#include <exception>
#include <sstream>
#include <iostream>


  /* Принимает строку в формате +XXX-YYY-ZZZZZZ
     Часть от '+' до первого '-' - это код страны.
     Часть между первым и вторым символами '-' - код города
     Всё, что идёт после второго символа '-' - местный номер.
     Код страны, код города и местный номер не должны быть пустыми.
     Если строка не соответствует этому формату, нужно выбросить исключение invalid_argument.
     Проверять, что номер содержит только цифры, не нужно.

     Примеры:
     * +7-495-111-22-33
     * +7-495-1112233
     * +323-22-460002
     * +1-2-coursera-cpp
     * 1-2-333 - некорректный номер - не начинается на '+'
     * +7-1233 - некорректный номер - есть только код страны и города
  */
  PhoneNumber::PhoneNumber(const string &international_number) {
	  if (international_number[0] != '+') {
		  throw invalid_argument("");
	  }
	  int i=1;
	  ostringstream ss;
	  while ((international_number[i] != '-') && (i < international_number.size())) {
		  ss << international_number[i];
		  i++;
	  }
	  this->country_code_ = ss.str();
	  //cout << country_code_ << endl;

	  if ((i == international_number.size()) || (country_code_.size() == 0)) {
		  throw invalid_argument("");
	  }
	  i++;
	  ostringstream ss1;
	  	  while ((international_number[i] != '-') && (i < international_number.size())) {
	  		  ss1 << international_number[i];
	  		  i++;
	  	  }
	  this->city_code_ = ss1.str();
	  //cout << i << " " << city_code_ << endl;
	  if ((i == international_number.size())  || (city_code_.size() == 0)) {
	  		  throw invalid_argument("");
	  	  }
	  i++;
	  ostringstream ss2;
	  	  	  while (i < international_number.size()) {
	  	  		  ss2 << international_number[i];
	  	  		  i++;
	  	  	  }
	  this->local_number_ = ss2.str();
	  //cout << local_number_ << endl;
	  if ((local_number_.size() == 0)) {
		  throw invalid_argument("");
	  }
  }

  string PhoneNumber::GetCountryCode() const {
	  return country_code_;
  }
  string PhoneNumber::GetCityCode() const {
	  return city_code_;
  }
  string PhoneNumber::GetLocalNumber() const {
	  return local_number_;
  }
  string PhoneNumber::GetInternationalNumber() const {
	  return "+" + country_code_ + "-" + city_code_ + "-" + local_number_;
  }


//int main() {
//	PhoneNumber n("+--");
//	return 0;}
