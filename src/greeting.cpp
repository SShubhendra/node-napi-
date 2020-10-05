#include <iostream>
#include <string>
#include "greeting.h"

std::string helloUser(std::string name)
{
  std::cout << "\n inp :" << name << "\n";
  return "Hello " + name + "!";
}

std::string echo(char **input, char **output)
{
  // std::cout << "\n input :" << input;
  // std::cout << "\n inputval1 :" << *input;
  // std::cout << "\n output1 :" << output;
  *output = *input;

  // std::cout << "\n inputval2 :" << input;
  // std::cout << "\n output2 :" << *output;
  // std::cout << "\n output :" << **output << "\n";
  return "Done.";
}
// #include <stdio.h>
// #include <stdlib.h>

// int helloUser(int n)
// {
//   if (n > 0)
//   {
//     return helloUser(n - 1) + n;
//   }
//   return 0;
// }

// int main()
// {
//   int x = 5;
//   // ("Enter value of x %d", &x);
//   printf("\n%d", helloUser(x));
//   return 0;
// }