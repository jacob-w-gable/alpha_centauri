include rules.mk

DEPS := src/driver.c $(KEYMAP_NAME).c config.h
ifeq ($(AUTOCORRECT_ENABLE), yes)
DEPS += autocorrect_data.h
endif

.PHONY: c json compile flash clean all deps

all: compile

# build the firmware (mostly, you should just use this to validate before flashing)
compile: $(DEPS)
	qmk compile

# Alias for compiling dependencies
deps: $(DEPS)

# Convert the json config to a needed c file
$(KEYMAP_NAME).c: $(KEYMAP_NAME).json
	qmk json2c -o $(KEYMAP_NAME).c $(KEYMAP_NAME).json

# Alias for the above
c: $(KEYMAP_NAME).c

# Convert the c file to json
json:
	qmk c2json -km default -kb alpha_centauri -o $(KEYMAP_NAME).json $(KEYMAP_NAME).c

# Build the autocorrect header from the dictionary
autocorrect_data.h: autocorrect_dictionary.txt
	qmk generate-autocorrect-data autocorrect_dictionary.txt

# Alias for the above
autocorrect: autocorrect_data.h

# Use this to flash the firmware. This flashes both sides with their own firmware,
# making it so that the USB can be plugged into either side.
flash: $(DEPS)
	./mount_rp2040.sh
	qmk flash -bl uf2-split-left
	sleep 2
	./mount_rp2040.sh
	qmk flash -bl uf2-split-right

flash_left: $(DEPS)
	./mount_rp2040.sh
	qmk flash -bl uf2-split-left

flash_right: $(DEPS)
	./mount_rp2040.sh
	qmk flash -bl uf2-split-right
	
clean:
	rm *.bak autocorrect_data.h keymap/jacob-w-gable.c


