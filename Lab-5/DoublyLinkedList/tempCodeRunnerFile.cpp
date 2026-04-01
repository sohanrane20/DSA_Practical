// A. 4. Delete all duplicate nodes
#include <iostream>
using namespace std;
struct Node {
    Node *previous;
    int data;
    Node *next;
};
void displayList(Node *head);
void removeElement(Node *head, Node *ptr);
Node* deleteAllDuplicates(Node *head);
int main() {
    Node *head, *newNode, *temp;
    int n, k;
    head = NULL;
    cout << "Enter number of nodes: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        newNode = new Node;
        cout << "Enter element " << i + 1 << ": ";
        cin >> newNode->data;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            temp = newNode;
            temp->previous = NULL;
        } else {
            newNode->previous = temp;
            temp->next = newNode;
            temp = newNode;
        }
    }
    head = deleteAllDuplicates(head);
    displayList(head);
    cout << endl;
    return 0;
}
void displayList(Node *head) {
    Node *ptr;
    ptr = head;
    while (ptr != NULL) {
        cout << ptr->data << "\t";
        ptr = ptr->next;
    }
}
Node* deleteNode(Node *head, Node *ptr) {
    if (ptr == head) {
        ptr->next->previous = NULL;
        head = ptr->next;
        return head;
    }
    Node *p;
    p = head;
    while (p->next != ptr) {
        p = p->next;
    }
    p->next = ptr->next;
    if (ptr->next != NULL) {
        ptr->next->previous = p;
    }
    return head;
}
Node* deleteAllDuplicates(Node *head) {
    Node *p, *q, *ptr, *temp;
    int flag;
    p = head;
    while (p != NULL) {
        q = p->next;
        flag = 0;
        while (q != NULL && flag == 0) {
            if (p->data == q->data) {
                flag = 1;
            }
            q = q->next;
        }
        
        if (flag == 1) {
            ptr = head;
            while (ptr != NULL) {
                if (ptr->data == p->data) {
                    temp = ptr->next;
                    head = deleteNode(head, ptr);
                    ptr = temp;
                } else {
                    ptr = ptr->next;
                }
            }
            p = head;
        } else {
            p = p->next;
        }
        
    }
    return head;
}