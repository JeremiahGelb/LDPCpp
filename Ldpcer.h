/*
 * Ldcper.h
 *
 *  Created on: May 6, 2018
 *      Author: Jeremiah
 */

#ifndef LDPCER_H_
#define LDPCER_H_
#include "Bitnode.h"
#include "Checknode.h"

class Ldpcer {
	std::vector<Checknode*> checknodes;
	std::vector<Bitnode*> bitnodes;
public:
	Ldpcer();
	virtual ~Ldpcer();
	void make_nodes(std::vector< std::vector<int> > h_matrix);
	void delete_nodes();
	void decode_channel_data(std::vector<double> channel_values, double sigma, int interations);

};

#endif /* LDPCER_H_ */
