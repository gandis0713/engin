#pragma once

#include "test.h"
#include <SDL2/SDL.h>

namespace engin
{

class WindowTest : public Test
{
protected:
    void SetUp() override;
    void TearDown() override;

    void* handle();

    SDL_Window* m_window;
    uint32_t m_width = 0;
    uint32_t m_height = 0;
};

} // namespace engin