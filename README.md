# Pirma užduotis (v0.3)
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
Rūšiavimas atliekamas pagal studento galutini rezultatą kuris yra apskaičiuojamas pagal formulę (0.4 * Namų darbų vidurkis + 0.6 * Egzamino pažymys). Studentai turintys <br>
<br>

 **Analizės eiga**
 <br>
 Su kiekvienu iš nurodytų failų dydžių atliekami šie veiksmai paeiliui:
 - Sukuriamas ir užpildomas failas
 - Nuskaitomas failo turinys
 - Failo turinys surūšiuojamas pagal minėtą kriterijų i du skirtingus konteinerius
 - Iš surušiuotų duonmenų konteineriu failai surašomi i output failus

 ## Analizės rezultatai
 **Vector tipo konteinerio rezultatai**
 <br>
|                                               |  1000   |  10000  | 100000 | 1000000 | 10000000  |
| --------------------------------------------- |:-------:|:-------:|:------:|:-------:|:---------:|
|  Failo generavimo laikas                      | 0,012 s | 0,054 s | 0,53 s | 6,117 s | 65,655 s  |
|  Failo nuskaitymo vidutinis laikas            | 0,009 s | 0,043 s | 0,395 s| 4,367 s | 44,966 s  |
|  Failo išrūšiavimo vidutinis laikas           | 0 s     | 0,002 s | 0,02 s | 0,49 s  | 30,547 s  |
|  Išrašymo į failus vidutinis laikas           | 0,008 s | 0,056 s | 0,560 s| 5,454 s | 57,283 s  |

 **List tipo konteinerio rezultatai**
 <br>
|                                               |  1000   |  10000  | 100000 | 1000000 | 10000000  |
| --------------------------------------------- |:-------:|:-------:|:------:|:-------:|:---------:|
|  Failo generavimo laikas                      | 0,012 s | 0,054 s | 0,53 s | 6,117 s | 65,655 s  |
|  Failo nuskaitymo vidutinis laikas            | 0,011 s | 0,061 s | 0,527 s| 5,277 s | 41,838 s  |
|  Failo išrūšiavimo vidutinis laikas           | 0 s     | 0,004 s | 0,041 s| 0,382 s | 39,220 s  |
|  Išrašymo į failus vidutinis laikas           | 0,009 s | 0,056 s | 0,537 s| 5,257 s | 73,464 s  |

## Analizės išvados
<br>
Matome jog su mažesniais failais konteinerio tipo skirtumas nedaro beveik jokios įtakos, tačiau failo dydžiui ir duomenų kiekiui didėjant, matome, jog **List** tipo konteineris yra mažiau efektyvesnis nei **Vector**

## Kompiuterio specifikacijos

CPU: Intel Core i5-6500 @ 3.2GHz<br>
RAM: 8GB DDR3 2133MHz<br>
STORAGE: SAMSUNG 850 EVO SSD<br>
