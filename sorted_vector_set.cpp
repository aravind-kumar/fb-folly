#include <iostream>
#include <algorithm>
#include <assert.h>
#include <folly/sorted_vector_types.h>


typedef folly::sorted_vector_set<int> sortedInts;

void fillValues(sortedInts& input)
{
   for(int i=0;i<10;i+=2)
      input.insert(i);
   for(int i=1;i<10;i+=2)
      input.insert(i);
}

void print(const sortedInts& input)
{
   for(auto&& number : input)
   	std::cout<<number <<"-->";
}

int main()
{
   // vector stored like a set in sorted order
   // insert and erase take O(n) and invalidate the iterators.
   sortedInts input;

   fillValues(input);
   
   print(input);
   assert(std::is_sorted(input.begin(),input.end()));
   
   return 0;
}
