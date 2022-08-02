#include "OdeModel.hpp"

namespace ode{
	void OdeModel::setState(const std::vector<float> state){
		this->state = state;
	}
		
	std::vector<float> OdeModel::getState(){
		return this->state;
	}
		
	void OdeModel::setTime(const float time){
		this->time = time;
	}
		
	float OdeModel::getTime(){
		return this->time;
	}
	
	void OdeModel::addTime(const float interval){
		this->time += interval;
	}
	
	int OdeModel::getNumEquations(){
		return this->numEquations;
	}
} // namespace ode
