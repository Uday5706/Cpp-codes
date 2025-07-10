#include <iostream>
using namespace std;

void pattern1(int n){
    for (int i=0 ; i<n ; i++ ){
        for (int j=0; j<n; j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}

void pattern2(int n){
    for (int i=0 ; i<n ; i++ ){
        for (int j=0; j<i+1; j++){
            cout<<"* ";
        }
        cout<<endl;
    }
} 

void pattern3(int n){
    for (int i=0 ; i<n ; i++ ){
        for (int j=1; j<=i+1; j++){
            cout<<j;
        }
        cout<<endl;
    }
}

void pattern4(int n){
    for (int i=0 ; i<n ; i++ ){
        for (int j=0; j<i+1; j++){
            cout<<i+1;
        }
        cout<<endl;
    }
}

void pattern5(int n){
    for (int i=n ; i>0 ; i-- ){
        for (int j=0; j<i; j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}

void pattern6(int n){
    for (int i=n ; i>0 ; i-- ){
        for (int j=1; j<=i; j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

void pattern7(int n){
    for (int i=0 ; i<n ; i++ ){
        for (int j=0; j<n-1-i; j++){
            cout<<"  ";
        }
        for (int j=0; j<2*i+1; j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}

void pattern8(int n){
    for (int i=n-1 ; i>=0 ; i-- ){
        for (int j=0; j<n-1-i; j++){
            cout<<"  ";
        }
        for (int j=0; j<2*i+1; j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}

void pattern9(int n){
    pattern7(n);
    pattern8(n);
}

void pattern10(int h){
    for (int i=1; i<=2*h-1; i++){
        int stars = i;
        if (i>h) stars = 2*h-i;
        for (int j=1; j<=stars; j++){
            cout<< "* ";
        }
        cout<<endl;
    }
}

void pattern11(int n){
    for (int i=0; i<n; i++){
        for (int j = 0; j<i+1;j++){
            if ((i+j)%2==0) cout<<"1 ";
            else cout<<"0 ";
        }
        cout<<endl;
    }
}

void pattern12(int n){
    for (int i=1; i<=n; i++){
         for (int j=1;j<=i; j++){
            cout<<j<<" ";
         }
         for (int j=2*(n-i); j>0;j--){
            cout<<"  ";
         }
         for (int j=i;j>=1; j--){
            cout<<j<<" ";
         }
         cout<<endl;
    }
}

void pattern13(int n){
    int sum=0;
    int i=1; //lvl
    for (int j=1;i<=n,j<=n*(n+1)/2;j++){
        sum+=j;
        int k = i*(i+1)/2; // total numbers till this lvl
        int end = k*(k+1)/2; //sum at end of level
        if (sum==end){
            cout<<j<<endl;
            i++;
        }
        else{
            cout<<j<<" ";
        }
    }
}

void pattern14(int n){
    for (int i=1;i<=n;i++){
        for (char j='A'; j<'A'+i; j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

void pattern15(int n){
    for (int i=n;i>=1;i--){
        for (char j='A'; j<'A'+i; j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

void pattern16(int n){
    for (char i='A'; i<'A'+n; i++){
        for (int j=0; j<i-'A'+1; j++){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}

void pattern17(int n){
    for (int i=0; i<n; i++){
        for (int j=0; j<n-i-1; j++){
            cout<<"  ";
        }
        char ch='A';
        int breakpoint = (2*i+1)/2;
        for (int j=1; j<=2*i+1;j++){
            cout<<ch<<" ";
            if (j<=breakpoint) ch++;
            else ch--;
        }

        cout<<endl;
    }
}

void pattern18(int n){
    for (int i = 0;i<n;i++){
        for (char j='A'+n-i-1; j<='A'+n-1;j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

void pattern19(int n){
    for (int i=0; i<n; i++){
        int space=(i>=n/2)?2*(n-i-1):2*i;
        int stars=(i>=n/2)?2*(i-n/2+1):n-2*i;
        for (int j=0;j<stars/2;j++){
            cout<<"* ";
        }
        for (int j=0; j<space; j++){
            cout<<"  ";
        }
        for (int j=0;j<stars/2;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}

void pattern20(int n){
    for (int i=0; i<n; i++){
        int stars = (i<=n/2)?2*(i+1):2*(n-i);
        int space = (i<=n/2)?n+1-2*(i+1):2*i-n+1;
        for (int j=0;j<stars/2;j++){
            cout<<"* ";
        }
        for (int j=0; j<space; j++){
            cout<<"  ";
        }
        for (int j=0;j<stars/2;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}

void pattern21(int n){    
    for (int i=0; i<n; i++){
        int stars =(i==0||i==(n-1))?n:2;
        int space = (i==0||i==(n-1))?0:n-2;
        for (int j=0;j<stars/2;j++){
            cout<<"* ";
        }
        for (int j=0; j<space; j++){
            cout<<"  ";
        }
        for (int j=0;j<stars/2;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}

void pattern22(int n){
    for (int i=0; i<2*n-1; i++){
        int end = (i>=n-1)?i-n+2: n-i;
        for (int j=n;j>end;j--){
            cout<<j<<" ";
        }
        for (int j=0;j<2*end-1;j++){
            cout<<end<<" ";
        }
        for (int j=end+1;j<=n;j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for (int i=0; i<2*n-1;i++){
        for (int j=0; j<2*n-1; j++){
            int top=i;
            int left = j;
            int right = (2*n-2)-j;
            int down = (2*n-2)-i;
            cout<<(n-min(min(top,down),min(left, right)))<<" ";
        }
        cout<<endl;
    }
}

int main() {
    int n;
    cin>>n;
    pattern22(n);
    return 0;
}