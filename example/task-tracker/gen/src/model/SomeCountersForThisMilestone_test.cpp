#include "gtest/gtest.h"

#include "SomeCountersForThisMilestone.h"

TEST(SomeCountersForThisMilestone, Deserialize)
{
    // TODO: generate test content
    openapi::SomeCountersForThisMilestone x;
    Json j;
    x.FromJSON(j);
    x.ToJSON(j);
}