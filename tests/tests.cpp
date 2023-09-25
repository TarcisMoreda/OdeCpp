#include <gtest/gtest.h>
#include <vector>
#include "../src/OdeCpp.hpp"

/***********************************************************
					ALPHA FUNCTION TESTS
***********************************************************/
TEST(AlphaTest, DiferentialEquation){
	ode::AlphaFunction func(1.0f, 10.0f, 3.0f);
	func.ModelDiferentialEquation(2.0f);
	std::vector<float> res = func.getState();
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
	func.ModelDiferentialEquation(4.0f);
	std::vector<float> out = func.getState();
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
TEST(ObserverTest, GenericSpikeObserver){
	ode::ModelFactory fac;
	float params[] = {1.0f, 2.0f, 3.0f, 4.0f};
	ode::BaseModel* func = fac.CreateNewModel<ode::IzhikevichModel>(params);
	ode::SpikeObserver obs;
	func->AttachObserver(&obs);
	func->NotifyObservers();

	EXPECT_FLOAT_EQ(obs.HasSpiked(), 1.0f);
	EXPECT_FLOAT_EQ(obs.HasSpiked(), 0.0f);
};
TEST(ObserverTest, SpikeObserver){
	ode::IzhikevichModel func(1.0f, 2.0f, 3.0f, 4.0f);
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
	ode::IzhikevichModel* model = (ode::IzhikevichModel*) factory.CreateNewModel<ode::IzhikevichModel>(params);

	float result = model->getParams('a');
	EXPECT_FLOAT_EQ(result, 1.0f);
	result = model->getParams('b');
	EXPECT_FLOAT_EQ(result, 10.0f);
	result = model->getParams('c');
	EXPECT_FLOAT_EQ(result, 3.0f);
	result = model->getParams('d');
	EXPECT_FLOAT_EQ(result, -10.0f);
	result = model->getParams('h');
	EXPECT_FLOAT_EQ(result, 0.0f);

	delete model;
}
TEST(FactoryTest, Alpha){
	ode::ModelFactory factory;
	float params[] = {
		1.0f, 10.0f, 3.0f
	};
	ode::AlphaFunction* model = (ode::AlphaFunction*) factory.CreateNewModel<ode::AlphaFunction>(params);

	float result = model->getParams('t');
	EXPECT_FLOAT_EQ(result, -1.0f/10.0f);
	result = model->getParams('w');
	EXPECT_FLOAT_EQ(result, 3.0f);
	result = model->getParams('a');
	EXPECT_FLOAT_EQ(result, 0.0f);

	delete model;
}

/***********************************************************
					SOLVER TESTS
***********************************************************/
TEST(SolverTest, EulerSolver){
	ode::EulerSolver solver;
	ode::ModelFactory factory;
	ode::SpikeObserver observer;
	
	float izhikevichParams[] = {
		0.02f, 0.2f, -65.0f, 8.0f
	};
	ode::IzhikevichModel* model = (ode::IzhikevichModel*) factory.CreateNewModel<ode::IzhikevichModel>(izhikevichParams);

	solver.Step(model, 1.0f, 0.001f);
	std::vector<float> state = model->getState();

	EXPECT_FLOAT_EQ(state[0], -65.007f);
	EXPECT_FLOAT_EQ(state[1], -8.0001f);
};

int main(int argc, char **argv){
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}