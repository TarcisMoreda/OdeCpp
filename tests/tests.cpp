#include <gtest/gtest.h>
#include <vector>
#include "../src/OdeCpp.hpp"

/***********************************************************
					ALPHA FUNCTION TESTS
***********************************************************/
TEST(AlphaTest, DiferentialEquation){
	ode::AlphaFunction func(1.0f, 10.0f, 3.0f);
	std::vector<float> res = func.ModelDiferentialEquation(2.0f);
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
	std::vector<float> out = func.ModelDiferentialEquation(4.0f);
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

	solver.Step(model, 0.001f, 1.0f);
	std::vector<float> state = model->getState();

	EXPECT_FLOAT_EQ(state[0], -65.007f);
	EXPECT_FLOAT_EQ(state[1], -8.0001f);
};

/***********************************************************
					SIMULATOR TESTS
***********************************************************/
// TEST(SimulatorTest, EulerSolver){
	// ode::ModelFactory factory;
	// ode::EulerSolver solver;
	// ode::BaseSimulator simulator(&solver);
// 
	// float izhikevichParams[] = {
		// 0.02f, 0.2f, -65.0f, 8.0f
	// };
	// for(int i=0; i<16; ++i)
		// simulator.InsertModel(factory.CreateNewModel(ode::IZHIKEVICH, izhikevichParams));
// 
	// float alphaParams1[] = {
		// 0.0f, 0.01f, 0.0f
	// };
	// float alphaParams2[] = {
		// 0.0f, 0.01f, 1.0f
	// };
	// for(int i=0; i<16; ++i)
		// if(i!=1)
			// simulator.InsertModel(factory.CreateNewModel(ode::ALPHA, alphaParams1));
		// else
			// simulator.InsertModel(factory.CreateNewModel(ode::ALPHA, alphaParams2));
// 
	// std::vector<float> inputs = {
		// 0.0f,
		// 0.5f*1024.0f,
		// 0.0f,
		// 0.0f,
		// 0.0f,
		// 0.0f,
		// 0.0f,
		// 0.0f,
		// 0.0f,
		// 0.0f,
		// 0.0f,
		// 0.0f,
		// 0.0f,
		// 0.0f,
		// 0.0f,
		// 0.0f
	// };
// 
	// std::vector<float> results = {
		// 0.000000f,
		// 0.001000f,
		// 0.001900f,
		// 0.002710f,
		// 0.003439f,
		// 0.004095f,
		// 0.004686f,
		// 0.005217f,
		// 0.005695f,
		// 0.006126f,
		// 0.006513f,
		// 0.006862f,
		// 0.007176f,
		// 0.007458f,
		// 0.007712f,
		// 0.007941f,
		// 0.008147f,
		// 0.008332f,
		// 0.008499f,
		// 0.008649f,
		// 0.008784f,
		// 0.008906f,
		// 0.009015f,
		// 0.009114f,
		// 0.009202f,
		// 0.009282f,
		// 0.009354f,
		// 0.009419f,
		// 0.009477f,
		// 0.009529f,
		// 0.009576f,
		// 0.009618f,
		// 0.009657f,
		// 0.009691f,
		// 0.009722f,
		// 0.009750f,
		// 0.009775f,
		// 0.009797f,
		// 0.009818f,
		// 0.009836f,
		// 0.009852f,
		// 0.009867f,
		// 0.009880f,
		// 0.009892f,
		// 0.009903f,
		// 0.009913f,
		// 0.009921f,
		// 0.009929f,
		// 0.009936f,
		// 0.009943f,
		// 0.009948f,
		// 0.009954f,
		// 0.009958f,
		// 0.009962f,
		// 0.009966f,
		// 0.009970f,
		// 0.009973f,
		// 0.009975f,
		// 0.009978f,
		// 0.009980f,
		// 0.009982f,
		// 0.009984f,
		// 0.009985f,
		// 0.009987f,
		// 0.009988f,
		// 0.009989f,
		// 0.009990f,
		// 0.009991f,
		// 0.009992f,
		// 0.009993f,
		// 0.009994f,
		// 0.009994f,
		// 0.009995f,
		// 0.009995f,
		// 0.009996f,
		// 0.009996f,
		// 0.009997f,
		// 0.009997f,
		// 0.009997f,
		// 0.009998f,
		// 0.009998f,
		// 0.009998f,
		// 0.009998f,
		// 0.009998f,
		// 0.009999f,
		// 0.009999f,
		// 0.009999f,
		// 0.009999f,
		// 0.009999f,
		// 0.009999f,
		// 0.009999f,
		// 0.009999f,
		// 0.009999f,
		// 0.009999f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f,
		// 0.010000f
	// };
// 
	// for(int i=0; i<results.size(); ++i){
		// float res = simulator.NeuronSetStep(1.0f, inputs);
		// EXPECT_FLOAT_EQ(res, results[i]);
	// }
// };

int main(int argc, char **argv){
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}