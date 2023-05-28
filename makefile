.SHELL := bash

all:
	g++ -g main.cpp
	@make run -s

debug:
	g++ -g main.cpp

run:
	@echo "---------------------"
	@sed -n "1,$$(($$(grep -n -x "===" test.txt | cut -d ":" -f 1 | sed -n "1p")-1))p" test.txt
	@echo -n "> "
	@sed -n "1,$$(($$(grep -n -x "===" test.txt | cut -d ":" -f 1 | sed -n "1p")-1))p" test.txt | ./a.out
	@echo "---------------------"
	@sed -n "$$(($$(grep -n -x "===" test.txt | cut -d ":" -f 1 | sed -n "1p")+1)),$$(($$(grep -n -x "===" test.txt | cut -d ":" -f 1 | sed -n "2p")-1))p" test.txt
	@echo -n "> "
	@sed -n "$$(($$(grep -n -x "===" test.txt | cut -d ":" -f 1 | sed -n "1p")+1)),$$(($$(grep -n -x "===" test.txt | cut -d ":" -f 1 | sed -n "2p")-1))p" test.txt | ./a.out
	@echo "---------------------"
	@sed -n "$$(($$(grep -n -x "===" test.txt | cut -d ":" -f 1 | sed -n "2p")+1)),$$(cat -n test.txt | tail -n1 | cut -f 1)p" test.txt
	@echo -n "> "
	@sed -n "$$(($$(grep -n -x "===" test.txt | cut -d ":" -f 1 | sed -n "2p")+1)),$$(cat -n test.txt | tail -n1 | cut -f 1)p" test.txt | ./a.out
	@echo "---------------------"



sandbox:
	sed -n "1,$$(($$(grep -n -x "===" test.txt | cut -d ":" -f 1 | sed -n "1p")-1))p" test.txt
	sed -n "$$(($$(grep -n -x "===" test.txt | cut -d ":" -f 1 | sed -n "1p")+1)),$$(($$(grep -n -x "===" test.txt | cut -d ":" -f 1 | sed -n "2p")-1))p" test.txt
	sed -n "$$(($$(grep -n -x "===" test.txt | cut -d ":" -f 1 | sed -n "2p")+1)),$$(cat -n test.txt | tail -n1 | cut -f 1)p" test.txt
