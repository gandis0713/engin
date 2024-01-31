
#pragma once

#include <gtest/gtest.h>

namespace engin
{

class Test : public testing::Test
{
protected:
    void SetUp() override;
    void TearDown() override;
};

} // namespace engin
