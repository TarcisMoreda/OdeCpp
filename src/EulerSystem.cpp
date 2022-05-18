#include "../include/EulerSystem.hpp"

using namespace ode;

void EulerSystem::addAlpha(AlphaFunction alpha){
	this->alphaFunctions.push_back(alpha);
}

void EulerSystem::addIzhikevich(IzhikevichModel izhikevich){
	this->izhikevichModels.push_back(izhikevich);
}

void EulerSystem::step(const float interval){
	if(this->alphaFunctions.size() != this->izhikevichModels.size()){
		throw std::runtime_error("The number of alpha functions and izhikevich models must be equal.");
	}
	if(this->alphaFunctions.size() == 0){
		throw std::runtime_error("No alpha functions were added.");
	}
	if(this->izhikevichModels.size() == 0){
		throw std::runtime_error("No izhikevich models were added.");
	}

}