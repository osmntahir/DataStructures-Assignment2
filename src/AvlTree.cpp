/** 
* @file -->AvlTree.cpp
* @description -->Node'ları bir arada tutan Avl ağacı
* @assignment 2
* @date 10/12/2023
* @author Osman Tahir Özdemir  osman.ozdemir3@ogr.sakarya.edu.tr  ya da ozdemirosmantahir@gmail.com
*/

#include "AvlTree.hpp"

// Node'ları arama ve ekleme işlemleri
Node* AvlTree::SearchAndAdd(Node* subNode, const int& item) {
    if (subNode == nullptr) subNode = new Node(item); // Eğer düğüm boşsa, yeni bir düğüm oluştur
    else if (item < subNode->data) {
        subNode->left = SearchAndAdd(subNode->left, item); // Sol alt ağaca git

        // Sol alt ağacın yüksekliği sağ alt ağacın yüksekliğinden 2 birim fazla ise dengesizlik durumu var
        if (Height(subNode->left) == Height(subNode->right) + 2) {
            if (item < subNode->left->data)
                subNode = SwapWithLeftChild(subNode); // Sol-sol durumu
            else {
                subNode->left = SwapWithRightChild(subNode->left);
                subNode = SwapWithLeftChild(subNode); // Sol-sağ durumu
            }
        }
    }
    else if (item > subNode->data) {
        subNode->right = SearchAndAdd(subNode->right, item); // Sağ alt ağaca git

        // Sağ alt ağacın yüksekliği sol alt ağacın yüksekliğinden 2 birim fazla ise dengesizlik durumu var
        if (Height(subNode->right) == Height(subNode->left) + 2) {
            if (item > subNode->right->data)
                subNode = SwapWithRightChild(subNode); // Sağ-sağ durumu
            else {
                subNode->right = SwapWithLeftChild(subNode->right);
                subNode = SwapWithRightChild(subNode); // Sağ-sol durumu
            }
        }
    }
    else;

    // Düğümün yüksekliğini güncelle
    subNode->height = Height(subNode);
    return subNode;
}

// Sol alt düğümle yer değiştirme
Node* AvlTree::SwapWithLeftChild(Node* subNode) {
    Node* tmp = subNode->left;
    subNode->left = tmp->right;
    tmp->right = subNode;

    // Düğümlerin yüksekliklerini güncelle
    subNode->height = Height(subNode);
    tmp->height = 1 + max(Height(tmp->left), subNode->height);

    return tmp;
}

// Sağ alt düğümle yer değiştirme
Node* AvlTree::SwapWithRightChild(Node* subNode) {
    Node* tmp = subNode->right;
    subNode->right = tmp->left;
    tmp->left = subNode;

    // Düğümlerin yüksekliklerini güncelle
    subNode->height = Height(subNode);
    tmp->height = 1 + max(Height(tmp->right), subNode->height);

    return tmp;
}

// Düğümü silme
bool AvlTree::DeleteNode(Node*& subNode) {
    Node* delNode = subNode;

    // Düğümün sağ alt dalı boşsa, sol alt dalı ile yer değiştir
    if (subNode->right == nullptr) subNode = subNode->left;
    // Düğümün sol alt dalı boşsa, sağ alt dalı ile yer değiştir
    else if (subNode->left == nullptr) subNode = subNode->right;
    else {
        // Düğümün sol alt dalında en büyük değeri bul
        delNode = subNode->left;
        Node* parentNode = subNode;
        while (delNode->right != nullptr) {
            parentNode = delNode;
            delNode = delNode->right;
        }

        // Silinecek düğümü, bulunan en büyük değerle değiştir
        subNode->data = delNode->data;

        // Eğer en büyük değer sol alt dalın kökü ise, sol alt dalı güncelle
        if (parentNode == subNode) subNode->left = delNode->left;
        // Değilse, bulunduğumuz düğümün sağ alt dalını güncelle
        else parentNode->right = delNode->left;
    }

    // Düğümü sil ve başarılı olduğunu belirt
    delete delNode;
    return true;
}

// Postorder dolaşma işlemi
void AvlTree::postorder(Node* subNode) {
    if (subNode != nullptr) {
        // Sol alt dalı ziyaret et
        postorder(subNode->left);

        // Sağ alt dalı ziyaret et
        postorder(subNode->right);

        // Yaprak düğüm kontrolü
        if (subNode->left == nullptr && subNode->right == nullptr) {
            // Eğer yaprak düğümse, postorder olarak yazdır
            stack->push(subNode->data);
            tempStack->push(subNode->data);
        }
        else {
            // Eğer yaprak değilse, sumNode'e ekle
            sumNode += subNode->data;
        }
    }
}

// Düğüm yüksekliğini hesaplama
int AvlTree::Height(Node* subNode) {
    if (subNode == nullptr) return -1;
    return 1 + max(Height(subNode->left), Height(subNode->right));
}

// Düğüm arama işlemi
bool AvlTree::Search(Node* subNode, const int& item) {
    if (subNode == nullptr) return false;
    if (subNode->data == item) return true;
    if (item < subNode->data) return Search(subNode->left, item);
    else return Search(subNode->right, item);
}

// AvlTree sınıfının yapıcı fonksiyonu
AvlTree::AvlTree() {
    root = nullptr;
    this->stack = new Stack();
    this->sumNode = 0;
    this->nextTree = nullptr;
    this->Ascii = '0';
    this->AvlNo = 0;
    this->tempStack = new Stack();
}

// SumNode değerini ASCII'ye çevirme
void AvlTree::sumNodeToAscii() {
    Ascii = sumNode % (90 - 65 + 1) + 65;
}

// Ağacın boş olup olmadığını kontrol etme
bool AvlTree::isEmpty() const {
    return root == nullptr;
}

// Yeni bir eleman eklemek
void AvlTree::Add(const int& item) {
    root = SearchAndAdd(root, item);
}

// Postorder dolaşma işlemi
void AvlTree::postorder() {
    postorder(root);
}

// Ağacın yüksekliğini alma
int AvlTree::Height() {
    return Height(root);
}

// Eleman arama işlemi
bool AvlTree::Search(const int& item) {
    return Search(root, item);
}

// Ağacı temizleme
void AvlTree::Clear() {
    while (!isEmpty()) DeleteNode(root);
}

// AvlTree sınıfının yıkıcı fonksiyonu
AvlTree::~AvlTree() {
    Clear();
    delete stack;
}
