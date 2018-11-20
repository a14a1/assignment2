#include <iostream>
#include<string.h>
using namespace std;
class Person
{
protected:
    string the_name;

public:

     Person();

     Person(string the_name)
     {
          this->the_name=the_name;
     }
     //Person(const Person& the_object);
     string get_name() const;
     Person& operator = (const Person& rt_side);
     friend istream& operator >>(istream& in_stream,Person& person_object);
     friend ostream& operator <<(ostream& out_stream, const Person& person_object);


};
class vehicle:public Person
{
protected:
     int cylinders;
public:
     vehicle();
     vehicle(Person the_name, int cyl):Person(the_name)
     {
         //this-> the_name=the_name;
          cylinders=cyl;
     }

};
class Truck:public vehicle
{
private :
    double load_capacity,towing_capacity;

public :
     Truck();

     Truck(Person the_name, int cylinders,double load,double towing):vehicle(the_name ,cylinders)
     {

        load_capacity  =load;
         towing_capacity =towing;
     }
  friend ostream& operator <<(ostream& out_stream, Truck& person_object);

};
istream& operator >>(istream& in_stream,Person& person_object){

in_stream>>person_object;
return in_stream;
};
ostream& operator <<(ostream& out_stream, Truck& person_object)
{
     ///out_stream<<person_object.the_name;
    /// x = person_object.cylinders;
      cout <<person_object.the_name;
       cout<<endl;
       cout <<person_object.cylinders;
        cout<<endl;
       cout <<person_object.load_capacity;
        cout<<endl;
       cout <<person_object.towing_capacity;

     return out_stream;
};
int main()
{
     Person z("ahmed hassan ");

     Truck y(z,4,14.45,154.1116);
     cout<<" the value you want it is :: " << endl <<  y;

    return 0;
}
