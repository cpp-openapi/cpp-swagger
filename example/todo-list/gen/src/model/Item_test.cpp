#include "gtest/gtest.h"

#include "Item.h"

TEST(Item, Deserialize)
{
    // TODO: generate test content
    openapi::Item x;
    Json j;
    x.FromJSON(j);
    x.ToJSON(j);
}