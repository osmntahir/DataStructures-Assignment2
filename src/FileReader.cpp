/** 
* @file -->FileReader.cpp
* @description -->Veriler.txt dosyasını okuyan ve ağaçları oluşturan FileReader sınıfı
* @assignment 2
* @date 12/12/2023
* @author Osman Tahir Özdemir  osman.ozdemir3@ogr.sakarya.edu.tr  ya da ozdemirosmantahir@gmail.com
*/

#include "FileReader.hpp"

// FileReader sınıfının yapıcı fonksiyonu
FileReader::FileReader(/* args */)
{
    this->Trees = new List();
}

// Dosyayı okuyan ve ağaçları oluşturan fonksiyon
void FileReader::ReadFile() {
    std::ifstream Oku("doc//veriler.txt");

    // Dosyanın açılıp açılamadığını kontrol et
    if (!Oku.is_open()) {
        std::cerr << "Dosya bulunamadi: doc//veriler.txt" << std::endl;
        return;
    }

    std::string a;
    while (getline(Oku, a)) {
        std::istringstream iss(a);
        std::string strnum;

        // Her satır için yeni bir AVL ağacı oluştur
        AvlTree* tree = new AvlTree();

        // Satırdaki her sayıyı oku ve AVL ağacına ekle
        while (getline(iss, strnum, ' ')) {
            try {
                int veri = std::stoi(strnum);
                tree->Add(veri);
            } catch (const std::invalid_argument& e) {
                std::cerr << "Gecersiz veri: {FileReader::ReadFile()}" << strnum << std::endl;
            }
        }

        // Ağacı postorder şeklinde dolaş ve ASCII değerini hesapla
        tree->postorder();
        tree->sumNodeToAscii();

        // Ağacı listeye ekle
        Trees->addTree(tree);
    }

    Oku.close();  // Dosyayı kapat
}

// Listeyi başlatan fonksiyon
void FileReader::Start()
{
    Trees->start();
}

// FileReader sınıfının yıkıcı fonksiyonu
FileReader::~FileReader()
{
   delete this->Trees;
}
