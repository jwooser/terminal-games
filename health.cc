#include "health.h"

void Health::heal() { ++hp; }

void Health::damage() { --hp; }

void Health::heal(size_t h) { hp += h; }

void Health::damage(size_t d) { hp -= d; }

int Health::gethp() const ( return hp; )

bool Health::dead() const ( return hp == 0; )
