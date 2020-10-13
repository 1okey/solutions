// https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int num = 0;
        for(; head != nullptr; head = head->next)
        {
            num *= 2;
            num += head->val;
        }
        return num;
    }
};