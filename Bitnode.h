/*
 * Bitnode.h
 *
 *  Created on: May 6, 2018
 *      Author: Jeremiah
 */

#ifndef BITNODE_H_
#define BITNODE_H_
#include <vector>
#include <string>
#include <iostream>
#include "message.h"
#include <math.h>       /* exp */

class Checknode;
// TODO Bitnode and Checknode should both inherit from parent Node class
// too much common functionality to have them be completely unique classes

class Bitnode {
	std::vector<Checknode*> checknodes;
	std::vector<message> messages;
	message calculate_upward_message(Checknode * dst);
	double p_of_one;
	double p_of_zero; // initial probabilities based on channel data;
public:
	Bitnode(double y, double sigma);
	Bitnode();
	void update_channel_data(double y, double sigma);
	void send_initial_probabilities();
	virtual ~Bitnode();
	void send_upward_messages();
	void accept_downward_message(message m);
	void add_checknode(Checknode* n); // Also sends first message to checknode
	void print_APP();

};

#endif /* BITNODE_H_ */
