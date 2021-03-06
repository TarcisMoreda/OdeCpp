#pragma once

#include <list>
#include <algorithm>
#include <memory>

namespace ode{
	class IObserver{
	public:
		/*
 		*	Função que é executada ao notificar os observadores.
 		*	@param observer	Ponteiro para um observador.
 		*/
		virtual float notification(const float time) = 0;
	};

	class ObserverSubject{
	private:
		std::list<std::shared_ptr<IObserver>> observers;

	public:
		/*
 		 *	Notifica os observadores do acontecimento de um evento.
 		 *	@param time	Tempo do acontecimento.
 		 */
		void notifyObservers(const float time){
			for(std::shared_ptr<IObserver> observer: this->observers)
				observer->notification(time);
		}

		/*
 		*	Insere um observador através de seu ponteiro.
 		*	@param observer	Ponteiro para um observador.
 		*/
		void attachObserver(std::shared_ptr<IObserver> observer){
			this->observers.push_back(observer);
		}

		/*
 		*	Remove um observador através de seu ponteiro.
 		*	@param observer	Ponteiro para um observador.
 		*/
		void detachObserver(std::shared_ptr<IObserver> observer){
			auto iterator = std::find(this->observers.begin(), this->observers.end(), observer);

			if(iterator != this->observers.end())
				observers.erase(iterator);
		}
	};
} // namespace ode