//Вам дан класс Rational, который описывает рациональное число. В нем определены методы add, sub,
//mul и div, которые прибавляют к нему число, отнимают число, умножают на число и делят на число
//соответственно. Кроме того в нем определен метод neg, который меняет знак на противоположный.

//Вам нужно определить операторы +=, -=, *=, /= для класса Rational так, чтобы они могли принимать
//в качестве аргументов и объекты типа Rational и целые числа. Кроме того вам необходимо определить
//операторы унарного минуса и плюса для класса Rational.

struct Rational
{
  Rational(int numerator = 0, int denominator = 1);

  void add(Rational rational);
  void sub(Rational rational);
  void mul(Rational rational);
  void div(Rational rational);

  void neg();
  void inv();
  double to_double() const;

  Rational & operator+=(Rational rational) {
    add(rational);
    return (*this);
  }

  Rational & operator+=(int number) {
    add(Rational(number));
    return (*this);
  }

  Rational & operator-=(Rational rational) {
    sub(rational);
    return (*this);
  }

  Rational & operator-=(int number) {
    sub(Rational(number));
    return (*this);
  }

  Rational & operator*=(Rational rational) {
    mul(rational);
    return (*this);
  }

  Rational & operator*=(int number) {
    mul(Rational(number));
    return (*this);
  }

  Rational & operator/=(Rational rational) {
    div(rational);
    return (*this);
  }

  Rational & operator/=(int number) {
    div(Rational(number));
    return (*this);
  }

  Rational operator+() const{
    Rational rat = *this;
    return rat;
  }

  Rational operator-() const{
    Rational rat = (*this);
    rat.neg();
    return rat;
  }

  operator double() const {
    double d = (*this).to_double();
    return d;
  }

  int lhs() const {
    return (int)numerator_;
  }
  int rhs() const {
    return (int)denominator_;
  }

private:
  int numerator_;
  int denominator_;
};

// Определите для класса Rational операторы сложения, вычитания, умножения и деления,
// так чтобы объекты типа Rational можно было складывать (вычитать, умножать и делить) не
// только друг с другом но и с целыми числами.

Rational operator+(Rational r1, Rational const& r2) {
  return r1+=r2;
}
Rational operator-(Rational r1, Rational const& r2) {
  return r1-=r2;
}
Rational operator*(Rational r1, Rational const& r2) {
  return r1*=r2;
}
Rational operator/(Rational r1, Rational const& r2) {
  return r1/=r2;
}

// Еще одна важная группа операторов, которые полезно реализовать для класса рациональных чисел —
// это операторы сравнения. Реализуйте операторы <, <=, >, >=, ==, != для класса Rational так,
// чтобы можно было сравнивать объекты класса Rational не только друг с другом, но и с целыми числами.
//
// При решении задания не используйте метод to_double, он введен в класс, в первую очередь,
// для удобства тестирования. Вы можете определять любые вспомогательные методы или функции
// если необходимо.

bool operator==(Rational const& r1, Rational const& r2){
  return (r1.lhs() * r2.rhs()) == (r2.lhs() * r1.rhs());
};
bool operator<(Rational const& r1, Rational const& r2){
  return (r1.lhs() * r2.rhs()) < (r2.lhs() * r1.rhs());
};

bool operator!=(Rational const& r1, Rational const& r2) {
  return !(r1 == r2);
};
bool operator>(Rational const& r1, Rational const& r2) {
  return r2 < r1;
};
bool operator<=(Rational const& r1, Rational const& r2){
  return !(r2 < r1);
};
bool operator>=(Rational const& r1, Rational const& r2) {
  return !(r1 < r2);
};

