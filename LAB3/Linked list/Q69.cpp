#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
struct node{
    int data;
    node *next;
};
node *createLinkedList(int n);
int countNode ( node *head){
    int count = 0;
    while ( head != NULL){
        count++;
        head = head->next;
    }
    return count;
}
int main() {
    
    return 0;
}