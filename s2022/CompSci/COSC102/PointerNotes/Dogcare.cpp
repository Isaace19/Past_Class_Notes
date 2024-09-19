// In Dgocare.cpp
/* Database of dogs to keep track of their stats and another dog they get along with */

#include <string>
#include <iostream>
#include <vector>

using namespace std;

/* Remember that attributes aren't normally public, and we usually have a constructor, Neither is the case here */

class Dog
{
public:
    string name;
    string breed;
    int age;
    Dog *bff;
  Dog();
  Dog(string n);
  ~Dog();
  static vector<Dog> database;
  // If I get a desctructor here. I aan fix it when a Dog is detected. with a destructor.
};

Dog::Dog(){
  
  cout << "Constructor Called. " << endl;
}
Dog::Dog(string n){
  cout << "Constructor called. Name is " << n << endl;
  name = n;
}
Dog::~Dog(){
  cout << "Destructor Called." << endl;
}


int main()
{
    // Making a pointer to a dog object, but no dog objects have been made yet;
    Dog *d;
    // creating the database of dogs. Still no dog created
    vector<Dog *> database;

    // Now we want to allocate memory to a new dog and have d point to it
    /*
    The memory here is garaunteed to exist until the program ends or
    until we explicity call delete on the pointer
    */

    d = new Dog;
    d->age = 7;
    d->name = "Fido";
    d->breed = "Husky";
    d->bff = NULL;

    database.push_back(d);
    cout << database[0]->name << endl;
    cout << d->age << endl;
    /*
    Why does it segement fault - we are accessing a part of memory that we are accessing memory that we have no
    access to. It will access the vector at reference 0 bceause that is the only thing pushed back at the moment
    we do not have a dog best friend for fido just yet :(
    */

    d = new Dog;
    /*
    we still have access to fido despite using the d variable again, this is because we pushed back fido's info, if we did
    not push his information into the database we would have a data leak
    */

    d->name = "Winston";
    d->breed = "corgi";
    d->age = 4;
    d->bff = database.at(0);
    database.push_back(d);

    cout << database.at(1)->breed << endl;
    cout << d->age << endl;

    /*
    Now we want to Fido and Winston to point to each other as best friends
    */

    database.at(0)->bff = database.at(1);
    // Alternatively you could do database.at(0)->bff = d;

    d = new Dog;
    d->name = "Rover";
    d->breed = "Lab";
    d->age = 2;
    d->bff = database.at(0);

    database.push_back(d);
    database.push_back(d);

    delete d;

    d = new Dog("Buddy");
    for(int i = 0; i < database.size(); i++){
      cout << database.at(i) << endl;
    }

    cout << database.size();
    /*
    If I need to access any dog, I use the database,
    d (the pointer) isn't useful because I resued the variable to create each dog.

    we've made a very small "graph" (in ipad notes) with these dogs via the bff ptr.
    */


    // FOR THE EXAM
    /*
      DATA SIZES
      POINER ARITHMETIC
      DESTRCUTORS ARE -> WHAT THEY LOOK LIKE

      EXAMPLE:
      CLASS
      SCREENSHOT

      MAIN
      DELETE

      YOU SHOULD BE ABLE TO POINT OUT ANY CONSTRUCTOR AND DECONSTRUCTOR FROM CLASS AND MAIN
     */
}
