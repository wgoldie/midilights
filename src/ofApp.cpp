#include "ofApp.h"

#define MAX_FPS 40.

//--------------------------------------------------------------
void ofApp::setup(){
	brightness = 0x00;
	color = 0x00;

	udpConnection.Create();
	udpConnection.Connect("10.0.1.190", 8899);
	udpConnection.SetNonBlocking(true);

	char c[1] = { 0x42 };

	udpConnection.Send(c, 1);
	// print input ports to console
	midiIn.listPorts();
	midiIn.openPort(0);

	// add ofApp as a listener
	midiIn.addListener(this);
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::newMidiMessage(ofxMidiMessage& msg) {
	// mapped to numark mixtrack volume encoders
	if (msg.control == 8) {
		char h[3] = { 0x40, msg.value * 2, 0x55 };
		udpConnection.Send(h, 3);
	}
	if (msg.control == 9) {
		char b[3] = { 0x4E, int((msg.value / 127.) * 25. + 2), 0x55 };
		udpConnection.Send(b, 3);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
