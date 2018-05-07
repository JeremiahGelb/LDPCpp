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

class Checknode;

class Bitnode {
	std::vector<Checknode*> checknodes;
public:
	Bitnode();
	virtual ~Bitnode();
	void send_upward_messages();
	void accept_downward_message(int message);
	void add_checknode(Checknode* n);
};

#endif /* BITNODE_H_ */
