// https://www.hackerrank.com/challenges/day-of-the-programmer/problem

bool is_leap(int y) {
    bool gregorian_leap = ((y % 4 == 0 && !(y % 100 == 0)) || y % 400 == 0);
    
    return y < 1918 && y % 4 == 0 || 
           y > 1918 && gregorian_leap;
}

string dayOfProgrammer(int y) {
    if (y == 1918) {
         return "26.09.1918";
    } 
    if (is_leap(y)) {
        return "12.09." + to_string(y);
    }
    
    return "13.09." + to_string(y);
}