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
    TEST_ASSERT_MSG(0 == img.size(), "Non-zero size for an empty image");
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
