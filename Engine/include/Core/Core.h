#ifndef CORE_H
#define CORE_H

#ifdef GAME_DEVELOPMENT

#include "GUI/ImWindows/Logs.h"
#include "GUI/ImWindows/GameObjects.h"
#include "GUI/ImWindows/ContentBrowser.h"
#include "GUI/ImWindows/Console.h"
#include "GUI/ImWindows/Config.h"
#include "GUI/ImWindows/DetailsPanel.h"

Engine::Config config;
Engine::Console console;
Engine::ContentBrowser contentBrowser;
Engine::DetailsPanel detailsPanel;
Engine::GameObjects gameObjects;
Engine::Logs logs;

#endif

#endif