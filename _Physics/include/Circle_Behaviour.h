#pragma once

#include "cinder/app/AppNative.h"
#include <vector>

using namespace cinder;
using namespace cinder::app;

class SolidCircle {
	Vec2f m_pos = Vec2f(0, 0);
	float m_angle = 0;
	float m_radius = 10;
	float m_speed = 1;
	int	  m_num_segments = 10;

	static std::vector<SolidCircle> solidCircleList;

public:
	SolidCircle(Vec2f pos, float angle, float radius, float speed, int numSegments);
	void update();
	void draw();
};

SolidCircle::SolidCircle(Vec2f pos = Vec2f(0, 0), float angle = 0, float radius = 10, float speed = 1, int numSegments = 10) {
	this->m_pos = pos;
	this->m_angle = angle;
	this->m_radius = radius;
	this->m_speed = speed;
	this->m_num_segments = numSegments > 0 ? numSegments : 0;
	this->solidCircleList.push_back(*this);
}

void SolidCircle::update() {
	m_pos += Matrix22f::createRotation(m_angle) * Vec2f(0, 1) * m_speed;
}

void SolidCircle::draw() {
	gl::pushModelView(); {
		gl::drawSolidCircle(m_pos, m_radius, m_num_segments);
	} gl::popModelView();
}

class SolidCircleList {

	
};