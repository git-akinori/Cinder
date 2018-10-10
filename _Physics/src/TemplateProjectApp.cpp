#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Camera.h"

#include "Objects.h"

using namespace ci;
using namespace ci::app;

class TemplateProjectApp : public AppNative {
	CameraPersp camera;

public:
	void setup();
	void mouseDown(MouseEvent event);
	void update();
	void draw();
};

void TemplateProjectApp::setup()
{
}

void TemplateProjectApp::mouseDown(MouseEvent event)
{
	
}

void TemplateProjectApp::update()
{
}

void TemplateProjectApp::draw()
{
	gl::clear(Color(0, 0, 0));

	gl::pushModelView(); {
		gl::translate(getWindowSize() / 2);
	} gl::popModelView();
}

CINDER_APP_NATIVE(TemplateProjectApp, RendererGl)
