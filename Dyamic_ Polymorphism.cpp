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
   /* void accelerate(){
        if(isEngineion==false){
          cout<<"The car cannot accelerate since the engine is off "<<endl;
          return;
        } 
        else currentspeed = currentspeed+=20;
        cout<<"The speed of the car becomes "<<currentspeed<<endl;
        //each time pushes the accelerating pedal increase the speed by 20 
    }
    void brake()
    {
        currentspeed -= 20;
        if(currentspeed<20) currentspeed =0;
        cout<<"The brake has been implemented and the speed is "<<currentspeed<<endl;
    }
    */
    virtual  void accelerate()=0;
    virtual  void brake()=0;
    // I have convreted them to the virtual class now its duty of manual car and eletric car to define it 
};
class ManualCar:public car{
    private:
    int currentgear;
    public:
    ManualCar(string b,string m) : car(b,m){
        currentgear =0;
    }
    //classc case of method overtriding 
    void accelerate()
    {
        if(isEngineion == false){
            cout<<"The Engine is off the car cannot be accelerted "<<endl;
            return;
        }
        else {
            currentspeed = currentspeed+30;//the manual car is supposed to have a good speed
            cout<<"The speed of the car after the accelertaion becomes "<<currentspeed<<endl;
        }
    }
    void brake()
    {
        currentspeed -= 20;
        if(currentspeed<20) currentspeed = 0;
        cout<<"The brake has been implemented and the speed of the car  is "<<currentspeed<<endl;
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
    void accelerate()
    {
        if(isEngineion == false){
            cout<<"The Engine is off the car cannot be accelerted "<<endl;
            return;
        }
        else {
            currentspeed = currentspeed+15;//the manual car is supposed to have a good speed
            cout<<"The speed of the car after the accelertaion becomes "<<currentspeed<<endl;
        }
    }
    void brake()
    {
        currentspeed -= 10;
        if(currentspeed<10) currentspeed = 0;
        cout<<"The brake has been implemented and the speed of the car  is "<<currentspeed<<endl;
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
