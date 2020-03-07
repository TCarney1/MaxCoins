#include <ctime>
#include <iostream>
#include <vector>


int waysToPay(const std::vector<int> &coins, int value, int currentCoin = 0, int depth = 0);

int main (int argc, char *argv[]){
    //start clock stuff
    clock_t start_t, end_t;
    double cpu_time_used;
    start_t = clock();

    //init prime num coins
    /*
    std::vector<int> coins{1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83,
                           89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181,
                           191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281,
                           283, 293};*/

    std::vector<int> coins{1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83,
                           89};

    //init total value
    int value = 100;

    std::cout << waysToPay(coins, value) << std::endl;

    //End clock stuff
    end_t = clock();
    cpu_time_used = ((double) (end_t - start_t)) / CLOCKS_PER_SEC;
    std::cout << "I have slept for " << cpu_time_used << " seconds" << std::endl;

    return 0;
}

//depth is number of coins used, since its +1 for each level of recursion
int waysToPay(const std::vector<int>& coins, int value, int currentCoin, int depth){
    // value left is equal to current coin, return 1 (can use this coin)
    if (value == 0 && depth <= 25 && depth >= 8){
        return 1;
    }
    // if value left is greater than the current coin the function is called again below to enter another
    // layer of recursion (coin can be used AND broken down into smaller coins).

    //init number of coins used at each level of recursion
    int numberOfWays = 0;

    //go through each coin (prime numbers) to see what the current value can be broken down into

    for(int i = currentCoin; i < coins.size(); i++){
        //we only care if the coin is smaller than the value left
        if(value - coins[i] >= 0){
            numberOfWays += waysToPay(coins, value - coins[i], i, depth +1);
        }

    }

    return numberOfWays;
}