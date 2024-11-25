#include "Core/Event.h"

namespace Engine
{
	EventManager& EventManager::Get()
	{
		static EventManager* instance = new EventManager();
		return *instance;
	}

	void EventManager::Register(EventListener* listener)
	{
		listeners.push_back(listener);
	}

	void EventManager::Fire(Event e)
	{
		for (auto listener : listeners)
		{
			listener->_OnEvent(e);
		}
	}
}