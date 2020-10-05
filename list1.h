//Branden Webb 10/4/2020
#include<iostream>
#include<string>

struct Node{
    std::string data;
    Node *link;
};

class Lilist{
    public:
        Lilist(){head = NULL;}
        void add(std::string item);
        void show();
        Node* search(std::string target);
        void move_front_to_back();
    private:
        Node *head;
};

void Lilist::add(std::string item){
    Node * tmp;
    if(head == NULL){
        head = new Node;
        head -> data = item;
        head -> link = NULL;
    }
    else{
        for(tmp = head; tmp->link != NULL; tmp = tmp -> link)
            ;  // this loop simply advances the pointer to last node in
                //the list
        tmp ->link = new Node;
        tmp = tmp->link;
        tmp->data = item;
        tmp->link = NULL;
    }
}

void Lilist::show(){
    for(Node *tmp = head; tmp != NULL; tmp = tmp->link)
        std::cout<<tmp->data<<"  ";
}
Node* Lilist::search(std::string target) {
  Node* cursor = head;
  while(cursor != NULL) {
    if(cursor->data == target) {
      return cursor;
    }
    cursor = cursor -> link;
  }
  return NULL;
}

void Lilist::move_front_to_back() {
  Node* front = head;
  head = head -> link;
  Node* back = front;
  Node* tmp;
  while(back ->link != NULL) {
    tmp = back;
    back = back -> link;
  }
  back -> link = head;
  tmp -> link = front;
  front -> link = NULL;
  head = back;
}
