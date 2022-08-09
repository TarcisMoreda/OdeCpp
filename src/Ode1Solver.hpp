#pragma once

#include "IzhikevichModel.hpp"
#include "AlphaFunction.hpp"

namespace ode{
	class Ode1Solver{
	private:
		SpikeObserver izhikevichObserver;
		void internalStep(OdeModel& model, const float interval, const float input);

	public:
		void step(OdeModel& model, const float interval, const float input);
	};
} // namespace ode