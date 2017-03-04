#include "MyForm.h"  //has all the cv libraries added
#include <iostream>
#include <fstream>
#include "dirent.h"
#include <string>
#include <stdio.h>
#include <msclr/marshal_cppstd.h>  //library to convert from System::String^ to std::string



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
std::string cashew_cascade_name = "../data/cashew_classifier/cashew_cascade2.xml"; //eye classifier file
std::string kosy_cascade_name = "../data/facial_recog_classifiers/kosy_face_cascade.xml"; //kosy classifier file
std::string disease_cascade_name = "../data/cashew_classifier/disease_cascade.xml"; //disease classifier file


//initialize the classifiers
CascadeClassifier face_cascade; 
CascadeClassifier eyes_cascade;
CascadeClassifier cashew_cascade;
CascadeClassifier kosy_cascade;
CascadeClassifier disease_cascade;
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
Mat detectAndDisplay(Mat frame, System::Windows::Forms::PictureBox^ pic)
{
	std::vector<Rect> faces; //initialize vector of found faces
	std::vector<Rect> cashew_leaf; //initialize vector of found cashew leaves
	std::vector<Rect> Kosy; //initialize vector of found cashew leaves
	std::vector<Rect> disease; //initialize vector of found cashew leaves
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
		rectangle(frame, faces[i].br(), faces[i].tl(), Scalar(0, 255, 0), 1, 8, 0);

		//-- Detect Kosy and diseases
		kosy_cascade.detectMultiScale(frame_gray, Kosy, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(30, 30));
		disease_cascade.detectMultiScale(frame_gray, disease, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(30, 30));
		if (Kosy.size() > 0)
		{  //write text to screen
			cv::putText(frame,
				"Hey Kosy", //text
				cv::Point(5, 10), // Coordinates
				cv::FONT_HERSHEY_COMPLEX_SMALL, // Font
				0.5, // Scale. 2.0 = 2x bigger
				cv::Scalar(255, 255, 255), // Color
				1, // Thickness
				CV_AA); // Anti-alias
		}
		else
		{
			cv::putText(frame,
				"You're not Kosy", //text
				cv::Point(5, 10), // Coordinates
				cv::FONT_HERSHEY_COMPLEX_SMALL, // Font
				0.5, // Scale. 2.0 = 2x bigger
				cv::Scalar(255, 255, 255), // Color
				1, // Thickness
				CV_AA); // Anti-alias
		}

		if (disease.size() > 0)
		{  //write text to screen
			cv::putText(frame,
				"Ewwww disease", //text
				cv::Point(5, 20), // Coordinates
				cv::FONT_HERSHEY_COMPLEX_SMALL, // Font
				0.5, // Scale. 2.0 = 2x bigger
				cv::Scalar(255, 255, 255), // Color
				1, // Thickness
				CV_AA); // Anti-alias
		}

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
				circle(frame, eye_center, radius, Scalar(255, 0, 255), 1, 8, 0);
			}
		}
	}

	//-- Detect cashew leaves
	cashew_cascade.detectMultiScale(frame_gray, cashew_leaf, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(30, 30));
	for (size_t k = 0; k < cashew_leaf.size(); k++)
	{ //-- Draw rect round the leaf using my own size of boxes
		Point br(cashew_leaf[k].br().x - ((cashew_leaf[k].br().x - cashew_leaf[k].tl().x) / 4), cashew_leaf[k].br().y + ((cashew_leaf[k].tl().y - cashew_leaf[k].br().y) / 4));
		Point tl(cashew_leaf[k].tl().x + ((cashew_leaf[k].br().x - cashew_leaf[k].tl().x) / 4), cashew_leaf[k].tl().y - ((cashew_leaf[k].tl().y - cashew_leaf[k].br().y) / 4));
		rectangle(frame, br, tl, Scalar(194, 82, 0), 3, 8, 0);
	}

	//-- Show what you got
	//DrawCvImage(pic, frame);
	imshow("Press Escape To Stop, Spacebar to capture", frame);
	return frame;
}


std::string RandomString(int len) //create random string with "len" number of chars
{
	srand(time(0));
	std::string str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	std::string newstr;
	int pos;
	while (newstr.size() != len) {
		pos = ((rand() % (str.size() - 1)));
		newstr += str.substr(pos, 1);
	}
	return newstr;
}


//camera feed
int video_cap(System::Windows::Forms::PictureBox^ pic, System::Windows::Forms::Control^ control)
{	
	VideoCapture cap;
	std::string file_name;
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

		new_image = detectAndDisplay(new_image, pic); //make it to be the entire augumented image
		int c = waitKey(10);
		if ((char)c == 27) { //escape key press
			control->Text = "Start Detecting";
			control->Enabled = true;
			// close the window
			face_detected = false;
			destroyAllWindows();
			break; 
		} 
		else if ((char)c == 32) //spacebar press
		{
			// Save the frame into a file
			file_name = "../data/screenshots/" + RandomString(10) + ".jpg";
			imwrite(file_name, new_image);
		}
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
	if (!cashew_cascade.load(cashew_cascade_name)) { printf("--(!)Error loading cashew cascade\n"); return -1; };
	if (!kosy_cascade.load(kosy_cascade_name)) { printf("--(!)Error loading Kosy cascade\n"); return -1; };
	if (!disease_cascade.load(disease_cascade_name)) { printf("--(!)Error loading disease cascade\n"); return -1; };

	video_cap(pic, control);
	return 0;
}


bool opencv_gui::face_det(void)
{
	return face_detected;
}


void opencv_gui::positive_prep(System::Windows::Forms::TextBox^ constraint_params, System::Windows::Forms::TextBox^ inputdir, System::Windows::Forms::TextBox^ outputdir, System::Windows::Forms::TextBox^ outputfilename, System::Windows::Forms::Label^ bottomlabel)
{
	std::string constraints = " " + msclr::interop::marshal_as< std::string >(constraint_params->Text) + "\n";
	if (constraints == "\n")
	{
		constraints = "1 2 2 199 199\n"; //set default constraints
	}
	std::string input_directory = msclr::interop::marshal_as< std::string >(inputdir->Text);
	std::string output_file = msclr::interop::marshal_as< std::string >(outputdir->Text) + "/" + msclr::interop::marshal_as< std::string >(outputfilename->Text) + ".txt";
	DIR *dir_p1 = opendir(input_directory.c_str());
	struct dirent *dir_entry_p;
	if (dir_p1 == NULL) {
		bottomlabel->Text = "Couldn't open directory\n";
	}

	//fprintf(stderr, "Copying...%s to %s\n", input_directory.c_str(), output_file.c_str());
	bottomlabel->Text = "Copying.." + inputdir->Text + "to" + outputdir->Text;
	std::ofstream output;
	output.open(output_file.c_str());
	while ((dir_entry_p = readdir(dir_p1)) != NULL) {
		output << input_directory + "/" << dir_entry_p->d_name << constraints;
	}

	bottomlabel->Text = "Done. Remember to remove . and .. dirs from text file\n"; 
	output.close();
}


void opencv_gui::negative_prep(System::Windows::Forms::TextBox^ inputdir, System::Windows::Forms::TextBox^ outputdir, System::Windows::Forms::TextBox^ outputfilename, System::Windows::Forms::Label^ bottomlabel)
{
	std::string constraints = "\n";
	std::string input_directory = msclr::interop::marshal_as< std::string >(inputdir->Text);
	std::string output_file = msclr::interop::marshal_as< std::string >(outputdir->Text) + "/" + msclr::interop::marshal_as< std::string >(outputfilename->Text) + ".txt";
	DIR *dir_p1 = opendir(input_directory.c_str());
	struct dirent *dir_entry_p;
	if (dir_p1 == NULL) {
		bottomlabel->Text = "Couldn't open directory\n";
	}

	//fprintf(stderr, "Copying...%s to %s\n", input_directory.c_str(), output_file.c_str());
	bottomlabel->Text = "Copying.." + inputdir->Text + "to" + outputdir->Text;
	std::ofstream output;
	output.open(output_file.c_str());
	while ((dir_entry_p = readdir(dir_p1)) != NULL) {
		output << input_directory + "/" << dir_entry_p->d_name << constraints;
	}

	bottomlabel->Text = "Done. Remember to remove . and .. dirs from text file\n";
	output.close();
}




