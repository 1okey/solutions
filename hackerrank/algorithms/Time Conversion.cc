// https://www.hackerrank.com/challenges/time-conversion/problem

string timeConversion(string s) {
    
    unsigned pos = s.find('M') - 1;
    string time = s.substr(0, pos);
    string suffix = s.substr(pos);
    stringstream ss;
    
    int hours = ((time[0] - '0') * 10) + (time[1] - '0');

    if((suffix == "PM" && !(hours == 24 || hours == 12)) || 
       (suffix == "AM" && (hours == 0 || hours == 12))) {
        cerr << hours;
        (hours += 12) %= 24;
    }

    if(hours < 10) {
        ss << '0';
    }
    ss << hours;
    string hours_s = ss.str();
    time[0] = hours_s[0];
    time[1] = hours_s[1];
    
    return time;
}
