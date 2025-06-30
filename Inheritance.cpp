#include <iostream>
#include <string>
using namespace std;
//inheritance provides large amount of resuability of code 
//the child class have specification concept of DBMS and the parent class have generalization
class car{
    //the object data is 
    protected:
    string brand;
    string model;
    bool isEngineion;
    int currentspeed;
    public:
    //the methods and functions to deal with the object data and show the behaviour of object data
    //the constructor
    car(string b,string m)
    {
        brand = b;
        model =m;
        isEngineion = false;
        currentspeed =0;
    }
    //the generic methods for all the cars
    void startEngine(){
        isEngineion = true;
        cout<< brand <<" "<<model<<" : the Engine of the car started "<<endl;
    }
    void stopEngine()
    {
        isEngineion = false;
        currentspeed =0;
        cout<<brand <<model<<" :the engine is turned off "<<endl;
    }
    void accelerate(){
        if(isEngineion==false){
          cout<<"The car cannot accelerate since the engine is off "<<endl;
          return;
        } 
        else currentspeed = currentspeed+=20;
        //each time pushes the accelerating pedal increase the speed by 20 
    }
    void brake()
    {
        currentspeed -= 20;
        if(currentspeed<20) currentspeed =0;
        cout<<"The brake has been implemented and the speed is "<<currentspeed<<endl;
    }
};
class ManualCar:public car{
    private:
    int currentgear;
    public:
    ManualCar(string b,string m) : car(b,m){
        currentgear =0;
    }
    void shiftGear(int gear)
    {
        currentgear = gear;
        cout<<"The car is cuurrently at the gear "<<currentgear<<endl;
    }
};
class ElectricCar : public car{
    private:
    int batteryLevel;
    public:
    ElectricCar(string b,string m) : car(b,m){
        batteryLevel =0;
    }
    void chargeBattery(int batteryLevel1)
    {
        batteryLevel  += batteryLevel1;
    }
};
int main()
{
    ManualCar* mymanualcar = new ManualCar( "Suzuki", "waganor");
    mymanualcar->startEngine();
    mymanualcar->shiftGear(1);
    mymanualcar->accelerate();
    mymanualcar->brake();
    mymanualcar->stopEngine();
    ElectricCar *myelectricCar = new ElectricCar("Tesla","t234");
    myelectricCar->startEngine();
    myelectricCar->chargeBattery(50);
    myelectricCar->accelerate();
    myelectricCar->brake();
    myelectricCar->stopEngine();
}
