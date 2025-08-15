class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small) { //set spots avail
        spots[0] = big;
        spots[1] = medium; 
        spots[2] = small;
    }
    
    bool addCar(int carType) { // if avail reduce number avail for type, else return false
        if (spots[--carType] != 0){
            spots[carType]--;
            return true;
        }
        else return false;
    }
private:
    int spots[3] = {0};
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
