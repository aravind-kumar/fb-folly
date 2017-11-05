#include <iostream>
#include <thread>
#include <functional>
#include <folly/dynamic.h>
#include <folly/json.h>
#include <folly/ProducerConsumerQueue.h>


// Generic Consumer function given a function to perform an operation
// Returns a wrapper function which wraps the consumer function inside it.

template<typename T>
auto getConsumer(folly::ProducerConsumerQueue<T>& queue,
	         std::function<void (T input)> givenConsumerFn)
{
   auto consumerFn = [&queue,givenConsumerFn]
		     {
                        for(;;)
                        {
                          T input;
                          while(!queue.read(input))
				continue;
     			  givenConsumerFn(input);
                        }
                     };
   return consumerFn;

}

void produceJsonObjects(folly::ProducerConsumerQueue<folly::dynamic>& queue)
{
   std::string jsonDocument1 = R"({"aravind":122,"kumar":[false, null, true, "false"]})";
   std::string jsonDocument2 = R"({"aravind":123,"kumar":[false, null, true, "false"]})";
   folly::dynamic d1 = folly::parseJson(jsonDocument1);
   folly::dynamic d2 = folly::parseJson(jsonDocument2);
   int count=0;
   for(;;)
   {
      ++count;
      folly::dynamic final = count%2 ? d1 : d2;
      while(!queue.write(final))
         continue;
   }
}

int main()
{
   folly::ProducerConsumerQueue<folly::dynamic> queue(100);
   std::function<void(folly::dynamic)> 
   printDynamicObject = [] (folly::dynamic input) 
  	         	{ std::cout<<folly::toPrettyJson(input);};

   auto consumerFn = getConsumer(queue,printDynamicObject); 
    
   std::thread consumer(consumerFn);
   
   produceJsonObjects(queue); 
   return 0;
}

