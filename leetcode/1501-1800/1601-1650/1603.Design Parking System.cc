// https://leetcode.com/problems/design-parking-system/

class ParkingSystem {
public:
    int types[3] = {0,0,0};

    ParkingSystem(int big, int medium, int small) 
    {
        types[0] = big;
        types[1] = medium;
        types[2] = small;
    }
    
    bool addCar(int carType) {
        if (types[carType - 1] == 0) {
            return false;
        }
        --types[carType - 1];
        return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */