#include <iostream>
#include <folly/dynamic.h>
#include <folly/json.h>

int main()
{
   std::string jsonDocument = R"({"aravind":122,"kumar":[false, null, true, "false"]})";
   folly::dynamic parsed = folly::parseJson(jsonDocument);
   auto temp = parsed["aravind"];
   auto str = folly::toPrettyJson(parsed); 
   std::cout<<str;
   return 0;
}
