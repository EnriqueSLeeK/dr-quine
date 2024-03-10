
NAME1 := Colleen
NAME2 := Grace
NAME3 := Sully

SRC1 := ./C/Colleen.c
SRC2 := ./C/Grace.c
SRC3 := ./C/Sully.c



Colleen-C: $(SRC1)
	gcc $(SRC1) -o $(NAME1)
Grace-C: $(SRC2)
	gcc $(SRC2) -o $(NAME2)
Sully-C: $(SRC3)
	gcc $(SRC3) -o $(NAME3)

clean:
	rm -f $(NAME1)
	rm -f $(NAME2)
	rm -f $(NAME3)
	rm -f Sully_*

help:
	@echo "Collen-C for Colleen written in C"
	@echo "Grace-C for Grace written in C"
	@echo "Sully-C for Sully written in C"

	@echo

	@echo "Collen-A for Collen written in ASM"
	@echo "Grace-A for Grace written in ASM"
	@echo "Sully-A for Sully written in ASM"
