#include <cpptest.h>
#include <iostream>

#include "CImg.h"

class CImgTestSuite : public Test::Suite
{
    public:
        CImgTestSuite()
        {
            TEST_ADD(CImgTestSuite::test1);
            TEST_ADD(CImgTestSuite::test2);
        }
        
    private:
        void test1();
        void test2();
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

void CImgTestSuite::test2()
{
    const unsigned int x = 256;
    const unsigned int y = 128;
    const unsigned int z = 64;
    const unsigned int c = 3;
    
    cimg_library::CImg<unsigned int> img1(x, y, z, c);
    TEST_ASSERT_MSG(x == img1.width(), "Image width mismatch");
    TEST_ASSERT_MSG(y == img1.height(), "Image height mismatch");
    TEST_ASSERT_MSG(z == img1.depth(), "Image depth mismatch");
    TEST_ASSERT_MSG(c == img1.spectrum(), "Image spectrum mismatch");
    TEST_ASSERT_MSG(((x * y * z * c) == img1.size()), "Image size mismatch");

    cimg_library::CImg<unsigned int> img2(img1, "xyzc");
    TEST_ASSERT_MSG(x == img2.width(), "Image width mismatch");
    TEST_ASSERT_MSG(y == img2.height(), "Image height mismatch");
    TEST_ASSERT_MSG(z == img2.depth(), "Image depth mismatch");
    TEST_ASSERT_MSG(c == img2.spectrum(), "Image spectrum mismatch");
    TEST_ASSERT_MSG(((x * y * z * c) == img2.size()), "Image size mismatch");

    cimg_library::CImg<unsigned int> img3(img1, "yzxc");
    TEST_ASSERT_MSG(y == img3.width(), "Image width mismatch");
    TEST_ASSERT_MSG(z == img3.height(), "Image height mismatch");
    TEST_ASSERT_MSG(x == img3.depth(), "Image depth mismatch");
    TEST_ASSERT_MSG(c == img3.spectrum(), "Image spectrum mismatch");
    TEST_ASSERT_MSG(((x * y * z * c) == img3.size()), "Image size mismatch");

    cimg_library::CImg<unsigned int> img4(img1, "zxyc");
    TEST_ASSERT_MSG(z == img4.width(), "Image width mismatch");
    TEST_ASSERT_MSG(x == img4.height(), "Image height mismatch");
    TEST_ASSERT_MSG(y == img4.depth(), "Image depth mismatch");
    TEST_ASSERT_MSG(c == img4.spectrum(), "Image spectrum mismatch");
    TEST_ASSERT_MSG(((x * y * z * c) == img4.size()), "Image size mismatch");

    cimg_library::CImg<unsigned int> img5(img1, "xzyc");
    TEST_ASSERT_MSG(x == img5.width(), "Image width mismatch");
    TEST_ASSERT_MSG(z == img5.height(), "Image height mismatch");
    TEST_ASSERT_MSG(y == img5.depth(), "Image depth mismatch");
    TEST_ASSERT_MSG(c == img5.spectrum(), "Image spectrum mismatch");
    TEST_ASSERT_MSG(((x * y * z * c) == img5.size()), "Image size mismatch");

    cimg_library::CImg<unsigned int> img6(img1, "yxzc");
    TEST_ASSERT_MSG(y == img6.width(), "Image width mismatch");
    TEST_ASSERT_MSG(x == img6.height(), "Image height mismatch");
    TEST_ASSERT_MSG(z == img6.depth(), "Image depth mismatch");
    TEST_ASSERT_MSG(c == img6.spectrum(), "Image spectrum mismatch");
    TEST_ASSERT_MSG(((x * y * z * c) == img6.size()), "Image size mismatch");

    cimg_library::CImg<unsigned int> img7(img1, "zyxc");
    TEST_ASSERT_MSG(z == img7.width(), "Image width mismatch");
    TEST_ASSERT_MSG(y == img7.height(), "Image height mismatch");
    TEST_ASSERT_MSG(x == img7.depth(), "Image depth mismatch");
    TEST_ASSERT_MSG(c == img7.spectrum(), "Image spectrum mismatch");
    TEST_ASSERT_MSG(((x * y * z * c) == img7.size()), "Image size mismatch");
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
