/*
 * Author: Isaac Abella
 * Description: SHA-1 Implementation
 */

#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <unordered_map>
#include <fstream>
using namespace std;

typedef unsigned long ulong;

struct credentials
{
    void set_salt(string &);
    void set_hash(string &);
    // overloaded operators
    void operator=(const credentials &);
    bool operator==(const credentials &);

    string salt;
    ulong password_hash;
};

void credentials::set_salt(string &username)
{
    // implement salting of the username
    salt = "g0b1g0rAnge" + username;
}

void credentials::set_hash(string &password)
{
    ulong temp_hash = 0; // index value for the shift loop.
    for (size_t i = 0; i < password.size(); i++)
    {
        temp_hash = (temp_hash << 5) | (temp_hash >> 27); // Cyclic shift (SHL=5, SHR=27)
        temp_hash ^= password[i];
    }
    password_hash = temp_hash;
}

void credentials::operator=(const credentials &dummy)
{
    salt = dummy.salt;
    password_hash = dummy.password_hash;
}

bool credentials::operator==(const credentials &dummy)
{
    // return value if dummy is equal to the password_hash.
    return password_hash == dummy.password_hash;
}

istream &operator>>(istream &in, credentials &login)
{
    char buffer[10];
    in.read(buffer, 10);
    buffer[10 - 1] = '\0';

    in >> hex >> login.salt >> login.password_hash;
    return in;
}

ostream &operator<<(ostream &out, const credentials &login)
{
    out << setw(10) << login.salt << " " << hex << login.password_hash << '\n';
    return out;
}

typedef unordered_map<string, credentials> hashtable;

void write_hashtable(hashtable &H, bool verbose)
{
    verbose = true;
    ofstream output_file("psswd.txt");
    if (output_file.fail())
    {
        cerr << "Error: Could not write into file\n";
        return;
    }

    // create pair structure of usernames and passwords
    // need to create non auto forloop
    for (hashtable::iterator it = H.begin(); it != H.end(); ++it)
    {
        const string &username = it->first;
        const credentials &password = it->second;
        output_file << username << " " << password << '\n';
    }
    output_file.close();
}

void read_hashtable(hashtable &H, bool verbose)
{
    verbose = true;
    ifstream input_file("logins1.txt");
    if (!input_file.is_open())
    {
        cerr << "Error: Could not read into file\n";
        return;
    }
    string username;
    credentials password; // create a credential object.
    while (input_file >> username >> password)
    {
        H[username] = password;
    }
}

int main(int argc, char *argv[])
{
    // parse command line options

    hashtable H;
    /*
    use the hash table functions to return the load factor and bucket sizes.
    unlike in program 3, we can create a faster and more effective way to process bucket data.
    add verbose bool function to both write and read hashtable
    */
    bool create = false, check = false, verbose = false;
    float max_load_fraction = 1.0;

    for (int i = 1; i < argc; i++)
    {
        string option = argv[i];
        if (option == "-create")
        {
            create = true;
        }
        else if (option == "-check")
        {
            check = true;
        }
        else if (option == "-load" && i + 1 < argc)
        {
            verbose = true;
        }
        else
            continue;
    }

    H.max_load_factor(max_load_fraction);

    if (create)
        write_hashtable(H, verbose);
    if (check)
        read_hashtable(H, verbose);

    if (verbose)
    {
        cout << "Hash table resizing: size " << H.size() << ", capacity " << H.bucket_count()
             << ", load " << H.load_factor() << endl;
        cout << "Hash table content:" << endl;
        for (size_t i = 0; i < H.bucket_count(); i++)
        {
            for (hashtable::local_iterator it = H.begin(i); it != H.end(i); ++it)
            {
                cout << it->first << " " << it->second << ", ";
            }
            cout << endl;
        }
    }
}