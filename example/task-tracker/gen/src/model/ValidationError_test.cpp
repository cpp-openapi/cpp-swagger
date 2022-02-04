#include "gtest/gtest.h"

#include "ValidationError.h"

TEST(ValidationError, Deserialize)
{
    // TODO: generate test content
    openapi::ValidationError x;
    Json j;
    x.FromJSON(j);
    x.ToJSON(j);
}