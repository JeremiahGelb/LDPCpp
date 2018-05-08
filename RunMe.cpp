/*
 * RunMe.cpp
 *
 *  Created on: May 8, 2018
 *      Author: Jeremiah
 */

#include "RunMe.h"

RunMe::RunMe() {
	// TODO Auto-generated constructor stub

}

RunMe::~RunMe() {
	// TODO Auto-generated destructor stub
}

int main(){
	// Making parity check matrix
	std::vector< std::vector<int> > h_matrix; // Think of this as row of columns
	std::vector<int> column0;
	std::vector<int> column1;
	std::vector<int> column2;
	std::vector<int> column3;
	std::vector<int> column4;
	std::vector<int> column5;
	std::vector<int> column6;

	h_matrix.push_back(column0);
	h_matrix.push_back(column1);
	h_matrix.push_back(column2);
	h_matrix.push_back(column3);
	h_matrix.push_back(column4);
	h_matrix.push_back(column5);
	h_matrix.push_back(column6);

	// first column
	h_matrix.at(0).push_back(1);
	h_matrix.at(0).push_back(0);
	h_matrix.at(0).push_back(0);
	h_matrix.at(0).push_back(0);
	h_matrix.at(0).push_back(1);
	h_matrix.at(0).push_back(0);
	h_matrix.at(0).push_back(1);

	//second column
	h_matrix.at(1).push_back(1);
	h_matrix.at(1).push_back(1);
	h_matrix.at(1).push_back(0);
	h_matrix.at(1).push_back(0);
	h_matrix.at(1).push_back(0);
	h_matrix.at(1).push_back(1);
	h_matrix.at(1).push_back(0);

	h_matrix.at(2).push_back(0);
	h_matrix.at(2).push_back(1);
	h_matrix.at(2).push_back(1);
	h_matrix.at(2).push_back(0);
	h_matrix.at(2).push_back(0);
	h_matrix.at(2).push_back(0);
	h_matrix.at(2).push_back(1);

	h_matrix.at(3).push_back(1);
	h_matrix.at(3).push_back(0);
	h_matrix.at(3).push_back(1);
	h_matrix.at(3).push_back(1);
	h_matrix.at(3).push_back(0);
	h_matrix.at(3).push_back(0);
	h_matrix.at(3).push_back(0);

	h_matrix.at(4).push_back(0);
	h_matrix.at(4).push_back(1);
	h_matrix.at(4).push_back(0);
	h_matrix.at(4).push_back(1);
	h_matrix.at(4).push_back(1);
	h_matrix.at(4).push_back(0);
	h_matrix.at(4).push_back(0);

	h_matrix.at(5).push_back(0);
	h_matrix.at(5).push_back(0);
	h_matrix.at(5).push_back(1);
	h_matrix.at(5).push_back(0);
	h_matrix.at(5).push_back(1);
	h_matrix.at(5).push_back(1);
	h_matrix.at(5).push_back(0);

	h_matrix.at(6).push_back(0);
	h_matrix.at(6).push_back(0);
	h_matrix.at(6).push_back(0);
	h_matrix.at(6).push_back(1);
	h_matrix.at(6).push_back(0);
	h_matrix.at(6).push_back(1);
	h_matrix.at(6).push_back(1);

	Ldpcer ldpcer;

	// call the function in the Ldpcer that makes the nodes based on the h_matrix
	ldpcer.make_nodes(h_matrix);

	double sigma  = 1;
	int iterations = 1;
	std::vector<double> channel_values;

	// the channel_values are a vector of doubles
	channel_values.push_back(1.2);
	channel_values.push_back(2.1);
	channel_values.push_back(1.8);
	channel_values.push_back(-.4);
	channel_values.push_back(-.1);
	channel_values.push_back(-.5);
	channel_values.push_back(-.1);

	std::vector<int> max_likelihood_codeword =  ldpcer.find_max_likelihood_codeword(channel_values, sigma, iterations);

	for(unsigned int i =0; i<max_likelihood_codeword.size(); i++){
		std::cout << "bit: " <<i << " = " << max_likelihood_codeword.at(i) << std::endl;
	}

	return 0;
}
