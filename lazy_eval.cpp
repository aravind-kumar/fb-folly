#include <iostream>
#include <vector>
#include <sys/time.h>
#include <ctime>
#include <folly/Lazy.h>

typedef long long int64; 
typedef unsigned long long uint64;

/* Results: 
   Note: Based on a few runs only on my mac os

    Time to initilize lazy = 0 ms
    Time after first use 193 ms
    Time withourLazy 185 ms

*/

uint64 GetTimeMs64()
{
 struct timeval tv;

 gettimeofday(&tv, NULL);

 uint64 ret = tv.tv_usec;
 /* Convert from micro seconds (10^-6) to milliseconds (10^-3) */
 ret /= 1000;

 /* Adds the seconds (10^0) after converting them to milliseconds (10^-3) */
 ret += (tv.tv_sec * 1000);

 return ret;
}

int main()
{
   /////////////////////////////////////////////////////////////////////////
   uint64 start = GetTimeMs64();
   auto lazyVector = folly::lazy
		        ([]{ return std::vector<int>(9999999,-1);});
   uint64 end = GetTimeMs64();

   /////////////////////////////////////////////////////////////////////////
   std::cout<<"\n Time to initilize lazy = "<<end-start<<" ms";

   start = GetTimeMs64();

   lazyVector().push_back(29);

   end = GetTimeMs64();
   std::cout<<"\n Time after first use "<<end-start<<" ms";
   /////////////////////////////////////////////////////////////////////////
   start = GetTimeMs64();
   std::vector<int> withouLazy(9999999,-1);
   withouLazy.push_back(29);
   end = GetTimeMs64();
   std::cout<<"\n Time withourLazy "<<end-start<<" ms";
   return 0;
}




