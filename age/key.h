#ifndef KEY_H
#define KEY_H

template <typename T>
class Key {
    friend T;
    Key() { }
	Key(Key const&) { }
};

#endif
