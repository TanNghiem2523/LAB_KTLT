#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
void calSum(string fileName)   {
    int sum = 0;
    string number;
    ifstream file(fileName);
    if (file.is_open()) {
        while ( file >> number){
                    sum += stoi(number);
    }
        }
        
    cout << sum;
}
using namespace std;

int main() {

}