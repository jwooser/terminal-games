#ifndef WORLD_H
#define WORLD_H

#include <map>
#include <list>
#include <queue>
#include <memory>
#include <type_traits>
#include <utility>
#include "entity.h"
#include "bitmap.h"
#include "point.h"
#include "physics.h"

using std::map;
using std::vector;
using std::list;
using std::queue;
using std::unique_ptr;
using std::pair;

class Game;

class World {
	map<int,list<unique_ptr<Entity>>> entities;
	queue<pair<Point, const Bitmap*>> render;
	queue<pair<unique_ptr<Entity>, int>> spawns;
	unique_ptr<Physics> physics;
	
	virtual void initialize(Game &game) = 0;
	virtual void process(Game &game) = 0;

	void queueRender(Entity *entity);

	void doEntityPhysics();
	void doEntityProcesses(Game &game);
	void doEntityDestroys();
	void doEntitySpawns(Game &game);
	void doEntityRenders();
  protected:
	template
	<typename T, typename std::enable_if<std::is_base_of<Entity, T>::value, int>::type = 0>
	T *queueSpawn(unique_ptr<T> entity, int height) {
		T *entity_ptr = entity.get();
		spawns.emplace(std::move(entity), height);
		return entity_ptr;
	}
	void toggleSolidBorder(bool solid);
	void queueDestroyAll();
  public:
	World();
	void doInitialize(Game &game);
	void doProcess(Game &game);
	queue<pair<Point, const Bitmap*>>& getRender();
	virtual ~World() = default;
};

#endif
