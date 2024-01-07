#include<bits/stdc++.h>
using namespace std;

/* defining T as a temp datatype
    the datatype is defined at the time of object 
    creation in the main function
 */
// SYNTAX of template
template <typename T , typename V>
class Pair{
    T x;
    V y;

    public:

    void setX(T x){
        this->x = x;
    }

    T getX(){
        return x;
    }

    void setY(V y){
        this->y = y;
    }

    V getY(){
        return y;
    }

};

//main function
int main(){
    /* specifing the datatype of T in angular braces*/
    /* 
        FOR SINGLE TYPE OF TEMPLATE
        Pair<int> p1;
        p1.setX(10);
        p1.setY(20);
        cout<<p1.getX()<<"\t"<<p1.getY()<<endl;

        Pair<double> p2;
        p2.setX(144.9206);
        p2.setY(8450.892);
        cout<<p2.getX()<<"\t"<<p2.getY()<<endl;
    */

    /* FOR MULTIPLE TYPES OF TEMPLATE */
    Pair<int,char> p1;
    p1.setX(10.39457);
    p1.setY('a');
    cout<<p1.getX()<<" "<<p1.getY()<<endl;

    Pair<Pair<int,char>, double> p2;
    p2.setX(p1);
    p2.setY(12090.09374);
    cout<<p2.getX().getX()<<" "<<p2.getX().getY()<<" "<<p2.getY()<<endl;
    /*   
        to create a pair with one datatype belonging to pair type 
        the it can be done as above ,ie, creating a triplet using 
        the same class       
    */
}