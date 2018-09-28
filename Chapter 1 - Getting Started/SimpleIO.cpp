#include <iostream>
#include <string>

int main(int argc, char * argv[])
{
    int x = 1, y = 2;

    /* Output from C++ is buffered. If immediate output is desirable, then use the
    statement “std::cout.flush();” after any std::cout command to ensure the output
    is printed before any other statements are executed, as shown in the listing below. */
    std::cout << "\'\t\a\" x = " << x << " and y = " << y << "\n"; //tab \t, bell sound \a
    std::cout.flush();
    
    //std::cin may be used to ask for more than one input at a time, as shown below.
    int account_number, pin;
    std::cout << "Enter your account number\n";
    std::cout << "and then your PIN followed by RETURN\n";
    std::cin >> account_number >> pin;

    std::string name;
    std::cout << "Enter your name and then hit RETURN\n";
    std::getline(std::cin, name); //Keyboard input for variables of type string is slightly different.
    std::cout << "Your name is " << name << "\n";
    
    return 0;
}