#include "genmotifsim.h"
#include <iostream>
#include <tclap/CmdLine.h>
#include <string>

using namespace TCLAP;

GenMotifSim* parse_args(int argc, char **argv, CmdLine* _cmd)
{	
	ValueArg<std::string> genome("G", "genome_file", "Name of Genome file to use for this program", true, "file name", "string");
	_cmd->add(genome);
	
	ValueArg<double> threshold("T", "threshold_value", "threshold value for the pogram; by default set at 0.25", false, 0.25, "double");
	_cmd->add(threshold);
	
	SwitchArg matrix("m", "matrix_file", "Name of Matrix file to use for this program", false);
	SwitchArg bed("b", "BED_file", "Name of BED file to use for this program" , false);
	_cmd->xorAdd(matrix, bed);
	
	_cmd->parse(argc, argv);
	
	std::string gen_file(genome.getValue());
	double T(threshold.getValue());
	bool file(matrix.getValue());
	
	GenMotifSim* sim = new GenMotifSim(gen_file, T, file);
	
	return sim;
	
}


int main(int argc, char **argv)
{
	CmdLine cmd("Genomic Motif Options");
	int error (0);
	GenMotifSim* simulation;
	
	try{
		simulation = parse_args(argc, argv, &cmd);
		simulation->run();
		
	} catch(std::runtime_error &e) {
		error = 1;
	} catch(TCLAP::ArgException &e) {
		std::cerr << "Error: " + e.error() + " " + e.argId() << std::endl;
		error =2; 
	} 
	
	return error;
}
