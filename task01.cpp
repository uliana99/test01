#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* reverse(Node* head) {
    if(head == nullptr)
        return head;

    Node* re_head = nullptr;

    while(head != nullptr)
    {
        Node* tmp = head -> next;
        head -> next = re_head;
        re_head = head;
        head = tmp;
    }
    
    return re_head;
}

int main() {
    return 0;
}