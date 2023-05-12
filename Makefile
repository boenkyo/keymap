KEYMAP = ioeu
KEYBOARD = splitkb/aurora/sweep

init:
	# Init submodule
	git submodule update --init --recursive
	
	# Symlink keymap
	rm -rf qmk_firmware/keyboards/$(KEYBOARD)/keymaps/$(KEYMAP)
	ln -s $(shell pwd)/keymap qmk_firmware/keyboards/$(KEYBOARD)/keymaps/$(KEYMAP)

flash:
	cd qmk_firmware; qmk flash -kb $(KEYBOARD) -km $(KEYMAP)

clean:
	rm -rf qmk_firmware/
