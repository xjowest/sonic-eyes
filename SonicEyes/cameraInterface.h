#include "typeDefs.h"
#include "ofMain.h"

class cameraInterface{
    public:
        cameraInterface();
        ~cameraInterface();

        ImageArray getImage();
    private:
        void convertGrabbedDataToImageArray(& ImageArray imArray, unsigned char * pixelData);

        ofVideoGrabber vidGrabber;
        int 				camWidth;
		int 				camHeight;
};
