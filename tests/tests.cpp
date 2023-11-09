#include <gtest/gtest.h>
#include <cstddef>
#include "../src/OdeCpp.hpp"

/***********************************************************
					ALPHA FUNCTION TESTS
***********************************************************/
TEST(AlphaTest, DiferentialEquation){
	ode::AlphaFunction func(1.0f, 10.0f, 3.0f);
	func.ModelDiferentialEquation(2.0f);
	float* res = func.getState();
	EXPECT_FLOAT_EQ(res[0], 5.9f);
};
TEST(AlphaTest, AlphaGetParams){
	ode::AlphaFunction func(1.0f, 10.0f, 3.0f);
	float result = func.getParams('t');
	EXPECT_FLOAT_EQ(result, -1.0f/10.0f);
	result = func.getParams('w');
	EXPECT_FLOAT_EQ(result, 3.0f);
	result = func.getParams('a');
	EXPECT_FLOAT_EQ(result, 0.0f);
	result = func.getParams('Z');
	EXPECT_FLOAT_EQ(result, 0.0f);
};
TEST(AlphaTest, AlphaEquals){
	ode::AlphaFunction func(1.0f, 10.0f, 3.0f);
	ode::AlphaFunction func2(1.0f, 10.0f, 3.0f);
	ode::AlphaFunction func3(0.5f, 30.0f, 2.0f);
	EXPECT_TRUE(func==func);
	EXPECT_TRUE(func==func2);
	EXPECT_FALSE(func==func3);
};

/***********************************************************
				IZHIKEVICH MODEL TESTS
***********************************************************/
TEST(IzhikevichTest, DiferentialEquation){
	ode::IzhikevichModel func(0.02f, 0.2f, -65.0f, 8.0f);
	func.ModelDiferentialEquation(1.0f);
	float* out = func.getState();
	EXPECT_NEAR(out[0], -7.0f, 0.1f);
	EXPECT_NEAR(out[1], -0.1f, 0.1f);
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
	result = func.getParams('Z');
	EXPECT_FLOAT_EQ(result, 0.0f);
};
TEST(IzhikevichTest, IzhikevichEquals){
	ode::IzhikevichModel func(1.0f, 2.0f, 3.0f, 4.0f);
	ode::IzhikevichModel func2(1.0f, 2.0f, 3.0f, 4.0f);
	ode::IzhikevichModel func3(2.0f, 2.0f, 3.0f, 4.0f);
	EXPECT_TRUE(func==func);
	EXPECT_TRUE(func==func2);
	EXPECT_FALSE(func==func3);
};

/***********************************************************
						OBSERVER TESTS
***********************************************************/
TEST(ObserverTest, SpikeObserver){
	float params[] = {1.0f, 2.0f, 3.0f, 4.0f};
	ode::ModelFactory factory;
	ode::IzhikevichModel func = factory.CreateNewModel<ode::IzhikevichModel>(params);
	ode::SpikeObserver obs;
	func.AttachObserver(&obs);
	func.NotifyObservers();

	EXPECT_FLOAT_EQ(obs.HasSpiked(), 1.0f);
	EXPECT_FLOAT_EQ(obs.HasSpiked(), 0.0f);
};

/***********************************************************
						FACTORY TESTS
***********************************************************/
TEST(FactoryTest, Izhikevich){
	ode::ModelFactory factory;
	float params[] = {
		1.0f, 10.0f, 3.0f, -10.0f
	};
	ode::IzhikevichModel model = factory.CreateNewModel<ode::IzhikevichModel>(params);

	float result = model.getParams('a');
	EXPECT_FLOAT_EQ(result, 1.0f);
	result = model.getParams('b');
	EXPECT_FLOAT_EQ(result, 10.0f);
	result = model.getParams('c');
	EXPECT_FLOAT_EQ(result, 3.0f);
	result = model.getParams('d');
	EXPECT_FLOAT_EQ(result, -10.0f);
	result = model.getParams('h');
	EXPECT_FLOAT_EQ(result, 0.0f);
}
TEST(FactoryTest, Alpha){
	ode::ModelFactory factory;
	float params[] = {
		1.0f, 10.0f, 3.0f
	};
	ode::AlphaFunction model = factory.CreateNewModel<ode::AlphaFunction>(params);

	float result = model.getParams('t');
	EXPECT_FLOAT_EQ(result, -1.0f/10.0f);
	result = model.getParams('w');
	EXPECT_FLOAT_EQ(result, 3.0f);
	result = model.getParams('a');
	EXPECT_FLOAT_EQ(result, 0.0f);
}

/***********************************************************
					SOLVER TESTS
***********************************************************/
TEST(SolverTest, EulerSolver){
	ode::EulerSolver<ode::IzhikevichModel> solver;
	ode::ModelFactory factory;
	ode::SpikeObserver observer;
	
	float izhikevichParams[] = {
		0.02f, 0.2f, -65.0f, 8.0f
	};
	ode::IzhikevichModel model = factory.CreateNewModel<ode::IzhikevichModel>(izhikevichParams);

	solver.Step(model, 1.0f, 0.001f);
	float* state = model.getState();

	EXPECT_NEAR(state[0], -65.0f, 0.5f);
	EXPECT_NEAR(state[1], -8.0f, 0.5f);
};

/***********************************************************
				COMPLETE SIMULATION TESTS
***********************************************************/
TEST(SimulationTest, Izhikevich){
	ode::EulerSolver<ode::IzhikevichModel> solver;
	ode::ModelFactory factory;
	ode::SpikeObserver observer;
	
	float izhikevichParams[] = {
		0.02f, 0.2f, -65.0f, 8.0f
	};
	ode::IzhikevichModel model = factory.CreateNewModel<ode::IzhikevichModel>(izhikevichParams);

	float res[5][2];
	float sol[5][2] = {
		{-65.0f, -8.0f},
		{-64.8f, -8.01f},
		{-64.6f, -8.02f},
		{-64.4f, -8.03f},
		{-64.2f, -8.04f}
	};

	for(size_t i=0; i<5; ++i){
		float* state = model.getState();
		res[i][0] = state[0];
		res[i][1] = state[1];
		solver.Step(model, 10.0f, 0.1f);
	}

	for(size_t i=0; i<5; ++i){
		EXPECT_NEAR(res[i][0], sol[i][0], 0.5f);
		EXPECT_NEAR(res[i][1], sol[i][1], 0.5f);
	}
};

int main(int argc, char **argv){
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}