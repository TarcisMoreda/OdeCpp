#pragma once

#include "OdeModel.hpp"

namespace ode{
	template<int N>
	class OdeSolver{
		private:
			int numModels = N;

		public:
			virtual void step(OdeModel& model, const float interval, const float input) = 0;

			int getNumModels(){
				return this->numModels;
			}
	};
} // namespace ode