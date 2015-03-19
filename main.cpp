/*Auteur Sébastien Raullet

Sources :

opencv.org
http://choorucode.com/2014/02/21/mat-in-opencv/
http://docs.opencv.org/doc/tutorials/core/mat_the_basic_image_container/mat_the_basic_image_container.html
https://github.com/jayrambhia/Vision/blob/master/OpenCV/C%2B%2B/disparity.cpp
http://blog.martinperis.com/
http://docs.opencv.org/doc/tutorials/core/mat_the_basic_image_container/mat_the_basic_image_container.html
http://www.developpez.net/forums/d565825/c-cpp/bibliotheques/opencv/carte-disparites/

Remerciments spéciaux :Arthur Brainville
*/

//Biblis pour faire tourner les 2 webcams et recuperer les images
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <stdio.h>
#include "highgui.h"
#include "cv.h"
//Biblis pour la map de diaparité
#include "opencv2/core/core.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "opencv2/contrib/contrib.hpp"
#include <string.h>

//Biblis pour la comparaison avec la map de disparité et la sortie de la profondeur
#include <cv.h>
#include <highgui.h>
#include <iostream>
#include <string>
#include <pcl/common/common_headers.h>
#include <pcl/io/pcd_io.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <boost/thread/thread.hpp>

//Création de la structure de matrice pour gérer le images

class Mat
{
public:
    Mat();
    Mat(int rows, int cols, int type);
    Mat(Size size, int type);
    Mat(const Mat& m);
    Mat(int rows, int cols, int type, void* data, size_t step=AUTO_STEP);
    Mat(Size size, int type, void* data, size_t step=AUTO_STEP);
 
    int flags;
    int dims;
    int rows, cols;
    uchar* data;
};




int main(int argc, char* argv[]) {
    //recuperera un caractere au clavier
	char temp;
	//création de matrice pour manipuler les images
	/*Mat M(2,2, CV_8UC3, Scalar(0,0,255));
    cout << "M = " << endl << " " << M << endl << endl;*/
    // Image
	//IplImage *image1;
	//IplImage *image2;
	Mat image1;
	Mat image2;
	
	/*cv::Mat mat(image);
	cv::Mat mat(image2);*/
	Mat g1, g2;
	
	
    //vidéo
	CvCapture *capture;
	CvCapture *capture2;
    
    //capture = cvCreateFileCapture("/path/to/your/video/test.avi"); // chemin pour un fichier
	capture = cvCreateCameraCapture(0);
	capture2 = cvCreateCameraCapture(1);
   // définir les parametres pour la création de la carte de disparités	
	
	Mat disp, disp8;
	//char* method = scanf("%c", method);
 
    // Vérifier l'ouverture du flux 
	if (!capture && !capture2) {
 
	printf("Nope !\n");
	return 1;
 
	}
	
 
 
	//Lance la capture tant que on appuie pas sur "c" ou "C"  
	while(temp != 'c' || temp != 'C') {
 
      
	image1 = imread(cvQueryFrame(capture));
        image2 = imread(cvQueryFrame(capture2));
     
     	//Passe les images des 2 cameras en uances de gris
     	cvtColor(image, g1, CV_BGR2GRAY);
     	cvtColor(image2, g2, CV_BGR2GRAY);
     
        cvShowImage( "Droite", image1);
        cvShowImage( "Gauche", image2);
 
      
        temp = cvWaitKey(10);
 
	}
 
	cvReleaseCapture(&capture);
	cvDestroyWindow("YOLOOO");
 
	return 0;
 
}


