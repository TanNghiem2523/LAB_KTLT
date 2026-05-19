#include<iostream>
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
node *addElement (node *p, int x){
    node *temp = createNode(x);
    p->next = temp;
    return temp;    
}
node *createLinkedList(int n) {
    if (n <= 0) return NULL;

    node *head = NULL;
    node *tail = NULL;

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;

        // Tạo node mới
        node *newNode = new node;
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            // Nếu là node đầu tiên
            head = newNode;
            tail = newNode;
        } else {
            // Gắn vào sau tail hiện tại và cập nhật lại tail
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}
bool isEqual ( node *head1, node *head2){
    while (head1 != NULL && head2 != NULL ){
        if (head1->data != head2->data ){
            return false;
        }
    }
    head1 = head1->next;
    head2 = head2->next;
    return ( head1 == NULL && head2 == NULL);
}
