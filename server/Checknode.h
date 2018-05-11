/*
 * Checknode.h
 *
 *  Created on: May 6, 2018
 *      Author: Jeremiah
 */

#ifndef CHECKNODE_H_
#define CHECKNODE_H_
#include <vector>
#include <string>
#include <iostream>
#include "message.h"


class Bitnode;
// TODO Bitnode and Checknode should both inherit from parent Node class
// too much common functionality to have them be completely unique classes

class Checknode {
	std::vector<Bitnode*> bitnodes;
	std::vector<message> messages;
	message calculate_downward_message(Bitnode * dst);

public:
	Checknode();
	virtual ~Checknode();
	void send_downward_messages();
	void accept_upward_message(message m);
	void add_bitnode(Bitnode* n);
};

#endif /* CHECKNODE_H_ */
