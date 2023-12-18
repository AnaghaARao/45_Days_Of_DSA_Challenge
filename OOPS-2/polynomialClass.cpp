
/*************
 Driver program to test below functions
 
int main()
{
    int count1,count2,choice;
    cin >> count1;
    
    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];
    
    for(int i=0;i < count1; i++) {
        cin >> degree1[i];
    }
    
    for(int i=0;i < count1; i++) {
        cin >> coeff1[i];
    }
    
    Polynomial first;
    for(int i = 0; i < count1; i++){
        first.setCoefficient(degree1[i],coeff1[i]);
    }
    
    cin >> count2;
    
    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];
    
    for(int i=0;i < count2; i++) {
        cin >> degree2[i];
    }
    
    for(int i=0;i < count2; i++) {
        cin >> coeff2[i];
    }
    
    Polynomial second;
    for(int i = 0; i < count2; i++){
        second.setCoefficient(degree2[i],coeff2[i]);
    }
    
    cin >> choice;
    
    Polynomial result;
    switch(choice){
            // Add
        case 1:
            result = first + second;
            result.print();
            break;
            // Subtract
        case 2 :
            result = first - second;
            result.print();
            break;
            // Multiply
        case 3 :
            result = first * second;
            result.print();
            break;
            
        case 4 : // Copy constructor
        {
            Polynomial third(first);
            if(third.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
        case 5 : // Copy assignment operator
        {
            Polynomial fourth(first);
            if(fourth.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
    }
    
    return 0;
}
****************/

class Polynomial {

    public:   
        int *degCoeff;
        int capacity;
        // default constructor
        Polynomial(){
            degCoeff = new int[10];
            capacity = 10;
            for(int i = 0 ; i < 10 ; i++) degCoeff[i]=0;
        }
        // copy constructor
        Polynomial(Polynomial const &p){
            degCoeff = new int[p.capacity];
            for(int i = 0 ; i < p.capacity; i++){
                degCoeff[i] = p.degCoeff[i];
            }
            capacity = p.capacity;
        }
        // copy assignment operator
        void operator=(Polynomial const &p){
            delete[] degCoeff;
            degCoeff = new int[p.capacity];
            for(int i = 0 ; i < p.capacity; i++) degCoeff[i] = p.degCoeff[i];
            this->capacity = p.capacity;
        }
        // print
        void print() const{
            for(int i = 0 ; i < capacity ; i++){
                if(degCoeff[i]!=0){
                    cout<< degCoeff[i]<<"x"<<i<<" ";
                }                
            }
            cout<<endl;
        }
        // set co-efficient function(degree,co-efficient)
        void setCoefficient(int deg, int coeff){
            if(deg >= capacity){
                int size = 2*capacity;
                while(size <= deg){
                    size*=2;
                }
                int *newDegCoeff = new int[size];
                for(int i = 0 ; i < size ; i++){
                    newDegCoeff[i] = 0;
                }
                for(int i = 0 ; i < capacity ; i++){
                    newDegCoeff[i] = degCoeff[i];
                }
                capacity = size;
                delete [] degCoeff;
                degCoeff = newDegCoeff;
            }
            degCoeff[deg] = coeff;
        }
        // get co-efficient function:
        int getCoeff(int deg){
            if(deg >= capacity) return 0;
            return degCoeff[deg];
        }
        // +
        Polynomial operator+(Polynomial p2){
            Polynomial p3;
            int i = 0 , j = 0;
            while(i < this->capacity && j< p2.capacity){
                int deg = i;
                int coeff = this->degCoeff[i] + p2.degCoeff[j];
                p3.setCoefficient(deg, coeff);
                i++;
                j++;
            }
            while(i < capacity){
                p3.setCoefficient(i,degCoeff[i]);
                i++;
            }
            while(j < p2.capacity){
                p3.setCoefficient(j, p2.degCoeff[j]);
                j++;
            }
            return p3;
        }
        // -
         Polynomial operator-(Polynomial p2){
            Polynomial p3;
            int i = 0 , j = 0;
            while(i < this->capacitinty && j< p2.capacity){
                int deg = i;
                int coeff = this->degCoeff[i] - p2.degCoeff[j];
                p3.setCoefficient(deg, coeff);
                i++;
                j++;
            }
            while(i < this->capacity){
                p3.setCoefficient(i, degCoeff[i]);
                i++;
            }
            while(j < this->capacity){
                p3.setCoefficient(j, (-1 * p2.degCoeff[j]));
                j++;
            }
            return p3;
        }
        // *
        Polynomial operator*(Polynomial p2){
            Polynomial p3;
            for(int j = 0 ; j < p2.capacity ; j++){
                for(int i = 0 ; i < capacity ; i++){
                   int newDeg = i+j;
                   int newCoeff = p3.getCoeff(newDeg) + (this->degCoeff[i] * p2.degCoeff[j]);
                   p3.setCoefficient(newDeg, newCoeff);
                }
            } 
            return p3;
        }
};
