#include <gtest/gtest.h>
#include <OdeCpp/OdeCpp.hpp>

//Teste da função diferencial alfa
TEST(AlphaTest, DiferentialEquation){
	ode::AlphaFunction func(1.0f, 10.0f, 3.0f);
	std::vector<float> out = func.modelDiferentialEquation(2.0f);
	EXPECT_FLOAT_EQ(out[0], 5.9f);
};
TEST(AlphaTest, AlphaGetParams){
	ode::AlphaFunction func(1.0f, 10.0f, 3.0f);
	float result = func.getParams('t');
	EXPECT_FLOAT_EQ(result, -1.0f/10.0f);
	result = func.getParams('w');
	EXPECT_FLOAT_EQ(result, 3.0f);
	result = func.getParams('a');
	EXPECT_FLOAT_EQ(result, 0.0f);
};

//Testes da função diferencial do neurônio Izhikevich
TEST(IzhikevichTest, DiferentialEquation){
	ode::IzhikevichModel func(0.02f, 0.2f, -65.0f, 8.0f);
	std::vector<float> out = func.modelDiferentialEquation(4.0f);
	EXPECT_FLOAT_EQ(out[0], -4.0f);
	EXPECT_FLOAT_EQ(out[1], -0.1f);
};
TEST(IzhikevichTest, IzhikevichGetParams){
	ode::IzhikevichModel func(1.0f, 10.0f, 3.0f, -10.0f);
	float result = func.getParams('a');
	EXPECT_FLOAT_EQ(result, 1.0f);
	result = func.getParams('b');
	EXPECT_FLOAT_EQ(result, 10.0f);
	result = func.getParams('c');
	EXPECT_FLOAT_EQ(result, 3.0f);
	result = func.getParams('d');
	EXPECT_FLOAT_EQ(result, -10.0f);
	result = func.getParams('h');
	EXPECT_FLOAT_EQ(result, 0.0f);
};

int main(int argc, char **argv){
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}