#include "MyTransform.h"

MyTransform::MyTransform(b2World* world, Vector2 position, Vector2 size)
{
	_world = world;
	_position = position;
	_size = size;

	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(_position.x, _position.y);
	_body = _world->CreateBody(&bodyDef);

	b2PolygonShape boxShape;
	boxShape.SetAsBox(_size.x / 2, _size.y / 2);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &boxShape;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;
	_body->CreateFixture(&fixtureDef);
}

void MyTransform::SetPosition(Vector2 newPosition)
{
	_position = newPosition;

	_body->SetTransform( b2Vec2(_position.x, _position.y), _body->GetAngle() );
}

b2Body* MyTransform::GetBody()
{
	return _body;
}

Rectangle MyTransform::GetRectangle()
{
	return { _position.x, _position.y, _size.x, _size.y };
}

Vector2 MyTransform::GetPosition()
{
	b2Vec2 bodyPosition = _body->GetPosition();

	return Vector2{ bodyPosition.x, bodyPosition.y };
}

Vector2 MyTransform::GetSize()
{
	return _size;
}
