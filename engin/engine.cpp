#include "engine.h"

#include <jipu/driver.h>

namespace engin
{

Engine::Engine()
{
    jipu::DriverDescriptor driverDescriptor{
        .type = jipu::DriverType::kVulkan
    };
    auto driver = jipu::Driver::create(driverDescriptor);
}

} // namespace engin