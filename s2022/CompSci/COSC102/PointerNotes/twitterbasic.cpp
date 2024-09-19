// Twitter Basic

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class user
{
private:
    string username;
    vector<user *> following;

public:
    user(string name);
    void follow(user *newFollowing);
    void printedwhoIfFollow();
    void setusername(string newName);
};

user::user(string name)
{
    username = name;
}

// using the two colons are a part of defining a new function inside of a function in a class

void user::follow(user *newFollow)
{
    following.push_back(newFollow); // pushing back into our following vector a newFollow of a name
}

void user::printedwhoIfFollow()
{
    cout << username << " follows these users: " << endl;

    for (int i = 0; i < following.size(); i++)
    {
        cout << "  " << following.at(i)->username << endl;
    }
}

void user::setusername(string name)
{
    username = name;
}

int main()
{
    // create a user

    user *me = new user("Isaac");
    user *ls = new user("Luke Sky");
    user *ts = new user("Taylor Swift");
    user *pm = new user("Peyton Manning");

    me->follow(ls);
    me->follow(ts);
    me->follow(pm);

    /*
    note 0 everything was user objects and not user pointers, I would do me.follow(who I wanted to follow)
    */

    me->printedwhoIfFollow();

    pm->setusername("Peyton Manning Official");
    me->printedwhoIfFollow();
}