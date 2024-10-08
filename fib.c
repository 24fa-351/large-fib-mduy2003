#include <stdio.h>
#include <stdint.h>

unsigned long long int fibRecursive(int fibValue)
{
   if (fibValue == 0 || fibValue == 1)
   {
      return fibValue;
   }
   return fibRecursive(fibValue - 1) + fibRecursive(fibValue - 2);
}

unsigned long long int fibIterative(int fibValue)
{
   unsigned long long int fibSum = 0;
   unsigned long long int prevNum = 0;
   unsigned long long int currentNum = 1;
   for (size_t ix = 1; ix < fibValue; ++ix)
   {
      fibSum = prevNum + currentNum;
      prevNum = currentNum;
      currentNum = fibSum;
   }
   return fibSum;
}

int main(int argc, char *argv[])
{
   unsigned long long int firstNum;
   unsigned long long int input = sscanf(argv[1], "%llu", &firstNum);
   char fibType = *argv[2];
   unsigned long long int nthNum = firstNum - 1;

   if (fibType == 'r')
   {
      unsigned long long int result = fibRecursive(nthNum);
      printf("%llu", result);
   }
   else if (fibType == 'i')
   {
      unsigned long long int result = fibIterative(nthNum);
      printf("%llu", result);
   }
   return 0;
}
