#include "gtest/gtest.h"

#include "UserCard.h"

TEST(UserCard, Deserialize)
{
    // TODO: generate test content
    openapi::UserCard x;
    Json j;
    x.FromJSON(j);
    x.ToJSON(j);
}