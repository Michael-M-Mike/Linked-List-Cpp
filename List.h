#pragma once
#include <iostream>
using namespace std;


class Node {

private:
    int data;
    Node* next;

public:
    Node(int data) {
        this->data = data;
        next = nullptr;
    }

    friend class List;
};

class List {

private:
    Node* head;
    Node* tail;

public:
    // Constructor & Destructor
    List();
    ~List();

    // Print List
    void print_list();

    // Essentials
    bool is_empty();
    int size();

    // Elements Addition
    void push_back(int data);
    void push_front(int data);
    void insert(int data, int index);

    // Elements Removal
    void remove_by_index(int index);
    void remove_first_occurence(int data);

    // Search
    int find(int data);
};
