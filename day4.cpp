#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <math.h>

using namespace std;

class bingo_matrix
{
public:
    // 5 x 5 bingo matrix
    int bingo_card[5][5];
    int bingo_score[5][5] = {0};
    bool winner = false;

    int get_score(){
        int sum = 0;
        for (int i = 0; i < 5; i++){
            for (int j = 0; j < 5; j++){
                // only count unmatched numbres
                if (!this->bingo_score[i][j]){
                    sum += bingo_card[i][j];
                }
            }
        }
        return sum;
    }

    // See if the value is in bingo_card
    // If value found, need to update bingo_score
    bool is_in_bingo(int value){
        for (int i = 0; i < 5; i++){
            for (int j = 0; j < 5; j++){
                if (bingo_card[i][j] == value){
                    this->bingo_score[i][j] = 1;
                    return true;
                }
            }
        }
        return false;
    };

    bool check_bingo(){
        // check rows for sum 5 and check cols for sum 5
        int sum_hor = 0, sum_vert = 0;;
        for (int i = 0; i < 5; i++){
            sum_hor = 0, sum_vert = 0;
            for (int j = 0; j < 5; j++){
                sum_hor += this->bingo_score[i][j];
                sum_vert += this->bingo_score[j][i];
            }
            if (sum_hor == 5 || sum_vert == 5)
            {
                cout << "BINGO!" << endl;
                return true;
            }
        }
        return false;
    }

    void print_bingo(){
        for (int i = 0; i < 5; i++){
            for (int j = 0; j < 5; j++){
                cout << bingo_card[i][j] << " ";
            }
            cout << endl;
        }
    };

    void print_match(){
        for (int i = 0; i < 5; i++){
            for (int j = 0; j < 5; j++){
                cout << bingo_score[i][j] << " ";
            }
            cout << endl;
        }
    };
};

int main()
{
    // Open file
    std::ifstream infile("input.txt");

    // Store bingo numbers in int vect
    string temp;
    getline(infile, temp);
    stringstream ss(temp);
    vector<int> bingo_nums;
    for (int i; ss >> i;){
        bingo_nums.push_back(i);
        if (ss.peek() == ','){
            ss.ignore();
        }
    }

    // Store matrices of the bingo cards
    vector<bingo_matrix*> bingo_cards;
    bingo_matrix* bingo_temp;
    int row = 0, col = 0;
    while(getline(infile, temp)){
        if (temp.length() == 1){
            cout << "creating new bingo card" << endl;
            bingo_temp = new bingo_matrix;
            bingo_cards.push_back(bingo_temp);
            row = 0, col = 0;
        }
        else{
            stringstream dd(temp);
            for (int z; dd >> z;){
                bingo_temp->bingo_card[row][col] = z;
                col++;
                if (col == 5)
                {
                    row++;
                    col = 0;
                }
            }
        }
    }

    // main loop through all input values
    /*
    for (auto input:bingo_nums){
        cout << input << endl;
        // check all bingo cards
        for (auto bongo:bingo_cards){
            if (bongo->is_in_bingo(input)){
                if (bongo->check_bingo()){
                    // find the score
                    int score = bongo->get_score();
                    score *= input;
                    cout << score << endl;

                    return 0;
                }
            }
        }
    }
    */
    
    // part 2
    for (auto input:bingo_nums){
        cout << input << endl;
        // check all bingo cards
        for (auto bongo:bingo_cards){
            if (bongo->is_in_bingo(input) && !(bongo->winner)){
                if (bongo->check_bingo()){
                    // find the score
                    int score = bongo->get_score();
                    score *= input;
                    cout << "WINNER" << score << endl;
                    bongo->winner = true;
                }
            }
        }
    }

    for (auto input:bingo_nums){
        cout << input << endl;
        // check all bingo cards
        if (bingo_cards.size() == 1)
        {
            cout << "only one card left..." << endl;
            if (bingo_cards[0]->is_in_bingo(input)){
                if (bingo_cards[0]->check_bingo()){
                    // find the score
                    int score = bingo_cards[0]->get_score();
                    score *= input;
                    cout << score << endl;

                    return 0;
                }
            }
        }
        else{
            for (int i = 0; i < bingo_cards.size(); i++){
                cout << "bingo cards to parse..." << bingo_cards.size() << endl;
                if (bingo_cards[i]->is_in_bingo(input)){
                    if (bingo_cards[i]->check_bingo()){
                        // pop bingo card that has bingo
                        bingo_cards.erase(bingo_cards.begin() + i);
                    }
                }
            }
        }
    }
}
