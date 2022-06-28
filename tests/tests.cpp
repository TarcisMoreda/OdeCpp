#include <OdeCpp/OdeCpp.hpp>
#include <gtest/gtest.h>

//Teste da função diferencial alfa
TEST(AlphaTest, DiferentialEquation){
	ode::AlphaFunction func(1.0f, 10.0f, 3.0f);
	std::vector<float> out = func.modelDiferentialEquation(2.0f);
	EXPECT_FLOAT_EQ(out[0], 5.9f);
};
TEST(AlphaTest, Step){
	ode::Ode1Solver solver;
	ode::AlphaFunction func(0.0f, 10.0f, 2.0f);

	const int NUM_ELEMENTS = 12;

	float inputs[] = {0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0};
	float expectedOut[] = {0.0f, 2.0f, 1.8f, 1.62f, 1.458f, 1.3122f, 1.18098f, 1.0628820f, 
						   2.9565938f, 2.66093442f, 2.394840978f, 2.15535688f};
	float testOut[NUM_ELEMENTS];

	for(size_t i=0; i<NUM_ELEMENTS; ++i){
		solver.step(func, 1, inputs[i]);
		testOut[i] = func.getState()[0];
		EXPECT_FLOAT_EQ(testOut[i], expectedOut[i]);
	}
};
TEST(AlphaTest, AlphaGetParams){
	ode::AlphaFunction func(1.0f, 10.0f, 3.0f);
	float result = func.getParams('A');
	float expected = -1.0f/10.0f;
	EXPECT_FLOAT_EQ(result, expected);
};

//Testes da função diferencial do neurônio Izhikevich
TEST(IzhikevichTest, DiferentialEquation){
	ode::IzhikevichModel func(0.02f, 0.2f, -65.0f, 8.0f);
	std::vector<float> out = func.modelDiferentialEquation(4.0f);
	EXPECT_FLOAT_EQ(out[0], -4.0f);
	EXPECT_FLOAT_EQ(out[1], -0.1f);
};

int main(int argc, char **argv){
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}