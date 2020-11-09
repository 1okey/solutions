// https://leetcode.com/problems/subrectangle-queries/

class SubrectangleQueries {

public:
    using rect = vector<vector<int>>;
    SubrectangleQueries(rect& rectangle) 
        : rectangle_(rectangle)
    {}
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for(;row1 <= row2; ++row1) {
            for(int i = col1; i <= col2; ++i) {
                rectangle_[row1][i] = newValue;
            }
        }
    }
    
    int getValue(int row, int col) {
        return rectangle_[row][col];
    }
private:
    rect rectangle_;
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */