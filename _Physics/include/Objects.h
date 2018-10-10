#pragma once

#include <vector>
#include <memory>

using namespace ci;
using namespace ci::app;

// �`�悷�镨�̂̊�{�N���X
struct Object {
	int type;
	Vec2f pos;
	float angle;
	float speed;

	Object();
	virtual void update() {}
	virtual void draw() {}
};

// �~�̃N���X
struct SolidCircle : public Object {
	float radius;
	int	  numSegments;

	SolidCircle(Vec2f pos, float angle, float radius, float speed, int numSegments);
	void update() override;
	void draw() override;
};

// �S�ẴI�u�W�F�N�g���Ǘ�����N���X
class Objects {
	static std::vector<std::unique_ptr<Object>> _objects;

public:
	static void createRandomObjects(int type, int num);
	static void add(Object& object);
	static void update();
	static void draw();
};