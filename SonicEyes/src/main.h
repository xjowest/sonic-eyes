#include "highPassFilter.h"

class mainClass{

 public:
    mainClass();
    ~mainClass();

	void setup();
	void update();
	void draw();

 private:
	highPassFilter hpFilter;
};
