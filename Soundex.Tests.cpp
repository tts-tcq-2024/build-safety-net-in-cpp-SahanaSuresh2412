#include <gtest/gtest.h>
#include "Soundex.h"

class SoundexTest : public ::testing::TestWithParam<std::pair<std::string, std::string>> {
};

TEST_P(SoundexTest, GenerateSoundex) {
    auto param = GetParam();
    const std::string& name = param.first;
    const std::string& expectedSoundex = param.second;

    EXPECT_EQ(generateSoundex(name), expectedSoundex);
}

INSTANTIATE_TEST_SUITE_P(
    SoundexTests,
    SoundexTest,
    ::testing::Values(
        std::make_pair("Example", "E251"),
        std::make_pair("Soundex", "S532"),
        std::make_pair("HWY", "H000"),
        std::make_pair("", ""),
        std::make_pair("A", "A000"),
        std::make_pair("Abcd", "A123"),
        std::make_pair("pfister", "P236"),
        std::make_pair("Tymczak", "T522"),
        std::make_pair("Honeyman", "H555")
    )
);

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
