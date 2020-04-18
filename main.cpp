#include <ctime>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>


class PayInCoins{

private:
    static const std::vector<int> coins;
    const int value, low, high;
    int lowerBound;
    int numWaysToPay;


public:
    PayInCoins(int value, int low, int high) : value{value}, low{low}, high{high} {
        //find the lower bound for the coins, so we aren't searching through coins that are larger than the value.
        auto end = std::lower_bound(coins.begin(), coins.end(), value);
        lowerBound = end - coins.begin();
        numWaysToPay = 0;
    }

    PayInCoins(): PayInCoins(0, 0, 0) {}

    explicit PayInCoins(int value): PayInCoins(value, 0, value) {}

    PayInCoins(int value, int high) : PayInCoins(value, high, high) {}


    int findNumWaysToPay(){
        //check how many different ways the value can be paid for in coins.
        if(this->value == 0){
            return 0;
        }
        numWaysToPay = this->waysToPay(this->value);
        //check if we need to use a gold coin.
        if(!std::binary_search(coins.begin(), coins.end(), value) && (low <= 1 || high <= 1)){
            numWaysToPay++;
        }
        return numWaysToPay;
    }

    //depth is number of coins used, since its +1 for each level of recursion
    int waysToPay(int valueLeft, int currentCoin = 0, int depth = 0){
        // value left is 0, so this is a possible way to pay, return 1 to be added to numberOfWays (can use these coins)
        if (valueLeft == 0 && depth <= high && depth >= low){
            return 1;
        }
        // if value left is greater than 0 the function is called again below to enter another
        // layer of recursion, to see what coins can be used to make up what value is left. (find other possible ways
        // to pay the rest).

        //init number of coins used at each level of recursion
        int numberOfWays = 0;

        //go through each coin (prime numbers) to see what the current value can be broken down into
        for(int i = currentCoin; i <= lowerBound; i++){
            //we only care if the coin is smaller than the value left
            if(valueLeft - coins[i] >= 0 && depth < high){
                numberOfWays += waysToPay(valueLeft - coins[i], i, depth +1);
            }
        }
        return numberOfWays;
    }
};

//init prime num coins
const std::vector<int> PayInCoins::coins ({1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83,
                                              89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181,
                                              191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281,
                                              283, 293, 307});

int main (int argc, char *argv[]){
    int numWays = 0;
    std::ofstream outputFile("Output.txt");
    std::ifstream inputFile("input");
    //inputFile.open(argv[1]);

    std::string input;
    while(std::getline(inputFile, input)) {
        std::stringstream ss(input);
        std::string token;
        std::vector<std::string> result;
        PayInCoins *amount = nullptr;

        //break up the input string by its spaces.
        while(std::getline(ss, token, ' ')){
            result.push_back(token);
        }

        int value, high, low;
        int size = result.size();

        //init amount object with values.
        if(size == 1){
            value = std::stoi(result[0]);
            amount = new PayInCoins(value);
        } else if(size == 2){
            value = std::stoi(result[0]);
            high = std::stoi(result[1]);
            amount = new PayInCoins(value, high);
        } else {
            value = std::stoi(result[0]);
            high = std::stoi(result[2]);
            low = std::stoi(result[1]);
            amount = new PayInCoins(value, low, high);
        }



        //start clock stuff
        clock_t start_t, end_t;
        double cpu_time_used;
        start_t = clock();

        //find how many ways there are to pay. Output it to the output file.
        outputFile << amount->findNumWaysToPay() << std::endl;

        //End clock stuff
        end_t = clock();
        cpu_time_used = ((double) (end_t - start_t)) / CLOCKS_PER_SEC;
        std::cout << "I have slept for " << cpu_time_used << " seconds" << std::endl;


        delete amount;
    }

    outputFile.close();
    inputFile.close();
    return 0;
}


