#include <iostream>

using namespace std;

void f(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void f2(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
void f3(int* a, int* b) {
    if (*a > *b) cout << *a << endl;
    else cout << *b << endl;
}

int main()
{
    /*
    int a = 5;
    int* pa = &a;
    cout << pa << " " << *pa << endl;
    cout << &a << " " << a << endl;

    *pa += 5;
    cout << pa << " " << a << " " << *pa <<  endl;
    */

    /*int a = 8, b = 3;
    cout << a << " " << b << endl;
    f(&a, &b);
    cout << a << " " << b << endl;
    f2(a, b);
    cout << a << " " << b << endl;*/

    /*
    const int size = 5;
    int arr[size] = { 55,71,45,6,13 };

    int* pa = &arr[0];
    cout << *pa << endl;
    int* pb = arr;

    cout << *pb <<  " " << *arr << endl;
    for (int i = 0; i < 5; i++) {
        //cout << arr[i];
        cout << *(pb++) << " ";
    }
    */

    //int a = 6, b = 9;
    //f3(&a, &b);
    
    int a = 0;
    int b = NULL;
    int* p = nullptr;
    cout << p;


}
