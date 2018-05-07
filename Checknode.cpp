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
	for(int i=0; i<bitnodes.size(); i++){
		bitnodes.at(i)->accept_downward_message(1);
	}
}

void Checknode::accept_upward_message(int message){
	std::cout << "I am a checknode and I got a " << message << std::endl;

}
