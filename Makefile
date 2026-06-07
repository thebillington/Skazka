all:
	./compile.sh

play: all
	mkdir -p play/rom
	cp main.gb play/rom/
	@printf "Copied main.gb to play/rom/\n"

clean:
	rm -f main.gb *.o *.sym *.map

.PHONY: all play clean
