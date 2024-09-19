/* Create a class that holds sensors that are connected to
   an embedded computer (like a watch) and use bit
   arithmetic to add/remove/check sensors. */
#include <iostream>
using namespace std;

enum SensorType {
    HR,             //0
    BloodPressure,  //1
    SPO2,    //2
};

class SensorList {
    private:
        int mySensors;
    public:
        SensorList() {
            mySensors = 0;
        }
        
        int getMySensors() { return mySensors; };

        /* Given a number (mySensors), write a function that tests if the i-th bit is set.
        int test_bit_set(SensorType index) {

        };
        */

        /* Given a number (mySensors), write a function that sets its i-th bit to 1, aka adding a sensor.    
        void set_bit(SensorType index) {
            
        };

        /* Given a number (mySensors), write a function that clears the i-th bit to 0, aka removes a sensor.     
        void clear_bit(SensorType index) {
            
        };
        */
};

int main() {
    SensorList myWatch;
    // We start with no sensors connected to the watch.
    cout << myWatch.getMySensors() << endl;
    
    //TODO: Add a HR to the watch
    cout << myWatch.getMySensors() << endl;

    //TODO: Add Blood Pressure to the watch
    cout << myWatch.getMySensors() << endl;
    
    //TODO: Remove HR
    cout << myWatch.getMySensors() << endl;

    //TODO: Check to see if SPO2 is set?

    //TODO: Add SPO2

    //Check to see if SPO2 is set?
    cout << myWatch.test_bit_set(SPO2) << endl;
}