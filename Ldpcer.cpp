/*
 * Ldpcer.cpp
 *
 *  Created on: May 6, 2018
 *      Author: Jeremiah
 */

#include "Ldpcer.h"

Ldpcer::Ldpcer() {
	// TODO Auto-generated constructor stub

}

Ldpcer::~Ldpcer() {
	// TODO Auto-generated destructor stub
}

int main(){
	Bitnode bitnode;
	Checknode checknode;

	bitnode.add_checknode(&checknode);
	checknode.add_bitnode(&bitnode);

	bitnode.send_upward_messages();
	checknode.send_downward_messages();

	bitnode.send_upward_messages();
	checknode.send_downward_messages();

	std::cout <<" made it to end" <<std::endl;

	return 0;
}
