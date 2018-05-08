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

void Ldpcer::make_nodes(std::vector< std::vector<int> > h_matrix){
	unsigned int number_of_bitnodes = h_matrix.size(); // number of columns
	unsigned int number_of_checknodes = h_matrix.at(0).size(); // number of rows (this could break on empty matrix)?

	std::cout << "bitnodes: "<< number_of_bitnodes << " checknodes: "<< number_of_checknodes << std::endl;
}
void Ldpcer::delete_nodes(){

}

