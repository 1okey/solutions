#include <iostream>
#include <string>
#include <vector>

// У каждого из нас есть ежемесячные дела, каждое из которых нужно выполнять в конкретный день
// каждого месяца: оплата счетов за электричество, абонентская плата за связь и пр.
//Вам нужно реализовать работу со списком таких дел, а именно, обработку следующих операций:

// -- ADD i s
// Добавить дело с названием s в день i.

// -- NEXT
// Закончить текущий месяц и начать новый. Если новый месяц имеет больше дней, чем текущий,
// добавленные дни изначально не будут содержать дел. Если же в новом месяце меньше дней, дела
//со всех удаляемых дней необходимо будет переместить на последний день нового месяца.

// Обратите внимание, что количество команд этого типа может превышать 11.

// -- DUMP i
// Вывести все дела в день i.

// Изначально текущим месяцем считается январь. Количества дней в месяцах соответствуют
// Григорианскому календарю с той лишь разницей, что в феврале всегда 28 дней.

// -- УКАЗАНИЕ --
// Для дописывания всех элементов вектора v2 в конец вектора v1 удобно использовать метод insert:



// -- ФОРМАТ ВВОДА --
// Сначала число операций Q, затем описания операций.
//Названия дел s уникальны и состоят только из латинских букв, цифр и символов подчёркивания.
//Номера дней i являются целыми числами и нумеруются от 1 до размера текущего месяца.

// -- ФОРМАТ ВЫВОДА --
// Для каждой операции типа DUMP в отдельной строке выведите количество дел в соответствующий день,
// а затем их названия, разделяя их пробелом. Порядок вывода дел в рамках каждой операции значения
// не имеет.


using std::cin;
using std::cout;
using std::string;
using std::vector;
using std::endl;

const vector<size_t> MONTH_LENGTHS =
  {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const size_t MONTH_COUNT = MONTH_LENGTHS.size();

int main() {
  int q;
  cin >> q;

  size_t month = 0;
  vector<vector<string>> days_concerns(MONTH_LENGTHS[month]);

  for (int i = 0; i < q; ++i) {
    string operation_code;
    cin >> operation_code;

    if (operation_code == "ADD") {

      size_t day;
      string concern;
      cin >> day >> concern;
      --day;
      days_concerns[day].push_back(concern);
    } else if (operation_code == "NEXT") {
      const size_t old_month_length = MONTH_LENGTHS[month];
      month = (month + 1) % MONTH_COUNT;
      const size_t new_month_length = MONTH_LENGTHS[month];
      if (new_month_length < old_month_length) {
        vector<string>& last_day_concerns = days_concerns[new_month_length - 1];

        for (size_t day = new_month_length; day < old_month_length; ++day) {
          last_day_concerns.insert(
              end(last_day_concerns),
              begin(days_concerns[day]), end(days_concerns[day]));
        }
      }
      days_concerns.resize(new_month_length);

    } else if (operation_code == "DUMP") {
      size_t day;
      cin >> day;
      --day;
      cout << days_concerns[day].size() << " ";
      for (const string& concern : days_concerns[day]) {
        cout << concern << " ";
      }
      cout << endl;

    }
  }

  return 0;
}

