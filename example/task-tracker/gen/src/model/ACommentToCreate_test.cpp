#include "gtest/gtest.h"

#include "ACommentToCreate.h"

TEST(ACommentToCreate, Deserialize)
{
    // TODO: generate test content
    openapi::ACommentToCreate x;
    Json j;
    x.FromJSON(j);
    x.ToJSON(j);
}