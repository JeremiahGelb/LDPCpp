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

class Checknode;

class Bitnode {
	std::vector<Checknode*> checknodes;
	std::vector<message> messages;
	message calculate_upward_message(Checknode * dst);
public:
	Bitnode();
	virtual ~Bitnode();
	void send_upward_messages();
	void accept_downward_message(message m);
	void add_checknode(Checknode* n);

};

#endif /* BITNODE_H_ */
