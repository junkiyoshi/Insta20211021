#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetColor(39);

	ofSetBackgroundAuto(false);

}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	//auto location = glm::vec2(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
	//auto scale = ofRandom(1, 10);

	for (int i = 0; i < 2; i++) {

		auto location = glm::vec2(ofMap(ofNoise(ofRandom(1000), ofGetFrameNum() * 0.05), 0, 1, 50, 670), ofMap(ofNoise(ofRandom(1000), ofGetFrameNum() * 0.05), 0, 1, 50, 670));
		auto scale = ofMap(ofNoise(ofRandom(1000), ofGetFrameNum() * 0.05), 0, 1, 1, 10);

		ofPushMatrix();
		ofTranslate(location);
		ofRotate(ofMap(ofNoise(ofRandom(1000), ofGetFrameNum() * 0.05), 0, 1, -360, 360));

		ofSetColor(39);
		ofFill();
		ofBeginShape();
		for (auto deg = 0; deg < 360; deg += 1) {

			ofVertex(this->make_point(deg * DEG_TO_RAD) * scale);
		}
		ofEndShape(true);

		ofSetColor(239);
		ofNoFill();
		ofBeginShape();
		for (auto deg = 0; deg < 360; deg += 1) {

			ofVertex(this->make_point(deg * DEG_TO_RAD) * scale);
		}
		ofEndShape(true);

		ofPopMatrix();
	}

	ofSetColor(239);
	ofFill();
	ofBeginShape();
	ofVertex(0, 0);
	ofVertex(ofGetWidth(), 0);
	ofVertex(ofGetWidth(), ofGetHeight());
	ofVertex(0, ofGetHeight());
	ofNextContour(true);
	ofVertex(50, 50);
	ofVertex(ofGetWidth() - 50, 50);
	ofVertex(ofGetWidth() - 50, ofGetHeight() - 50);
	ofVertex(50, ofGetHeight() - 50);
	ofEndShape(true);
}

//--------------------------------------------------------------
//Reference by https://twitter.com/shiffman/status/1095764239665512453
glm::vec2 ofApp::make_point(float theta) {

	float x = 16 * (pow(sin(theta), 3));
	float y = 13 * cos(theta) - 5 * cos(2 * theta) - 2 * cos(3 * theta) - cos(4 * theta);
	return glm::vec2(x, -y);
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}