#include<iostream>
using namespace std;

// Iterative factorial
float fact(float n){
    int fact = 1;
    if (n==1){
        return 1;
    }
    else{
         for(int i=1;i<=n;i++){
            fact*=i;
         }
         return fact;
    }
}

// Recursive factorial
int fact_(int n){
    int fact =1;
    if (n==0||n==1){
        return 1;
    }
    else{
        fact = n*fact_(n-1);
    }
    return fact; // added return to keep your code valid
}

int main(){
    int n, choice;
    cout<<"Enter the value of n: ";
    cin>>n;

    cout<<"Choose method:\n1. Iterative\n2. Recursive\nEnter choice: ";
    cin>>choice;

    if(choice==1){
        int a = fact(n);
        cout<<"The factorial of "<<n<<" is: "<<a;
    }
    else if(choice==2){
        int a = fact_(n);
        cout<<"The factorial of "<<n<<" is: "<<a;
    }
    else{
        cout<<"Invalid choice!";
    }

    return 0;
}
