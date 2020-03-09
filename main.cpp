
#include <iostream>
#include "List.h"

using namespace std;

int main() {

    List nums;

    nums.print_list();

    nums.push_back(20);
    nums.push_back(40);
    nums.push_back(60);

    nums.print_list();

    nums.push_front(16);
    nums.push_front(32);
    nums.push_front(64);

    nums.print_list();

    nums.insert(10, 0);
    nums.print_list();

    nums.remove_by_index(0);
    nums.print_list();

    nums.remove_by_index(1);
    nums.print_list();

    nums.remove_by_index(3);
    nums.print_list();

    nums.push_front(100);
    nums.push_front(50);
    nums.push_back(100);
    nums.print_list();

    nums.remove_first_occurence(50);
    nums.print_list();
    nums.remove_first_occurence(20);
    nums.print_list();

    cout << nums.find(100) << endl;
    cout << nums.find(44) << endl;
    cout << nums.find(60) << endl;
    return 0;
}