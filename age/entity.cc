#include "entity.h"
#include <utility>
#include "game.h"
#include "properties.h"

const Bitmap Entity::noSprite = Bitmap{};

void Entity::doInitialize(Game &game) {
    initialize(game);
}

void Entity::doProcess(Game &game) {
    process(game);
    recalibrate(game.getInput());
    if(isOutsideBorder()) ++ticksOutsideBorder;
    else ticksOutsideBorder = 0;
    if(ticksOutsideBorder >= 5) queueDestroy();
}

void Entity::setHeight(int h, EntityKey) { height = h; }

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
    if (forms.size() == 0) return noSprite;
    return forms[currForm]->getFrame();
}

void Entity::setSpriteOffset(size_t form, Point o) {
    forms[form]->setOffset(o);
}

Point Entity::getSpriteOffset() const {
	return forms[currForm]->getOffset();
}
