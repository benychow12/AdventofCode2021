#include <iostream>
#include <fstream>

int main()
{
    std::ifstream infile("input.txt");
    
    int prev_input = 0;
    int new_input;
    int counter = -1;
    while (infile >> new_input)
    {
        if (new_input > prev_input)
        {
            std::cout << "Increment...new vs old..." << new_input << " " << prev_input << std::endl;
            counter++;
        }
        prev_input = new_input;
    }

    std::cout << counter << std::endl;
}