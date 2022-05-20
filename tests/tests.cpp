#include "../include/OdeCpp.hpp"
#include <gtest/gtest.h>

//Teste da função diferencial alfa
TEST(AlphaTest, DiferentialEquation){
	ode::AlphaFunction func(1.0f, 10.0f, 3.0f);
	std::array<float, 1> out = func.modelDiferentialEquation(2.0f);
	EXPECT_FLOAT_EQ(out[0], 5.9f);
};

//Testes da função diferencial do neurônio Izhikevich
TEST(IzhikevichTest, DiferentialEquation1){
	ode::IzhikevichModel func(0.02f, 0.2f, -65.0f, 8.0f);
	std::array<float, 2> out = func.modelDiferentialEquation(4.0f);
	EXPECT_FLOAT_EQ(out[0], -4.0f);
};
TEST(IzhikevichTest, DiferentialEquation2){
	ode::IzhikevichModel func(0.02f, 0.2f, -65.0f, 8.0f);
	std::array<float, 2> out = func.modelDiferentialEquation(4.0f);
	EXPECT_FLOAT_EQ(out[1], -0.1f);
};

int main(int argc, char **argv){
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}