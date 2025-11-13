@echo off
echo Building WORDLE GAME...
gcc -mconsole src\wordlist.c src\game.c src\main_game.c -o wordle_game.exe

echo Building WORDLE SOLVER...
gcc -mconsole src\wordlist.c src\game.c src\solver.c src\main_solver.c -o wordle_solver.exe

echo Build done.
pause
