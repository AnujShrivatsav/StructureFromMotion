#include<opencv2/opencv.hpp>
#include<iostream>
#include<opencv2/features2d.hpp>

using namespace std;
using namespace cv;

int MaxFeatures = 250;

int main()
{   std::vector<KeyPoint> k1, k2;
    Mat D1, D2;
    Mat img1 = imread("B23.jpg", IMREAD_GRAYSCALE);
    Mat img2 = imread("B25.jpg", IMREAD_GRAYSCALE);
    Mat kimg1, kimg2, ORB_matches;
    const Scalar color = Scalar::all(0);
    Ptr<Feature2D> f1 = ORB::create(MaxFeatures);
    Ptr<Feature2D> f2 = ORB::create(MaxFeatures);
    f1->detectAndCompute(img1, Mat(), k1, D1);
    f2->detectAndCompute(img2, Mat(), k2, D2);
    Ptr<BFMatcher> b1 = BFMatcher::create(NORM_HAMMING, true);
    std::vector<DMatch> matches;
    b1->match(D1, D2, matches, Mat());
    // for(int i = 0; i < matches.size(); i++)
    //     if(matches[i].distance < 50)
    //         matches[i];
    cv::drawMatches(img1, k1, img2, k2, matches, ORB_matches, color);
    imshow("Feature matches", ORB_matches);
    waitKey(0);
    // {   if(i==0)
    //     {cv::drawKeypoints(img1, k1, kimg1, color);
    //     imshow("Image with Features", kimg1);
    //     waitKey(2000);
    //     }
    //     cv::drawKeypoints(img2, k2, kimg2, color);
    //     imshow("Image with Features", kimg2);
    //     waitKey(2000);
    // }
    return(0);
}