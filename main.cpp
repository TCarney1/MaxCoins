#include <time.h>
#include <iostream>

//test

int main ()
{
    clock_t start_t, end_t;
    double cpu_time_used;

    start_t = clock();

    /* Do the work. */

   for(int i = 0 ; i< 10000; i++){
       for(int j = 0; j < 1000000; j++){

       }
   }

    end_t = clock();
    cpu_time_used = ((double) (end_t - start_t)) / CLOCKS_PER_SEC;

    std::cout << "I have slept for " << cpu_time_used << " seconds" << std::endl;

    return 0;
}