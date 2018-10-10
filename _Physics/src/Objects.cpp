#include "cinder/app/AppNative.h"
#include "Objects.h"

// 生成されたオブジェクトをObjectsで管理できるようにする
Object::Object() {
	Objects::add(*this);
}




SolidCircle::SolidCircle(Vec2f pos, float angle = 0, float radius = 10, float speed = 1, int numSegments = 10) {
	this->type = 0;
	this->pos = pos;
	this->angle = angle;
	this->radius = radius;
	this->speed = speed;
	this->numSegments = numSegments > 0 ? numSegments : 0;
}

void SolidCircle::update() {
	pos += Matrix22f::createRotation(this->angle) * Vec2f(1, 0) * this->speed;
}

void SolidCircle::draw() {
	gl::pushModelView(); {
		gl::translate(pos);
		gl::drawSolidCircle(this->pos, this->radius, this->numSegments);
	} gl::popModelView();
}




void Objects::createRandomObjects(int type, int num) {
	_objects.reserve(num);
	for (int i = 0; i < num; i++) {
		if (type == 0) {
			std::unique_ptr<SolidCircle> ptr(new SolidCircle(Vec2f(0, 0)));
			_objects.emplace_back(std::move(ptr));
		}
	}
}

void Objects::add(Object& object) {
}

void Objects::update() {
}

void Objects::draw() {
}