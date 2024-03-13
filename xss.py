import sys
from PyQt5.QtWidgets import (
    QApplication,
    QWidget,
    QVBoxLayout,
    QLabel,
    QLineEdit,
    QPushButton,
    QTextEdit
)
from PyQt5.QtGui import QColor

import requests
from bs4 import BeautifulSoup
import urllib.parse

class XSSDetector(QWidget):
    def __init__(self):
        super().__init__()
        self.init_arayuz()

    def init_arayuz(self):
        self.setWindowTitle('XSS Açık Tarayıcı')
        self.setStyleSheet("background-color: black; color: white;")

        self.url_etiketi = QLabel('Hedef URL:')
        self.url_etiketi.setStyleSheet("color: white;")
        self.url_giris = QLineEdit()
        self.tara_butonu = QPushButton('Tara')
        self.tara_butonu.setStyleSheet("background-color: grey; color: black;")
        self.tara_butonu.clicked.connect(self.xss_tara)

        self.sonuc_etiketi = QLabel('XSS Açıkları:')
        self.sonuc_etiketi.setStyleSheet("color: white;")
        self.sonuc_metin = QTextEdit()
        self.sonuc_metin.setStyleSheet("background-color: #333; color: white;")
        self.sonuc_metin.setReadOnly(True)

        yerlesim = QVBoxLayout()
        yerlesim.addWidget(self.url_etiketi)
        yerlesim.addWidget(self.url_giris)
        yerlesim.addWidget(self.tara_butonu)
        yerlesim.addWidget(self.sonuc_etiketi)
        yerlesim.addWidget(self.sonuc_metin)

        self.setLayout(yerlesim)

    def xss_tara(self):
        hedef_url = self.url_giris.text()
        aciklar = self.xss_ara(hedef_url)

        if aciklar:
            self.sonuc_metin.clear()
            self.sonuc_metin.append("Bulunan XSS Açıkları:")
            for acik in aciklar:
                self.sonuc_metin.append(acik)
        else:
            self.sonuc_metin.clear()
            self.sonuc_metin.append("XSS Açığı Bulunamadı.")

    def xss_ara(self, url):
        payloads = [
            '<script>alert("XSS")</script>',
            '<img src="x" onerror="alert(\'XSS\')" />',
            '<svg onload="alert(\'XSS\')" />',
            'document.getElementById("username").innerHTML = username;',
            'var username = decodeURIComponent(location.search.slice(1));'
        ]
        sonuclar = []

        try:
            response = requests.get(url, verify=True)
            soup = BeautifulSoup(response.content, 'html.parser')

            metinler = soup.find_all(string=True)
            for metin in metinler:
                for payload in payloads:
                    if payload in metin:
                        sonuclar.append(f"Metin içinde XSS bulundu: {payload}")

            parsed_url = urllib.parse.urlparse(url)
            query_params = urllib.parse.parse_qs(parsed_url.query)
            for param, values in query_params.items():
                for value in values:
                    for payload in payloads:
                        if payload in value:
                            sonuclar.append(f"URL parametresinde XSS bulundu ({param}): {payload}")
        except requests.RequestException as e:
            print(f"Hata: {e}")

        return sonuclar

def uygulamayi_calistir():
    app = QApplication(sys.argv)
    pencere = XSSDetector()
    pencere.show()
    sys.exit(app.exec_())

if __name__ == '__main__':
    uygulamayi_calistir()
