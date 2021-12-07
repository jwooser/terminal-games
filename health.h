#ifndef HEALTH_H
#define HEALTH_H

class Health {
    int hp = 0;
    
  public:
    void heal();
    void damage();
    void heal(size_t h);
    void damage(size_t d);
    int gethp() const;
    bool dead() const;
    virtual ~Health() = default;
}

#endif
