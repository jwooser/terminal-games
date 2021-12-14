#ifndef ENTITY_H
#define ENTITY_H

#include "body.h"
#include <memory>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <type_traits>
#include "point.h"
#include "bitmap.h"
#include "sprite.h"

using std::unique_ptr;
using std::string;

class Game;

class Entity : public Body {

    size_t ticksOutsideBorder = 0;
    std::queue<unique_ptr<Entity>> spawns;
    std::set<string> tags;

    static const Bitmap noSprite;
    std::vector<unique_ptr<Sprite>> forms;
    size_t currForm = 0;

    virtual void initialize(Game &game) = 0;
    virtual void process(Game &game) = 0;

  public:

    virtual ~Entity() = default;

    void doInitialize(Game &game);
    void doProcess(Game &game);

    template 
    <typename T, typename std::enable_if<std::is_base_of<Entity, T>::value, int>::type = 0>
    T *queueSpawn(unique_ptr<T> entity) {
        T *entity_ptr = entity.get();
        spawns.push(std::move(entity));
        return entity_ptr;
	  }
    std::queue<unique_ptr<Entity>> &getSpawns();

    void addTag(string tag);
    void removeTag(string tag);
    bool hasTag(string tag);

    void nextForm();
    void setForm(size_t form);
    size_t addSprite(unique_ptr<Sprite> sprite);
    const Bitmap& getSpriteFrame() const;
    void setSpriteOffset(size_t form, Point o);
    Point getSpriteOffset() const;

};

#endif
