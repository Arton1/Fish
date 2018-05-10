#include <memory>
#include "Engine.h"

int WinMain()
{
	std::unique_ptr<Engine> gameEngine = std::make_unique<Engine>();
	gameEngine->run();
    return 0;
}

