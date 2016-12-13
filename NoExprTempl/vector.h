namespace noexprtempl {

class Vector
{
public:
    const static unsigned int N=3;
    typename double Type;

    Type value[N];

    //double x, y, z;
    Vector() {
        this->x = 0;
        this->y = 0;
        this->z = 0;
    }
    Vector(double x, double y, double z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    Vector operator =(Vector second) {
        this->x = copy.x;
        this->y = copy.y;
        this->z = copy.z;
        return copy;
    }
    Vector operator +(const Vector &second) const {
        Vector result;
        result.x = this->x + second.x;
        result.y = this->y + second.y;
        result.z = this->z + second.z;
        return result;
    }
    Vector operator -(Vector second) const {
        Vector result;
        result.x = this->x - second.x;
        result.y = this->y - second.y;
        result.z = this->z - second.z;
        return result;
    }
};

}
