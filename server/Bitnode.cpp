/*
 * Bitnode.cpp
 *
 *  Created on: May 6, 2018
 *      Author: Jeremiah
 */

#include "Bitnode.h"
#include "Checknode.h"

Bitnode::Bitnode(double y, double sigma) {
	// Assuming channel sends (-1)^cj -> +1 for logic0, -1 for logic 1
	// AWGN, BPSK, equally probable bits
	// Make this more modular?
	p_of_one = 1 / (1 + exp((-2*-1*y)/(sigma*sigma)));
	p_of_zero = 1-p_of_one;
}

Bitnode::Bitnode(){
	p_of_one = .5;
	p_of_zero = .5; // default value is .5 (like a deletion)
}

void Bitnode::update_channel_data(double y, double sigma){
	// Assuming channel sends (-1)^cj -> +1 for logic0, -1 for logic 1
	// AWGN, BPSK, equally probable bits
	// Make this more modular?
	// TODO do error checking this would break on sigma = 0.
	p_of_one = 1 / (1 + exp((-2*-1*y)/(sigma*sigma)));
	p_of_zero = 1-p_of_one;
}

Bitnode::~Bitnode() {
	// TODO Auto-generated destructor stub
}

void Bitnode::add_checknode(Checknode* n){
	checknodes.push_back(n);
}

void Bitnode::send_initial_probabilities(){
	message m;
	m.one = p_of_one;
	m.zero = p_of_zero;
	m.source = this;

	for(unsigned int i=0; i<checknodes.size(); i++){
		checknodes.at(i)->accept_upward_message(m);
	}
}

void Bitnode::send_upward_messages(){
	for(unsigned int i=0; i<checknodes.size(); i++){
		checknodes.at(i)->accept_upward_message(calculate_upward_message(checknodes.at(i)));
	}
}

message Bitnode::calculate_upward_message(Checknode * dst){
	// calculates upward message based on last round of downward messages
	message m;
	m.one = p_of_one;
	m.zero = p_of_zero;
	m.source = this;

	// Perhaps optimize here by multiplying all then dividing out unwanted
	for(unsigned int i=0; i<messages.size(); i++){
		if(messages.at(i).source != dst){
			m.one = m.one * (messages.at(i).one);
			m.zero = m.zero * (messages.at(i).zero);
		}
	}

	double sum = m.one + m.zero;

	m.one = m.one/sum;
	m.zero = m.zero/sum;

	return m;
}

void Bitnode::print_APP(){
	// print out final app probabilities
	message m;
	m.one = p_of_one;
	m.zero = p_of_zero;
	m.source = this;

	for(unsigned int i=0; i<messages.size(); i++){
			m.one = m.one * (messages.at(i).one);
			m.zero = m.zero * (messages.at(i).zero);
	}

	double sum = m.one + m.zero;

	m.one = m.one/sum;
	m.zero = m.zero/sum;

	std::cout << this << std::endl;
	std::cout << "p(0) = "<< m.zero << std::endl;
	std::cout << "p(1) = "<< m.one << std::endl;

}

int Bitnode::return_best_guess(){
	// Calculates final APP probabilities for a bit - returns the bits best guess at its identity
	message m;
	m.one = p_of_one;
	m.zero = p_of_zero;
	m.source = this;

	for(unsigned int i=0; i<messages.size(); i++){
			m.one = m.one * (messages.at(i).one);
			m.zero = m.zero * (messages.at(i).zero);
	}

	if(m.one>m.zero){
		return 1;
	}

	else{
		return 0;
	}

}

void Bitnode::accept_downward_message(message m){
	// A checknode will call this function to send a downward message.
	// TODO Make it so that only a checknode can call this???


	for(unsigned int i=0; i<messages.size(); i++){
			if(messages.at(i).source == m.source){
				messages.at(i) = m;
				//std::cout << "bitnode " << this << " updated "  << m.one << ";" << m.zero <<" from: " << m.source << std::endl;
				return;
			}
		}

	messages.push_back(m); // if there is no existing message from that source, add it to the vector.
	//std::cout << "bitnode " << this << " got "  << m.one << ";" << m.zero <<" from: " << m.source << std::endl;
}
