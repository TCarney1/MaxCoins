#include <ctime>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>


int waysToPay(const std::vector<int>& coins, int value, const int& high, const int& low, int currentCoin = 0, int depth = 0);

int main (int argc, char *argv[]){
    //std::ofstream outputFile("Output.txt");
    std::ifstream inputFile;
    inputFile.open(argv[1]);

    //init prime num coins
    std::vector<int> coins{1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83,
                            89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181,
                          191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281,
             283, 293};


    //std::vector<int> coins{1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89};

    std::string input;
    while(std::getline(inputFile, input)) {
        std::vector<int> values(3); //values[0] = Value to find, values[1] = lower bound, values[2] = upper bound
        std::string current;
        int count = 0;

        for(int i = 0; i < input.size() + 1; i++){
            if(input[i] == ' ' || i == input.size()){
                values[count] = (stoi(current));
                count ++;
                current = "";
            } else {
                current.push_back(input[i]);
            }
        }
        //if there are no upper and lower bounds, they will both be 0. set upper bound to the value (So it checks all
        //depths
        if(values[1] == values[2]){
            values[2] = values[0];
        }

        //the upper bound will only be less than the lower bound if there is no upper bound.
        //This means that only 1 number has been enter which means we needs to only check that number 'depth' or
        // 'no. of coins used'.
        if(values[2] < values[1]){
            values[2] = values[1];
        }

        //start clock stuff
        clock_t start_t, end_t;
        double cpu_time_used;
        start_t = clock();


        std::cout << values[0] << " " << values[1] << " " << values[2] << " ";
        //find how many ways there are to pay.
        std::cout << waysToPay(coins, values[0], values[2], values[1]) << std::endl;

        //End clock stuff
        end_t = clock();
        cpu_time_used = ((double) (end_t - start_t)) / CLOCKS_PER_SEC;
        std::cout << "I have slept for " << cpu_time_used << " seconds" << std::endl;
    }

    //outputFile.close();
    inputFile.close();
    return 0;
}

//depth is number of coins used, since its +1 for each level of recursion
int waysToPay(const std::vector<int>& coins, int value, const int& high, const int& low, int currentCoin, int depth){
    // value left is equal to current coin, return 1 (can use these coins)
    if (value == 0 && depth <= high && depth >= low){
        return 1;
    }
    // if value left is greater than the current coin the function is called again below to enter another
    // layer of recursion (coin can be used AND broken down into smaller coins).

    //init number of coins used at each level of recursion
    int numberOfWays = 0;

    //go through each coin (prime numbers) to see what the current value can be broken down into
    for(int i = currentCoin; i < coins.size(); i++){
        //we only care if the coin is smaller than the value left
        if(value - coins[i] >= 0 && depth <= high){
            numberOfWays += waysToPay(coins, value - coins[i], high, low, i,depth +1);
        }
    }
    return numberOfWays;
}

