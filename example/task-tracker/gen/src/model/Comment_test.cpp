#include "gtest/gtest.h"

#include "Comment.h"

TEST(Comment, Deserialize)
{
    // TODO: generate test content
    openapi::Comment x;
    Json j;
    x.FromJSON(j);
    x.ToJSON(j);
}