#include "gtest/gtest.h"

#include "TaskAllOf.h"

TEST(TaskAllOf, Deserialize)
{
    // TODO: generate test content
    openapi::TaskAllOf x;
    Json j;
    x.FromJSON(j);
    x.ToJSON(j);
}