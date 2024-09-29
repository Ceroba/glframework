#pragma once
#include "inputhandler.h"
class App {
public:
	InputHandler inputhandler;

	virtual void OnStartup() {};
	virtual void OnClose() {};
	virtual void Run() = 0;
	virtual void MainLoop() = 0;
};