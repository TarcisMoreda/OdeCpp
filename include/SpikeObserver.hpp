#pragma once

namespace ode{
	class SpikeObserver{
	public:
		virtual float spikeFired(const float time) = 0;
	};

	class SpikeSubject{
	public:
		virtual void attachObserver(SpikeObserver& observer) = 0;
		virtual void detachObserver(SpikeObserver& observer) = 0;
		virtual void notifyObservers() = 0;
	};
} // namespace ode