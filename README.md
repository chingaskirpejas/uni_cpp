# Pirma užduotis (v0.2)
1. Šioje programoje naudojami duomenys susije su studentais - _vardas, pavarde, pažymiai, egzamino įvertinimas_
2. Vartotojas turi keturias parinktis darbui su duomenimis:
 	- Duomenų įvedimas ranka
  	- Duomenų automatinis generavimas (nerašant į failą)
  	- Duomenų nuskaitymas iš failo
  	- Failų su duomenimis generavimas
3. Duomenų išvedimo į ekraną metu bus rodomi studento vardas, **pavardė bei galutinis rezultatas**, _jei vartotojas pasirenka duomenų įvedimą ranka turėtų būt papildomai nurodoma pagal kokius kriterijus išvesti duomenis (**vidurkis** arba **mediana**)_

## Programos veikimo analizė
Programos veikimas buvo analizuojamas penkiais skirtingais failų dydžiais (failo pavadinime nurodytas studentų skaičius faile).<br>
```
1000.txt
10000.txt
100000.txt
1000000.txt
10000000.txt
```
<br>
Konkrečiai buvo analizuojamas failų su duomenimis generavimas, sugeneruotų duomenų nuskaitymas, rūšiavimas ir galiausiai surašymas į išvesties failus. <br>
<br>
Rūšiavimas atliekamas pagal studento galutini rezultatą kuris yra apskaičiuojamas pagal formulę (0.4 * Namų darbų vidurkis + 0.6 * Egzamino pažymys). Studentai kurių vidurkis yra mažiau nei 5 yra priskiriami vienai grupei, o studentai kurių vidurkis yra lygus arba daugiau už 5 yra priskiriami kitai grupei.  <br>
<br>

 **Analizės eiga**
 <br>
 Su kiekvienu iš nurodytų failų dydžių atliekami šie veiksmai paeiliui, bei matuojamas laikas sugaištas kiekvienam veiksmui atlikti:
 - Sukuriamas ir užpildomas failas
 - Nuskaitomas failo turinys
 - Failo turinys surūšiuojamas pagal minėtą kriterijų 
 - Studentai iš kiekvienos grupes yra surašomi į atskirus failus
<br>
<br>
Failo analizei pasibaigus, gauti rezultatai yra išvedami į ekraną.

## Analizės rezultatai
![image](https://github.com/chingaskirpejas/uni_cpp/assets/47268986/c45c1d99-1ced-49d4-a45c-f7a73b067cbb) ![image](https://github.com/chingaskirpejas/uni_cpp/assets/47268986/b572421b-7f9c-4654-ba2c-121e5b9a884a)
![image](https://github.com/chingaskirpejas/uni_cpp/assets/47268986/5ce30f1c-67d7-4133-99d2-eb3d7afb5d91) ![image](https://github.com/chingaskirpejas/uni_cpp/assets/47268986/12f923df-7216-4659-a45f-2c94bbbc03e4)
![image](https://github.com/chingaskirpejas/uni_cpp/assets/47268986/a20a13e3-9d6c-451d-9d8b-6283a7d4e0ee)




