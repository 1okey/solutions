#include <iostream>
#include <vector>
#include <deque>
using namespace std;

struct Operation {
  char type = 0;
  int operand = 0;
};

bool NeedsBraces(char last_operator, char current_operator){
  return (current_operator == '*' || current_operator == '/') &&
      (last_operator == '+' || last_operator == '-');
}

void PrintWithBraces(vector<Operation>& operations, int& initial){
  deque<string> expression;
  char last_operator = '*';
  expression.push_front(to_string(initial));
  for(Operation& o: operations){
    if(NeedsBraces(last_operator, o.type)){
      expression.push_front("(");
      expression.push_back(")");
    }
    expression.push_back(" ");
    expression.push_back(string(1, o.type));
    expression.push_back(" ");
    expression.push_back(to_string(o.operand));
    last_operator = o.type;
  }
  for(auto& item: expression){
    cout << item;
  }
}

void PrintWithExtraBraces(vector<Operation>& operations, int& initial){
  deque<string> expression;
  expression.push_front(to_string(initial));
  for(Operation& o: operations){
    expression.push_front("(");
    expression.push_back(") ");
    expression.push_back(string(1, o.type));
    expression.push_back(" ");
    expression.push_back(to_string(o.operand));
  }
  for(auto& item: expression){
    cout << item;
  }
};

int main(){
  int initial;
  size_t n;
  cin >> initial >> n;
  vector<Operation> operations(n);
  for(Operation& o : operations){
    cin >> o.type >> o.operand;
  }
//  PrintWithExtraBraces(operations, initial);
//  PrintWithBraces(operations, initial);
}

