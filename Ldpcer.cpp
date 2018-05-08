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
	delete_nodes();
}

void Ldpcer::make_nodes(std::vector< std::vector<int> > h_matrix){
	delete_nodes(); // delete old nodes

	unsigned int number_of_bitnodes = h_matrix.size(); // number of columns
	unsigned int number_of_checknodes = h_matrix.at(0).size(); // number of rows (this could break on empty matrix)?
	//std::cout << "bitnodes: "<< number_of_bitnodes << " checknodes: "<< number_of_checknodes << std::endl;

	for(unsigned int i = 0; i<number_of_bitnodes; i++){
		bitnodes.push_back(new Bitnode);
		//std::cout << "made bitnode at: " <<  bitnodes.at(i) << std::endl;
	}

	for(unsigned int i = 0; i<number_of_checknodes; i++){
		checknodes.push_back(new Checknode);
		//std::cout << "made checknode at: " <<  checknodes.at(i) << std::endl;
	}

	for(unsigned int i = 0; i<number_of_checknodes; i++){
		for(unsigned int j = 0; j<number_of_bitnodes; j++){
			if(h_matrix.at(j).at(i)){ // if that spot in the matrix is a one

				checknodes.at(i)->add_bitnode(bitnodes.at(j));//introduce the nodes to each other
				bitnodes.at(j)->add_checknode(checknodes.at(i));
			}
		}
	}


}

void Ldpcer::decode_channel_data(std::vector<double> channel_values, double sigma, int interations){
	// update the channel values on all of the nodes
	// then iterate and print apps
}

void Ldpcer::delete_nodes(){
	for(unsigned int i = 0; i<bitnodes.size(); i++){
		delete bitnodes.at(i);
		//std::cout << "deleted bitnode at: " <<  bitnodes.at(i) << std::endl;
	}

	for(unsigned int i = 0; i<checknodes.size(); i++){
		delete checknodes.at(i);
		//std::cout << "deleted checknode at: " <<  checknodes.at(i) << std::endl;
	}
}

