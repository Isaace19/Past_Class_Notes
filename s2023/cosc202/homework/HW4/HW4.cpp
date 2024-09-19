/*
Name: Isaac Abella
Description: Homework Solution Attempt
*/

#include <iostream>
#include <sstream>
#include <list>


// brownie points code - create a template
template <typename T>
class my_eq{
public:
    /*A const object can only be initialized in c++, and objects have to have all their members intializied in a list like 
    how it is below. So basically the whole thing is that const values can only ever get a value when it's initialized because you can't
    modify a const after it's initializiation or it would error out. 
    */
    my_eq(const T&target) : match_target(target) {}
    
    //compare the target object of v.list with the rest of the list. 
    bool match(const T& value) const {
        return value == match_target;
    }

private: 
    T match_target;
};


template <typename Iterator, typename T_target>
int my_count(Iterator begin, Iterator end, const T_target &target)
{
    int track_instance = 0;
    while(begin != end)
    {
        /*
        Now we have the my_count use the my_eq function to match the target object to the list that it was created from.
        so now we have the target from v.begin and it will copare back to the list v. 
        */
        if (target.match(*begin))
        {
            track_instance++;
        }    
        begin++;
    }
    return track_instance;
}

int main()
{
    std::list<int> v;
    std::list<int>::iterator iv;
    int value;

    while (std::cin >> value){
        v.push_back(value);
    }
    int target = *v.begin();

    int N = my_count(v.begin(), v.end(), my_eq<int>(target));
    std::cout << "Found " << N << " instances of " << target << "\n";
    // output is the same as the paper, however I do need to enter a back tick ` in order to get the code to work.
    // is this perhaps just the way that we grab data from the user input without doing stringstream or EOF? 
    // I did not think to change it since I do not know if that would be allowed. 

    return 0;
}
