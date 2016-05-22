#include <cpptest.h>

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>

#include "CImg.h"

typedef enum
{
    TERSE_TEXT_OUTPUT = 0,
    VERBOSE_TEXT_OUTPUT = 1,
    COMPILER_OUTPUT = 2,
    HTML_OUTPUT = 3
} OutputType;

class CImgTestSuite : public Test::Suite
{
    public:
        CImgTestSuite()
        {
            TEST_ADD(CImgTestSuite::cimgUTestEmptyImage);
            TEST_ADD(CImgTestSuite::cimgUTestDataInput);
            TEST_ADD(CImgTestSuite::cimgUTestOperators);
            TEST_ADD(CImgTestSuite::test2);
            TEST_ADD(CImgTestSuite::test3);
            TEST_ADD(CImgTestSuite::test4);
            TEST_ADD(CImgTestSuite::test5);
            TEST_ADD(CImgTestSuite::test6);
            TEST_ADD(CImgTestSuite::test7);
            TEST_ADD(CImgTestSuite::test8);
        }
        
    private:
        void cimgUTestEmptyImage();
        void cimgUTestDataInput();
        void cimgUTestOperators();
        void test2();
        void test3();
        void test4();
        void test5();
        void test6();
        void test7();
        void test8();
};

void CImgTestSuite::cimgUTestEmptyImage()
{
    cimg_library::CImg<float> img1, img2;
    
    TEST_ASSERT_MSG(0 == img1.width(), "Non-zero width for an empty image");
    TEST_ASSERT_MSG(0 == img1.height(), "Non-zero height for an empty image");
    TEST_ASSERT_MSG(0 == img1.depth(), "Non-zero depth for an empty image");
    TEST_ASSERT_MSG(0 == img1.spectrum(), "Non-zero spectrum for an empty image");
    TEST_ASSERT_MSG(0 == img1.size(), "Non-zero size for an empty image");
    TEST_ASSERT_MSG(NULL == img1.data(), "Non-null data pointer for an empty image");
    TEST_ASSERT_MSG(false == img1.is_shared(), "Shared empty image");
    TEST_ASSERT_MSG(NULL == img1.begin(), "Non-null data pointer for an empty image");
    TEST_ASSERT_MSG(NULL == img1.end(), "Non-null data pointer for an empty image");
    TEST_ASSERT_MSG(0 == strcmp("float", img1.pixel_type()), "Pixel type incorrect for an empty image");
    TEST_ASSERT_MSG(true == img1.is_empty(), "Empty image termed as non-empty");
    TEST_ASSERT_MSG(false == img1.is_inf(), "Empty image contains Inf");
    TEST_ASSERT_MSG(false == img1.is_nan(), "Empty image containf Nan");
    TEST_ASSERT_MSG(true == img1.is_sameX(0), "Non-zero width for an empty image");
    TEST_ASSERT_MSG(true == img1.is_sameX(img2), "Non-zero width for an empty image");
    TEST_ASSERT_MSG(true == img1.is_sameY(0), "Non-zero height for an empty image");
    TEST_ASSERT_MSG(true == img1.is_sameY(img2), "Non-zero height for an empty image");
    TEST_ASSERT_MSG(true == img1.is_sameZ(0), "Non-zero depth for an empty image");
    TEST_ASSERT_MSG(true == img1.is_sameZ(img2), "Non-zero depth for an empty image");
    TEST_ASSERT_MSG(true == img1.is_sameC(0), "Non-zero spectrum for an empty image");
    TEST_ASSERT_MSG(true == img1.is_sameC(img2), "Non-zero spectrum for an empty image");
    TEST_ASSERT_MSG(true == img1.is_sameXY(0, 0), "Non-zero width and/or height for an empty image");
    TEST_ASSERT_MSG(true == img1.is_sameXY(img2), "Non-zero width and/or height for an empty image");
    TEST_ASSERT_MSG(true == img1.is_sameXZ(0, 0), "Non-zero width and/or depth for an empty image");
    TEST_ASSERT_MSG(true == img1.is_sameXZ(img2), "Non-zero width and/or depth for an empty image");
    TEST_ASSERT_MSG(true == img1.is_sameXC(0, 0), "Non-zero width and/or spectrum for an empty image");
    TEST_ASSERT_MSG(true == img1.is_sameXC(img2), "Non-zero width and/or spectrum for an empty image");
    TEST_ASSERT_MSG(true == img1.is_sameYZ(0, 0), "Non-zero height and/or depth for an empty image");
    TEST_ASSERT_MSG(true == img1.is_sameYZ(img2), "Non-zero height and/or depth for an empty image");
    TEST_ASSERT_MSG(true == img1.is_sameYC(0, 0), "Non-zero height and/or spectrum for an empty image");
    TEST_ASSERT_MSG(true == img1.is_sameYC(img2), "Non-zero height and/or spectrum for an empty image");
    TEST_ASSERT_MSG(true == img1.is_sameZC(0, 0), "Non-zero depth and/or spectrum for an empty image");
    TEST_ASSERT_MSG(true == img1.is_sameZC(img2), "Non-zero depth and/or spectrum for an empty image");
    TEST_ASSERT_MSG(true == img1.is_sameXYZ(0, 0, 0), "Non-zero width and/or height and/or depth for an empty image");
    TEST_ASSERT_MSG(true == img1.is_sameXYZ(img2), "Non-zero width and/or height and/or depth for an empty image");
    TEST_ASSERT_MSG(true == img1.is_sameXYC(0, 0, 0), "Non-zero width and/or height and/or spectrum for an empty image");
    TEST_ASSERT_MSG(true == img1.is_sameXYC(img2), "Non-zero width and/or height and/or spectrum for an empty image");
    TEST_ASSERT_MSG(true == img1.is_sameXZC(0, 0, 0), "Non-zero width and/or depth and/or spectrum for an empty image");
    TEST_ASSERT_MSG(true == img1.is_sameXZC(img2), "Non-zero width and/or depth and/or spectrum for an empty image");
    TEST_ASSERT_MSG(true == img1.is_sameYZC(0, 0, 0), "Non-zero height and/or depth and/or spectrum for an empty image");
    TEST_ASSERT_MSG(true == img1.is_sameYZC(img2), "Non-zero height and/or depth and/or spectrum for an empty image");
    TEST_ASSERT_MSG(true == img1.is_sameXYZC(0, 0, 0, 0), "Non-zero width and/or height and/or depth and/or spectrum for an empty image");
    TEST_ASSERT_MSG(true == img1.is_sameXYZC(img2), "Non-zero width and/or height and/or depth and/or spectrum for an empty image");
    TEST_ASSERT_MSG(false == img1.containsXYZC(0, 0, 0, 0), "Pixel exists for an empty image");
    TEST_THROWS_MSG(img1.median(), cimg_library::CImgInstanceException, "CImgInstanceException expected");
    TEST_ASSERT_MSG(0 == img1.product(), "Non-zero product for an empty image");
    TEST_ASSERT_MSG(0 == img1.sum(), "Non-zero sum for an empty image");
    TEST_ASSERT_MSG(true == isnan(img1.mean()), "Non-zero mean for an empty image");
    TEST_THROWS_MSG(img1.variance(0), cimg_library::CImgInstanceException, "CImgInstanceException expected");
    TEST_THROWS_MSG(img1.variance(1), cimg_library::CImgInstanceException, "CImgInstanceException expected");
    TEST_THROWS_MSG(img1.variance(2), cimg_library::CImgInstanceException, "CImgInstanceException expected");
    TEST_THROWS_MSG(img1.variance(3), cimg_library::CImgInstanceException, "CImgInstanceException expected");
    TEST_THROWS_MSG(img1.variance_noise(0), cimg_library::CImgInstanceException, "CImgInstanceException expected");
    TEST_THROWS_MSG(img1.variance_noise(1), cimg_library::CImgInstanceException, "CImgInstanceException expected");
    TEST_THROWS_MSG(img1.variance_noise(2), cimg_library::CImgInstanceException, "CImgInstanceException expected");
    TEST_THROWS_MSG(img1.variance_noise(3), cimg_library::CImgInstanceException, "CImgInstanceException expected");
    TEST_THROWS_MSG(img1.magnitude(-1), cimg_library::CImgInstanceException, "CImgInstanceException expected");
    TEST_THROWS_MSG(img1.magnitude(0), cimg_library::CImgInstanceException, "CImgInstanceException expected");
    TEST_THROWS_MSG(img1.magnitude(1), cimg_library::CImgInstanceException, "CImgInstanceException expected");
    TEST_THROWS_MSG(img1.magnitude(), cimg_library::CImgInstanceException, "CImgInstanceException expected");
    TEST_THROWS_MSG(img1.trace(), cimg_library::CImgInstanceException, "CImgInstanceException expected");
    TEST_THROWS_MSG(img1.det(), cimg_library::CImgInstanceException, "CImgInstanceException expected");
}

void CImgTestSuite::cimgUTestDataInput()
{
    cimg_library::CImg<float> img;
    
    TEST_THROWS_MSG(img.load(NULL), cimg_library::CImgArgumentException, "CImgArgumentException expected");
    TEST_THROWS_MSG(img.load("non-existent-file"), cimg_library::CImgIOException, "CImgIOException expected");
    TEST_THROWS_MSG(img.load_ascii("non-existent-file"), cimg_library::CImgIOException, "CImgIOException expected");
    TEST_THROWS_MSG(img.load_dlm("non-existent-file"), cimg_library::CImgIOException, "CImgIOException expected");
    TEST_THROWS_MSG(img.load_bmp("non-existent-file"), cimg_library::CImgIOException, "CImgIOException expected");
    TEST_THROWS_MSG(img.load_jpeg("non-existent-file"), cimg_library::CImgIOException, "CImgIOException expected");
    TEST_THROWS_MSG(img.load_magick("non-existent-file"), cimg_library::CImgIOException, "CImgIOException expected");
    TEST_THROWS_MSG(img.load_png("non-existent-file"), cimg_library::CImgIOException, "CImgIOException expected");
    TEST_THROWS_MSG(img.load_pnm("non-existent-file"), cimg_library::CImgIOException, "CImgIOException expected");
    TEST_THROWS_MSG(img.load_pfm("non-existent-file"), cimg_library::CImgIOException, "CImgIOException expected");
    TEST_THROWS_MSG(img.load_rgb("non-existent-file", 1, 1), cimg_library::CImgIOException, "CImgIOException expected");
    TEST_THROWS_MSG(img.load_rgba("non-existent-file", 1, 1), cimg_library::CImgIOException, "CImgIOException expected");
    TEST_THROWS_MSG(img.load_tiff(NULL), cimg_library::CImgArgumentException, "CImgArgumentException expected");
    TEST_THROWS_MSG(img.load_tiff("non-existent-file"), cimg_library::CImgIOException, "CImgIOException expected");
    TEST_THROWS_MSG(img.load_minc2(NULL), cimg_library::CImgArgumentException, "CImgArgumentException expected");
    TEST_THROWS_MSG(img.load_minc2("non-existent-file"), cimg_library::CImgIOException, "CImgIOException expected");
    TEST_THROWS_MSG(img.load_analyze("non-existent-file"), cimg_library::CImgIOException, "CImgIOException expected");
    TEST_THROWS_MSG(img.load_cimg("non-existent-file"), cimg_library::CImgIOException, "CImgIOException expected");
    TEST_THROWS_MSG(img.load_inr("non-existent-file"), cimg_library::CImgIOException, "CImgIOException expected");
    TEST_THROWS_MSG(img.load_pandore("non-existent-file"), cimg_library::CImgIOException, "CImgIOException expected");
    TEST_THROWS_MSG(img.load_parrec(NULL), cimg_library::CImgArgumentException, "CImgArgumentException expected");
    TEST_THROWS_MSG(img.load_parrec("non-existent-file"), cimg_library::CImgIOException, "CImgIOException expected");
    TEST_THROWS_MSG(img.load_raw("non-existent-file"), cimg_library::CImgIOException, "CImgIOException expected");
    TEST_THROWS_MSG(img.load_yuv("non-existent-file", 10), cimg_library::CImgArgumentException, "CImgArgumentException expected");
    TEST_THROWS_MSG(img.load_video(NULL), cimg_library::CImgArgumentException, "CImgArgumentException expected");
    TEST_THROWS_MSG(img.load_video("non-existent-file"), cimg_library::CImgIOException, "CImgIOException expected");
    TEST_THROWS_MSG(img.load_ffmpeg_external(NULL), cimg_library::CImgArgumentException, "CImgArgumentException expected");
    TEST_THROWS_MSG(img.load_ffmpeg_external("non-existent-file"), cimg_library::CImgIOException, "CImgIOException expected");
    TEST_THROWS_MSG(img.load_gif_external(NULL), cimg_library::CImgArgumentException, "CImgArgumentException expected");
    TEST_THROWS_MSG(img.load_gif_external("non-existent-file"), cimg_library::CImgIOException, "CImgIOException expected");
    TEST_THROWS_MSG(img.load_graphicsmagick_external(NULL), cimg_library::CImgArgumentException, "CImgArgumentException expected");
    TEST_THROWS_MSG(img.load_graphicsmagick_external("non-existent-file"), cimg_library::CImgIOException, "CImgIOException expected");
    TEST_THROWS_MSG(img.load_gzip_external(NULL), cimg_library::CImgIOException, "CImgIOException expected");
    TEST_THROWS_MSG(img.load_gzip_external("non-existent-file"), cimg_library::CImgIOException, "CImgIOException expected");
    TEST_THROWS_MSG(img.load_imagemagick_external(NULL), cimg_library::CImgArgumentException, "CImgArgumentException expected");
    TEST_THROWS_MSG(img.load_imagemagick_external("non-existent-file"), cimg_library::CImgIOException, "CImgIOException expected");
    TEST_THROWS_MSG(img.load_medcon_external(NULL), cimg_library::CImgArgumentException, "CImgArgumentException expected");
    TEST_THROWS_MSG(img.load_medcon_external("non-existent-file"), cimg_library::CImgIOException, "CImgIOException expected");
    TEST_THROWS_MSG(img.load_dcraw_external(NULL), cimg_library::CImgArgumentException, "CImgArgumentException expected");
    TEST_THROWS_MSG(img.load_dcraw_external("non-existent-file"), cimg_library::CImgIOException, "CImgIOException expected");
    TEST_THROWS_MSG(img.load_other(NULL), cimg_library::CImgArgumentException, "CImgArgumentException expected");
    TEST_THROWS_MSG(img.load_other("non-existent-file"), cimg_library::CImgIOException, "CImgIOException expected");

    TEST_THROWS_MSG(img.get_load(NULL), cimg_library::CImgArgumentException, "CImgArgumentException expected");
    TEST_THROWS_MSG(img.get_load("non-existent-file"), cimg_library::CImgIOException, "CImgIOException expected");
    TEST_THROWS_MSG(img.get_load_ascii("non-existent-file"), cimg_library::CImgIOException, "CImgIOException expected");
    TEST_THROWS_MSG(img.get_load_dlm("non-existent-file"), cimg_library::CImgIOException, "CImgIOException expected");
    TEST_THROWS_MSG(img.get_load_bmp("non-existent-file"), cimg_library::CImgIOException, "CImgIOException expected");
    TEST_THROWS_MSG(img.get_load_jpeg("non-existent-file"), cimg_library::CImgIOException, "CImgIOException expected");
    TEST_THROWS_MSG(img.get_load_magick("non-existent-file"), cimg_library::CImgIOException, "CImgIOException expected");
    TEST_THROWS_MSG(img.get_load_png("non-existent-file"), cimg_library::CImgIOException, "CImgIOException expected");
    TEST_THROWS_MSG(img.get_load_pnm("non-existent-file"), cimg_library::CImgIOException, "CImgIOException expected");
    TEST_THROWS_MSG(img.get_load_pfm("non-existent-file"), cimg_library::CImgIOException, "CImgIOException expected");
    TEST_THROWS_MSG(img.get_load_rgb("non-existent-file", 1, 1), cimg_library::CImgIOException, "CImgIOException expected");
    TEST_THROWS_MSG(img.get_load_rgba("non-existent-file", 1, 1), cimg_library::CImgIOException, "CImgIOException expected");
    TEST_THROWS_MSG(img.get_load_tiff(NULL), cimg_library::CImgArgumentException, "CImgArgumentException expected");
    TEST_THROWS_MSG(img.get_load_tiff("non-existent-file"), cimg_library::CImgIOException, "CImgIOException expected");
    TEST_THROWS_MSG(img.get_load_minc2(NULL), cimg_library::CImgArgumentException, "CImgArgumentException expected");
    TEST_THROWS_MSG(img.get_load_minc2("non-existent-file"), cimg_library::CImgIOException, "CImgIOException expected");
    TEST_THROWS_MSG(img.get_load_analyze("non-existent-file"), cimg_library::CImgIOException, "CImgIOException expected");
    TEST_THROWS_MSG(img.get_load_cimg("non-existent-file"), cimg_library::CImgIOException, "CImgIOException expected");
    TEST_THROWS_MSG(img.get_load_inr("non-existent-file"), cimg_library::CImgIOException, "CImgIOException expected");
    TEST_THROWS_MSG(img.get_load_pandore("non-existent-file"), cimg_library::CImgIOException, "CImgIOException expected");
    TEST_THROWS_MSG(img.get_load_parrec(NULL), cimg_library::CImgArgumentException, "CImgArgumentException expected");
    TEST_THROWS_MSG(img.get_load_parrec("non-existent-file"), cimg_library::CImgIOException, "CImgIOException expected");
    TEST_THROWS_MSG(img.get_load_raw("non-existent-file"), cimg_library::CImgIOException, "CImgIOException expected");
    TEST_THROWS_MSG(img.get_load_yuv("non-existent-file", 10), cimg_library::CImgArgumentException, "CImgArgumentException expected");
    TEST_THROWS_MSG(img.get_load_video(NULL), cimg_library::CImgArgumentException, "CImgArgumentException expected");
    TEST_THROWS_MSG(img.get_load_video("non-existent-file"), cimg_library::CImgIOException, "CImgIOException expected");
    TEST_THROWS_MSG(img.get_load_ffmpeg_external(NULL), cimg_library::CImgArgumentException, "CImgArgumentException expected");
    TEST_THROWS_MSG(img.get_load_ffmpeg_external("non-existent-file"), cimg_library::CImgIOException, "CImgIOException expected");
    TEST_THROWS_MSG(img.get_load_gif_external(NULL), cimg_library::CImgArgumentException, "CImgArgumentException expected");
    TEST_THROWS_MSG(img.get_load_gif_external("non-existent-file"), cimg_library::CImgIOException, "CImgIOException expected");
    TEST_THROWS_MSG(img.get_load_graphicsmagick_external(NULL), cimg_library::CImgArgumentException, "CImgArgumentException expected");
    TEST_THROWS_MSG(img.get_load_graphicsmagick_external("non-existent-file"), cimg_library::CImgIOException, "CImgIOException expected");
    TEST_THROWS_MSG(img.get_load_gzip_external(NULL), cimg_library::CImgIOException, "CImgIOException expected");
    TEST_THROWS_MSG(img.get_load_gzip_external("non-existent-file"), cimg_library::CImgIOException, "CImgIOException expected");
    TEST_THROWS_MSG(img.get_load_imagemagick_external(NULL), cimg_library::CImgArgumentException, "CImgArgumentException expected");
    TEST_THROWS_MSG(img.get_load_imagemagick_external("non-existent-file"), cimg_library::CImgIOException, "CImgIOException expected");
    TEST_THROWS_MSG(img.get_load_medcon_external(NULL), cimg_library::CImgArgumentException, "CImgArgumentException expected");
    TEST_THROWS_MSG(img.get_load_medcon_external("non-existent-file"), cimg_library::CImgIOException, "CImgIOException expected");
    TEST_THROWS_MSG(img.get_load_dcraw_external(NULL), cimg_library::CImgArgumentException, "CImgArgumentException expected");
    TEST_THROWS_MSG(img.get_load_dcraw_external("non-existent-file"), cimg_library::CImgIOException, "CImgIOException expected");
    TEST_THROWS_MSG(img.get_load_other(NULL), cimg_library::CImgArgumentException, "CImgArgumentException expected");
    TEST_THROWS_MSG(img.get_load_other("non-existent-file"), cimg_library::CImgIOException, "CImgIOException expected");    
}

void CImgTestSuite::cimgUTestOperators()
{
    const unsigned int _width = 2;
    const unsigned int _height = 2;
    const unsigned int _depth = 1;
    const unsigned int _spectrum = 3;
    
    cimg_library::CImg<float> img1(_width, _height, _depth, _spectrum, 
                                   0, 64, 128, 255,
                                   255, 128, 64, 0,
                                   0, 64, 128, 255);
    
    cimg_library::CImg<float> img2(_width, _height, _depth, _spectrum, 
                                   255, 128, 64, 0,
                                   0, 64, 128, 255,
                                   255, 128, 64, 0);
    
    TEST_ASSERT_MSG(_width == img1.width(), "Image width mismatch");
    TEST_ASSERT_MSG(_height == img1.height(), "Image height mismatch");
    TEST_ASSERT_MSG(_depth == img1.depth(), "Image depth mismatch");
    TEST_ASSERT_MSG(_spectrum == img1.spectrum(), "Image spectrum mismatch");
    TEST_ASSERT_MSG((_width * _height * _depth * _spectrum) == img1.size(), "Image size mismatch");
    TEST_ASSERT_MSG(0 == strcmp("float", img1.pixel_type()), "Pixel type incorrect for the image");

    TEST_ASSERT_MSG(0 == img1(0, 0, 0, 0), "R-component of Pixel value mismatch");
    TEST_ASSERT_MSG(255 == img1(0, 0, 0, 1), "G-component of Pixel value mismatch");
    TEST_ASSERT_MSG(0 == img1(0, 0, 0, 2), "B-component of Pixel value mismatch");
    TEST_ASSERT_MSG(128 == img1(0, 1, 0, 0), "R-component of Pixel value mismatch");
    TEST_ASSERT_MSG(64 == img1(0, 1, 0, 1), "G-component of Pixel value mismatch");
    TEST_ASSERT_MSG(128 == img1(0, 1, 0, 2), "B-component of Pixel value mismatch");
    TEST_ASSERT_MSG(64 == img1(1, 0, 0, 0), "R-component of Pixel value mismatch");
    TEST_ASSERT_MSG(128 == img1(1, 0, 0, 1), "G-component of Pixel value mismatch");
    TEST_ASSERT_MSG(64 == img1(1, 0, 0, 2), "B-component of Pixel value mismatch");
    TEST_ASSERT_MSG(255 == img1(1, 1, 0, 0), "R-component of Pixel value mismatch");
    TEST_ASSERT_MSG(0 == img1(1, 1, 0, 1), "G-component of Pixel value mismatch");
    TEST_ASSERT_MSG(255 == img1(1, 1, 0, 2), "B-component of Pixel value mismatch");
    
    img1 = 200;
    cimg_forXYZC(img1, x, y, z, c)
    {
        unsigned int pixelVal = img1(x, y, z, c);
        TEST_ASSERT_MSG(pixelVal == 200, "Pixel value incorrect");
    }
    
    img1 = img2;
    TEST_ASSERT_MSG(255 == img1(0, 0, 0, 0), "R-component of Pixel value mismatch");
    TEST_ASSERT_MSG(0 == img1(0, 0, 0, 1), "G-component of Pixel value mismatch");
    TEST_ASSERT_MSG(255 == img1(0, 0, 0, 2), "B-component of Pixel value mismatch");
    TEST_ASSERT_MSG(64 == img1(0, 1, 0, 0), "R-component of Pixel value mismatch");
    TEST_ASSERT_MSG(128 == img1(0, 1, 0, 1), "G-component of Pixel value mismatch");
    TEST_ASSERT_MSG(64 == img1(0, 1, 0, 2), "B-component of Pixel value mismatch");
    TEST_ASSERT_MSG(128 == img1(1, 0, 0, 0), "R-component of Pixel value mismatch");
    TEST_ASSERT_MSG(64 == img1(1, 0, 0, 1), "G-component of Pixel value mismatch");
    TEST_ASSERT_MSG(128 == img1(1, 0, 0, 2), "B-component of Pixel value mismatch");
    TEST_ASSERT_MSG(0 == img1(1, 1, 0, 0), "R-component of Pixel value mismatch");
    TEST_ASSERT_MSG(255 == img1(1, 1, 0, 1), "G-component of Pixel value mismatch");
    TEST_ASSERT_MSG(0 == img1(1, 1, 0, 2), "B-component of Pixel value mismatch");
    
    img1 = "1, 2, 3, 4";
    TEST_ASSERT_MSG(1 == img1(0, 0, 0, 0), "R-component of Pixel value mismatch");
    TEST_ASSERT_MSG(1 == img1(0, 0, 0, 1), "G-component of Pixel value mismatch");
    TEST_ASSERT_MSG(1 == img1(0, 0, 0, 2), "B-component of Pixel value mismatch");
    TEST_ASSERT_MSG(3 == img1(0, 1, 0, 0), "R-component of Pixel value mismatch");
    TEST_ASSERT_MSG(3 == img1(0, 1, 0, 1), "G-component of Pixel value mismatch");
    TEST_ASSERT_MSG(3 == img1(0, 1, 0, 2), "B-component of Pixel value mismatch");
    TEST_ASSERT_MSG(2 == img1(1, 0, 0, 0), "R-component of Pixel value mismatch");
    TEST_ASSERT_MSG(2 == img1(1, 0, 0, 1), "G-component of Pixel value mismatch");
    TEST_ASSERT_MSG(2 == img1(1, 0, 0, 2), "B-component of Pixel value mismatch");
    TEST_ASSERT_MSG(4 == img1(1, 1, 0, 0), "R-component of Pixel value mismatch");
    TEST_ASSERT_MSG(4 == img1(1, 1, 0, 1), "G-component of Pixel value mismatch");
    TEST_ASSERT_MSG(4 == img1(1, 1, 0, 2), "B-component of Pixel value mismatch");
    
    img1 = "x + y";
    cimg_forXYZC(img1, x, y, z, c)
    {
        unsigned int pixelVal = img1(x, y, z, c);
        TEST_ASSERT_MSG(pixelVal == (x + y), "Pixel value incorrect");
    }
    
    img1 = img2;
    img1 += 20;
    cimg_forXYZC(img1, x, y, z, c)
    {
        unsigned int initialPixelVal = img2(x, y, z, c);
        TEST_ASSERT_MSG((initialPixelVal + 20) == img1(x, y, z, c), "Pixel value incorrect");
    }
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
        
        cimg_forXYZC(img, i, j, k, l)
        {
            unsigned int pixelVal = img(i, j, k, l);
            TEST_ASSERT_MSG(pixelVal == initialVal, "Initial value of pixel incorrect");
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

void CImgTestSuite::test6()
{
    cimg_library::CImg<int> img1("images/ht.png");
    cimg_library::CImg<int> img2 = img1.get_sqr();
    
    cimg_forXYZC(img1, i, j, k, l)
    {
        TEST_ASSERT_MSG((img1(i, j, k, l) * img1(i, j, k, l)) == img2(i, j, k, l), "CImg::get_sqr method error");
    }
    
    cimg_library::CImg<int> img3(img1);
    img3.sqr();
    
    cimg_forXYZC(img1, i, j, k, l)
    {
        TEST_ASSERT_MSG((img1(i, j, k, l) * img1(i, j, k, l)) == img3(i, j, k, l), "CImg::get_sqr method error");
    }
}

void CImgTestSuite::test7()
{
    cimg_library::CImg<float> img1("images/ht.png");
    cimg_library::CImg<float> img2 = img1.get_sqrt();
    
    cimg_forXYZC(img1, i, j, k, l)
    {
        TEST_ASSERT_DELTA_MSG(sqrt(img1(i, j, k, l)), img2(i, j, k, l), 0.01, "CImg::get_sqrt method error");
    }
    
    cimg_library::CImg<float> img3(img1);
    img3.sqrt();
    
    cimg_forXYZC(img1, i, j, k, l)
    {
        TEST_ASSERT_DELTA_MSG(sqrt(img1(i, j, k, l)), img3(i, j, k, l), 0.01, "CImg::get_sqrt method error");
    }
}

void CImgTestSuite::test8()
{
    cimg_library::CImg<long double> img1("images/ht.png");
    cimg_library::CImg<long double> img2 = img1.get_exp();
    
    cimg_forXYZC(img1, i, j, k, l)
    {
        TEST_ASSERT_DELTA_MSG(exp(img1(i, j, k, l)), img2(i, j, k, l), 0.01, "CImg::get_exp method error");
    }
    
    cimg_library::CImg<long double> img3(img1);
    img3.exp();
    
    cimg_forXYZC(img1, i, j, k, l)
    {
        TEST_ASSERT_DELTA_MSG(exp(img1(i, j, k, l)), img3(i, j, k, l), 0.01, "CImg::get_exp method error");
    }
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
