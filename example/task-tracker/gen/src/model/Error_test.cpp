#include "gtest/gtest.h"

#include "Error.h"

TEST(Error, Deserialize)
{
    // TODO: generate test content
    openapi::Error x;
    Json j;
    x.FromJSON(j);
    x.ToJSON(j);
}