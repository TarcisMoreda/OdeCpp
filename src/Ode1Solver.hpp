#pragma once

#include "IzhikevichModel.hpp"
#include "AlphaFunction.hpp"

namespace ode{
	class Ode1Solver{
	private:
		SpikeObserver izhikevichObserver;

		template<typename ModelType>
		void internalStep(ModelType& model, const float interval, const float input);

	public:
		template<typename ModelType>
		float step(ModelType& model, const float interval, const float input);
	};
} // namespace ode