#pragma once

#include <list>
#include <algorithm>

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
		std::list<IObserver*> mObserversList;

	public:
		virtual void NotifyObservers() = 0;

		/**
		 * @brief Insere um ponteiro para um observador na lista
		 * 
		 * @param observer 
		 */
		void AttachObserver(IObserver* observer){
			this->mObserversList.push_back(observer);
		}

		/**
		 * @brief Remove um observador através de seu ponteiro
		 * 
		 * @param observer 
		 */
		void DetachObserver(IObserver* observer){
			auto iterator = std::find(this->mObserversList.begin(), this->mObserversList.end(), observer);

			if(iterator!=this->mObserversList.end())
				mObserversList.erase(iterator);
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
