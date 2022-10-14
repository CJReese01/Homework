// Linked List
#include <iostream>
using namespace std;
// Making a Node STRUCT containing a data int and a pointer
struct Node { 
  int data; // You can also templatize this
  Node *next; 
};
class LinkedList
{
    Node* head; // Head pointer
    Node* tail;
    Node* iteration;
  public:
    LinkedList() // Initializing head pointer
    {
      head = NULL; 
      tail = NULL;
      iteration = NULL;
    }

    LinkedList* intersection(LinkedList intersectionee){
        iterate_start();
        LinkedList *intersectioned = new LinkedList;
        while(get_iterator() != NULL){
            if(intersectionee.search(get_iterator()->data)!=-1)
                intersectioned->push_back(get_iterator()->data);
            iterate();
        }
        return intersectioned;
    }
    LinkedList* unionate(LinkedList unionee){
        LinkedList *unioned = new LinkedList;
        while(iterate()!=NULL){
            unioned->push_back(get_iterator()->data);
        }
        LinkedList intersect;
        intersect.head = intersection(unionee)->head;
        intersect.iterate_start();
        unioned->merge(unionee);
        while(intersect.get_iterator()!=NULL){
            unioned->remove_value(intersect.get_iterator()->data);
            intersect.iterate();
        }
        return unioned;
    }

    LinkedList* merge(LinkedList appendee){
        tail->next=appendee.iterate_start();
    }
    Node *iterate(){
        if(iteration==NULL){
            iteration=head;
            return iteration;
        }
        iteration = iteration->next;
        return iteration;
    }
    Node* iterate_start(){
        iteration=head;
        return iteration;
    }

    Node* get_iterator(){
        return iteration;
    }
    Node* get_tail(){
        return tail;
    }

    void push_front(int val) // inserting elements (At start of the list)
    {
      Node* new_node = new Node; // make a new node
      new_node->data = val;
      new_node->next = NULL;
      if (head == NULL){ // If list is empty, make the new node, the head
        head = new_node;
        tail = new_node;
      }
      else
      {
        new_node->next = head; // else, make the new_node the head and its next, the previous head
        head = new_node;
      }
    }
    void push_back(int val) // inserting elements (At start of the list)
    {
      Node* new_node = new Node; // make a new node
      new_node->data = val;
      new_node->next = NULL;
      if (head == NULL){ // If list is empty, make the new node, the head
        head = new_node;
        tail = new_node;
      }
      else
      {
        tail->next = new_node; // else, make the new_node the head and its next, the previous head
        tail = new_node;
      }
    }
    int search(int val) // loop over the list. return true if element found
    {
      Node* temp = head;
      int index = 0;
      while(temp != NULL)
      {
        if (temp->data == val)
          return index;
        temp = temp->next;
        index++;
      }
      return -1;
    }
    void remove_index(int index) // loop over the list. return true if element found
    {
        if(head==NULL)
            return;
        if(head==tail&&index==0){
            delete head;
            head=NULL;
            return;
        }
        if(index==0){
            Node* temp = head->next;
            delete head;
            head = temp;
            return;
      }
      Node* temp = head;
      for(int i=0;i<index-1;i++)
      {
        if(temp->next==NULL){
            std::cout<<"Index out of range"<<std::endl;
            return;
        }
        temp = temp->next; 
      }
      Node *removed = temp->next;
      temp->next = removed->next;
      delete removed;
    } 

    void remove_value(int val)
    {
      if (head->data == val) // If the head is to be deleted
      {
        Node* temp = head->next;
        delete head;
        head = temp;
        return;
      }
      if (head->next == NULL) // If there is only one element in the list
      {
        if (head->data == val) // If the head is to be deleted. Assign null to the head
        {
          delete head;
          head = NULL;
          return;
        }
        cout << "Value not found!" << endl; // else print, value not found
        return;
      }
      Node* temp = head; // Else loop over the list and search for the node to delete
      while(temp->next!= NULL)
      {
        if (temp->next->data == val) // When node is found, delete the node and modify the pointers
        {
          Node* temp_ptr = temp->next->next;
          delete temp->next;
          temp->next = temp_ptr;
          return;
        }
        temp = temp->next;
      }
      cout << "Value not found" << endl; // Else, the value was never in the list
    }

    void display()
    {
      Node* temp = head;
      while(temp != NULL)
      {
        cout << temp->data << " ";
        temp = temp->next;
      }
      cout << endl;
    }
};

int main() {
  
  LinkedList L; // Making a list of Lucas Sequence
  L.push_front(2);
  L.push_front(1);
  L.push_front(3);
  L.push_front(4);
  L.push_front(7);

  LinkedList J;
  J.push_front(2);
  J.push_front(1);
  J.push_front(3);
  J.push_front(10);
  
  cout << "Current Linked List: ";
  L.display();
  cout << "Deleting index 0: ";
  L.remove_index(0);
  L.display();
  cout << "Deleting 13: ";
  L.remove_value(1);
  cout << "Searching for 1: ";
  cout << L.search(1) << endl;
  cout << "Searching for 13: ";
  cout << L.search(13) << endl;
  cout << "intersection" << endl;
  L.display();
  J.display();
  L.intersection(J)->display();
  cout << "union" << endl;
  L.display();
  J.display();
  L.unionate(J)->display();
  cout << "merge" << endl;
  L.display();
  J.display();
  L.merge(J);
  L.display();
}