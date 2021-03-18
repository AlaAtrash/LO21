#include "fraction.cpp"
int main()
{
    MATH::Fraction f(1, 4), g(1, 4), s(0,0);
    cout <<"f = "<<f<<"\ng = "<<g<<endl;

    s.somme(f, g);
    cout <<"s = "<<s<<endl;
    /*
    int x, y;
    cout<<"Numerateur : ";
    cin>>x;
    cout<<"Denominateur : ";
    cin>>y;
    f.setFraction(x, y);
    */
    //cout <<"f = "<<f<<endl;
    return 0;
}
