USERNAME = boenkyo
KB_BASE = splitkb/aurora
KB = corne

.PHONY: init flash draw clean
init:
	git submodule update --init --recursive --remote --merge
	
	rm -rf qmk_firmware/keyboards/$(KB_BASE)/$(KB)/keymaps/$(USERNAME)
	rm -rf qmk_firmware/users/$(USERNAME)
	ln -s $(shell pwd)/keymaps/$(KB) qmk_firmware/keyboards/$(KB_BASE)/$(KB)/keymaps/$(USERNAME)
	ln -s $(shell pwd)/userspace qmk_firmware/users/$(USERNAME)

	# Compilation db
	cd qmk_firmware; qmk generate-compilation-database -kb $(KB_BASE)/$(KB) -km $(USERNAME)

flash:
	cd qmk_firmware; qmk flash -kb $(KB_BASE)/$(KB) -km $(USERNAME)

draw:
	qmk c2json --no-cpp -kb $(KB_BASE)/$(KB) -km $(USERNAME) qmk_firmware/keyboards/$(KB_BASE)/$(KB)/keymaps/$(USERNAME)/keymap.c | keymap parse -c 10 -q - > keymaps/$(KB)/keymap.yaml

clean:
	rm -rf qmk_firmware/
	