#include "packagingMachine.h"
#include <sstream>

PackagingMachine::PackagingMachine(int boxCap): boxCapacity(boxCap)
{}

unsigned PackagingMachine::numberOfBoxes() {
	return boxes.size();
}

unsigned PackagingMachine::addBox(Box& b1) {
	boxes.push(b1);
	return boxes.size();
}

HeapObj PackagingMachine::getObjects() const {
	return this->objects;
}

HeapBox PackagingMachine::getBoxes() const {
	return this->boxes;
}

// ---------------------------------------------

// TODO
unsigned PackagingMachine::loadObjects(vector<Object> &objs) {
    for (auto itr = objs.begin(); itr != objs.end(); itr++) {
        if (itr->getWeight() <= this->boxCapacity) {
            objects.push(*itr);
            itr = objs.erase(itr);
            itr--;
        }
    }
    return objects.size();
}


// TODO
Box PackagingMachine::searchBox(Object& obj) {
    HeapBox temp;
    bool found = false;
    Box box = Box(10);
    vector<Box> v;
    while (!boxes.empty()) {
        if (found == false && boxes.top().getFree() >= obj.getWeight()) {
            found = true;
            v.push_back(boxes.top());
            boxes.pop();
        }
        else {
            temp.push(boxes.top());
            boxes.pop();
        }
    }
    this->boxes = temp;
    if (!v.empty()) return v[0];
    else return box;
}


// TODO
unsigned PackagingMachine::packObjects() {
    Box box;
    while (!objects.empty()) {
        Object object = objects.top();
        box = searchBox(object);
        box.addObject(object);
        boxes.push(box);
    }
    return boxes.size();
}

// TODO
stack<Object> PackagingMachine::boxWithMoreObjects() const {
    HeapBox aux = boxes;
    stack<Object> res;
    Box maxbox = Box(boxCapacity);
    while (!aux.empty()) {
        if (aux.top().getSize() > maxbox.getSize()) {
            maxbox = aux.top();
        }
        aux.pop();
    }
    while (!maxbox.getObjects().empty()) {
        res.push(maxbox.getObjects().top());
        maxbox.getObjects().pop();
    }
	return res;
}



