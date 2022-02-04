#include "gtest/gtest.h"

#include "TaskCard.h"

TEST(TaskCard, Deserialize)
{
    // TODO: generate test content
    openapi::TaskCard x;
    Json j;
    x.FromJSON(j);
    x.ToJSON(j);
}