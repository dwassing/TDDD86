#include <iostream>
#include "Tour.h"
#include "Node.h"
#include "Point.h"

using namespace std;

Tour::Tour(){}

Tour::Tour(Point a, Point b, Point c, Point d){

	//creating a circular linked list (I hope)
	firstNode = new Node(a,
				new Node(b,
				new Node(c,
				new Node(d, firstNode))));
}

Tour::~Tour(){

	clear();
}

void Tour::addPoint(Point point){

	//if list is empty, add as first node
	//otherwise, traverse list until last node is found then add node
	if (firstNode == nullptr){
		firstNode = new Node(point, nullptr);
	}
	else{
        Node *current = firstNode;
        while (current->next != nullptr){
            current = current->next;
        }
        current->next = new Node(point, nullptr);
	}
}

void Tour::clear() { //clears from the front to the back (if there is such a thing in a circular linked list...)

	Node *current = firstNode;

	while (firstNode != nullptr) {
		current = current->next;
		delete current;
	}
}

void Tour::show(){ //prints the linked list to console

	Node *current = firstNode;

    while (current != nullptr || current->next != firstNode) {
        cout << current->point.toString() << endl;
        current = current->next;
	}
}

void Tour::draw(QGraphicsScene *scene){

    // TODO: write this member
}

int Tour::size(){

	Node *current = firstNode;

	int pointCtr = 0;
	while(current != nullptr || current->next != firstNode){
		pointCtr++;
		current = current->next;
	}
}

double Tour::distance(){

    Node* current = firstNode;
    double tourDistance = 0;

    while (current != nullptr || current->next != firstNode) {
        tourDistance += current->point.distanceTo(current->next->point);
        current = current->next;
    }
    return tourDistance;
}

void Tour::insertNearest(Point p){

    // TODO: write this member
}

void Tour::insertSmallest(Point p){

    // TODO: write this member
}
