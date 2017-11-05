#include <iostream>
#include <thread>
#include <functional>
#include <folly/dynamic.h>
#include <folly/json.h>
#include <folly/ProducerConsumerQueue.h>

template<typename T>
auto getConsumer(std::function<void (T input)> givenConsumerFn)
{
   auto consumerFn = [givenConsumerFn](T givenInput)
		     {
     			givenConsumerFn(givenInput);
                     };
   return consumerFn;

}

folly::ProducerConsumerQueue<folly::dynamic> queue(100);
int main()
{

   return 0;
}

