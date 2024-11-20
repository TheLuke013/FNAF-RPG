#ifndef FNAF_RPG_H
#define FNAF_RPG_H

#include <Engine.h>

namespace Game
{
	class FNAFRPG : public Engine::GameApplication
	{
	public:
		FNAFRPG();
		~FNAFRPG();

		void OnReady() override;
		void OnUpdate() override;
		void OnEvent(Engine::Event e) override;
		void OnImGuiRender() override;
		void OnMenuBarRender() override;
		void OnDockspaceUpdate() override;

	};
}

#endif
