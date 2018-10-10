#pragma once

#include <vector>
#include <memory>

using namespace ci;
using namespace ci::app;

// 描画する物体の基本クラス
struct Object {
	int type;
	Vec2f pos;
	float angle;
	float speed;

	Object();
	virtual void update() {}
	virtual void draw() {}
};

// 円のクラス
struct SolidCircle : public Object {
	float radius;
	int	  numSegments;

	SolidCircle(Vec2f pos, float angle, float radius, float speed, int numSegments);
	void update() override;
	void draw() override;
};

// 全てのオブジェクトを管理するクラス
class Objects {
	static std::vector<std::unique_ptr<Object>> _objects;

public:
	static void createRandomObjects(int type, int num);
	static void add(Object& object);
	static void update();
	static void draw();
};