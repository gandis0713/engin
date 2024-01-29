#pragma once

#include "camera.h"

namespace engin
{
class Engine final
{
public:
    explicit Engine();
    ~Engine() = default;

    Camera& createCamera();
};

} // namespace engin