#include "EulerSolver.hpp"

namespace ode{
	void EulerSolver::Step(BaseModel* model, const float input, const float interval){
		std::vector<float> dy = model->ModelDiferentialEquation(input);
		std::vector<float> y = model->getState();

		for(long unsigned int i=0; i<y.size(); ++i)
			y[i] += (interval*dy[i]);

		model->setState(y);
		model->addTime(interval);
	}
} // namespace ode
