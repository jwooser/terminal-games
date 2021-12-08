#ifndef HEALTH_H
#define HEALTH_H

class Health {
    int hp = 0;
    
  public:
    void heal();
    void damage();
    void heal(int h);
    void damage(int d);
    int gethp() const;
    bool dead() const;
    virtual ~Health() = default;
};

#endif
