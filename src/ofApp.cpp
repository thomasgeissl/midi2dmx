#include "ofApp.h"

void ofApp::setup()
{
	_dmx.connect("tty.usbserial-EN160415");

	midiIn.listInPorts();
	midiIn.openVirtualPort("midi2dmx");
	midiIn.ignoreTypes(false, false, false);
	midiIn.addListener(this);
	midiIn.setVerbose(true);
}

void ofApp::update()
{
	_dmx.update();
}

void ofApp::draw()
{
}

void ofApp::keyPressed(int key)
{
}

void ofApp::keyReleased(int key)
{
}

void ofApp::mouseMoved(int x, int y)
{
}

void ofApp::mouseDragged(int x, int y, int button)
{
}

void ofApp::mousePressed(int x, int y, int button)
{
}

void ofApp::mouseReleased(int x, int y, int button)
{
}

void ofApp::mouseEntered(int x, int y)
{
}

void ofApp::mouseExited(int x, int y)
{
}

void ofApp::windowResized(int w, int h)
{
}

void ofApp::gotMessage(ofMessage msg)
{
}

void ofApp::dragEvent(ofDragInfo dragInfo)
{
}

void ofApp::newMidiMessage(ofxMidiMessage &msg)
{
	if (msg.status == MIDI_NOTE_ON)
	{
		ofLogNotice()<<msg.pitch;
		_dmx.setLevel(msg.pitch, msg.velocity * 2);
	}
}
