KEYMAP = ioeu
KEYBOARD = splitkb/aurora/sweep

init:
	git submodule update --init --recursive --remote --merge
	
	rm -rf qmk_firmware/keyboards/$(KEYBOARD)/keymaps/$(KEYMAP)
	ln -s $(shell pwd)/keymap qmk_firmware/keyboards/$(KEYBOARD)/keymaps/$(KEYMAP)

	# Compilation db
	cd qmk_firmware; qmk generate-compilation-database -kb $(KEYBOARD) -km $(KEYMAP)

flash:
	cd qmk_firmware; qmk flash -kb $(KEYBOARD) -km $(KEYMAP)

compile:
	cd qmk_firmware; qmk compile -kb $(KEYBOARD) -km $(KEYMAP)

draw:
	qmk c2json --no-cpp -kb $(KEYBOARD) -km $(KEYMAP) qmk_firmware/keyboards/$(KEYBOARD)/keymaps/$(KEYMAP)/keymap.c | keymap parse -c 10 -q - > keymap.yaml
clean:
	rm -rf qmk_firmware/
