// https://leetcode.com/problems/day-of-the-week/

class Solution {
public:
    int months_in_days [13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    string day_names [7] = {"Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday"};
    
    bool is_leap(int year) {
        return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    }
    
    string dayOfTheWeek(int day, int month, int year) {
        
        int days = day + (is_leap(year) && month > 2) + ((year - 1971) * 365);
        
        for (int start = 1972; start < year; start += 4) {
            days += is_leap(start);
        }
        
        for (int i = 0; i < month; ++i) {
            days += months_in_days[i];
        }
        
        return day_names[days % 7];
    }
};