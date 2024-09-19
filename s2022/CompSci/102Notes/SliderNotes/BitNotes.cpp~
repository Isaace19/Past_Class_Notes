/* CS102 Notes on Masks and Bit Ops */


#include <cstdint>
#include <iostream>
using namespace std;

int main() {
    /*  MASKS
    A mask defines which bits you want to keep, and which ones
    you want to clear. Masking is the act of applying a mask to a value.

    Simple masks refer to one bit mask for each bit position. We've made 
    8 masks below for these cases.

    NOTE: Using the constant expression keyword here. Like const, a
    compiler error will occur when any code tries to modify the value.
    However, const is used on just variables. Constexpr can also be used
    with functions and constructors. Constexpr says that the value,
    or return value, is constant and usually is computed at compile time.
    That is, the compiler basically copies and pastes these values for us,
    but writing them this way makes the masks more readable.
    C++11 introduces constexpr.
    To compile with C++11, use -std=c++11 on the command line.
    Ex, g++ -std=C++11 -o BitNotes BitNotes.cpp
*/
    constexpr uint8_t mask0{ 1 << 0 }; // represents bit 0, aka 0b0000'0001
    constexpr uint8_t mask1{ 1 << 1 }; // represents bit 1, aka 0b0000'0010
    constexpr uint8_t mask2{ 1 << 2 }; // represents bit 2, aka 0b0000'0100
    constexpr uint8_t mask3{ 1 << 3 }; // represents bit 3, aka 0b0000'1000
    constexpr uint8_t mask4{ 1 << 4 }; // represents bit 4, aka 0b0001'0000
    constexpr uint8_t mask5{ 1 << 5 }; // represents bit 5, aka 0b0010'0000
    constexpr uint8_t mask6{ 1 << 6 }; // represents bit 6, aka 0b0100'0000
    constexpr uint8_t mask7{ 1 << 7 }; // represents bit 7, aka 0b1000'0000

    /* FLAGS
    We use the term "flag" in programming to "flag" if something is on.
    In the sensors example, the bits that were set were "flags" that the
    respective sensor was turned on. If the HR bit was set, we could also
    say that the HR flag was set. You'll see this term through around.
    In order to generalize, I'm going to make a "flags" variable to
    represent what we currently have "set". This is equivalent to the
    sensorslist integer we used last time.
    Note that the flags will change depending on what is set, but the masks
    are constant.
    I'm going to start with all the flags turned off. 
    */
    uint8_t flags = 0; // all flags are off, aka 0b0000'0000

    /* New type - uint8_t
    Notice I've included <cstdint> in our file.
    This introduces what may be new types to some of you. 
    uint8_t
    uint16_t
    uint32_t
    uint64_t
    are unsigned integer types with width of exactly 8, 16, 32 and 64 bits respectively.
    The 'u' stands for unsigned. A "signed" integer can be a positive integer or a
    negative integer, i.e. both positive 3 and negative 3 could be stored in a
    signed integer.
    An "unsigned" integer does NOT store a sign, so we can only store positive numbers.
    For reference, the signed versions are written like the unsigned versions only you
    remove the 'u' (int8_t, int16_t, int32_t, and int64_t),
    but we will be using the unsigned versions for bit manipulation and flags.
    
    Why would we use these types? To only use the space we need and not waste space!
    Remember: 8 bits = 1 byte.
    
    1 byte -> [0-255] or [0x00-0xFF]
    uint8_t         number8     = testValue; // 255
    unsigned char    numberChar    = testValue; // 255

    2 bytes -> [0-65535] or [0x0000-0xFFFF]
    uint16_t         number16     = testValue; // 65,535
    unsigned short    numberShort    = testValue; // 65,535

    4 bytes -> [0-4294967295] or [0x00000000-0xFFFFFFFF]
    uint32_t         number32     = testValue; // 4,294,967,295
    unsigned int     numberInt    = testValue; // 4,294,967,295

    8 bytes -> [0-18446744073709551615] or [0x0000000000000000-0xFFFFFFFFFFFFFFFF]
    uint64_t             number64         = testValue; // 18,446,744,073,709,551,615
    unsigned long long     numberLongLong    = testValue; // 18,446,744,073,709,551,615
    */
 
    /* Below is a "ternary expression" - a shorthand for an if statement.
       If (flags & mask1) is true (non-zero), then we will print what's on the left of the colon (on).
       If it's false, we'll print what's on the right of the colon (off).
    */
    cout << "Bit 1 is " << ((flags & mask1) ? "on\n" : "off\n");

    flags |= mask1; // Turn bit 1 on

    cout << "Bit 1 is " << ((flags & mask1) ? "on\n" : "off\n");

    /* Last we we turned one bit on at a time. How can we turn two bits on
       at once? Try it below by turning bits 3 and 4 on at the same time.
    */
    cout << "Bit 3 is " << ((flags & mask3) ? "on\n" : "off\n");
    cout << "Bit 4 is " << ((flags & mask4) ? "on\n" : "off\n");
    cout << "Turning bits 3 and 4 on\n";
    flags |= (mask3 | mask4);
    cout << "Bit 3 is " << ((flags & mask3) ? "on\n" : "off\n");
    cout << "Bit 4 is " << ((flags & mask4) ? "on\n" : "off\n");

    /* Now, let's turn off bit 4. (think: clear bit)
    */
    flags &= ~mask4;
    cout << "Bit 4 is " << ((flags & mask4) ? "on\n" : "off\n");
    cout << endl;

    /* We didn't do this last time... let's flip a bit. How could we
     flip bits? Try with bit 2.
     XOR.
    */
    cout << "Bit 2 is " << ((flags & mask2) ? "on\n" : "off\n");
    cout << "Flipping bit 2.\n";
    flags ^= mask2;
    cout << "Bit 2 is " << ((flags & mask2) ? "on\n" : "off\n");
    cout << "Flipping bit 2 again.\n";
    flags ^= mask2;
    cout << "Bit 2 is " << ((flags & mask2) ? "on\n" : "off\n");
    cout << endl;

    /* Can we flip (toggle) multiple bits simultaneously?
       Take a moment and try with bits 6 and 7.
    */
   cout << "Bit 6 is " << ((flags & mask6) ? "on\n" : "off\n");
   cout << "Bit 7 is " << ((flags & mask7) ? "on\n" : "off\n");
   flags ^= (mask6 | mask7);
   cout << "Bit 6 is " << ((flags & mask6) ? "on\n" : "off\n");
   cout << "Bit 7 is " << ((flags & mask7) ? "on\n" : "off\n");


}