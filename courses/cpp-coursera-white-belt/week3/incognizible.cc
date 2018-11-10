class Incognizable {
public:
  Incognizable() = default;
  Incognizable(const int& a){}
  Incognizable(const int& a, const int& b){}
};

int main() {
  Incognizable a;
  Incognizable b = {};
  Incognizable c = {0};
  Incognizable d = {0, 1};
  return 0;
}

