#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main()
{
    VideoCapture cap("Recording.mp4");
    if (!cap.isOpened())
    {
        cout << "Cannot open video file.\n";
        return -1;
    }

    double fps = cap.get(CAP_PROP_FPS);
    cout << "Frames per second (FPS): " << fps << endl;

    namedWindow("MyVideo", WINDOW_AUTOSIZE);
    while (1)
    {
        Mat frame;
        if (!cap.read(frame))
        {
            cout << "\n Cannot read the video file. \n";
            break;
        }
        blur(frame, frame, Size(10, 10));
        imshow("MyVideo", frame);

        if (waitKey(30) == 27)
        {
            break;
        }
    }
    return 0;
}
