#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
void swap(int *ptr1, int*ptr2){
    int a = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = a;

}
int main() {
    int a = 6; int b =7;
    int *ptr1 = &a;
    int *ptr2 = &b;
    swap(ptr1,ptr2);
    return 0;
}