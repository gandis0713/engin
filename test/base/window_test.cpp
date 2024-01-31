#include "window_test.h"

namespace engin
{

void WindowTest::SetUp()
{
    Test::SetUp();

    m_width = 1280;
    m_height = 720;
    EXPECT_GT(SDL_Init(SDL_INIT_VIDEO), -1);
    m_window = SDL_CreateWindow("Window Test",
                                SDL_WINDOWPOS_UNDEFINED,
                                SDL_WINDOWPOS_UNDEFINED,
                                m_width,
                                m_height,
                                SDL_WINDOW_SHOWN);
    EXPECT_NE(nullptr, m_window);
}

void WindowTest::TearDown()
{
    SDL_DestroyWindow(m_window);
    SDL_Quit();

    Test::TearDown();
}

} // namespace engin