#include <vector>
#include <gtest/gtest.h>
#include <functional>
#include <iostream>
#include "candle.h"

TEST(CandleTest, BodyContains_True)
{
    Candle candle = Candle(100, 200, 50, 150);
    EXPECT_TRUE(candle.body_contains(150));
}

TEST(CandleTest, BodyContains_False)
{
    Candle candle = Candle(100, 200, 50, 150);
    EXPECT_FALSE(candle.body_contains(57));
}

TEST(CandleTest, BodyContains_BoundaryOpen)
{
    Candle candle = Candle(100, 200, 50, 150);
    EXPECT_TRUE(candle.body_contains(100));
}

TEST(CandleTest, Contains_True)
{
    Candle candle = Candle(100, 200, 50, 150);
    EXPECT_TRUE(candle.contains(120));
}

TEST(CandleTest, Contains_False)
{
    Candle candle = Candle(100, 200, 50, 150);
    EXPECT_FALSE(candle.contains(30));
}

TEST(CandleTest, Contains_BoundaryLow)
{
    Candle candle = Candle(100, 200, 50, 150);
    EXPECT_TRUE(candle.contains(50));
}

TEST(CandleTest, FullSize_1)
{
    Candle candle = Candle(100, 200, 50, 150);
    EXPECT_EQ(candle.full_size(), 150);
}

TEST(CandleTest, FullSize_2)
{
    Candle candle = Candle(100, 210, 40, 150);
    EXPECT_EQ(candle.full_size(), 170);
}

TEST(CandleTest, FullSize_3)
{
    Candle candle = Candle(100, 300, 140, 100);
    EXPECT_EQ(candle.full_size(), 160);
}

TEST(CandleTest, BodySize_1)
{
    Candle candle = Candle(100, 200, 150, 50);
    EXPECT_EQ(candle.body_size(), 50);
}

TEST(CandleTest, BodySize_2)
{
    Candle candle = Candle(100, 300, 50, 250);
    EXPECT_EQ(candle.body_size(), 150);
}


TEST(CandleTest, BodySize_3)
{
    Candle candle = Candle(70, 200, 50, 250);
    EXPECT_EQ(candle.body_size(), 180);
}

TEST(CandleTest, IsRed_True)
{
    Candle candle = Candle(150, 100, 160, 90);
    EXPECT_TRUE(candle.is_red());
}
TEST(CandleTest, IsRed_False_2)
{
    Candle candle = Candle(150, 100, 160, 150);
    EXPECT_FALSE(candle.is_red());
}

TEST(CandleTest, IsRed_False_1)
{
    Candle candle(100, 160, 90, 150); // close > open
    EXPECT_FALSE(candle.is_red());
}

TEST(CandleTest, IsGreen_True)
{
    Candle candle(100, 160, 90, 150); // close > open
    EXPECT_TRUE(candle.is_green());
}

TEST(CandleTest, IsGreen_False_1)
{
    Candle candle(150, 160, 140, 100); // close < open
    EXPECT_FALSE(candle.is_green());
}

TEST(CandleTest, IsGreen_False_2)
{
    Candle candle(150, 160, 100, 150);
    EXPECT_FALSE(candle.is_green());
}