// FuzzyTools.cpp

// Created by Conrad Kent (kentcm@mail.uc.edu) based on previous classwork in MATLAB

#include <math.h>
#include <iostream>
#include <vector>

namespace ConradFuzzy{

float TriangleInMemFun(float x, std::vector<float> MemFunDefinition) {
float a = MemFunDefinition[0];
float b = MemFunDefinition[1];
float c = MemFunDefinition[2];
/* x is the crisp, a is the left point, b is the center point, c is the
right point, mu is the degree of membership. */

	float mu;
	if (a <= x && x < b) {
	    mu = (x-a)/(b-a);
	} else if (b <=x && x <= c) {
	    mu = (c-x)/(c-b);
	} else {
	    mu=0;
	}
	return mu;
};	// float TriangleInMemFun



class TriangleOutMemFun {
/* Defining the triangular output membership function as a class */	

	public:
		std::vector<float> LeftEdges;	// The left edge of each of the triangular output membership functions
		std::vector<float> Centers;	// The center points of each of the triangular output membership functions
		std::vector<float> RightEdges;	// The right edge of each of the triangular output membership functions
		std::vector<float> MuOuts;	// The degree of membership in each of the output membership functions
		int NumberOfMFs;		// The number of MFs
}; 	// class TriangleOutMemFun






float CenterOfGravDefuzz(TriangleOutMemFun OutputFunction) {
/* Center of gravity defuzzification, limited to using triangular output
membership functions defined in the class "TriangleOutMemFun" */

	int size = OutputFunction.NumberOfMFs;
	float sumAreas;	// The sum of all the areas
	float sumCOGs;		// The sum of all the areas multiplied by their centers
	float tempArea;	// Temporary area for each iteration of the for loop
	for (int i=0; i<size; i++) {
		tempArea=0.5*OutputFunction.MuOuts[i]*(OutputFunction.RightEdges[i]-OutputFunction.LeftEdges[i]);
		sumAreas=sumAreas+tempArea;
		sumCOGs=sumCOGs+tempArea*OutputFunction.Centers[i];
  	};	// for
  	
  	return sumCOGs/sumAreas;	//crisp output using COG defuzz
};	// float CenterOfAreaDefuzz

}	// namespace ConradFuzzy
