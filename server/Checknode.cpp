/*
 * Checknode.cpp
 *
 *  Created on: May 6, 2018
 *      Author: Jeremiah
 */

#include "Checknode.h"
#include "Bitnode.h"

Checknode::Checknode() {
	// TODO Auto-generated constructor stub

}

Checknode::~Checknode() {
	// TODO Auto-generated destructor stub
}

void Checknode::add_bitnode(Bitnode* n){
	bitnodes.push_back(n);
}

void Checknode::send_downward_messages(){
	for(unsigned int i=0; i<bitnodes.size(); i++){
		bitnodes.at(i)->accept_downward_message(calculate_downward_message(bitnodes.at(i)));
	}
}

message Checknode::calculate_downward_message(Bitnode * dst){\
	// Room for optimization here - multiply all the (2q-1) then divide out the unwanted one?
	double p_one = .5;

	for(unsigned int i=0; i<messages.size(); i++){
		if(messages.at(i).source != dst){
			p_one = p_one*(2*messages.at(i).one - 1);
		}
	}

	p_one = (.5) + (p_one);

	message m;
	m.one = 1-p_one; // This doesn't make much sense, but it fixed the problem.
	m.zero = p_one; // Perhaps double check 18notes 10 page 26
	m.source = this;

	return m;
}

void Checknode::accept_upward_message(message m){
	// TODO Make it so that only a bitnode can call this???
	for(unsigned int i=0; i<messages.size(); i++){
			if(messages.at(i).source == m.source){
				messages.at(i) = m;
				//std::cout << "checknode " << this << " updated "  << m.one << ";" << m.zero <<" from: " << m.source << std::endl;
				return;
			}
		}

	messages.push_back(m); // if there is no existing message from that source, add it to the vector.
	//std::cout << "checknode " << this << " got "  << m.one << ";" << m.zero <<" from: " << m.source << std::endl;
}
