#include "../include/IzhikevichModel.hpp"
#include <algorithm>

using namespace ode;

/*
 *	Construtor do modelo de Izhikevich.
 *	@param a,b,c,d	Valores do modelo.
 */
IzhikevichModel::IzhikevichModel(const float a, const float b, const float c, const float d){
	this->numEquations = 2;
	this->state[0] = c;
	this->state[1] = -d;

	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
}

/*
 *	Faz o cálculo diferencial da função alfa.
 *	v' = 0.04*(v^2)+5*v+140-u+I
 *	u' = a*(b-v)
 *	@param input	A corrente de entrada.
 *	@return			Um std::array contendo v' no index 0 e u' no index 1.
 */
std::array<float, MAX_EQUATIONS> IzhikevichModel::modelDiferentialEquation(const float input){
	std::array<float, MAX_EQUATIONS> newState;
	newState[0] = 0.04f*(this->state[0]*this->state[0])+5.0f*this->state[0]+140.0f-this->state[1]+input;
	newState[1] = this->a*(this->b*this->state[0]-this->state[1]);

	return newState;
}

/*
 *	Compara o modelo de Izhikevich atual com outro.
 *	@param other	Ponteiro para o outro modelo.
 *	@return			Boolean correspondente.
 */
bool IzhikevichModel::equals(const IzhikevichModel* other){
	if(this==other || (this->numEquations==other->numEquations && this->state==other->state && 
	this->time==other->time && this->a==other->a && this->b==other->b && this->c==other->c && this->d==other->d))
		return true;

	return false;
}

/*
 *	Insere um observador através de seu ponteiro.
 *	obs: Usuário deve especificar sua implementacao de observer.SpikeFired(const float time)
 *	@param observer	Ponteiro para um observador.
 */
void IzhikevichModel::attachObserver(Observer<float>& observer){
	this->observers.push_back(&observer);
}

/*
 *	Remove um observador através de seu ponteiro.
 *	@param observer	Ponteiro para um observador.
 */
void IzhikevichModel::detachObserver(Observer<float>& observer){
	auto iterator = std::find(this->observers.begin(), this->observers.end(), &observer);

	if(iterator != this->observers.end())
		observers.erase(iterator);
}

/*
 *	Notifica os observadores que um spike aconteceu, o que acontece quando essa funcao é chamada será a funcao observer.spikeFired(const float time).
 *	@param observer	Ponteiro para um observador.
 */
void IzhikevichModel::notifyObservers(){
	for(Observer<float>* observer: this->observers)
		observer->notification(this->time);
}