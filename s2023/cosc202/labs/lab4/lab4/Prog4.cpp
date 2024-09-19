/*
 * Author: Isaac Abella
 * Description: SHA-1 Implementation
 */

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
    salt = "g0b1g0rAnge";
    for (size_t i = 0; i < salt.size(); i++)
    {
        salt[i] += username[i % username.size()] & 0x07;
        if (!isalnum(salt[i]))
        {
            salt[i] = '*';
        }
    }
}

void credentials::set_hash(string &password)
{
    string salted_password = password + salt;
    // implement cyclic shift of string & salting this is a string shift through hash
    ulong index = 0;
    for (size_t i = 0; i < salted_password.size(); i++)
    {
        index = (index << 5) | (index >> 27);
        index += salted_password[i];
    }
    password_hash = index;
}

void credentials::operator=(const credentials &cred)
{
    salt = cred.salt; // copy the user credentials
    password_hash = cred.password_hash;
}

bool credentials::operator==(const credentials &cred)
{
    // return value if cred is equal to the password_hash.
    return password_hash == cred.password_hash;
}

istream &operator>>(istream &in, credentials &login)
{
    in >> login.salt >> hex >> login.password_hash;
    return in;
}

ostream &operator<<(ostream &out, const credentials &login)
{
    out << left << setw(10) << login.salt << ' ' << hex << login.password_hash;
    return out;
}

typedef unordered_map<string, credentials> hashtable;

void write_hashtable(hashtable &H, bool verbose)
{
    H.clear();
    string username, password;
    while (cin >> username >> password)
    {

        if (verbose)
        {
            cout << "** S =" << right << setw(5) << H.size() << " N = "
                 << right << setw(4) << H.bucket_count()
                 << " : load = " << fixed << setprecision(2) << H.load_factor() << '\n';
            // printing details of the bucket states of the table.
        }
        credentials cred;
        cred.set_salt(username);
        cred.set_hash(password);
        H[username] = cred;
    }

    if (verbose)
    {
        cout << "** S =" << right << setw(5) << H.size() << " N = "
             << right << setw(4) << H.bucket_count()
             << " : load = " << fixed << setprecision(2) << H.load_factor() << '\n';
    }

    if (verbose)
    {
        for (size_t i = 0; i < H.bucket_count(); ++i)
        {
            cout << setw(6) << i << setw(5) << H.bucket_size(i);
            for (hashtable::local_iterator it = H.begin(i); it != H.end(i); ++it)
            {
                cout << ' ' << it->first;
            }
            cout << '\n';
        }
    }

    ofstream fout("passwd.txt");
    if (fout.fail())
    {
        cerr << "Error: Could not write into file\n";
        return;
    }

    for (hashtable::iterator it = H.begin(); it != H.end(); ++it)
    {
        fout << left << setw(10) << it->first << ' ' << it->second << '\n';
    }
    fout.close();
}

void read_hashtable(hashtable &H, bool verbose)
{
    H.clear();

    ifstream input_file("passwd.txt");

    if (!input_file.is_open())
    {
        cerr << "Error: Could not read into file\n";
        return;
    }

    string username;
    credentials password;
    while (input_file >> username >> password)
    {

        if (verbose)
        {
            cout << setprecision(2);
            cout << "** S =" << right << setw(5) << H.size() << " N = "
                 << right << setw(4) << H.bucket_count()
                 << " : load = " << fixed << H.load_factor() << '\n';
            // printing details of the bucket states of the table.
            for (size_t i = 0; i < H.bucket_count(); ++i)
            {
                cout << right << setw(6) << i << right << setw(5) << H.bucket_size(i);

                for (hashtable::local_iterator it = H.begin(i); it != H.end(i); ++it)
                {
                    cout << " " << it->first;
                }
                cout << endl;
            }
        }
        H[username] = password;
    }

    input_file.close();
}

int main(int argc, char *argv[])
{
    if (argc == 1 || argc > 5)
    {
        cerr << "usage: ./Prog4 -create|check [-load Z] [-verbose] < logins.txt\n";
        return 1;
    }
    hashtable H;
    bool create = false, check = false, verbose = false;

    for (int i = 1; i < argc; ++i)
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
        else if (option == "-load")
        {
            if (i < (argc - 1))
                H.max_load_factor(stof(argv[++i]));
        }
        else if (option == "-verbose")
        {
            verbose = true;
        }
        else
        {
            cerr << "usage: ./Prog4 -create|check [-load Z] [-verbose] < logins.txt\n";
        }
    }

    if (create)
    {
        write_hashtable(H, verbose);
    }
    else if (check)
    {
        read_hashtable(H, verbose);
        cout << left;
        if (verbose)
            cout << '\n';

        string username, password;
        credentials cred;

        while ((cin >> username >> password))
        {
            hashtable::iterator it = H.find(username);
            cred.set_salt(username);
            cred.set_hash(password);

            cout << setw(10) << username << ' ';

            if (it == H.end())
            {
                cout << " bad username";
            }
            else if (it->second.password_hash == cred.password_hash)
            {
                {
                    cout << "access granted";
                }
            }
            else
            {
                cout << "bad password";
            }
            cout << '\n';
        }
    }
    return 0;
}