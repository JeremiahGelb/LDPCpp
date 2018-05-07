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
	//Right now testing functionality in main -> eventually there should be a "instantiate hanning" function
	// and a decode channel data function
	std::vector<Checknode*> checknodes;
	std::vector<Bitnode*> bitnodes;

	//7,3,4 simplex
	// Eventually hope to make this more modular - make bitnodes and checknodes based on parity check matrix
	// Have this be a webapp -> send parity check matrix as a JSON?
	// Decode multiple sets of channel data without remakng bit nodes and check nodes

	//making bitnodes
	Bitnode bitnode1(1.2,1);
	Bitnode bitnode2(2.1,1);
	Bitnode bitnode3(1.8,1);
	Bitnode bitnode4(-.4,1);
	Bitnode bitnode5(-.1,1);
	Bitnode bitnode6(-.5,1);
	Bitnode bitnode7(-.1,1);

	//adding bitnodes to list
	bitnodes.push_back(&bitnode1);
	bitnodes.push_back(&bitnode2);
	bitnodes.push_back(&bitnode3);
	bitnodes.push_back(&bitnode4);
	bitnodes.push_back(&bitnode5);
	bitnodes.push_back(&bitnode6);
	bitnodes.push_back(&bitnode7);

	//making checknodes
	Checknode checknode1;
	Checknode checknode2;
	Checknode checknode3;
	Checknode checknode4;
	Checknode checknode5;
	Checknode checknode6;
	Checknode checknode7;

	//adding checknodes to list
	checknodes.push_back(&checknode1);
	checknodes.push_back(&checknode2);
	checknodes.push_back(&checknode3);
	checknodes.push_back(&checknode4);
	checknodes.push_back(&checknode5);
	checknodes.push_back(&checknode6);
	checknodes.push_back(&checknode7);

	// telling bitnodes which checknodes they are in
	bitnode1.add_checknode(&checknode1);
	bitnode1.add_checknode(&checknode5);
	bitnode1.add_checknode(&checknode7);

	bitnode2.add_checknode(&checknode1);
	bitnode2.add_checknode(&checknode2);
	bitnode2.add_checknode(&checknode6);

	bitnode3.add_checknode(&checknode2);
	bitnode3.add_checknode(&checknode3);
	bitnode3.add_checknode(&checknode7);

	bitnode4.add_checknode(&checknode1);
	bitnode4.add_checknode(&checknode3);
	bitnode4.add_checknode(&checknode4);

	bitnode5.add_checknode(&checknode2);
	bitnode5.add_checknode(&checknode4);
	bitnode5.add_checknode(&checknode5);

	bitnode6.add_checknode(&checknode3);
	bitnode6.add_checknode(&checknode5);
	bitnode6.add_checknode(&checknode6);

	bitnode7.add_checknode(&checknode4);
	bitnode7.add_checknode(&checknode6);
	bitnode7.add_checknode(&checknode7);

	//telling checknodes which bit nodes they have.
	checknode1.add_bitnode(&bitnode1);
	checknode1.add_bitnode(&bitnode2);
	checknode1.add_bitnode(&bitnode4);

	checknode2.add_bitnode(&bitnode2);
	checknode2.add_bitnode(&bitnode3);
	checknode2.add_bitnode(&bitnode5);

	checknode3.add_bitnode(&bitnode3);
	checknode3.add_bitnode(&bitnode4);
	checknode3.add_bitnode(&bitnode6);

	checknode4.add_bitnode(&bitnode4);
	checknode4.add_bitnode(&bitnode5);
	checknode4.add_bitnode(&bitnode7);

	checknode5.add_bitnode(&bitnode1);
	checknode5.add_bitnode(&bitnode5);
	checknode5.add_bitnode(&bitnode6);

	checknode6.add_bitnode(&bitnode2);
	checknode6.add_bitnode(&bitnode6);
	checknode6.add_bitnode(&bitnode7);

	checknode7.add_bitnode(&bitnode1);
	checknode7.add_bitnode(&bitnode3);
	checknode7.add_bitnode(&bitnode7);

	int iterations = 10; // Should be parameter of function call with channel data
	for(int i = 0; i<iterations; i++){

		for(unsigned int j = 0; j<checknodes.size(); j++){
			checknodes.at(j)->send_downward_messages();
		}

		for(unsigned int j = 0; j<bitnodes.size(); j++){
			bitnodes.at(j)->send_upward_messages();
		}
	}

	std::cout <<"Final..." <<std::endl;
	for(unsigned int j = 0; j<bitnodes.size(); j++){
				bitnodes.at(j)->print_APP();
			}

	std::cout <<" made it to end" <<std::endl;

	return 0;
}

