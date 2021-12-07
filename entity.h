#ifndef ENTITY_H
#define ENTITY_H

#include <cstdint>
#include <memory>
#include <map>
#include <vector>
#include <queue>
#include "point.h"
#include "bitmap.h"
#include "sprite.h"
#include "action.h"
#include "border.h"

using std::unique_ptr;
using std::vector;
using std::queue;
using std::map;

class Game;

class Entity {
    Point position;

    bool destroy = false;

    size_t ticksOutsideBorder = 0;

    queue<unique_ptr<Entity>> spawns;

    vector<unique_ptr<Sprite>> forms;
    static const Bitmap noSprite;
    size_t currForm = 0;

    Point bounds;
    int16_t collisionLayer;

    Point velocity;
	Action input = Action::INVALID;
	map<Action,Point> actions;
    Border gravitation = Border::NONE;
    static const map<Border,Point> gravity;

    virtual void initialize(Game &game) = 0;
	virtual void process(Game &game) = 0;
    virtual void collideX(Entity *other) = 0;
    virtual void collideY(Entity *other) = 0;
    virtual void collideB(Border b) = 0;
    virtual void passEntity(Entity *other) = 0;
  public:
	virtual ~Entity() = default;

    void doInitialize(Game &game);
    void doProcess(Game &game);
    void doCollideX(Entity *other);
    void doCollideY(Entity *other);
	void doCollideB(Border b);
    void doPassEntity(Entity *other);

    void queueDestroy();
    bool isTaggedDestroy() const;

    template <typename T>
    T *queueSpawn(unique_ptr<T> entity) {
		T *entity_ptr = entity.get();
		spawns.push(std::move(entity));
		return entity_ptr;
	}
    queue<unique_ptr<Entity>> &getSpawns();

    void setPosition(Point p);
    void setPosition(int x, int y);
    void setX(int x);
    void setY(int y);
    Point getPosition() const;

    bool isOutsideBorder() const;

    void nextForm();
    void setForm(size_t form);
    size_t addSprite(unique_ptr<Sprite> sprite);
    const Bitmap& getSpriteFrame() const;
    void setSpriteOffset(size_t form, Point o);
	Point getSpriteOffset() const;
    
    void setBounds(Point b);
    Point getBounds() const;
    bool isOverlapping(const Entity &other) const;
    bool isOverlapping(Point other_p, Point other_b) const;
    void setCollisionLayer(int16_t cl);
    int16_t getCollisionLayer() const;
    bool isCollidable(const Entity &other) const;

    void setVelocity(Point v);
    void setVelocity(int vx, int vy);
    void reflectVelocityY();
    void reflectVelocityX();
    Point getVelocity() const;

    void setAction(Action a, Point v);
    bool isPlayerControlled() const;

    void setGravitation(Border b);

};

#endif
