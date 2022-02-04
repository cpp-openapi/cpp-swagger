#include "gtest/gtest.h"

#include "Milestone.h"

TEST(Milestone, Deserialize)
{
    // TODO: generate test content
    openapi::Milestone x;
    Json j;
    x.FromJSON(j);
    x.ToJSON(j);
}