#include <iostream>
#include <algorithm>
#include <folly/FBVector.h>

int main()
{
  folly::fbvector<int> newVector;
  int num;
  std::cout<<"\n Enter the number of element ";
  std::cin>>num;
  for(int i=0;i<num;++i)
  { 
     int input;
     std::cin>>input;
     newVector.push_back(input);
  }
  auto printFn = [](int num) { std::cout<<num<<" ";};
  std::for_each(newVector.begin(),newVector.end(),printFn);
  return 0;
}
