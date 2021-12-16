#include "entity.h"
#include <utility>
#include "game.h"
#include "properties.h"

const Bitmap Entity::noSprite = Bitmap{};

void Entity::doInitialize(Game &game, int h, Key<World>) {
    height = h;
    initialize(game);
	recalibrate(game.getInput(), {});
}

void Entity::doProcess(Game &game, Key<World>) {
    process(game);
    recalibrate(game.getInput(), {});
    if(isOutsideBorder()) ++ticksOutsideBorder;
    else ticksOutsideBorder = 0;
    if(ticksOutsideBorder >= 5) queueDestroy();
}

std::queue<pair<unique_ptr<Entity>, int>> &Entity::getSpawns() { return spawns; }

// ********************************************************************************
// SPRITE/GRAPHICS METHODS
// ********************************************************************************

void Entity::nextForm() {
    ++currForm;
    if (currForm >= forms.size()) {
        currForm = 0;
    }
}

void Entity::setForm(size_t form) {
    if (form < forms.size()) currForm = form;
}

size_t Entity::addSprite(unique_ptr<Sprite> sprite) {
    size_t form = forms.size();
    forms.push_back(std::move(sprite));
    return form;
}

const Bitmap &Entity::getSpriteFrame() const {
    if (forms.empty()) return noSprite;
    return forms[currForm]->getFrame();
}

void Entity::setSpriteOffset(size_t form, Point o) {
    if (form < forms.size()) forms[form]->setOffset(o);
}

Point Entity::getSpriteOffset() const {
    if (forms.empty()) return Point{0, 0};
	return forms[currForm]->getOffset();
}
