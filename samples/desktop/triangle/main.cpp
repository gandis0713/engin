#include "engine.h"
#include <spdlog/spdlog.h>

int main(int argc, char** argv)
{
    spdlog::set_level(spdlog::level::trace);
    engin::Engine engine;
    return 0;
}