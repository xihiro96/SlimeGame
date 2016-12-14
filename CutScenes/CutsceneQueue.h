//
// Created by Randy Deng on 12/11/16.
// specialized templated class for handling cutscenes
// all templated function definitions must be in .h file

#pragma once

#include <vector>
#include <iostream>

// Note: may need to be modified to work with cutscene objects
// namely, changing the returned elements into pointers to objects

template<class T>
class CutsceneQueue {
public :
    // Queue functions
    // push element
    void push(T const& elem) {elems.push_back(elem);}
    // pop element
    void pop() {
        if (elems.empty()) {
            std::cout << "Queue is empty. Cannot pop." << std::endl;
        } else {
            elems.erase(elems.begin());
        }
    }
    // returns front element
    T getTop() {
        if (elems.empty()) {
            std::cout << "Queue is empty. Cannot get top." << std::endl;
        } else {
            return elems.front();
        }
    }
    // empties queue
    void clear() {elems.clear();}
    // returns if queue is empty
    bool isEmpty() const {return elems.empty();}
private :
    std::vector<T> elems; // elements, backed by vector
};

// EXAMPLE CODE *******************************
/*
CutsceneQueue<int> intQueue;
CutsceneQueue<std::string> stringQueue;

// manipulate int queue
intQueue.push(7);
std::cout << intQueue.getTop() << std::endl;
intQueue.push(10);
intQueue.push(12);
intQueue.pop();
std::cout << intQueue.getTop() << std::endl;
intQueue.pop();
std::cout << intQueue.getTop() << std::endl;

// manipuate string queue
stringQueue.push("rawr");
std::cout << stringQueue.getTop() << std::endl;
stringQueue.push("this is for marites");
stringQueue.push("to use");
stringQueue.pop();
std::cout << stringQueue.getTop() << std::endl;
stringQueue.pop();
std::cout << stringQueue.getTop() << std::endl;
while (true) {} // loop forever
*/
/*
 * output:
 * 7
 * 10
 * 12
 * rawr
 * this is for marites
 * to use
 */
// EXAMPLE CODE END ***************************