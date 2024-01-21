/** 
* @file -->Stack.cpp
* @description -->Ağacın yapraklarındaki sayıları tutan yığın sınıfı
* @assignment 2
* @date 12/12/2023
* @author Osman Tahir Özdemir  osman.ozdemir3@ogr.sakarya.edu.tr  ya da ozdemirosmantahir@gmail.com
*/

#include "Stack.hpp"
#include <iomanip>

// Yığın sınıfının yapıcı fonksiyonu
Stack::Stack() 
{
    this->capacity = 10;
    this->topIndex = -1;
    this->data = new int[capacity];
}

// Yığın sınıfının yıkıcı fonksiyonu
Stack::~Stack() {
    delete[] data;
}

// Yığına eleman ekler
void Stack::push(int value) {
    if (isFull()) {
        expand(2 * capacity);  // Yığın doluysa kapasiteyi iki katına çıkar
    }
    data[++topIndex] = value;  // Yığına eleman ekler ve topIndex'i artırır
}

// Yığından eleman çıkar
void Stack::pop() {
    if (isEmpty()) {
        cout << "Stack underflow, cannot pop from an empty stack." << endl;
        return;
    }
    --topIndex;  // TopIndex'i azaltarak eleman çıkar
}

// Yığın boş mu kontrolü
bool Stack::isEmpty() 
{ 
   return topIndex == -1; 
} 

// Yığın dolu mu kontrolü
bool Stack::isFull() {
    return topIndex == capacity - 1;
}

// Yığının en üstündeki elemanı döndürür
int Stack::top() {
    if (isEmpty()) {
        cout << "Stack is empty." << endl;
        return -1;  // Varsayılan olarak -1, yığında geçerli bir eleman olmadığını belirtir
    }
    return data[topIndex];
}

// Yığındaki elemanları güzel bir şekilde ekrana yazdırmak için aşırı yüklenmiş << operatörü
ostream& operator<<(ostream& os, Stack& stack)
{
    os << setw(5) << "---->";
    for (int i = 0; i <= stack.topIndex; i++) {
        os << stack.data[stack.topIndex - i] << endl;
        os << setw(5) << "    ";     
    }
    cout << endl;
    return os;
}

// Yığının kapasitesini genişletir
void Stack::expand(int size) {
    int* newData = new int[size];
    for (int i = 0; i <= topIndex; ++i) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = size;
}
