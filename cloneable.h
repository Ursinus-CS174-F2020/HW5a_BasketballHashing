#ifndef CLONEABLE_H
#define CLONEABLE_H

class Cloneable {
    public:
        virtual ~Cloneable() {};
        virtual Cloneable* clone() = 0;
};


#endif