#include "gtest/gtest.h"

#include "ValidationErrorAllOf.h"

TEST(ValidationErrorAllOf, Deserialize)
{
    // TODO: generate test content
    openapi::ValidationErrorAllOf x;
    Json j;
    x.FromJSON(j);
    x.ToJSON(j);
}