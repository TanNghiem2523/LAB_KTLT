#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
struct node{
    int data;
    node *next;
};
node *createNode(int x){
    node *temp = new node;
    temp->data = x;
    temp->next = NULL;
    return temp;
}
node *createLinkedList(int n){
    node *head = NULL;
    node *tail = NULL;
    for ( int i  = 0; i<n;i++){
        int x;
        cin>>x;
        node *temp = createNode(x);
        if ( head == NULL && tail == NULL){
            head = temp;
            tail = temp;
        }
        else {
            tail->next = temp;
            tail = temp;
        }
    }
    return head;
}
int searchLinkedList(node *head , int key){
    int count = 0;
    while ( head != NULL){
        if (head->data == key) return count;
        else{
            count++;
            head = head->next;
        }
    }
    return -1;
}
int main() {
    
    return 0;
}