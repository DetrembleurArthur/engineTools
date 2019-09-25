#ifndef POLYMORPH_ENTITY_HPP
#define POLYMORPH_ENTITY_HPP
#include "Widget.hpp"
#include <functional>
#include <type_traits>

namespace se
{
	template <class T=RectEntity>
	class PolymorphEntity : public T
	{
	private:
		std::function<void()> updateLambda = [](){};
	public:
		using T::T;
		void setUpdate(std::function<void()> updateLambda);
		virtual void update() override;
	};
	template <class T>
	void PolymorphEntity<T>::setUpdate(std::function<void()> updateLambda)
	{
		this->updateLambda = updateLambda;
	}

	template <class T>
	void PolymorphEntity<T>::update()
	{
		if(!std::is_abstract<T>())
		{
			this->T::update();
		}
		this->updateLambda();
	}
}

#endif
