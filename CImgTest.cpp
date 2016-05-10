#include <cpptest.h>
#include <iostream>

#include "CImg.h"

class CImgTestSuite : public Test::Suite
{
    public:
        CImgTestSuite()
        {
            TEST_ADD(CImgTestSuite::test1);
        }
        
    private:
        void test1();
};

void CImgTestSuite::test1()
{
    cimg_library::CImg<float> img;
    TEST_ASSERT_MSG(0 == img.width(), "Non-zero width for an empty image");
    TEST_ASSERT_MSG(0 == img.height(), "Non-zero height for an empty image");
    TEST_ASSERT_MSG(0 == img.depth(), "Non-zero depth for an empty image");
    TEST_ASSERT_MSG(0 == img.spectrum(), "Non-zero spectrum for an empty image");
    TEST_ASSERT_MSG(0 == img.size(), "Non-zero size for an empty image");
    
    cimg_library::CImg<unsigned int> img1(256, 0, 256, 3);
    TEST_ASSERT_MSG(0 == img1.width(), "Non-zero width for an empty image");
    TEST_ASSERT_MSG(0 == img1.height(), "Non-zero height for an empty image");
    TEST_ASSERT_MSG(0 == img1.depth(), "Non-zero depth for an empty image");
    TEST_ASSERT_MSG(0 == img1.spectrum(), "Non-zero spectrum for an empty image");
    TEST_ASSERT_MSG(0 == img1.size(), "Non-zero size for an empty image");

    cimg_library::CImg<unsigned int> img2(256, 256, 0, 3);
    TEST_ASSERT_MSG(0 == img2.width(), "Non-zero width for an empty image");
    TEST_ASSERT_MSG(0 == img2.height(), "Non-zero height for an empty image");
    TEST_ASSERT_MSG(0 == img2.depth(), "Non-zero depth for an empty image");
    TEST_ASSERT_MSG(0 == img2.spectrum(), "Non-zero spectrum for an empty image");
    TEST_ASSERT_MSG(0 == img2.size(), "Non-zero size for an empty image");

    cimg_library::CImg<unsigned int> img3(256, 256, 256, 0);
    TEST_ASSERT_MSG(0 == img3.width(), "Non-zero width for an empty image");
    TEST_ASSERT_MSG(0 == img3.height(), "Non-zero height for an empty image");
    TEST_ASSERT_MSG(0 == img3.depth(), "Non-zero depth for an empty image");
    TEST_ASSERT_MSG(0 == img3.spectrum(), "Non-zero spectrum for an empty image");
    TEST_ASSERT_MSG(0 == img3.size(), "Non-zero size for an empty image");
}

bool run_CImgTestSuite()
{
    CImgTestSuite ts;
    Test::TextOutput output(Test::TextOutput::Verbose);
    
    return ts.run(output, false);
}

int main(int argc, char** argv)
{
    run_CImgTestSuite();
    
    return 0;
}
