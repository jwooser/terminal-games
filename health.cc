#include "health.h"

void Health::heal() { ++hp; }

void Health::damage() { --hp; }

void Health::heal(int h) { hp += h; }

void Health::damage(int d) { hp -= d; }

int Health::gethp() const { return hp; }

bool Health::dead() const { return hp <= 0; }
