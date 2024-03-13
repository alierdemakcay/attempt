var veritabani = [
    { id: 1, ad: "Ahmet", yas: 30 },
    { id: 2, ad: "Mehmet", yas: 25 },
    { id: 3, ad: "Ayşe", yas: 35 },
    { id: 4, ad: "Fatma", yas: 28 }
];

function kullaniciBul(id) {
    for (var i = 0; i < veritabani.length; i++) {
        if (veritabani[i].id === id) {
            return veritabani[i];
        }
    }
    return null; 
}

function isimleKullaniciBul(ad) {
    for (var i = 0; i < veritabani.length; i++) {
        if (veritabani[i].ad === ad) {
            return veritabani[i];
        }
    }
    return null; 
}

var arananKullanici = kullaniciBul(2);
if (arananKullanici) {
    console.log("ID'si 2 olan kullanıcı bulundu:", arananKullanici);
} else {
    console.log("ID'si 2 olan kullanıcı bulunamadı.");
}

arananKullanici = isimleKullaniciBul("Ayşe");
if (arananKullanici) {
    console.log("İsmi Ayşe olan kullanıcı bulundu:", arananKullanici);
} else {
    console.log("İsmi Ayşe olan kullanıcı bulunamadı.");
}
