#include <bits/stdc++.h>
#include<queue>
using namespace std;
 
class Info {
    int data;
    Info* next;
};

Info*(int data){

    Info* new_node = new Node();
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void printList(Info* head){
    while (head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
}

class Cmp {
    public:
    bool operator()(Info* a, Info* b) {
        return a->data > b->data;
    }
};

vector<int> mergeKSortedLL(Info* &ListArray) {

    priority_queue<Info*, vector<Info*>, Cmp > minheap;
    int n = ListArray.size();
    
    if( k == 0)
        return NULL;

    //step1: put the first element fo all rows into the heap
    for(int i=0; i<k; i++) {
        if(ListArray[i] != NULL)
            minheap.push(ListArray[i]);
    }

    Info* head = NULL;
    Info* tail = NULL;

    //step-2
    while(minheap.size() > 0) {
        //fetch top element
        Info* temp = minheap.top();
        minheap.pop();

        if(temp->next == NULL)
            minHeap.push(temp->next);
        
        if(head == NULL){
            //ans LL is empty
            head = temp;
            tail = temp;
        }
        else{
            //insert at LL
            tail->next = temp;
            tail = temp;
        }
    }
    return head;
}

int main() {

   // Number of linked lists
    int N = 3;

    Info* arr[N];
    // Creating k = 3 sorted lists
    arr[0] = new Node(1);
    arr[0]->next = new Node(3);
    arr[0]->next->next = new Node(5);
    arr[0]->next->next->next = new Node(7);
 
    arr[1] = new Node(2);
    arr[1]->next = new Node(4);
    arr[1]->next->next = new Node(6);
    arr[1]->next->next->next = new Node(8);
 
    arr[2] = new Node(0);
    arr[2]->next = new Node(9);
    arr[2]->next->next = new Node(10);
    arr[2]->next->next->next = new Node(11);
 
    // Merge the k sorted lists
    Info* head = mergeKSortedLists(arr);
 
    // Print the merged list
    printList(head);
 
    return 0;
}
