# Use with caution!!!! Make sure to set correct device (check dmesg for sdXX)
sudo dd if=build/tfl_micro_pico.uf2 of=/dev/sdd1 bs=25600
