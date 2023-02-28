#pragma once

#include <list>
#include <algorithm>
#include <memory>

namespace ode{
	class IObserver{
		protected:
		float mTime = 0.0f;

		public:
		~IObserver() = default;

		/*
 		*	Função que é executada ao notificar os observadores.
 		*	@param observer	Ponteiro para um observador.
 		*/
		virtual void Notification(const float time) = 0;
	};

	class SpikeObserver: public IObserver{
		private:
		int mSpiked = false;

		public:
		float HasSpiked(){
			if(this->mSpiked){
				this->mSpiked = false;
				return 1.0f;
			}
			return 0.0f;
		}

		void Notification(const float time) override{
			this->mTime = time;
			this->mSpiked = true;
		}
	};

	class ObserverSubject{
	protected:
		std::list<IObserver*> mObserversList;

	public:
		/*
 		 *	Notifica os observadores do acontecimento de um evento.
 		 *	@param time	Tempo do acontecimento.
 		 */
		virtual void NotifyObservers() = 0;

		/*
 		*	Insere um observador através de seu ponteiro.
 		*	@param observer	Ponteiro para um observador.
 		*/
		void AttachObserver(IObserver* observer){
			this->mObserversList.push_back(observer);
		}

		/*
 		*	Remove um observador através de seu ponteiro.
 		*	@param observer	Ponteiro para um observador.
 		*/
		void DetachObserver(IObserver* observer){
			auto iterator = std::find(this->mObserversList.begin(), this->mObserversList.end(), observer);

			if(iterator!=this->mObserversList.end())
				mObserversList.erase(iterator);
		}

		bool HasObserver(IObserver* observer){
			for(auto internalObserver: this->mObserversList)
				if(internalObserver==observer)
					return true;

			return false;
		}
	};
} // namespace ode
