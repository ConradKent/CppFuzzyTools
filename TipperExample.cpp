#include "FuzzyTools.h"

int main() {
int service;
int quality;

std::cout << "Enter service (1-10)\n";
std::cin >> service;

std::cout << "Enter quality (1-10)\n";
std::cin >> quality;

// Defining the left, right, and center of each triangular MF
std::vector<float> serviceMF_Poor = {0,0,5};
std::vector<float> serviceMF_Average = {0,5,10};
std::vector<float> serviceMF_Good = {5,10,10};

std::vector<float> qualityMF_Poor = {0,0,5};
std::vector<float> qualityMF_Average = { 0,5,10};
std::vector<float> qualityMF_Good = {5,10,10};

//Fuzzifying to degree of membership in each MF
float serviceDegree_Poor = ConradFuzzy::TriangleInMemFun(service,serviceMF_Poor);
float serviceDegree_Average = ConradFuzzy::TriangleInMemFun(service,serviceMF_Average);
float serviceDegree_Good = ConradFuzzy::TriangleInMemFun(service,serviceMF_Good);

float qualityDegree_Poor = ConradFuzzy::TriangleInMemFun(quality,qualityMF_Poor);
float qualityDegree_Average = ConradFuzzy::TriangleInMemFun(quality,qualityMF_Average);
float qualityDegree_Good = ConradFuzzy::TriangleInMemFun(quality,qualityMF_Good);

std::cout << "Service degrees of membership" << serviceDegree_Poor << " " << serviceDegree_Average << " " << serviceDegree_Good << "\n";
std::cout << "Quality degrees of membership" << qualityDegree_Poor << " " << qualityDegree_Average << " " << qualityDegree_Good << "\n";

//Defining the output membership function
ConradFuzzy::TriangleOutMemFun OutputMF;
OutputMF.NumberOfMFs=3;
OutputMF.LeftEdges=	{0,	0,	13};
OutputMF.Centers=	{0,	13,	25};
OutputMF.RightEdges=	{13,	25,	25};


// Rules
//debugging
std::cout << "About to do OutputMF.MuOuts calculations\n";

OutputMF.MuOuts.push_back(std::max(qualityDegree_Poor,serviceDegree_Poor)); 	// if quality is poor OR service is poor, tip is poor
OutputMF.MuOuts.push_back(serviceDegree_Average); 				// if service is average, tip is medium
OutputMF.MuOuts.push_back(std::max(qualityDegree_Good,serviceDegree_Good)); 	// if quality is good OR service is good, tip is good

std::cout << "Finished OutputMF.MuOuts calculations\n";

// Defuzzification (CoG)
float Crisp_Output=CenterOfGravDefuzz(OutputMF);

// Display crisp tip
std::cout << "Suggested tip percentage: " << Crisp_Output << "\n";
}

