#include "simple_linked_list.h"

#include <stdexcept>
#include <vector>
#include <iostream>
#include <string>

namespace simple_linked_list {

std::size_t List::size() const {
    // TODO: Return the correct size of the list.
    return this->current_size;
}

void List::push(int entry) {
    // TODO: Implement a function that pushes an Element with `entry` as data to
    // the front of the list.
    bool noHead{this->head == nullptr};
    Element* newHead = new Element(entry);
        
    if (noHead) {
        this->head = newHead;
        
    } else {
        newHead->next = this->head;
        this->head = newHead;
    }
    
    ++this->current_size;
}

int List::pop() {
    // TODO: Implement a function that returns the data value of the first
    // element in the list then discard that element.
    int headData{0};
    
    if (this-> head != nullptr) {
        headData = this->head->data;
        
        if (this->head->next != nullptr) {
            Element* oldHead = this->head;
            this->head = this->head->next;
            delete oldHead;
            --this->current_size;
            
        } else {
            delete this->head;
            --this->current_size;
        }
    }
    return headData; 
}

void List::reverse() {
    // TODO: Implement a function to reverse the order of the elements in the
    // list.
    std::vector<Element*> nodes{};
    Element* currentNode = this->head;

    // Search all nodes in Linked List
    while(currentNode != nullptr) {
        std::cout << "Input Data: " << std::to_string(currentNode->data) << std::endl;
        nodes.push_back(currentNode);
        currentNode = currentNode->next;
    }

    // Iterate in reverse to build reversed list
    if (nodes.size() == 2) {
        Element* oldHead{this->head};
        this->head = oldHead->next;
        this->head->next = oldHead;
        oldHead->next = nullptr;
    } else if (nodes.size() > 2) {
        currentNode = this->head = nodes[nodes.size() - 1];
        
        for (int i = nodes.size() - 2; i >= 0; --i) {
            currentNode->next = nodes[i];
            currentNode  = currentNode->next;
        }
    }
}

List::~List() {
    /*Element* currentNode{this->head};

    while (currentNode) {
        // nullptr registers as falsey
        Element* next = currentNode->next;
        delete currentNode;
        currentNode = next;
    }*/
}

}  // namespace simple_linked_list
