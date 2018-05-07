/*
 * Bitnode.cpp
 *
 *  Created on: May 6, 2018
 *      Author: Jeremiah
 */

#include "Bitnode.h"
#include "Checknode.h"

Bitnode::Bitnode() {
	// TODO Auto-generated constructor stub

}

Bitnode::~Bitnode() {
	// TODO Auto-generated destructor stub
}

void Bitnode::add_checknode(Checknode* n){
	checknodes.push_back(n);
}

void Bitnode::send_upward_messages(){
	for(int i=0; i<checknodes.size(); i++){
		checknodes.at(i)->accept_upward_message(calculate_upward_message(checknodes.at(i)));
	}
}

message Bitnode::calculate_upward_message(Checknode * dst){
	message m;
	m.one = .5;
	m.zero = .5;
	m.source = this;

	return m;
}

void Bitnode::accept_downward_message(message m){
	for(int i=0; i<messages.size(); i++){
			if(messages.at(i).source == m.source){
				messages.at(i) = m;
				std::cout << "bitnode " << this << " updated "  << m.one << ";" << m.zero <<" from: " << m.source << std::endl;
				return;
			}
		}

	messages.push_back(m); // if there is no existing message from that source, add it to the vector.
	std::cout << "bitnode " << this << " got "  << m.one << ";" << m.zero <<" from: " << m.source << std::endl;
}
