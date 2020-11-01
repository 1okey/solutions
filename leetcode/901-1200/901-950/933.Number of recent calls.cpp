#include <deque>
#include <iostream>
using std::deque;

static const int opt = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class RecentCounter {
private:
    deque<int> pings; 
public:
    RecentCounter() = default;
    
    int ping(int t) {
        pings.push_back(t);

        while(pings.size() > 0 && t - 3000 > pings.front())
            pings.pop_front();
        
        return static_cast<int>(pings.size());
    }
};

// or using static array
class RecentCounter {
private:
    unsigned start = 0;
    unsigned end = 0;
    int buffer [10000]; 
public:
    RecentCounter() = default;
    
    int ping(int t) {
        buffer[end++] = t; 
        
        while(start != end && t - 3000 > buffer[start])
            ++start;
        
        return end - start;
    }
};