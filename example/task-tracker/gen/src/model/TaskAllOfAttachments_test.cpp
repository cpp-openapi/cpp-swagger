#include "gtest/gtest.h"

#include "TaskAllOfAttachments.h"

TEST(TaskAllOfAttachments, Deserialize)
{
    // TODO: generate test content
    openapi::TaskAllOfAttachments x;
    Json j;
    x.FromJSON(j);
    x.ToJSON(j);
}