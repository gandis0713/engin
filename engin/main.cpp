#include <spdlog/spdlog.h>

int main(int argc, char** argv)
{
    spdlog::set_level(spdlog::level::trace);
    spdlog::debug("hello world.");
    
    return 0;
}