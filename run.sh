


g++ calculator.cpp -o calculator

g++ createeditFile.cpp -o createeditFile -lsfml-audio -lsfml-system -pthread

g++ guessgame.cpp -o guessgame $(pkg-config --cflags --libs gtk+-3.0)


g++ movefile.cpp -o movefile


g++ tictactoe.cpp -o tictactoe

g++ main.cpp -o main -pthread

g++ fileinfo.cpp -o fileinfo 

g++ insta.cpp -o insta 

g++ date.cpp -o date

g++ unitconverter.cpp -o unitconverter

g++ RPS.cpp -o RPS

