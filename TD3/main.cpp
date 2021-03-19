#include "fraction.cpp"
int main()
{
    Fraction f(1, 4), g(1, 2);
    Fraction s;
    cout <<"f = "<<f<<"\ng = "<<g<<"\ns = "<<s<<endl;
    
    cout <<"f = "<<f<<"\ng = "<<g<<"\ns = "<<s++<<endl;

    cout<<"\ns = "<<s<<endl;
    
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
