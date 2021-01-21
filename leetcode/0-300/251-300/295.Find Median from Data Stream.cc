// https://leetcode.com/problems/find-median-from-data-stream/

class MedianFinder {    
    vector<int> nums;
private:
    int getMedianIndex(int target)
    {
        int mid = 0;
        int left = 0;
        int right = nums.size() - 1;
        
        while(left <= right) {
            mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                return mid;
            } else if(nums[mid] > target) {
                right = mid - 1;
            } else{
                left = mid + 1;
            }
        }
        
        return left;
    }
public:
    MedianFinder() = default;
    
    void addNum(int num) noexcept {
        if (nums.size() == 0) { 
            nums.push_back(num);
        } else {
            nums.insert(nums.begin() + getMedianIndex(num), num);
        }
    }
    
    double findMedian() {
        if (nums.size() % 2 == 1) {
            return (double) nums[nums.size() / 2]; 
        } else if (nums.size() > 0) {
            int mid = nums.size() / 2;
            return ((double) nums[mid] + nums[mid - 1]) / 2.0;
        } 
        
        return 0.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */