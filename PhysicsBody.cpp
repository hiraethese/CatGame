#include "PhysicsBody.h"

PhysicsBody::PhysicsBody(b2World* world,
    MyTransform* transform,
    b2BodyType bodyType,
    float speed)
{
    _world = world;
    _transform = transform;
    _speed = speed;

    Vector2 position = _transform->GetPosition();
    Vector2 size = _transform->GetSize();

    b2BodyDef bodyDef;
    bodyDef.type = bodyType;
    bodyDef.position.Set(position.x, position.y);
    _body = _world->CreateBody(&bodyDef);

    b2PolygonShape boxShape;
    boxShape.SetAsBox(size.x / 2, size.y / 2);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &boxShape;

    if (bodyType == b2_dynamicBody)
    {
        fixtureDef.density = 1.0f;
    }
    else if (bodyType == b2_staticBody)
    {
        fixtureDef.density = 0.0f;
    }

    fixtureDef.friction = 0.2f;
    _body->CreateFixture(&fixtureDef);
}

void PhysicsBody::MoveWithKeyboard()
{
    Vector2 direction = { 0.0f, 0.0f };

    if (IsKeyDown(KEY_W)) {
        direction.y -= 1.0f;
    }
    if (IsKeyDown(KEY_S)) {
        direction.y += 1.0f;
    }
    if (IsKeyDown(KEY_A)) {
        direction.x -= 1.0f;
    }
    if (IsKeyDown(KEY_D)) {
        direction.x += 1.0f;
    }

    direction = Vector2Normalize(direction);

    b2Vec2 newPosition = _body->GetPosition() +
        b2Vec2(direction.x * _speed * GetFrameTime(),
            direction.y * _speed * GetFrameTime());
    
    float halfWidth = _transform->GetSize().x * 0.5f;
    float halfHeight = _transform->GetSize().y * 0.5f;
    newPosition.x = Clamp(newPosition.x, halfWidth, SCREEN_WIDTH - halfWidth);
    newPosition.y = Clamp(newPosition.y, halfHeight, SCREEN_HEIGHT - halfHeight);

    SetTransform(newPosition);
}

void PhysicsBody::ChaseTarget(Vector2 target)
{
    Vector2 position = _transform->GetPosition();
    Vector2 direction = Vector2Subtract(target, position);
    direction = Vector2Normalize(direction);

    b2Vec2 newPosition = _body->GetPosition() +
        b2Vec2(direction.x * _speed * GetFrameTime(),
            direction.y * _speed * GetFrameTime());

    SetTransform(newPosition);
}

void PhysicsBody::MoveInDirection(Vector2 direction)
{
    direction = Vector2Normalize(direction);

    b2Vec2 velocity = b2Vec2(direction.x * _speed * GetFrameTime(),
        direction.y * _speed * GetFrameTime());

    b2Vec2 newPosition = _body->GetPosition() + velocity;

    SetTransform(newPosition);
}

void PhysicsBody::SetTransform(b2Vec2 newPosition)
{
    Vector2 newTransformPosition;
    newTransformPosition.x = newPosition.x;
    newTransformPosition.y = newPosition.y;

    _transform->SetPosition(newTransformPosition);
    _body->SetTransform(newPosition, _body->GetAngle());
}

void PhysicsBody::SetSpeed(float newSpeed)
{
    _speed = newSpeed;
}

MyTransform* PhysicsBody::GetTransform()
{
    return _transform;
}

b2Body* PhysicsBody::GetBody()
{
    return _body;
}
