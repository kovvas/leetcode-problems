// Number: 1603
// Name: Design Parking System
// Tags: design

class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small) 
        : d_big(big), d_medium(medium), d_small(small) {}
    
    bool addCar(int carType) {
        if (carType == 1 && d_big > 0) d_big--;
        else if (carType == 2 && d_medium > 0) d_medium--;
        else if (carType == 3 && d_small > 0) d_small--;
        else return false;
        return true;
    }

private:
    int d_big;
    int d_medium;
    int d_small;
};

class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small) {
        d_data.push_back(big);
        d_data.push_back(medium);
        d_data.push_back(small);
    }
    
    bool addCar(int carType) {
        if (d_data[carType - 1] != 0) {
            d_data[carType - 1]--;
            return true;
        }
        return false;
    }

private:
    vector<int> d_data;
};