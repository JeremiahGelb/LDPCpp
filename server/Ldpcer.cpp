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
	delete_nodes(); // delete old nodes before making new ones.

	// TODO add some error checking here
	// TODO Perhaps we should reject all all zero rows or columns
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

std::vector<int> Ldpcer::find_max_likelihood_codeword(std::vector<double> channel_values, double sigma, int iterations){
	// TODO Check channel value length is same as bitnodes?

	for(unsigned int i =0; i< channel_values.size(); i++){
		// give all the bitnodes their channel data
		bitnodes.at(i)->update_channel_data(channel_values.at(i), sigma);
	}

	for(unsigned int j = 0; j<checknodes.size(); j++){
		// have each bitnode send its initial probability based on channel data
		bitnodes.at(j)->send_initial_probabilities();
	}

	for(int i = 0; i<iterations; i++){

		for(unsigned int j = 0; j<checknodes.size(); j++){
			checknodes.at(j)->send_downward_messages();
		}

		for(unsigned int j = 0; j<bitnodes.size(); j++){
			bitnodes.at(j)->send_upward_messages();
		}
	}

	std::vector<int> max_likelihood_codeword;

	for(unsigned int j = 0; j<bitnodes.size(); j++){
		// each bitnode returns its  best guess of its identity
		max_likelihood_codeword.push_back(bitnodes.at(j)->return_best_guess());

		//std::cout << "bit: " <<j << " = " << bitnodes.at(j)->return_best_guess() << std::endl;
	}

	return max_likelihood_codeword;
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

	bitnodes.clear();
	checknodes.clear();
}

