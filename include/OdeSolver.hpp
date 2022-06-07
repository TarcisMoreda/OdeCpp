#pragma once

#include "OdeModel.hpp"

namespace ode{
	template<size_t N>
	class OdeSolver{
		public:
			virtual void step(OdeModel<N>& model, const float interval, const float input) = 0;
	};
} // namespace ode