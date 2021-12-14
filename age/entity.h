#ifndef ENTITY_H
#define ENTITY_H

#include "body.h"
#include <memory>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <type_traits>
#include <utility>
#include "point.h"
#include "bitmap.h"
#include "sprite.h"
#include "entityKey.h"

using std::unique_ptr;
using std::string;
using std::pair;

class Game;

class Entity : public Body {
    int height = 0;

    size_t ticksOutsideBorder = 0;
    std::queue<pair<unique_ptr<Entity>, int>> spawns;
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

    void setHeight(int h, EntityKey);
    template 
    <typename T, typename std::enable_if<std::is_base_of<Entity, T>::value, int>::type = 0>
    T *queueSpawn(unique_ptr<T> entity, int h) {
        T *entity_ptr = entity.get();
		spawns.emplace(std::move(entity), h);
		return entity_ptr;
	}
	template
    <typename T, typename std::enable_if<std::is_base_of<Entity, T>::value, int>::type = 0>
	T *queueSpawn(unique_ptr<T> entity) {
        T *entity_ptr = entity.get();
        spawns.emplace(std::move(entity), height);
        return entity_ptr;
    }
    std::queue<pair<unique_ptr<Entity>, int>> &getSpawns();

    void nextForm();
    void setForm(size_t form);
    size_t addSprite(unique_ptr<Sprite> sprite);
    const Bitmap& getSpriteFrame() const;
    void setSpriteOffset(size_t form, Point o);
    Point getSpriteOffset() const;

};

#endif
