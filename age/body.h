#ifndef BODY_H
#define BODY_H

#include <map>
#include <set>
#include "point.h"
#include "action.h"
#include "border.h"
#include "bodyKey.h"

class Entity;

class Body {
    bool destroy = false;

    Point position;
    Point bounds;

    unsigned int layer;
    unsigned int mask;
    std::set<Body*> seen;

    Point velocity;
    Point gravity;
    Point push;
    std::map<Action,Point> controls;
    Point totalv;

    virtual void collideX(Entity *other) = 0;
    virtual void collideY(Entity *other) = 0;
    virtual void collide(Border b) = 0;
    virtual void pass(Entity *other) = 0;

  public:

    void doCollideX(Body *other);
    void doCollideY(Body *other);
    void doCollide(Border b);
    void doPass(Body *other);

    void queueDestroy();
    bool isFlaggedDestroy() const;

    void setPosition(Point p);
    void setPosition(int x, int y);
    void setX(int x);
    void setY(int y);
    Point getPosition() const;
    
    void setBounds(Point b);
    Point getBounds() const;

	  bool isOutsideBorder() const;

    bool isOverlapping(const Body &other) const;
    bool isOverlapping(Point other_p, Point other_b) const;

    void setCollisionLayer(unsigned int cl);
    void setCollisionMask(unsigned int cl);
    bool isCollidable(const Body &other) const;

    void setVelocity(Point v);
    void setVelocity(int vx, int vy);
    void reflectVelocityY();
    void reflectVelocityX();
    Point getVelocity() const;

    void doPush(Point v);
    void doPush(int vx, int vy);

    void setAction(Action a, Point v);
    bool isPlayerControlled() const;

    void setGravitation(Border b);

    Point getTotalVelocity() const;
    void recalibrate(Action input, BodyKey);
};

#endif
