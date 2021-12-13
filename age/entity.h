#ifndef ENTITY_H
#define ENTITY_H

#include <memory>
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
using std::set;
using std::map;

class Game;

class Entity : public Body {

    size_t ticksOutsideBorder = 0;

    queue<unique_ptr<Entity>> spawns;

    static const Bitmap noSprite;
    vector<unique_ptr<Sprite>> forms;
    size_t currForm = 0;

    virtual void initialize(Game &game) = 0;
	virtual void process(Game &game) = 0;
  public:
	virtual ~Entity() = default;

    void doInitialize(Game &game);
    void doProcess(Game &game);

    template <typename T>
    T *queueSpawn(unique_ptr<T> entity) {
		T *entity_ptr = entity.get();
		spawns.push(std::move(entity));
		return entity_ptr;
	}
    queue<unique_ptr<Entity>> &getSpawns();

    void nextForm();
    void setForm(size_t form);
    size_t addSprite(unique_ptr<Sprite> sprite);
    const Bitmap& getSpriteFrame() const;
    void setSpriteOffset(size_t form, Point o);
	Point getSpriteOffset() const;

};

#endif
