#pragma once

#include <cstddef>

namespace ode{
	class IObserver{
		protected:
		float mTime = 0.0f;

		public:
		~IObserver() = default;
		virtual void Notification(const float time) = 0;
	};

	class SpikeObserver: public IObserver{
		private:
		int mSpiked = false;

		public:
		/**
		 * @brief Reseta o estado do observador
		 * 
		 * @return 1 caso tenha acontecido um spike, 0 caso não tenha acontecido
		 */
		float HasSpiked(){
			if(this->mSpiked){
				this->mSpiked = false;
				return 1.0f;
			}
			return 0.0f;
		}

		/**
		 * @brief Notifica o observador de um Spike
		 * 
		 * @param time O momento em que o spike aconteceu
		 */
		void Notification(const float time) override{
			this->mTime = time;
			this->mSpiked = true;
		}
	};

	class ObserverSubject{
	protected:
		IObserver* mObserversList[8];
		size_t mObserverQuant = 0;
		int mEmpty = -1;

	public:
		virtual void NotifyObservers() = 0;

		/**
		 * @brief Insere um ponteiro para um observador na lista
		 * 
		 * @param observer 
		 */
		void AttachObserver(IObserver* observer){
			if(this->mObserverQuant==8)
				return;
			this->mObserversList[this->mObserverQuant++] = observer;
		}

		/**
		 * @brief Checa se o observador está na lista
		 * 
		 * @param observer 
		 * @return boolean
		 */
		bool HasObserver(IObserver* observer){
			for(auto internalObserver: this->mObserversList)
				if(internalObserver==observer)
					return true;

			return false;
		}
	};
} // namespace ode
