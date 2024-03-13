#include <QApplication>
#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>
#include <QWebEngineView>
#include <QPushButton>
#include <QLineEdit>
#include <QProgressBar>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Ana pencere oluşturuluyor
    QMainWindow window;
    window.setWindowTitle("Web Görünümü");

    // Ana merkezi widget oluşturuluyor
    QWidget *centralWidget = new QWidget(&window);
    window.setCentralWidget(centralWidget);

    // Merkezi düzen oluşturuluyor
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    // Web görünümü oluşturuluyor
    QWebEngineView *webView = new QWebEngineView(centralWidget);
    webView->setUrl(QUrl("https://trsoic.com.tr"));

    // Geri gitme, ileri gitme ve sayfa yenileme düğmeleri oluşturuluyor
    QPushButton *backButton = new QPushButton("Geri Git", centralWidget);
    QPushButton *forwardButton = new QPushButton("İleri Git", centralWidget);
    QPushButton *reloadButton = new QPushButton("Sayfayı Yenile", centralWidget);

    // Geri gitme, ileri gitme ve sayfa yenileme işlevselliği ekleniyor
    QObject::connect(backButton, &QPushButton::clicked, webView, &QWebEngineView::back);
    QObject::connect(forwardButton, &QPushButton::clicked, webView, &QWebEngineView::forward);
    QObject::connect(reloadButton, &QPushButton::clicked, webView, &QWebEngineView::reload);

    // URL girişi için bir QLineEdit oluşturuluyor
    QLineEdit *urlLineEdit = new QLineEdit(centralWidget);
    urlLineEdit->setText("https://trsoic.com.tr");

    // Sayfaya gitme düğmesi oluşturuluyor
    QPushButton *goButton = new QPushButton("Git", centralWidget);
    QObject::connect(goButton, &QPushButton::clicked, [=]() {
        webView->setUrl(QUrl(urlLineEdit->text()));
    });

    // İlerleme çubuğu oluşturuluyor
    QProgressBar *progressBar = new QProgressBar(centralWidget);
    progressBar->setRange(0, 100);
    QObject::connect(webView, &QWebEngineView::loadProgress, progressBar, &QProgressBar::setValue);

    // Web görünümü, URL girişi, düğmeler ve ilerleme çubuğu düzen içine ekleniyor
    layout->addWidget(backButton);
    layout->addWidget(forwardButton);
    layout->addWidget(reloadButton);
    layout->addWidget(urlLineEdit);
    layout->addWidget(goButton);
    layout->addWidget(progressBar);
    layout->addWidget(webView);

    // Ana pencere gösteriliyor
    window.show();

    // Uygulama döngüsü başlatılıyor
    return app.exec();
}
#include <iostream>

int main() {
    std::cout << "NO ERR" << std::endl;
    return 0;
}
#include <iostream>

int main() {
    std::cout << "NO ERR" << std::endl;
    return 0;
}
#include <iostream>

int main() {
    std::cout << "NO ERR" << std::endl;
    return 0;
}
#include <iostream>

int main() {
    std::cout << "NO ERR" << std::endl;
    return 0;
}
#include <iostream>

int main() {
    std::cout << "NO ERR" << std::endl;
    return 0;
}
#include <iostream>

int main() {
    std::cout << "NO ERR" << std::endl;
    return 0;
}
#include <iostream>

int main() {
    std::cout << "NO ERR" << std::endl;
    return 0;
}
