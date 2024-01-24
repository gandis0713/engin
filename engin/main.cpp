#include <jipu/driver.h>
#include <spdlog/spdlog.h>

int main(int argc, char** argv)
{
    jipu::DriverDescriptor driverDescriptor{
        .type = jipu::DriverType::kVulkan
    };
    auto driver = jipu::Driver::create(driverDescriptor);

    return 0;
}