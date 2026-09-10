# CS258 In-class 2: Virtual Classes and Templates

## Assignment Overview

Create a simple shape drawing system that demonstrates both virtual classes and template classes. Students will build a hierarchy of shapes and a generic container to manage them.

## Part 1: Virtual Classes 

### Task
Create a shape hierarchy using virtual functions for polymorphism.

### Requirements

1. **Base Class**: Create an abstract `Shape` class with:
   - Pure virtual function `draw()`
   - Pure virtual function `area()`
   - Virtual destructor

2. **Derived Classes**: Create three concrete shape classes:
   - `Circle` (requires radius)
   - `Rectangle` (requires width and height)
   - `Triangle` (requires base and height)

3. **Implementation**: Each derived class should:
   - Implement `draw()` to print the shape name and dimensions
   - Implement `area()` to calculate and return the area
   - Have appropriate constructors

### Example Usage
```cpp
// Note: This won't work with abstract base class, but shows the concept
Circle c(5.0);
Rectangle r(4.0, 6.0);
Triangle t(3.0, 4.0);

c.draw();
cout << "Area: " << c.area() << endl;
```

## Part 2: Template Classes

### Task
Create a generic container class using templates to store and manage shapes.

### Requirements

1. **Template Container**: Create a `Container<T>` class that:
   - Stores an array of type T objects (not pointers)
   - Has a maximum capacity (use static array, size 10)
   - Tracks current number of items

2. **Methods**: Implement these methods:
   - `add(T item)` - adds item to container
   - `get(int index)` - returns item at index
   - `size()` - returns current number of items

3. **Specialization**: Create a template specialization for `Container<Circle>` that adds:
   - `getTotalArea()` - returns sum of all circles' areas
   - `drawAll()` - calls draw() on all circles

### Example Usage
```cpp
Container<Circle> circleContainer;
circleContainer.add(Circle(3.0));
circleContainer.add(Circle(5.0));

circleContainer.drawAll();
cout << "Total area: " << circleContainer.getTotalArea() << endl;
```

## Part 3: Integration (15 minutes)

### Task
Combine both concepts in a simple main function.

### Requirements

1. Create separate `Container<Circle>`, `Container<Rectangle>`, and `Container<Triangle>` objects
2. Add at least 2 shapes to each container
3. Display all shapes and their individual areas from each container
4. Display the total area for each type of shape
5. Demonstrate templates by showing the same container works with different shape types

## Expected Output
```
Circle Container:
Drawing Circle with radius: 3
Area: 28.27
Drawing Circle with radius: 5
Area: 78.54
Total area of circles: 106.81

Rectangle Container:
Drawing Rectangle with width: 4, height: 6
Area: 24
Drawing Rectangle with width: 2, height: 8
Area: 16
Total area of rectangles: 40
```

## Makefile
Create a Makefile to compile each file correctly.

## Learning Objectives

**Virtual Classes:**
- Understand abstract base classes and pure virtual functions
- Learn how virtual functions enable runtime polymorphism
- Practice proper use of virtual destructors
- Work with concrete derived classes

**Template Classes:**
- Create generic classes that work with any type
- Understand template instantiation
- Learn template specialization for specific types
- Practice working with value semantics instead of pointer semantics

## Starter Code Structure

```cpp
#include <iostream>
using namespace std;

// Base class
class Shape {
public:
    // TODO: Add pure virtual functions and virtual destructor
};

// Derived classes
class Circle : public Shape {
private:
    double radius;
public:
    // TODO: Implement constructor and virtual functions
};

// Template container class
template<typename T>
class Container {
private:
    T items[10];
    int count;
public:
    Container() : count(0) {}
    // TODO: Implement container methods
};

// Template specialization for Circle
template<>
class Container<Circle> {
    // TODO: Add specialized methods for Circle
};

int main() {
    // TODO: Create containers for each shape type, add shapes, and demonstrate functionality
    return 0;
}
```

