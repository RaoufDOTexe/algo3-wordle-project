# 🎮 Wordle Game & Solveur — ALGO3 L2 ISIL

Projet réalisé dans le cadre du module **ALGO3 (Langage C)** — Département Informatique, USTHB.  
Ce projet comporte :

- ✔️ une implémentation complète du jeu **Wordle** en ligne de commande  
- ✔️ un **solveur automatique** capable de deviner un mot de 5 lettres  
- ✔️ un rapport d’analyse détaillé (complexité, stratégie, documentation)

---

## 📌 Fonctionnalités principales

### 🎮 Partie 1 — Jeu Wordle
- Lecture d’un dictionnaire de mots (`words.txt`)
- Choix aléatoire d’un mot de 5 lettres
- Vérification des mots saisis par l'utilisateur
- Gestion des 6 tentatives autorisées
- Retour du feedback :
  - 🟩 **Vert** : bonne lettre au bon emplacement  
  - 🟨 **Jaune** : lettre correcte au mauvais emplacement  
  - ⬛ **Gris** : lettre absente  
- Affichage coloré compatible Windows (ANSI Colors)

---

### 🤖 Partie 2 — Solveur automatique
Le solveur :

- choisit un mot initial simple (premier de la liste des candidats)
- reçoit le feedback du programme Wordle
- filtre la liste des mots possibles
- élimine les mots incompatibles
- répète jusqu’à trouver le mot

Cette stratégie est simple, déterministe et adaptée au niveau du module ALGO3.

---

## 📁 Structure du projet

```
Wordle-Solver/
│
├── src/
│   ├── game.c
│   ├── game.h
│   ├── solver.c
│   ├── solver.h
│   ├── wordlist.c
│   ├── wordlist.h
│   ├── main_game.c
│   └── main_solver.c
│
├── dict/
│   └── words.txt
│
├── build.bat
├── README.md
└── Rapport_Wordle.pdf / Rapport_Wordle.docx
```

---

## ▶️ Compilation et exécution (Windows + MinGW)

### 🔧 Compilation
Lancer simplement :

```
build.bat
```

Cela génère automatiquement :

```
wordle_game.exe
wordle_solver.exe
```

---

## 🎮 Lancer le jeu Wordle
```
wordle_game.exe
```

---

## 🤖 Lancer le solveur
```
wordle_solver.exe
```

---

## 📄 Rapport
Le rapport fourni comprend :

- la description de la stratégie  
- la justification des structures de données  
- l’analyse de complexité  
- la documentation du code  
- des captures d’écran  

---

## 🛠️ Technologies utilisées
- Langage C (standard ANSI)
- MinGW / GCC
- ANSI Terminal Colors
- Programmation modulaire
- Allocation dynamique (malloc/free)

---

## 👨‍💻 Auteur
**Mohammed Amine Abderraouf Ali**  
L2 ISIL — USTHB  
Module : ALGO3

---

## 📜 Licence
Projet réalisé dans un cadre académique (usage éducatif uniquement).