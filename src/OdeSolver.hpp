#pragma once

#include "OdeModel.hpp"

namespace ode{
	class OdeSolver{
		public:
			virtual ~OdeSolver() = 0;
	};
} // namespace ode