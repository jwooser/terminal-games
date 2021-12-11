#include "health.h"

void Health::heal() { ++hp; }

void Health::damage() { if (!invuln) --hp; }

void Health::heal(int h) { hp += h; }

void Health::damage(int d) { if (!invuln) hp -= d; }

void Health::toggleinvuln(bool i) { invuln = i; }

int Health::gethp() const { return hp; }

bool Health::dead() const { return hp <= 0; }
