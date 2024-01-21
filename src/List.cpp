/** 
* @file -->List.cpp
* @description -->Ağaçları bir arada tutan ve yığınlarla ilgili işlemler yapan Tekli bağlı liste sınıfı
* @assignment 2
* @date 14/12/2023
* @author Osman Tahir Özdemir  osman.ozdemir3@ogr.sakarya.edu.tr  ya da ozdemirosmantahir@gmail.com
*/

#include "List.hpp"
#include <iostream>

// List sınıfının yapıcı fonksiyonu
List::List() 
{
    this->firstTree = nullptr;
    this->treeCount = 0;
    this->avlNo = 0;
    this->isDeleted = false;
    this->choice = 0;
}

// Stack'leri yedekleme fonksiyonu
void List::backUpStacks()
{
    if (firstTree == nullptr)
    {
        cout << "liste bos "; return;
    }

    // Liste üzerinde dolaşarak her AVL ağacının yedek stack'ini oluştur
    for (AvlTree* i = firstTree; i != nullptr; i = i->nextTree)
    {
       
        i->stack = new Stack(*(i->tempStack));
       
    }
}

// Listeyi başlatma fonksiyonu
void List::start() {
    executeStack((choice % 2) ? findMinTopfromStacks() : findMaxTopFromStacks());
    ++choice;
}


// Yeni bir AVL ağacını liste sonuna ekleme fonksiyonu
void List::addTree(AvlTree* newTree)
{
    if (firstTree == nullptr)
    {
        treeCount++;
        newTree->AvlNo = treeCount;
        firstTree = newTree;
        return;
    }

    AvlTree* temp = firstTree;
    while (temp->nextTree != nullptr)
    {
        temp = temp->nextTree;
    }
    treeCount++;
    newTree->AvlNo = treeCount;
    temp->nextTree = newTree;
}

// Stack'ler arasında en büyük top değerine sahip AVL ağacını bulma fonksiyonu
AvlTree* List::findMaxTopFromStacks()
{
    if (!firstTree) {
        std::cout << "Liste bos. En buyuk dugum bulunamadi.\n";
        return nullptr;
    }

    AvlTree* maxNode = firstTree;
    AvlTree* current = firstTree->nextTree;

    while (current) {
        if (current->stack->top() > maxNode->stack->top()) {
            maxNode = current;
        }
        current = current->nextTree;
    }

    return maxNode;
}

// Stack'ler arasında en küçük top değerine sahip AVL ağacını bulma fonksiyonu
AvlTree* List::findMinTopfromStacks()
{
    if (!firstTree) {
        std::cout << "Liste bos. En kucuk dugum bulunamadi.\n";
        return nullptr;
    }

    AvlTree* minTree = firstTree;
    AvlTree* current = firstTree->nextTree;

    while (current) {
        if (current->stack->top() < minTree->stack->top()) {
            minTree = current;
        }
        current = current->nextTree;
    }

    return minTree;
}

// Stack'i işleme ve gerekirse AVL ağacını silme fonksiyonu
void List::executeStack(AvlTree* executeToTree) {
    if (!firstTree) {
        std::cout << "Liste bos. Yigin islemi yapilamaz.\n";
        return;
    }

    // İlk AVL ağacına işlem yapılacaksa
    if (firstTree == executeToTree) {
        if (!executeToTree->stack->isEmpty()) {
            executeToTree->stack->pop();
            if (executeToTree->stack->isEmpty()) {
                treeCount--;

                AvlTree* temp = firstTree;
                firstTree = firstTree->nextTree;
                delete temp;
                this->choice = 0;
               backUpStacks();
            system("cls");
                printTrees();
            }
        }
        return;
    }

    // İlk AVL ağacı değilse
    AvlTree* current = firstTree;
    AvlTree* prev = nullptr;

    // İlgili AVL ağacını bul
    while (current && current != executeToTree) {
        prev = current;
        current = current->nextTree;
    }

    // AVL ağacı bulunduysa işlemi gerçekleştir
    if (current) {
        if (!current->stack->isEmpty()) {
            current->stack->pop();
            if (current->stack->isEmpty()) {
                treeCount--;
                prev->nextTree = current->nextTree;
                delete current;
                
                this->choice = 0;
               backUpStacks();
                system("cls");
                printTrees();
            }
        }
    } else {
        std::cout << "Dugum bulunamadi. Silme islemi yapilamaz.\n";
    }
}

// Ağaçları ekrana yazdırma fonksiyonu
void List::printTrees()
{
    if (firstTree == nullptr)
    {
        std::cout << "Liste bos\n";
        return;
    }

    AvlTree* temp = firstTree;
    while (temp != nullptr)
    {
        cout << temp->Ascii;
        if (treeCount == 1)
        {
            system("cls");
            cout << "=====================================\n";
            cout << "|                                   |\n";
            cout << "|                                   |\n";
            cout << "|     son karakter : " << temp->Ascii << "              |\n";
            cout << "|     avl no :  " << temp->AvlNo << "                 |\n";
            cout << "|                                   |\n";
            cout << "|                                   |\n";
            cout << "=====================================\n";
        }
        temp = temp->nextTree;
    }
}

// Ağaç sayısını getiren fonksiyon
int List::getAvlTreeCount()
{
    return treeCount;
}

// List sınıfının yıkıcı fonksiyonu
List::~List()
{
      AvlTree* current = firstTree;

    while(current!=nullptr)
    {
        AvlTree* deleteNode = current;

        current= current->nextTree;
        delete deleteNode;
        delete deleteNode->tempStack;
    }

}
