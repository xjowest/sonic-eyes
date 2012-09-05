#include "cameraInterface.h"

class mainClass : public ofBaseApp{

 public:
    mainClass();
    ~mainClass();

	void setup();
	void update();
	void draw();

 private:
    cameraInterface * camInterface;
};
