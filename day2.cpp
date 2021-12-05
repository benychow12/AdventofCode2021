#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main()
{
    std::ifstream infile("input.txt");

    std::string direction;
    int value;

    int hor_val, depth;

    while (infile >> direction >> value){

        if (direction.compare("forward") == 0){
            // cout << hor_val << endl;
            // cout << value << endl;            
            hor_val += value;
        }
        else if (direction.compare("up") == 0){
            depth -= value;
        }
        else if (direction.compare("down") == 0){
            depth += value;
        }
    }

    std::cout << depth << " " << hor_val << std::endl;
    

    return 0;
}