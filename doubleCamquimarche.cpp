#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <stdio.h>
#include "highgui.h"
#include "cv.h"




int main () {
    //recuperera un caractere au clavier
    char temp;
    // Image
     IplImage *image;
     IplImage *image2;
    //vidéo
   CvCapture *capture;
   CvCapture *capture2;
    
    //capture = cvCreateFileCapture("/path/to/your/video/test.avi"); // chemin pour un fichier
    capture = cvCreateCameraCapture(0);
    capture2 = cvCreateCameraCapture(1);
 
    // Vérifier l'ouverture du flux 
    if (!capture && !capture2) {
 
       printf("Nope !\n");
       return 1;
 
    }
	
 
    
    while(temp != 'c' || temp != 'C') {
 
      
       image = cvQueryFrame(capture);
       image2 = cvQueryFrame(capture2);
     
       cvShowImage( "Droite", image);
        cvShowImage( "Gauche", image2);
 
      
       temp = cvWaitKey(10);
 
    }
 
    cvReleaseCapture(&capture);
    cvDestroyWindow("YOLOOO");
 
    return 0;
 
}


