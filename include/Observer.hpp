#pragma once

#include <vector>

namespace ode{
	template <typename T>
	class Observer{
	public:
		virtual T notification(const float time) = 0;
	};

	template <typename T>
	class ObserverSubject{
	protected:
		std::vector<Observer<T>*> observers;

	public:
		virtual void attachObserver(Observer<T>& observer) = 0;
		virtual void detachObserver(Observer<T>& observer) = 0;
		virtual void notifyObservers() = 0;
	};
} // namespace ode