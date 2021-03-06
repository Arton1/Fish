#include <memory>
#include "Engine.h"

#ifdef _DEBUG
int main()
#else
int WinMain()
#endif
{
	std::unique_ptr<Engine> gameEngine = std::make_unique<Engine>();
	gameEngine->run();
    return 0;
}

