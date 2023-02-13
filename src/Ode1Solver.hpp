#pragma once

#include "OdeSolver.hpp"
#include "IzhikevichModel.hpp"
#include "AlphaFunction.hpp"

namespace ode{
	class Ode1Solver: public OdeSolver{
	private:
		SpikeObserver izhikevichObserver;
		void internalStep(OdeModel& model, const float interval, const float input);

	public:
		void setup(IzhikevichModel* model);
		void step(OdeModel& model, const float interval, const float input, const int id) override;
	};
} // namespace ode
