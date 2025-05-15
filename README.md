# Projekt-MLTR
Ta repozitorij vsebuje testne in demonstracijske programe za razvojno ploščo **GEMS Amethyst**, zasnovano v okviru projekta **Erasmus+ GEMS**. Plošča temelji na mikrokrmilniku **ESP32-C3** in vključuje RGB LED, svetlobni senzor TEPT5700, uporabniške gumbe, USB-C povezavo ter osnovne komunikacijske vmesnike.

## Namen repozitorija
Cilj repozitorija je prikazati osnovno delovanje posameznih komponent plošče skozi kratke, samostojne primere kode, ki so primerni za testiranje, uvodno učenje in prototipiranje.

## Vsebina
### 1. Osnovni primer – Preklapljanje barve LED z gumbom
- Program omogoča **kroženje barv RGB LED** (rdeča → zelena → modra) ob vsakem pritisku gumba BTN.
- LED sveti stalno z maksimalno svetlostjo.
- Namen: Preverjanje delovanja RGB LED in gumba.

### 2. Napredni primer – "Dihanje" LED glede na osvetljenost
- RGB LED dioda **dihajoče** utripa (PWM 0–4095).
- Uporabnik lahko z gumbom BTN izbere barvni kanal (R/G/B).
- **Hitrost dihanja** je odvisna od osvetljenosti prostora, merjene s fototranzistorjem.
- Namen: Prikaz uporabe svetlobnega senzorja, PWM LEDC in interaktivnosti z uporabnikom.


## Avtorji
Ta projekt je bil razvit v okviru predmeta *Mehatronika in laserska tehnika - RRP* na Fakulteti za strojništvo UL.

Avtorji:
- Jaka Česen
- Tilen Dolinar
- Ines Džombič
- Jakob Erhartič

Mentor:
- doc. dr. Gašper Škulj
