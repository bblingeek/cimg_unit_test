#include <cpptest.h>
#include <iostream>
#include <fstream>
#include <cstring>

#include "CImg.h"

typedef enum
{
    TERSE_TEXT_OUTPUT = 0,
    VERBOSE_TEXT_OUTPUT = 1,
    COMPILER_OUTPUT = 2,
    HTML_OUTPUT = 3
} OUTPUT_TYPE;

class CImgTestSuite : public Test::Suite
{
    public:
        CImgTestSuite()
        {
            TEST_ADD(CImgTestSuite::test1);
            TEST_ADD(CImgTestSuite::test2);
            TEST_ADD(CImgTestSuite::test3);
            TEST_ADD(CImgTestSuite::test4);
            TEST_ADD(CImgTestSuite::test5);
        }
        
    private:
        void test1();
        void test2();
        void test3();
        void test4();
        void test5();
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

void CImgTestSuite::test3()
{
    const unsigned int x = 256;
    const unsigned int y = 128;
    const unsigned int z = 64;
    const unsigned int c = 3;
    
    for(int initialVal = 0; initialVal <= 5; initialVal++)
    {
        cimg_library::CImg<unsigned int> img(x, y, z, c, initialVal);
        
        for(int i = 0; i < x; i++)
        {
            for(int j = 0; j < y; j++)
            {
                for(int k = 0; k < z; k++)
                {
                    for(int l = 0; l < c; l++)
                    {
                        unsigned int pixelVal = img(i, j, k, l);
                        TEST_ASSERT_MSG(pixelVal == initialVal, "Initial value of pixel incorrect");
                    }
                }
            }
        }
    }
}

void CImgTestSuite::test4()
{
    cimg_library::CImg<unsigned char> img1;
    TEST_ASSERT_MSG(0 == strcmp("unsigned char", img1.pixel_type()), "Pixel type mismatch");
    
    cimg_library::CImg<char> img2;
    TEST_ASSERT_MSG(0 == strcmp("char", img2.pixel_type()), "Pixel type mismatch");
    
    cimg_library::CImg<unsigned short> img3;
    TEST_ASSERT_MSG(0 == strcmp("unsigned short", img3.pixel_type()), "Pixel type mismatch");
    
    cimg_library::CImg<short> img4;
    TEST_ASSERT_MSG(0 == strcmp("short", img4.pixel_type()), "Pixel type mismatch");
    
    cimg_library::CImg<unsigned int> img5;
    TEST_ASSERT_MSG(0 == strcmp("unsigned int", img5.pixel_type()), "Pixel type mismatch");
    
    cimg_library::CImg<int> img6;
    TEST_ASSERT_MSG(0 == strcmp("int", img6.pixel_type()), "Pixel type mismatch");
    
    cimg_library::CImg<unsigned long> img7;
    TEST_ASSERT_MSG(0 == strcmp("unsigned int64", img7.pixel_type()), "Pixel type mismatch");
    
    cimg_library::CImg<long> img8;
    TEST_ASSERT_MSG(0 == strcmp("int64", img8.pixel_type()), "Pixel type mismatch");
    
    cimg_library::CImg<float> img9;
    TEST_ASSERT_MSG(0 == strcmp("float", img9.pixel_type()), "Pixel type mismatch");

    cimg_library::CImg<double> img10;
    TEST_ASSERT_MSG(0 == strcmp("double", img10.pixel_type()), "Pixel type mismatch");
}

void CImgTestSuite::test5()
{
    const unsigned int x = 256;
    const unsigned int y = 128;
    const unsigned int z = 64;
    const unsigned int c = 3;

    cimg_library::CImg<float> img1;
    TEST_ASSERT_MSG(false == img1.is_shared(), "Non-Shared image indicated as shared");
    TEST_ASSERT_MSG(true == img1.is_empty(), "Empty image indicated as non-empty");
    TEST_ASSERT_MSG(false == img1.is_inf(), "Empty image contains inf");
    TEST_ASSERT_MSG(false == img1.is_nan(), "Empty image contains nan");
    
    cimg_library::CImg<float> img2(x, y, z, c, 0);
    TEST_ASSERT_MSG(false == img2.is_shared(), "Non-Shared image indicated as shared");
    TEST_ASSERT_MSG(false == img2.is_empty(), "Non-Empty image indicated as empty");
    TEST_ASSERT_MSG(false == img2.is_inf(), "Non-Empty & Non-inf image contains inf");
    TEST_ASSERT_MSG(false == img2.is_nan(), "Non-Empty & Non-nan image contains nan");
}

bool run_tests(int outputType)
{
    Test::Suite ts;
    bool retVal = false;
    
    ts.add(std::auto_ptr<Test::Suite>(new CImgTestSuite));
    
    switch(outputType)
    {
        case TERSE_TEXT_OUTPUT:
            {
                Test::TextOutput output(Test::TextOutput::Terse);
                retVal = ts.run(output);
            }
            break;
            
        case VERBOSE_TEXT_OUTPUT:
            {
                Test::TextOutput output(Test::TextOutput::Verbose);
                retVal = ts.run(output);
            }
            break;
            
        case COMPILER_OUTPUT:
            {
                Test::CompilerOutput output;
                retVal = ts.run(output);
            }
            break;
            
        case HTML_OUTPUT:
            {
                Test::HtmlOutput output;
                std::fstream outfile;
                
                outfile.open("output.html", std::ios_base::out);
                retVal = ts.run(output);
                output.generate(outfile);
                outfile.close();
            }
            break;
    }
    return retVal;
}

void usage()
{
    std::cout<<std::endl;
    std::cout<<"--------- Usage ----------"<<std::endl;
    std::cout<<"> ./CImgTest <output type>"<<std::endl;
    std::cout<<std::endl;
    std::cout<<"  Output Types"<<std::endl;
    std::cout<<"  tt : Terse Text output"<<std::endl;
    std::cout<<"  vt : Verbose Text output"<<std::endl;
    std::cout<<"  ct : Compiler output"<<std::endl;
    std::cout<<"  ht : HTML output"<<std::endl;
    std::cout<<std::endl;
}

int main(int argc, char** argv)
{
    if(argc != 2)
    {
        usage();
    }
    else
    {
        if(0 == strcmp(argv[1], "tt"))
        {
            run_tests(TERSE_TEXT_OUTPUT);
        }
        else if(0 == strcmp(argv[1], "vt"))
        {
            run_tests(VERBOSE_TEXT_OUTPUT);
        }
        else if(0 == strcmp(argv[1], "ct"))
        {
            run_tests(COMPILER_OUTPUT);
        }
        else if(0 == strcmp(argv[1], "ht"))
        {
            run_tests(HTML_OUTPUT);
        }
        else
        {
            usage();
        }
    }
    return 0;
}
