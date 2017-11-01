#include <iostream>
#include <folly/FBString.h>

int main()
{
   folly::fbstring helloWorld("Hello world, First program using FBFolly");
   std::cout<<helloWorld;
   return 0;
}
