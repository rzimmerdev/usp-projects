class Shape {
    _type;
    _perimeter;

    get type() {
        return this._type;
    }

    get perimeter() {
        return this._perimeter;
    }

    constructor(type, perimeter) {
        this._type = type;
        this._perimeter = perimeter;
    }
}

class Triangle extends Shape {
    constructor(a, b, c) {
        super("Triangle", a + b + c);
        [this.a, this.b, this.c] = [a, b, c];
    }
}


class Square extends Shape {
    constructor(side) {
        super("Square", 4 * side);
        this.side = side;
    }
}