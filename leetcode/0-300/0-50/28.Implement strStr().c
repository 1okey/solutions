// https://leetcode.com/problems/implement-strstr/

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(!needle.size())
            return 0;
        
        if (haystack.size() == needle.size()) {
            return  haystack == needle ? 0 : -1;
        }
        
        for (size_t i = 0; i < haystack.size(); ++i) {
            size_t k = 0;
            for(;haystack[k + i] == needle[k] 
                && i + k < haystack.size() 
                && k < needle.size(); ++k);
            
            if(k >= needle.size()) {
                return i; 
            }
        }
        
        return -1;
    }
};