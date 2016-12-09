#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "Graph.h"

using namespace std;


// return a vector of strings containing the stations names indexed by their identifiers
// throw an exception if there was a problem opening or reading the file
std::vector<string> readStationNames(const std::string& filename) {
	vector <string> Station(400); 
	fstream file(filename); 
	if (!file) {
		throw invalid_argument("Unable to open file " + filename);
	}
	string name;
	int number; 
	while (!file.eof())
	{	
		file >> name >> number; 
		Station[number] = name; 
		
		
	}
	file.close(); 
	
	return Station; 
}



// return a graph representing these station links
// throw an exception if there was a problem opening or reading the file
Graph *buildGraphfromDatafile(const std::string& filename) {
	int route1, route2; 
	fstream route(filename);
	Graph map(400);

	if(!route)
	{
		throw invalid_argument("Unable to open file " + filename);
	}

	while (!route.eof())
	{
		route >> route1 >> route2; 
		map.insertEdge(route1, route2);
	}

	route.close(); 
	return &map;
}
