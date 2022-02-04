#include "gtest/gtest.h"

#include "Task.h"

TEST(Task, Deserialize)
{
    // TODO: generate test content
    openapi::Task x;
    Json j;
    x.FromJSON(j);
    x.ToJSON(j);
}