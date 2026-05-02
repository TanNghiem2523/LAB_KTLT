#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
 long int decimalToBinary(int decimal_number)
{
	if(decimal_number < 1) return 0;
	return ((decimal_number % 2) + 10 * decimalToBinary(decimal_number/2)); 
}main() {
    
    return 0;
}