#include <gtest/gtest.h>
#include "../src/OdeCpp.hpp"

TEST(AlphaTest, DiferentialEquation){
	ode::AlphaFunction func(1.0f, 10.0f, 3.0f);
	EXPECT_FLOAT_EQ(func.modelDiferentialEquation(2.0f)[0], 5.9f);
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
TEST(AlphaTest, AlphaEquals){
	ode::AlphaFunction func(1.0f, 10.0f, 3.0f);
	ode::AlphaFunction func2(1.0f, 10.0f, 3.0f);
	ode::AlphaFunction func3(0.5f, 30.0f, 2.0f);
	EXPECT_TRUE(func.equals(&func));
	EXPECT_TRUE(func.equals(&func2));
	EXPECT_FALSE(func.equals(&func3));
};

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
TEST(IzhikevichTest, IzhikevichEquals){
	ode::IzhikevichModel func(1.0f, 2.0f, 3.0f, 4.0f);
	ode::IzhikevichModel func2(1.0f, 2.0f, 3.0f, 4.0f);
	ode::IzhikevichModel func3(2.0f, 2.0f, 3.0f, 4.0f);
	EXPECT_TRUE(func.equals(&func));
	EXPECT_TRUE(func.equals(&func2));
	EXPECT_FALSE(func.equals(&func3));
};

TEST(SolverTest, Ode1Solver){
	ode::Ode1Solver solver;

	ode::IzhikevichModel izhikevich(0.02f,0.2f,65.0f,8.0f);
	ode::AlphaFunction alpha(0.0f, 0.01f, 1.0f);

	solver.setup(izhikevich);
	solver.step(&izhikevich, 0.001f, 1, 0);
	solver.step(&alpha, 0.001f, 0, 1);

	EXPECT_FLOAT_EQ(alpha.getState()[0], 0.001f);
 };

TEST(SimulatorTest, Ode1Solver){
	ode::Ode1Solver solver;
	ode::OdeSimulator simulator(&solver);

	for(int i=0; i<16; ++i){
		simulator.addIzhikevich(0.02f, 0.2f, -65.0f, 8.0f);
	}

	std::vector<ode::AlphaFunction> alphas;
	for(int i=0; i<16; ++i){
		if(i!=1)
			simulator.addAlpha(0.0f, 0.01f, 0.0f);
		else
			simulator.addAlpha(0.0f, 0.01f, 1.0f);
	}

	std::vector<float> inputs = {
		0.0f,
		0.5f*1024.0f,
		0.0f,
		0.0f,
		0.0f,
		0.0f,
		0.0f,
		0.0f,
		0.0f,
		0.0f,
		0.0f,
		0.0f,
		0.0f,
		0.0f,
		0.0f,
		0.0f
	};

	float results[] = {
		0.000000f,
		0.001000f,
		0.001900f,
		0.002710f,
		0.003439f,
		0.004095f,
		0.004686f,
		0.005217f,
		0.005695f,
		0.006126f,
		0.006513f,
		0.006862f,
		0.007176f,
		0.007458f,
		0.007712f,
		0.007941f,
		0.008147f,
		0.008332f,
		0.008499f,
		0.008649f,
		0.008784f,
		0.008906f,
		0.009015f,
		0.009114f,
		0.009202f,
		0.009282f,
		0.009354f,
		0.009419f,
		0.009477f,
		0.009529f,
		0.009576f,
		0.009618f,
		0.009657f,
		0.009691f,
		0.009722f,
		0.009750f,
		0.009775f,
		0.009797f,
		0.009818f,
		0.009836f,
		0.009852f,
		0.009867f,
		0.009880f,
		0.009892f,
		0.009903f,
		0.009913f,
		0.009994f,
		0.009994f,
		0.009995f,
		0.009995f,
		0.009996f,
		0.009996f,
		0.009997f,
		0.009997f,
		0.009997f,
		0.009998f,
		0.009998f,
		0.009998f,
		0.009998f,
		0.009998f,
		0.009999f,
		0.009999f,
		0.009999f,
		0.009999f,
		0.009999f,
		0.009999f,
		0.009999f,
		0.009999f,
		0.009999f,
		0.009999f,
		0.010000f,
	};

	for(int i=0; i<95; ++i){
		float res = simulator.neuronSetStep(1.0f, inputs);
		EXPECT_FLOAT_EQ(res, results[i]);
	}
};

int main(int argc, char **argv){
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}