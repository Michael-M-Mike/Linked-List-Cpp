
#include "List.h"

// ---------------------------------------- Constructor & Destructor
List::List() {
    head = nullptr;
    tail = nullptr;
}

List::~List() {
    if (head != nullptr) {
        delete head;
    }
}

// ---------------------------------------- Empty List Check
bool List::is_empty() {
    if (head == nullptr) {
        return true;
    }
    else {
        return false;
    }
}


// ---------------------------------------- Print List
void List::print_list() {
    if (is_empty()) {
        cout << "List is Empty." << endl;
        return;
    }
    else {
        cout << "{Head} -> ";
        for (Node* iterator = head; iterator != nullptr; iterator = iterator->next) {
            cout << iterator->data << " -> ";
        }
        cout << "{Null}" << endl;
        return;
    }
}


// ---------------------------------------- Get List Size
int List::size() {
    if (is_empty()) {
        return 0;
    }
    else {
        int size_counter = 0;
        for (Node* iterator = head; iterator != nullptr; iterator = iterator->next) {
            size_counter++;
        }
        return size_counter;
    }
}


// ---------------------------------------- Elements Addition
void List::push_back(int data) {
    // Create a New Node & Store data
    Node* link = new Node(data);

    if (is_empty()) {
        head = link;
        tail = link;
    }
    else {
        tail->next = link;
        tail = link;
    }
}


void List::push_front(int data) {
    // Create a New Node & Store data
    Node* link = new Node(data);

    if (is_empty()) {
        head = link;
        tail = link;
    }
    else {
        link->next = head;
        head = link;
    }
}


void List::insert(int data, int index) {
    // Create a New Node & Store data
    Node* link = new Node(data);

    if (is_empty() || index == 0) {
        push_front(data);
    }
    
    else if (index >= size()) {
        push_back(data);
    }

    else {
        int index_counter = 0;
        Node* iterator;
        for (iterator = head; index_counter != index - 1; iterator = iterator->next) {
            index_counter++;
        }

        link->next = iterator->next;
        iterator->next = link;
    }
}


// ---------------------------------------- Elements Removal
void List::remove_by_index(int index) {

    if (is_empty()) {
        return;
    }

    // Special Case (Index = 0)
    if (index == 0) {
        Node* temp_ptr_to_delete = head;
        head = head->next;
        delete temp_ptr_to_delete;
        return;
    }


    // Check index validity
    else if (index >= 0 && index < size()) {

        int index_counter = 0;
        Node* iterator;
        for (iterator = head; index_counter != index - 1; iterator = iterator->next) {
            index_counter++;
        }

        Node* temp_ptr_to_delete = iterator->next;
        iterator->next = iterator->next->next;
        delete temp_ptr_to_delete;
        return;
    }
}


void List::remove_first_occurence(int data) {

    if (is_empty()) {
        return;
    }

    // First Node Check
    if (head->data == data) {
        remove_by_index(0);
        return;
    }

    Node* iterator = head;
    Node* iterator_follower = head;

    while (iterator != nullptr) {

        iterator = iterator->next;
        if (iterator->data == data) {

            Node* temp_ptr_to_delete = iterator;
            iterator_follower->next = iterator->next;
            delete temp_ptr_to_delete;
            return;
        }
        else {
            iterator_follower = iterator_follower->next;
        }
    }
}


// ---------------------------------------- Search
int List::find(int data) {

    int index_counter = 0;
    Node* iterator;
    for (iterator = head; iterator != nullptr; iterator = iterator->next) {
        
        if (iterator->data == data) {
            return index_counter;
        }
        else {
            index_counter++;
        }
    }
    return -1;
}
