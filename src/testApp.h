#pragma once

#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>

#include "ofMain.h"
#include "ofxAndroid.h"

class testApp : public ofxAndroidApp {
	
public:
	void setup();
	void update();
	void draw();
	
	// android destroys the gl context when it pauses apps
	// most OF textures are automatically regenerated
	// but you'll need to regenerate the vbo yourself
	void resume();

	void touchDown(ofTouchEventArgs &touch);
	void touchMoved(ofTouchEventArgs &touch);
	void touchUp(ofTouchEventArgs &touch);
	void touchDoubleTap(ofTouchEventArgs &touch);
	void touchCancelled(ofTouchEventArgs &touch);
	
	bool	bPause;
	int		zoom, zoomTarget;

	ofVideoGrabber grabber;
};


