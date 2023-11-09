#pragma once

#include "IModel.hpp"
#include "ISolver.hpp"
#include "Observer.hpp"
#include <cstddef>

namespace ode{
	template<typename model1, typename model2, typename solver1, typename solver2, typename observer, size_t size>
	class ISimulator{
	protected:
		solver1 mModelSolver;
		solver2 mFunctionSolver;
		model1 mModel[size];
		model2 mFunction[size];
		size_t mSize=0;
		observer mObserver;

	public:
		ISimulator(){};
		virtual ~ISimulator(){};
		virtual float NeuronStep(const float* inputs, const float interval) = 0;

		void InsertModel(float params1[], float params2[]){
			if(size==this->mSize)
				return;
			
			this->mModel[this->mSize] = model1(params1);
			this->mModel[this->mSize].AttachObserver(&this->mObserver);
			this->mFunction[this->mSize++] = model2(params2);
		};
	};
} // namespace ode