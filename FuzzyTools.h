// FuzzyTools.cpp

// Created by Conrad Kent (kentcm@mail.uc.edu) based on previous classwork in MATLAB

#ifndef CONRAD_FUZZY_TOOLS_  /* Include guard */
#define CONRAD_FUZZY_TOOLS

#include <math.h>
#include <iostream>
#include <vector>

namespace ConradFuzzy{

float TriangleInMemFun(float x, float a, float b, float c);

class TriangleOutMemFun {
/* Defining the triangular output membership function as a class */	

	public:
		std::vector<float> LeftEdges;
		std::vector<float> Centers;
		std::vector<float> RightEdges;
		std::vector<float> MuOuts;
}; 	// class TriangleOutMemFun

float CenterOfGravDefuzz(TriangleOutMemFun OutputFunction);

}	// namespace ConradFuzzy

#endif
