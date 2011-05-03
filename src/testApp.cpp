#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	ofBackground(0,0,0);
	//ofRegisterTouchEvents(this);
	//ofxiPhoneSetOrientation(OFXIPHONE_ORIENTATION_LANDSCAPE_RIGHT);

	grabber.initGrabber(ofGetWidth(), ofGetHeight());

	bPause	   = false;

	zoom	   = -500;
	zoomTarget = 350;
}

// android destroys the gl context when it pauses apps
// most OF textures are automatically regenerated
// but you'll need to regenerate the vbo yourself
void testApp::resume(){
}

//--------------------------------------------------------------
void testApp::update(){
	grabber.update();

	//sweet - this is how you zoom in
	zoom += (zoomTarget-zoom) * 0.04;

}

//--------------------------------------------------------------
void testApp::draw() {
	ofBackground(20,20,20);

	ofDrawBitmapString(ofToString(ofGetFrameRate(), 1), 5, 20);
	grabber.draw(0, 0);
}

//--------------------------------------------------------------
void testApp::touchDown(ofTouchEventArgs &touch){
	if(touch.id == 2) bPause = !bPause;
}

//--------------------------------------------------------------
void testApp::touchMoved(ofTouchEventArgs &touch){
	if(touch.id == 1) {
		zoomTarget = ofMap(touch.x, 0.0, ofGetWidth(), 100, 500);
	}
}

//--------------------------------------------------------------
void testApp::touchUp(ofTouchEventArgs &touch){
	
}

//--------------------------------------------------------------
void testApp::touchDoubleTap(ofTouchEventArgs &touch){
	//get monster to look up
	
}

//--------------------------------------------------------------
void testApp::touchCancelled(ofTouchEventArgs &touch){
	
}
