#include <ctime>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>


int waysToPay(const std::vector<int>& coins, const int& endCoins, int value, const int& high, const int& low, int currentCoin = 0, int depth = 0);

int main (int argc, char *argv[]){
    int numWays = 0;
    std::ofstream outputFile("Output.txt");
    std::ifstream inputFile;
    inputFile.open(argv[1]);

    //init prime num coins
    std::vector<int> coins{1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83,
                          89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181,
                          191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281,
            283, 293, 307};

    std::string input;

    while(std::getline(inputFile, input)) {

        std::stringstream ss(input);
        std::string token;
        std::vector<std::string> result;

        //break up the input string by its spaces.
        while(std::getline(ss, token, ' ')){
            result.push_back(token);
        }

        int value, high, low;
        int size = result.size();

        //init values
        if(size == 1){
            value = std::stoi(result[0]);
            high = std::stoi(result[0]);
            low = 0;
        } else if(size == 2){
            value = std::stoi(result[0]);
            high = std::stoi(result[1]);
            low = std::stoi(result[1]);
        } else if (size == 3){
            value = std::stoi(result[0]);
            high = std::stoi(result[2]);
            low = std::stoi(result[1]);
        } else {
            value = 0;
            high = 0;
            low = 0;
        }

        //find the lower bound for the coins, so we aren't searching through coins that are larger than the value.
        auto end = std::lower_bound(coins.begin(), coins.end(), value);
        int endCoins = end - coins.begin();

        std::cout << value << " " << low << " " << high << std::endl;

        //start clock stuff
        clock_t start_t, end_t;
        double cpu_time_used;
        start_t = clock();

        //find how many ways there are to pay. Output it to the output file.
        numWays = waysToPay(coins, endCoins, value, high, low);

        // check for gold coin situations.
        if(!std::binary_search(coins.begin(), coins.end(), value) && (low <= 1 || high <= 1)){
            numWays++;
        }
        outputFile << numWays << std::endl;

        //End clock stuff
        end_t = clock();
        cpu_time_used = ((double) (end_t - start_t)) / CLOCKS_PER_SEC;
        std::cout << "I have slept for " << cpu_time_used << " seconds" << std::endl;
    }

    outputFile.close();
    inputFile.close();
    return 0;
}

//depth is number of coins used, since its +1 for each level of recursion
int waysToPay(const std::vector<int>& coins, const int& endCoins, int value, const int& high, const int& low, int currentCoin, int depth){
    // value left is 0, so this is a possible way to pay, return 1 to be added to numberOfWays (can use these coins)
    if (value == 0 && depth <= high && depth >= low){
        return 1;
    }
    // if value left is greater than 0 the function is called again below to enter another
    // layer of recursion, to see what coins can be used to make up what value is left. (find other possible ways
    // to pay the rest).

    //init number of coins used at each level of recursion
    int numberOfWays = 0;

    //go through each coin (prime numbers) to see what the current value can be broken down into
    for(int i = currentCoin; i <= endCoins; i++){
        //we only care if the coin is smaller than the value left
        if(value - coins[i] >= 0 && depth < high){
            numberOfWays += waysToPay(coins, endCoins, value - coins[i], high, low, i,depth +1);
        }
    }
    return numberOfWays;
}

