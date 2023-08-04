#include "PhysicsBody.h"

PhysicsBody::PhysicsBody(float speed,
	b2World* world,
	MyTransform* transform)
{
	_speed = speed;
	_world = world;
	_transform = transform;

	_body = _transform->GetBody();
}

void PhysicsBody::SetSpeed(float newSpeed)
{
	_speed = newSpeed;
}

void PhysicsBody::MoveWithKeyboard()
{
    Vector2 position = _transform->GetPosition();
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

    if ( CheckCollision(newPosition - _body->GetPosition()) ) {
        newPosition = _body->GetPosition();
    }

    _body->SetTransform( newPosition, _body->GetAngle() );
}

void PhysicsBody::ChaseTarget(Vector2 target)
{
    Vector2 position = _transform->GetPosition();
    Vector2 direction = Vector2Subtract(target, position);
    direction = Vector2Normalize(direction);

    b2Vec2 newPosition = _body->GetPosition() +
        b2Vec2(direction.x * _speed * GetFrameTime(),
            direction.y * _speed * GetFrameTime());

    if ( CheckCollision(newPosition - _body->GetPosition()) ) {
        newPosition = _body->GetPosition();
    }

    _body->SetTransform(newPosition, _body->GetAngle());
}

void PhysicsBody::MoveInDirection(Vector2 direction)
{
    direction = Vector2Normalize(direction);

    b2Vec2 velocity = b2Vec2(direction.x * _speed * GetFrameTime(),
        direction.y * _speed * GetFrameTime());

    b2Vec2 newPosition = _body->GetPosition() + velocity;

    _body->SetTransform(newPosition, _body->GetAngle());
}

bool PhysicsBody::CheckCollision(const b2Vec2& velocity)
{
    b2Transform transform;
    transform.Set(_body->GetPosition(), _body->GetAngle());

    for (b2ContactEdge* edge = _body->GetContactList(); edge; edge = edge->next) {
        b2Contact* contact = edge->contact;

        if (contact->IsTouching()) {
            b2WorldManifold worldManifold;
            contact->GetWorldManifold(&worldManifold);

            for (int i = 0; i < b2_maxManifoldPoints; i++) {
                if (b2Dot(worldManifold.points[i] - transform.p, velocity) > 0.0f) {
                    return true;
                }
            }
        }
    }

    return false;
}

MyTransform* PhysicsBody::GetTransform()
{
    return _transform;
}
