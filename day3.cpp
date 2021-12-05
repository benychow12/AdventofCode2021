#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;
int main()
{
    std::ifstream infile("input.txt");

    char bit;
    int digit_counter = 0;
    float bin_val[12] = {0};
    int line_val = 0;

    while (infile >> bit){
        bin_val[digit_counter] += (int)bit - 48;
 
        if (digit_counter < 11){
            digit_counter++;
        }
        else{
            digit_counter = 0;
            line_val++;
        }
    }

    int gamma = 0;
    int epsilon = 0;
    int power = 11;
    for (int j = 0; j < 12; j++)
    {
        bin_val[j] = round(bin_val[j] / line_val);
        gamma += pow(2, power) * bin_val[j];
        // stupid compliment 
        int comp = ((int)bin_val[j] + 1) % 2;
        epsilon += pow(2, power) * comp;
        power--;
    }

    cout << endl << gamma * epsilon << endl;


    return 0;
}