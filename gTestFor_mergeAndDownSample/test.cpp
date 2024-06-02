#include "pch.h"
#include <gtest/gtest.h>

TEST(mergeAndDownsample, TEST_NormalCase1)
{
    std::string image00 = "../sand/image00.png";
    std::string image01 = "../sand/image01.png";
    std::string image10 = "../sand/image10.png";
    std::string image11 = "../sand/image11.png";
    std::string outputImage = "../sand/OutImage.png";

    EXPECT_TRUE(mergeAndDownsample2x2Images(image00, image01, image10, image11, outputImage));

    std::ifstream outputFile(outputImage);
    EXPECT_TRUE(outputFile.good()) << "Output file does not exist or cannot be opened.";

    outputFile.close();
}

TEST(mergeAndDownsample, TEST_NormalCase2)
{
    std::string image00 = "../test/1.png";
    std::string image01 = "../test/2.png";
    std::string image10 = "../test/3.png";
    std::string image11 = "../test/4.png";
    std::string outputImage = "../test/OutImage.png";

    EXPECT_TRUE(mergeAndDownsample2x2Images(image00, image01, image10, image11, outputImage));

    std::ifstream outputFile(outputImage);
    EXPECT_TRUE(outputFile.good()) << "Output file does not exist or cannot be opened.";

    outputFile.close();
}

TEST(mergeAndDownsample, TEST_NormalCase3)
{
    std::string image00 = "../test1/1.png";
    std::string image01 = "../test1/2.png";
    std::string image10 = "../test1/3.png";
    std::string image11 = "../test1/4.png";
    std::string outputImage = "../test1/OutImage.png";

    EXPECT_TRUE(mergeAndDownsample2x2Images(image00, image01, image10, image11, outputImage));

    std::ifstream outputFile(outputImage);
    EXPECT_TRUE(outputFile.good()) << "Output file does not exist or cannot be opened.";

    outputFile.close();
}

TEST(mergeAndDownsample, TEST_ImageLoadFail)
{
    std::string non_existing_image = "../sand/non_existing_image.png";
    std::string outputImage = "../sand/OutImage.png";

    EXPECT_FALSE(mergeAndDownsample2x2Images(non_existing_image, non_existing_image, non_existing_image, non_existing_image, outputImage));
}

TEST(mergeAndDownsample, TEST_ImageSizematch)
{
    std::string image00 = "../sand/image00.png";
    std::string image01 = "../sand/image01_resized.png";
    std::string image10 = "../sand/image10.png";
    std::string image11 = "../sand/image11.png";
    std::string outputImage = "../sand/OutImage.png";

    EXPECT_FALSE(mergeAndDownsample2x2Images(image00, image01, image10, image11, outputImage));
}

TEST(mergeAndDownsample, TEST_ImageSizeNotEven)
{
    std::string Oddimage00 = "../sand/1.png";
    std::string Oddimage01 = "../sand/2.png";
    std::string Oddimage10 = "../sand/3.png";
    std::string Oddimage11 = "../sand/4.png";
    std::string outputImage = "../sand/OutImage.png";

    EXPECT_FALSE(mergeAndDownsample2x2Images(Oddimage00, Oddimage01, Oddimage10, Oddimage11, outputImage));
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}