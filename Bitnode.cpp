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
		checknodes.at(i)->accept_upward_message(1);
	}
}

void Bitnode::accept_downward_message(int message){
	std::cout << "I am a bitnode and I got a " << message << std::endl;

}
