#include <spdlog/spdlog.h>

#include "camera.h"
#include "engine.h"

int main(int argc, char** argv)
{
    engin::Engine engine;
    engin::PerspectiveCamera camera{ 45.f, 1.f, 0.1f, 1000.f };

    return 0;
}