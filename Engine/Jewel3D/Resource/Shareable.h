// Copyright (c) 2017 Emilian Cioca
#pragma once
#include <memory>

namespace Jwl
{
	template<class Derived>
	class Shareable : private std::enable_shared_from_this<Derived>
	{
	protected:
		// If the Derived class must have a private constructor, declare "friend ShareableAlloc;"
		// and make_shared will still be able to instantiate it.
		using ShareableAlloc = std::_Ref_count_obj<Derived>;

	public:
		using Ptr = std::shared_ptr<Derived>;
		using ConstPtr = std::shared_ptr<const Derived>;
		using WeakPtr = std::weak_ptr<Derived>;
		using ConstWeakPtr = std::weak_ptr<const Derived>;

		Ptr GetPtr()
		{
			return shared_from_this();
		}

		ConstPtr GetPtr() const
		{
			return shared_from_this();
		}

		WeakPtr GetWeakPtr()
		{
			return shared_from_this();
		}

		ConstWeakPtr GetWeakPtr() const
		{
			return shared_from_this();
		}

		template<typename... Args>
		static Ptr MakeNew(Args&&... params)
		{
			return std::make_shared<Derived>(std::forward<Args>(params)...);
		}
	};
}

#define REFLECT_SHAREABLE(Class) \
	REFLECT_BASIC(Class::Ptr) \
	REFLECT_BASIC(Class::ConstPtr) \
	REFLECT_BASIC(Class::WeakPtr) \
	REFLECT_BASIC(Class::ConstWeakPtr)
