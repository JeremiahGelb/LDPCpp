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
	std::vector<Checknode*> checknodes;
	std::vector<Bitnode*> bitnodes;

	//7,3,4 simplex

	//making bitnodes
	Bitnode bitnode1;
	Bitnode bitnode2;
	Bitnode bitnode3;
	Bitnode bitnode4;
	Bitnode bitnode5;
	Bitnode bitnode6;
	Bitnode bitnode7;

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

	int iterations = 3;
	for(int i = 0; i<iterations; i++){
		for(int j = 0; j<bitnodes.size(); j++){
			bitnodes.at(j)->send_upward_messages();
		}

		for(int j = 0; j<checknodes.size(); j++){
			checknodes.at(j)->send_downward_messages();
		}
	}

	std::cout <<" made it to end" <<std::endl;

	return 0;
}

