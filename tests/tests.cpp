#include "../include/OdeSolver.hpp"
#include <iostream>

void testAlphaFunction(){
	ode::AlphaFunction func(1.0f, 10.0f, 3.0f);
	float* output = func.modelDiferentialEquation(2.0f);

	if(output[0]==5.9f)
		std::cout << "OK" << std::endl;
	else
		std::cout << output[0] << std::endl;
}

void testIzhikevichModel(){
	ode::IzhikevichModel func(0.02f, 0.2f, -65.0f, 8.0f);
	float* output = func.modelDiferentialEquation(4.0f);
	//0.04*(-65*-65)+5*-65+140-8+4
	if(output[0]==-4.0f)
		std::cout << "OK" << std::endl;
	else
		std::cout << output[0] << std::endl;
}

int main(int argc, char const *argv[]){
	testAlphaFunction();
	testIzhikevichModel();
	return 0;
}