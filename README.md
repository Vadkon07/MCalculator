# MCalculator

MCalculator (Minimalistic Calculator) that's a very minimalistic calculator for your computer and his OSs as Windows, Linux, and MacOS. This calculator has all the basic functions which you will ever need, without advanced options as science calculator or something else.

This app I created personally for me, to calculate my finances.

## Requierements

**OS:** Windows, Linux, MacOS
**CPU:** If your PC can run browser - he also will run this calculator, easy.
**RAM:** 64MB
**Storage:** 50KB (size of a compiled app)

## Some Information

**Language:** C
**GUI:** gtk3
**License:** MIT

## Installation

1. **Clone the repository:**
```console
git clone https://github.com/Vadkon07/MCalculator.git
cd MCalculator/
```
2. **Compile the code:**
```console
gcc -o mcalculator main.c `pkg-config --cflags --libs gtk+-3.0`
```
3. **Run the app:**
```console
./mcalculator
```

## To-Do

- [ ] **Better README:** Make look of him better. Better description
- [ ] **Keys Support:** If user clicks on '3' (for example), it will click on a '3' button in app's GUI.
- [ ] **Colors:** Make some button colored, as green, purple, or orange.
- [ ] **Don't Reset Result, continue to add to him:** After '=' it shouldn't reset matematical operation, it should give to a user possibility to continue to calculate with result which he got.
- [ ] **Create Logo.**
