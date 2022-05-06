#include "../include/EulerSystem.hpp"

void ode::EulerSystem::addAlpha(AlphaFunction alpha){
	this->alphaFunctions.push_back(alpha);
}

void ode::EulerSystem::addIzhikevich(IzhikevichModel izhikevich){
	this->izhikevichModels.push_back(izhikevich);
}

void ode::EulerSystem::step(const float interval){

}