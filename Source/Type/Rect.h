#pragma once
template <typename T>
class Rect
{
public:
    Rect(T R, T G, T B, T A) : X(R), Y(G), W(B), H(A) {}
public:
    T X;
    T Y;
    T H;
    T W;
};


using Rectu = Rect<unsigned int>;
using Recti = Rect<int>;
using Rectf = Rect<float>;
