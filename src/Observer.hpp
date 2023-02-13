#pragma once

#include <list>
#include <algorithm>
#include <memory>

namespace ode{
	class IObserver{
	public:
		~IObserver() = default;

		/*
 		*	Função que é executada ao notificar os observadores.
 		*	@param observer	Ponteiro para um observador.
 		*/
		virtual void notification(const float time) = 0;
	};

	class SpikeObserver: public IObserver{
		private:
		int spiked = false;

		void resetInternalState(){
			this->spiked = false;
		}

		public:
		float hasSpiked(){
			if(this->spiked){
				this->spiked = false;
				return 1.0f;
			}
			return 0.0f;
		}

		void notification(const float time) override{
			this->spiked = true;
		}
	};

	class ObserverSubject{
	protected:
		std::list<IObserver*> observers;

	public:
		/*
 		 *	Notifica os observadores do acontecimento de um evento.
 		 *	@param time	Tempo do acontecimento.
 		 */
		virtual void notifyObservers() = 0;

		/*
 		*	Insere um observador através de seu ponteiro.
 		*	@param observer	Ponteiro para um observador.
 		*/
		void attachObserver(IObserver* observer){
			this->observers.push_back(observer);
		}

		/*
 		*	Remove um observador através de seu ponteiro.
 		*	@param observer	Ponteiro para um observador.
 		*/
		void detachObserver(IObserver* observer){
			auto iterator = std::find(this->observers.begin(), this->observers.end(), observer);

			if(iterator!=this->observers.end())
				observers.erase(iterator);
		}

		bool hasObserver(IObserver* observer){
			for(auto internalObserver: this->observers)
				if(internalObserver==observer)
					return true;

			return false;
		}
	};
} // namespace ode
