#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int noMhs;
    string name;
    Node* next;
    Node* prev;
};

Node* START = NULL;

void addNode() {
    Node* newNode = new Node();  //step 1 :create a new node
    cout << "\nenter the roll number of the student: ";
    cin >> newNode->noMhs;      //assign value to the data field of the new node    
    cout << "\nEnter the name of the student: ";
    cin >> newNode->name;      //assign  value to the data field of the new node

    //insert the new node in the list
    if (START == NULL || newNode->noMhs <= START->noMhs) { //step 2 insert to new node
        if (START != NULL && newNode->noMhs == START->noMhs) {
            cout << "\033[31mDuplicate roll numbers not allowed\033[on" << endl;
            return;
        }
        //if the list is empty, make the new node the start
        newNode->next = START;  //step 3:make the new mode point to the first node
        if (START != NULL) {
            START->prev = newNode;//step 4 : make the first node point to the new node
        }
        newNode->prev = NULL; // step 5:make the new node point to null
        START = newNode; //step 6 make the new node the first node
    }
    else {
        //insert the new node in the middle or at the end
        Node* current = START;// step 1.a:start from the first node
        Node* previous = NULL;// step 1.b:previous node is null initially

        while (current != NULL && current->noMhs < newNode->noMhs) {//step 1.c:traver
            previous = current;//stop 1.d:move the previous to the current node
            current = current->next;//step 1.e:move the current to the next node
        }
        newNode->next = current; //step 4:make the next field of the new node point
        newNode->prev = previous; //step 6:make the previous fiels of the prvious

        if (current != NULL) {
            current->prev = newNode;
        }

    }


int main() {

}