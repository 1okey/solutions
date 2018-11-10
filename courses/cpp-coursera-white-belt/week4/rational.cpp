#include <iostream>
#include <exception>
using namespace std;

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>

using namespace std;

class Rational {
public:
  Rational() {  // дробь по умолчанию — 0/1
    numerator_ = 0;
    denominator_ = 1;
  }
  Rational(int new_numerator, int new_denominator) {
    if (new_denominator == 0) {
      throw invalid_argument("Invalid argument");
    }
    const int gcd = getGcd(abs(new_numerator), abs(new_denominator));
    numerator_ = new_numerator / gcd;
    denominator_ = new_denominator / gcd;
    if (denominator_ < 0) {
      denominator_ = -denominator_;
      numerator_ = -numerator_;
    }
  }

  int Numerator() const {
    return numerator_;
  }

  int Denominator() const {
    return denominator_;
  }

  void SetNumerator (const int & n){
    numerator_ = n;
    int gcd = getGcd(numerator_, denominator_);
    numerator_ /= gcd;
    denominator_ /= gcd;
  }

  void SetDenominator (const int & d){
    if(numerator_ < 0 && denominator_ < 0){
      numerator_ = abs(numerator_);
    }
    denominator_ = abs(d);
    int gcd = getGcd(numerator_, denominator_);
    numerator_ /= gcd;
    denominator_ /= gcd;
  }

private:
  int getGcd(int a, int b){
    while(a > 0 && b > 0){
      if(a > b)
        a %= b;
      else
        b %= a;
    }
    return a + b;
  }
  int numerator_;
  int denominator_;
};

Rational operator+(const Rational & lhs, const Rational & rhs){
  int n = (lhs.Numerator() * rhs.Denominator()) + (rhs.Numerator() * lhs.Denominator());
  return Rational(n, lhs.Denominator() * rhs.Denominator());
}

Rational operator-(const Rational & lhs, const Rational & rhs){
  int n = (lhs.Numerator() * rhs.Denominator()) - (rhs.Numerator() * lhs.Denominator());
  return Rational(n, lhs.Denominator() * rhs.Denominator());
}

Rational operator*(const Rational & lhs, const Rational & rhs){
  return Rational(lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator());
}

Rational operator/(const Rational & lhs, const Rational & rhs){
  if (rhs.Numerator() == 0) {
    throw domain_error("Division by zero");
  }
  return Rational(lhs.Numerator() * rhs.Denominator(), lhs.Denominator() * rhs.Numerator());
}

bool operator<(const Rational & lhs, const Rational & rhs){
  return (lhs.Numerator() * rhs.Denominator()) < (lhs.Denominator() * rhs.Numerator());
}

bool operator>(const Rational & lhs, const Rational & rhs){
  return (lhs.Numerator() * rhs.Denominator()) > (lhs.Denominator() * rhs.Numerator());
}

istream & operator>>(istream & stream, Rational & r){
  int n = 0,d = 0;
  stream >> n;
  stream.ignore(1);
  if(stream.eof()){
    return stream ;
  }
  stream >> d;
  r = {n,d};

  return stream;
}

ostream & operator<<(ostream & stream, const Rational & lhs){
  stream << lhs.Numerator() << "/" << lhs.Denominator();
  return stream;
}

bool operator==(const Rational & lhs, const Rational & rhs){
  return ((lhs.Numerator() * rhs.Denominator()) == (rhs.Numerator() * lhs.Denominator()));
}


int main(){
  Rational r1, r2, r3;
  char op;
  try {
    cin >> r1 >> op >> r2;
    if(op == '+'){
      r3 = r1 + r2;
    } else if(op == '-'){
      r3 = r1 - r2;
    } else if(op == '/'){
      r3 = r1 / r2;
    } else if(op == '*'){
      r3 = r1 * r2;
    }
    cout << r3;
  } catch (const invalid_argument & ex) {
    cout << ex.what() << endl;
  } catch (const domain_error & ex){
    cout << ex.what() << endl;
  }

  return 0;
}

