#include <gtest/gtest.h>
#include "Soundex.cpp"


TEST(SoundexTest, HandlesEmptyString) {
    EXPECT_EQ(generateSoundex(""), "");
}

TEST(SoundexTest, HandlesSingleCharacter) {
    EXPECT_EQ(generateSoundex("A"), "A000");
}

TEST(SoundexTest, getSoundexCode){
    EXPECT_EQ(getSoundexCode("A"), "0");
}

TEST(SoundexTest, getSoundexCode){
    EXPECT_EQ(getSoundexCode("B"), "1");
}

TEST(SoundexTest, getSoundexCode){
    EXPECT_EQ(getSoundexCode("B"), "1");
}

TEST(SoundexTest, getSoundexCode){
    EXPECT_EQ(getSoundexCode("C"), "2");
}

TEST(SoundexTest, getSoundexCode){
    EXPECT_EQ(getSoundexCode("D"), "3");
}
TEST(SoundexTest, getSoundexCode){
    EXPECT_EQ(getSoundexCode("L"), "4");
}
TEST(SoundexTest, getSoundexCode){
    EXPECT_EQ(getSoundexCode("M"), "5");
}
TEST(SoundexTest, getSoundexCode){
    EXPECT_EQ(getSoundexCode("R"), "6");
}
