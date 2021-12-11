#ifndef HEALTH_H
#define HEALTH_H

class Health {
    int hp = 0;
    bool invuln = false;

  public:
    void heal();
    void damage();
    void heal(int h);
    void damage(int d);
    void toggleinvuln(bool i);
    int gethp() const;
    bool dead() const;
    virtual ~Health() = default;
};

#endif
