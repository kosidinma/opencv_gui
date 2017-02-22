#include "MyForm.h"  //has all the cv libraries added
#include <iostream>
#include <stdio.h>

using namespace System;
using namespace System::Windows::Forms;
using namespace cv;


/// Global variables
/*
The classification will be done using the LBP trained classifier for the face 
and Haar for the eyes (LBP has no eye training set).

Trade-off (Speed vs Accuracy)
LBP is faster (a few times faster) but less accurate. (10-20% less than Haar).
E.g. If you want to detect faces on an embedded system, LBP is the choice, because it does all the calculations in integers. 
Haar uses floats, whick is a killer for embedded/mobile.

An LBP cascade can still be trained to perform similarly (or better) than the Haar cascade, but out of the box, 
the Haar cascade is about 3x slower better at accurately detecting the location of a face. 
This increase in accuracy is quite significant given that face detection can operate in the 95%+ accuracy range.

Chose LBP because processing speed is important for timing GUI applications such as this
*/

//std::string face_cascade_name = "../data/facial_recog_classifiers/lbpcascade_frontalface.xml"; //face classifier file
std::string face_cascade_name = "../data/facial_recog_classifiers/haarcascade_frontalface_alt.xml"; //face classifier file
std::string eyes_cascade_name = "../data/facial_recog_classifiers/haarcascade_eye_tree_eyeglasses.xml"; //eye classifier file
//initialize the classifiers
CascadeClassifier face_cascade; 
CascadeClassifier eyes_cascade;
bool face_detected = false;
int brightness_val;
int contrast_val;



[STAThread]
void Main(array<opencv_gui::String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	opencv_gui::MyForm form;
	Application::Run(%form);
}



void DrawCvImage(System::Windows::Forms::Control^ control, cv::Mat& colorImage)
{
	System::Drawing::Graphics^ graphics = control->CreateGraphics();
	System::IntPtr ptr(colorImage.ptr());
	System::Drawing::Bitmap^ b = gcnew System::Drawing::Bitmap(colorImage.cols, colorImage.rows, colorImage.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr);
	System::Drawing::RectangleF rect(0, 0, control->Width, control->Height);
	graphics->DrawImage(b, rect);
	delete graphics;
}



/** @function to detect and display faces*/
void detectAndDisplay(Mat frame, System::Windows::Forms::PictureBox^ pic)
{
	std::vector<Rect> faces; //initialize vector of found faces
	Mat frame_gray;

	//convert to grayscale opencv
	cvtColor(frame, frame_gray, COLOR_BGR2GRAY);
	equalizeHist(frame_gray, frame_gray);

	//-- Detect faces
	face_cascade.detectMultiScale(frame_gray, faces, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(30, 30));
	if (faces.size() > 0)
	{
		face_detected = true;
	}
	else
	{
		face_detected = false;
	}
	/*
	Rectangles in opencv
	void rectangle(Mat& img, Point pt1, Point pt2, const Scalar& color, int thickness=1, int lineType=8, int shift=0)
	Parameters:
	img – Image.
	pt1 – Vertex of the rectangle.
	pt2 – Vertex of the rectangle opposite to pt1 .
	rec – Alternative specification of the drawn rectangle.
	color – Rectangle color or brightness (grayscale image).
	thickness – Thickness of lines that make up the rectangle. Negative values, like CV_FILLED , mean that the function has to draw a filled rectangle.
	lineType – Type of the line. See the line() description.
	shift – Number of fractional bits in the point coordinates.
	
	NB: .tl() = TopLeft;
		.br() = BottomRight;
	*/


	/*
	OpenCV Drawing a Circle
	void circle(Mat& img, Point center, int radius, const Scalar& color, int thickness=1, int lineType=8, int shift=0)
	Parameters:
	img – Image where the circle is drawn.
	center – Center of the circle.
	radius – Radius of the circle.
	color – Circle color.
	thickness – Thickness of the circle outline, if positive. Negative thickness means that a filled circle is to be drawn.
	lineType – Type of the circle boundary. See the line() description.
	shift – Number of fractional bits in the coordinates of the center and in the radius value.
	*/


	for (size_t i = 0; i < faces.size(); i++) //draw rectangle around all faces
	{
		//-- Draw rectangle round the face
		rectangle(frame, faces[i].br(), faces[i].tl(), Scalar(255, 255, 255), 3, 8, 0);

		Mat faceROI = frame_gray(faces[i]);
		std::vector<Rect> eyes;

		//haarcascade_frontalface_alt

		//-- In each face, detect eyes 
		eyes_cascade.detectMultiScale(faceROI, eyes, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(30, 30));

		if (eyes.size() == 2) //two eyes found in face
		{
			for (size_t j = 0; j < eyes.size(); j++)
			{ //-- Draw circle round the eyes
				Point eye_center(faces[i].x + eyes[j].x + eyes[j].width / 2, faces[i].y + eyes[j].y + eyes[j].height / 2);
				int radius = cvRound((eyes[j].width + eyes[j].height)*0.25);
				circle(frame, eye_center, radius, Scalar(255, 0, 255), 3, 8, 0);
			}
		}
	}
	//-- Show what you got
	//DrawCvImage(pic, frame);
	imshow("Press Escape To Stop", frame);
}



//camera feed
int video_cap(System::Windows::Forms::PictureBox^ pic, System::Windows::Forms::Control^ control)
{	
	VideoCapture cap;
	if (!cap.open(0)) // open the default camera (camera 0), use something different from 0 otherwise;
		return 0;
	cap.set(CV_CAP_PROP_FRAME_WIDTH, 320);
	cap.set(CV_CAP_PROP_FRAME_HEIGHT, 240);
	while (1) {
		double alpha = 2.0; /**< Simple contrast control (alpha value [1.0-3.0])*/ 
		int beta = 2;  /**< Simple brightness control (beta value [0-100])*/
		Mat frame;
		cap >> frame;
		if (frame.empty()) {}; // end of video stream
		Mat new_image = Mat::zeros(frame.size(), frame.type());

		/// Do the operation new_image(i,j) = alpha*image(i,j) + beta to increase image brightness
		for (int y = 0; y < frame.rows; y++)
		{
			for (int x = 0; x < frame.cols; x++)
			{
				for (int c = 0; c < 3; c++)
				{
					new_image.at<Vec3b>(y, x)[c] =
						saturate_cast<uchar>(alpha*(frame.at<Vec3b>(y, x)[c]) + beta);
				}
			}
		}

		detectAndDisplay(new_image, pic);
		int c = waitKey(10);
		if ((char)c == 27) { 
			control->Text = "Start Detecting";
			control->Enabled = true;
			// close the window
			face_detected = false;
			destroyAllWindows();
			break; 
		} // escape
	}
	// the camera will be closed automatically upon exit
	// cap.close();
	return 0;
}





int opencv_gui::button_test(System::Windows::Forms::PictureBox^ pic, System::Windows::Forms::Control^ control, System::Windows::Forms::TrackBar^ brightness, System::Windows::Forms::TrackBar^ contrast)
{
	brightness_val = brightness->Value;
	contrast_val = contrast->Value;
	//-- 1. Load the cascades for the facial identification
	if (!face_cascade.load(face_cascade_name)) { printf("--(!)Error loading face cascade\n"); return -1; };
	if (!eyes_cascade.load(eyes_cascade_name)) { printf("--(!)Error loading eyes cascade\n"); return -1; };

	video_cap(pic, control);
	return 0;
}


bool opencv_gui::face_det(void)
{
	return face_detected;
}





