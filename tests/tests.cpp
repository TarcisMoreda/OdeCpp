#include "./acutest.hpp"
#include "../include/OdeSolver.hpp"
#include <iostream>
#include <cmath>

inline bool floatIsEqual(float a, float b){
	return std::abs(a-b) <= 1e-5*std::abs(a);
}

//Teste da funcao alfa
void test_AlphaDiferentialEquation(){
	ode::AlphaFunction func(1.0f, 10.0f, 3.0f);
	std::array<float, MAX_EQUATIONS> output = func.modelDiferentialEquation(2.0f);

	TEST_ASSERT_(floatIsEqual(output[0], 5.9f), "Alpha_v' = %lf == %lf", 
												output[0], 5.9f);
}

void test_IzhikevichDiferentialEquation(){
	ode::IzhikevichModel func(0.02f, 0.2f, -65.0f, 8.0f);
	std::array<float, MAX_EQUATIONS> output = func.modelDiferentialEquation(4.0f);
	
	TEST_ASSERT_(floatIsEqual(output[0], -4.0f), "Izhikevich_v' = %lf == %lf",
												output[0], -4.0f);

	TEST_ASSERT_(floatIsEqual(output[1], -0.1f), "Izhikevich_u' = %lf == %lf",
												output[1], -0.1f);
}

TEST_LIST = {
	{"Alpha Diferential Equation", test_AlphaDiferentialEquation},
	{"Izhikevich Diferential Equation", test_IzhikevichDiferentialEquation},
	{0}
};