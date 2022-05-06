#pragma once
#include <vector>
#include "OdeSolver.hpp"
#include "AlphaFunction.hpp"
#include "IzhikevichModel.hpp"

namespace ode{
	class EulerSystem: OdeSolver{
		private:
			std::vector<AlphaFunction> alphaFunctions;
			std::vector<IzhikevichModel> izhikevichModels;

		public:
			void addAlpha(AlphaFunction alpha);
			void addIzhikevich(IzhikevichModel izhikevich);
			void step(const float interval);
	};
} // namespace ode