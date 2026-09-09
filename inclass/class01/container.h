#ifndef CONTAINER_H
#define CONTAINER_H

template<typename T>
class Container {
private:
    T items[10];
    int count;
public:
    Container() : count(0) {}

    void add(T item) {
        if (count < 10) {
            items[count++] = item;
        }
    }

    T get(int index) {
        return items[index];
    }

    int size() { return count; }
};

#endif
